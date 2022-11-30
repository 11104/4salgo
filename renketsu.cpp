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

//insert to s
static void s_in(const char* sc,const char* sm){
    snode* stmp;
    stmp=(snode*)malloc(sizeof(snode));
    stmp->skey=sc;
    stmp->smean=sm;
    stmp->snext=NULL;
    shead=stmp;
}

//print s
void prints(){
    snode *stmp;
    for(stmp=shead;stmp->snext!=NULL;stmp=stmp->snext){
        std::cout<<stmp->skey<<" "<<stmp->smean<<std::endl;
    }
}

//insert to t
static void t_in(const char* tc,const char* tm){
    int clen=strlen(tc);
    int check;
    tnode point;
    point=*thead;
    for(int i=0;i<clen;i++){
        check=tc[i];
        if(point.tnext[check]==NULL)break;
        else point=point.tnext[check];
    }
    tnode* ttmp;
    ttmp=(tnode*)malloc(sizeof(tnode));
    ttmp->tkey=tc;
    ttmp->tmean=tm;
    ttmp->tnext=NULL;

}


//print t


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