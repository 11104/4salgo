#include <stdio.h>
#include <string>
#include <iostream>
/*
#include <locale.h>
#include <wchar.h>
*/
using namespace std;

//typedef snode
typedef struct s_node{
    const char* skey;
    const char* smean;
    struct s_node *snext;
}snode;
snode* shead=NULL;

//typedef tnode
typedef struct t_node{
    const char* tkey;
    const char* tmean;
    struct t_node *tnext[26];
}tnode;
tnode* thead=NULL;

//convert char to int
int numchar(char ch){
    int henkan;
    henkan=ch;
    //convert uppercase to lowercase
    if('A'<=ch&&ch<='Z')ch+=32;
    return henkan-97;
}

//insert check s

///*
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
//*/

//insert to s
static void s_in(const char* sc,const char* sm){
    if(s_incheckt(sc)){
        snode* stmp;
        stmp=(snode*)malloc(sizeof(snode));
        stmp->skey=sc;
        stmp->smean=sm;
        stmp->snext=NULL;
        shead=stmp;
    }else std::cout<<sc<<" has already exist!\n"<<std::endl;
}

//print s
void prints(){
    snode *stmp;
    for(stmp=shead;stmp->snext!=NULL;stmp=stmp->snext){
        std::cout<<stmp->skey<<" "<<stmp->smean<<std::endl;
    }
}

///*
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
//*/

//insert to t
static void t_in(const char* tc,const char* tm){
    if(t_incheckt(tc)){//check alrady exit
        int clen=strlen(tc);
        int check;
        t_node* point;
        point=thead;
        int lencount=0;
        for(int i=0;i<clen;i++){
            check=numchar(tc[i]);
            lencount++;
            if(lencount<clen&&point->tnext[check]==NULL){
                tnode* tntmp;
               tntmp=(tnode*)malloc(sizeof(tnode));
               for(int i=0;i<=26;i++){
                    tntmp->tnext[i]=NULL;
                }
                point->tnext[check]=tntmp;
            }
            else point=point->tnext[check];
        }
        tnode* ttmp;
        ttmp=(tnode*)malloc(sizeof(tnode));
        ttmp->tkey=tc;
        ttmp->tmean=tm;
        for(int i=0;i<=26;i++){
        ttmp->tnext[i]=NULL;
        }
    }else{
        std::cout<<tc<<" has already exist!\n"<<std::endl;
    }
}


//print t
void printt(){
    tnode *ttmp;

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
    printt();

    
    return 0;
}