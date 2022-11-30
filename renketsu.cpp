#include <stdio.h>
#include <string>
#include <iostream>
#include <locale.h>
#include <wchar.h>
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
    return henkan-97;
}

//intsert to s
static void s_in(const char* sc/*,string sm*/){
    snode* stmp;
    stmp=(snode*)malloc(sizeof(snode));
    stmp->skey=sc;
    string sa;
    std::cin>>sa;
    stmp->smean=sa;
    stmp->snext=NULL;
    shead=stmp;
}

//print s
void prints(){
    snode *stmp;
    for(stmp=shead;stmp->snext!=NULL;stmp=stmp->snext){
        std::cout<<stmp->skey<<" ";
        std::wcout<<stmp->smean<<std::endl;
    }
}

//main
void swstr(const char *){};

int main(){
    setlocale(LC_ALL, "ja_JP.UTF-8");
    s_in("apple");
    s_in("pencil");

    prints();

    
    return 0;
}