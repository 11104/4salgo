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
bool stable[677]={};
int s_incheck(const char* sic){
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

//insert to s
static void s_in(const char* sc,const char* sm){
    if(s_incheck(sc)){
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

//insert check t
bool ttable[677]={};
int t_incheck(const char* tic){
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

//insert to t
static void t_in(const char* tc,const char* tm){
    if(t_incheck(tc)){//check alrady exit
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
    s_in("apple","ringo");
    s_in("pencil","enpitsu");
    s_in("key","kagi");
}
/*
void t_first(){
    t_in
}
*/

int main(){
    setlocale(LC_ALL, "ja_JP.UTF-8");
    s_first();

    prints();

    
    return 0;
}