/*!! issue
    First push can't do correctly
*/

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

//typedef s_node
//s_nodeを定義します。
struct t_node{
    const char* tkey;//単語
    const char* tmean;//意味
    struct t_node *tnext[26];//次の単語(s_node)
};
t_node *thead[26];//new s_node;

//return line
//改行します。
void space(){
    std::cout<<std::endl;
}

//convert char to int
//ASCIIによって文字を数字に変換する。(改善案用)
int numchar(char ch){
    int henkan;
    henkan=ch;
    //convert uppercase to lowercase
    //大文字を小文字に変換する
    if('A'<=ch&&ch<='Z')ch+=32;
    return henkan-97;
}

//insert to t
int t_count=0;
static void t_in(const char* tc,const char* tm){
    int ptnode=0;
    int tlen=strlen(tc);
    std::cout<<"Add word:"<<tc<<" mean:"<<tm<<std::endl;
    t_node *ttmp=(t_node*)malloc(sizeof(t_node));
    ttmp->tkey=tc;
    ttmp->tmean=tm;
    t_node *ti=(t_node*)malloc(sizeof(t_node));
    ti=thead[numchar(tc[0])];
    int i=0;
    for(i=0;i<tlen-1;i++){
        if(ti->tnext[numchar(tc[i])]==NULL){
            t_node *tnew=(t_node*)malloc(sizeof(t_node));
            ti->tnext[numchar(tc[i])]=tnew;
        }else ti=ti->tnext[numchar(tc[i])];
    }
    ti->tnext[numchar(tc[i])]=ttmp;
    t_count++;
    //free(ttmp);
    //free(ti);
}

/*
//search s

//文字列c1とc2を比較。一致していれば1を返す。
int cmp(const char* c1,const char* c2){
    int c1len=strlen(c1);
    int c2len=strlen(c2);
    if(c1len!=c2len)return 0;
    for(int i=0;i<c1len;i++){
        if(c1[i]!=c2[i])return 0;
    }
    return 1;
}

//検索ヒットした単語と意味を表示する。
int t_incheck(const char* sic){
    std::cout<<"Search word:"<<sic<<std::endl;
    if(s_count==0)return 0;
    int silen=strlen(sic);
    int cmpcount=0;
    s_node *sintmp=(s_node*)malloc(sizeof(s_node));
    for(sintmp=shead;sintmp->snext!=NULL;sintmp=sintmp->snext){
        cmpcount++;
        if(cmp(sic,sintmp->skey)){
            std::cout<<"Found! "<<sic<<" mean:"<<sintmp->smean<<" Passed node:"<<cmpcount<<std::endl;
            space();
            return 1;
        }
    }
    std::cout<<sic<<" isn't exist."<<std::endl;
    space();
    return 0;
}
*/

//main
/*
//sの中身をprintする。
void s_print(){
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
*/

/*
//delete from s
//sから単語を取り除く。
int s_delete(const char* dels){
    std::cout<<"Delete :"<<dels<<std::endl;
    if(s_count==0){
        std::cout<<dels<<" isn't exist."<<std::endl;
        return 0;
    }
    int cmpcount=0;
    s_node *sdetmp=(s_node*)malloc(sizeof(s_node));
    for(sdetmp=shead;sdetmp->snext!=NULL;sdetmp=sdetmp->snext){
        cmpcount++;
        if(cmp(dels,sdetmp->skey)){
            sdetmp->snext=sdetmp->snext->snext;            
            std::cout<<"Deleted. Passed node:"<<cmpcount<<std::endl;
            space();
            return 1;
        }
    }
    std::cout<<dels<<" isn't exist."<<std::endl;
    space();
    return 0;

}


void s_set();
*/

int main(){
    for(int j=0;j<26;j++){
        thead[j]=NULL;
    }
   ///* test
    //t_in(" "," ");
    t_in("one","ichi");
    //t_in("two","ni");
    //t_in("hello","konichiha");
    /*
    s_print();
    
    s_delete("one");
    t_incheck("one");
    t_in("one","ichi");
    t_incheck("one");
    s_print();
    //*/
   //s_set();
   return 0;
}

/*
void s_set(){
    std::cout<<"1 t_in"<<std::endl;
    space();
    t_in("","");
    t_in("one","ichi");
    t_in("two","ni");
    space();

    std::cout<<"data set.."<<std::endl;
    t_in("three","san");
    t_in("four","yon");
    t_in("god","kami");
    t_in("sky","sora");
    t_in("seven","nana");
    t_in("eight","hachi");
    t_in("nine","kyu");
    t_in("ten","juu");
    t_in("eleven","juuichi");
    t_in("twelve","juuni");
    t_in("threteen","juusan");
    t_in("fourteen","juuyo");
    t_in("five","go");
    t_in("six","roku");
    t_in("seventeen","juunana");
    t_in("eighteen","juuhachi");
    t_in("nineteen","juukyu");
    t_in("twenty","nujuu");
    t_in("twentyone","nijuuichi");
    t_in("twentytwo","nijuuni");
    t_in("twentythree","nijuusan");
    t_in("twentyfour","nijuuyon");
    t_in("twentyfive","nujuugo");
    t_in("twentysix","nijuuroku");
    t_in("twentyseven","nijuunana");
    t_in("twentyeight","nijuuhachi");
    t_in("twentynine","nijuukyu");
    t_in("win","katsu");
    //s_print();//test
    std::cout<<"data set complete."<<std::endl;
    space();

    std::cout<<"2 t_incheck"<<std::endl;
    t_incheck("one");
    t_incheck("five");
    t_incheck("six");
    t_incheck("win");
    space();

    std::cout<<"3 s_delete"<<std::endl;
    s_delete("one");
    s_delete("five");
    s_delete("six");
    s_delete("win");
    
    //s_print();//test

    std::cout<<"senkei hikaku completed!"<<std::endl;
}
*/