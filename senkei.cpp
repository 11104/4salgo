#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

struct s_node{
    const char* skey;
    const char* smean;
    s_node *snext;
};
s_node *shead=new s_node;

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
            std::cout<<"Found! "<<stmp->skey<<" means "<<stmp->smean<<std::endl;
            std::cout<<"checked "<<cmpcount<<"times."<<std::endl;
            return 0;
        }
    }
    std::cout<<stmp->skey<<" isn't exist."<<std::endl;
    std::cout<<"checked "<<cmpcount<<"times."<<std::endl;
    return 1;
}

//insert to s
static void s_in(const char* sc,const char* sm){
    int psnode=0;
    if(s_incheck(sc)){
        s_node *stmp=new s_node;
        stmp->skey=sc;
        stmp->smean=sm;
        stmp->snext=NULL;
        shead=stmp;
        std::cout<<"Successed! Passed node:"<<psnode<<std::endl;
    }//else std::cout<<sc<<" has already exist!\n"<<std::endl;
}

int main(){
    s_in("one","ichi");
    return 0;
}