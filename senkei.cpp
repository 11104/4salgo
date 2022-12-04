#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

struct s_node{
    const char* skey;
    const char* smean;
    struct s_node *snext;
};
s_node *shead=NULL;//new s_node;

//convert char to int
int numchar(char ch){
    int henkan;
    henkan=ch;
    //convert uppercase to lowercase
    if('A'<=ch&&ch<='Z')ch+=32;
    return henkan-97;
}

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
    if(shead==NULL)return 1;
    int silen=strlen(sic);
    int cmpcount=0;
    s_node *stmp=new s_node;
    for(stmp=shead;stmp->snext!=NULL;stmp=stmp->snext){
        cmpcount++;
        if(!cmp(sic,stmp->skey)){
            std::cout<<"Found! "<<stmp->skey<<" mean:"<<stmp->smean<<std::endl;
            std::cout<<" Passed node:"<<cmpcount<<std::endl;
            return 0;
        }
    }
    std::cout<<stmp->skey<<" isn't exist."<<std::endl;
    return 1;
}

//insert to s
static void s_in(const char* sc,const char* sm){
    int psnode=0;
    //if(shead!=NULL){
        s_node *stmp=(s_node*)malloc(sizeof(s_node));
        stmp->skey=sc;
        stmp->smean=sm;
        stmp->snext=shead;
        shead=stmp;
        std::cout<<"Successed! :"<<stmp->skey<<": Passed node:"<<psnode<<std::endl;
    //}
}

void prints(){
    s_node *spr;//=(s_node*)malloc(sizeof(s_node));//new s_node;
    for(spr=shead;spr->snext!=NULL;spr=spr->snext){
        std::cout<<spr->skey<<" "<<spr->smean<<std::endl;
    }
}

int main(){
    s_in("one","ichi");
    prints();
    return 0;
}