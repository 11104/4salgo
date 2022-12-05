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



//insert to s
int s_count=0;
static void s_in(const char* sc,const char* sm){
    int psnode=0;
    //if(s_count!=0){
        s_node *stmp=(s_node*)malloc(sizeof(s_node));
        stmp->skey=sc;
        stmp->smean=sm;
        stmp->snext=shead;
        shead=stmp;
        std::cout<<"Successed! :"<<stmp->skey<<": Passed node:"<<psnode<<std::endl;
    //}
    s_count++;
}

int s_incheck(const char* sic){
    if(s_count==0)return 1;
    int silen=strlen(sic);
    int cmpcount=0;
    s_node *sintmp=(s_node*)malloc(sizeof(s_node));
    for(sintmp=shead;sintmp->snext!=NULL;sintmp=sintmp->snext){
        /*
        if(cmpcount==0){
            sintmp=sintmp->snext;
            cmpcount++;
        }else{
            */
        cmpcount++;
        if(cmp(sic,sintmp->skey)){
            std::cout<<"Found! "<<sic<<" mean:"<<sintmp->smean<<std::endl;
            std::cout<<" Passed node:"<<cmpcount<<std::endl;
            return 0;
        //}
    }
    }
    std::cout<<sintmp->skey<<" isn't exist."<<std::endl;
    return 1;
}

void space(){
    std::cout<<std::endl;
}

void prints(){
    s_node *spr;//=(s_node*)malloc(sizeof(s_node));//new s_node;
    space();
    std::cout<<"Print s_list"<<std::endl;
    int spricount=1;
    for(spr=shead;spr->snext!=NULL;spr=spr->snext){
        std::cout<<spricount<<" "<<spr->skey<<" "<<spr->smean<<std::endl;
        spricount++;
    }
    space();
}



int main(){
    /*!! issue
    First push can't do correctly
    */
    s_in(" "," ");
    s_in("one","ichi");
    s_in("two","ni");
    s_in("hello","konichiha");
    prints();
    s_incheck("one");
    return 0;
}