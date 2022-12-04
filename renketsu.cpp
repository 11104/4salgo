#include <stdio.h>
#include <string>
#include <iostream>
/*
#include <locale.h>
#include <wchar.h>
*/
using namespace std;

//typedef snode
struct s_node{
    const char* skey;
    const char* smean;
    s_node *snext;
};
//snode* shead=(snode*)malloc(sizeof(snode));
s_node *shead=new s_node;

//typedef tnode
struct t_node{
    const char* tkey;
    const char* tmean;
    struct t_node *tnext[26];
};
//tnode* thead=(tnode*)malloc(sizeof(tnode));
t_node *thead=new t_node;

//convert char to int
int numchar(char ch){
    int henkan;
    henkan=ch;
    //convert uppercase to lowercase
    if('A'<=ch&&ch<='Z')ch+=32;
    return henkan-97;
}

//insert check s
int cmp(const char* c1,const char* c2){
    int c1len=strlen(c1);
    int c2len=strlen(c2);
    if(c1len!=c2len)return 0;
    for(int i=0;i<c1len;i++){
        if(c1[i]!=c2[i])return 0;
    }
    return 1;
}

int s_incheck(const char* sic){
    int silen=strlen(sic);
    int cmpcount=0;
    s_node *stmp=new s_node;
    for(stmp=shead;stmp->snext!=NULL;stmp=stmp->snext){
        cmpcount++;
        if(!cmp(sic,stmp->skey)){
            std::cout<<"Found! "<<stmp->skey<<" means "<<stmp->smean<<std::endl;
            std::cout<<"checked "<<cmpcount<<"times."<<std::endl;
            return 0;
        }
    }
    std::cout<<stmp->skey<<" isn't exist."<<std::endl;
    std::cout<<"checked "<<cmpcount<<"times."<<std::endl;
    return 1;
}

/*
//insert check s using table
bool stable[677]={};
int s_incheckt(const char* sic){
    int silen=strlen(sic);
    int slencount=0;
    for(int i=0;i<silen;i++){
        slencount+=numchar(sic[i]);
    }
    if(ttable[slencount]==true){
        //std::cout<<sic<<" has already exist!\n"<<std::endl;
        return 0;
    }else{
        stable[slencount]=true;
        return 1;
    }
}
*/

//insert to s
static void s_in(const char* sc,const char* sm){
    if(s_incheck(sc)){
        s_node *stmp=new s_node;
        stmp->skey=sc;
        stmp->smean=sm;
        stmp->snext=NULL;
        shead=stmp;
    }//else std::cout<<sc<<" has already exist!\n"<<std::endl;
}

//print s
void prints(){
    s_node *stmp=(s_node*)malloc(sizeof(s_node));//new s_node;
    for(stmp=shead;stmp->snext!=NULL;stmp=stmp->snext){
        std::cout<<stmp->skey<<" "<<stmp->smean<<std::endl;
    }
}

//search s
void s_search(const char* ss){
    s_incheck(ss);
}

//insert check t
int t_incheck(const char* tic){
    int tilen=strlen(tic);
    int cmpcount=0;
    t_node *ttmp=new t_node;
    ttmp=thead;
    for(int i=0;i<tilen;i++){
        if(ttmp->tnext[numchar(tic[i])]==NULL){
            std::cout<<tic<<" doesn't exist."<<std::endl;
            return 1;
        }else ttmp=ttmp->tnext[numchar(tic[i])];
    }
    std::cout<<tic<<" has already exist. It means"<<ttmp->tmean<<std::endl;
    return 0;
}

/*
//insert check t using table
bool ttable[677]={};
int t_incheckt(const char* tic){
    int tilen=strlen(tic);
    int tlencount=0;
    for(int i=0;i<tilen;i++){
        tlencount+=numchar(tic[i]);
    }
    if(ttable[tlencount]==true){
        //std::cout<<tic<<" has already exist!\n"<<std::endl;
        return 0;
    }else{
        ttable[tlencount]=true;
        return 1;
    }
}
*/

//insert to t
static void t_in(const char* tc,const char* tm){
    if(t_incheck(tc)){//check alrady exit
        int clen=strlen(tc);
        int check;
        t_node *point=new t_node;
        point=thead;
        int lencount=0;
        for(int i=0;i<clen;i++){
            check=numchar(tc[i]);
            lencount++;
            if(lencount<clen&&point->tnext[check]==NULL){
                t_node *tntmp=new t_node;
               for(int i=0;i<=26;i++){
                    tntmp->tnext[i]=NULL;
                }
                point->tnext[check]=tntmp;
            }
            else point=point->tnext[check];
        }
        t_node *ttmp=new t_node;
        ttmp->tkey=tc;
        ttmp->tmean=tm;
        for(int i=0;i<=26;i++){
        ttmp->tnext[i]=NULL;
        }
    }else{
        std::cout<<tc<<" has already exist!\n"<<std::endl;
    }
}

/*
//print t
//!!!When not using table,"print t" can't use.
//!!!Because the way of printing use table.


void printt(){
    tnode *ttmp=(tnode*)malloc(sizeof(tnode));

}
*/

//search t
void t_search(const char* ts){
    t_incheck(ts);
}


//void swstr(const char *){};


//main
void s_first(){
    s_in("one","ichi");
    s_in("two","ni");
    s_in("three","san");
    s_in("four","yon");
    s_in("five","go");
    s_in("six","roku");
    s_in("seven","nana");
    s_in("eight","hachi");
    s_in("nine","kyu");
    s_in("ten","ju");
    s_in("apple","ringo");
    s_in("pencil","enpitsu");
}

void t_first(){
    t_in("one","ichi");
    t_in("two","ni");
    t_in("three","san");
    t_in("four","yon");
    t_in("five","go");
    t_in("six","roku");
    t_in("seven","nana");
    t_in("eight","hachi");
    t_in("nine","kyu");
    t_in("ten","ju");
    t_in("apple","ringo");
    t_in("pencil","enpitsu");
}


int main(){
    setlocale(LC_ALL, "ja_JP.UTF-8");
    s_first();
    t_first();
    prints();
    //printt();
    char finds1[26];
    scanf("%s",finds1);
    const char* finds1c=finds1;
    s_search(finds1c);

    char findt1[26];
    scanf("%s",findt1);
    const char* findt1c=findt1;
    t_search(findt1c);

    
    return 0;
}