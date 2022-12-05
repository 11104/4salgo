/*!! issue
    First push can't do correctly
*/

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

//typedef s_node
//s_nodeを定義します。
struct s_node{
    const char* skey;//単語
    const char* smean;//意味
    struct s_node *snext;//次の単語(s_node)
};
s_node *shead=NULL;//new s_node;

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

//insert to s
int s_count=0;
static void s_in(const char* sc,const char* sm){
    int psnode=0;
    std::cout<<"Add word:"<<sc<<" mean:"<<sm<<std::endl;
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
int s_incheck(const char* sic){
    std::cout<<"Search word:"<<sic<<std::endl;
    if(s_count==0)return 0;//list underflow
    int silen=strlen(sic);
    int cmpcount=0;
    s_node *sintmp=(s_node*)malloc(sizeof(s_node));
    for(sintmp=shead;sintmp->snext!=NULL;sintmp=sintmp->snext){
        cmpcount++;
        if(cmp(sic,sintmp->skey)){//cmpが1を返す==単語を発見==if文がtrue==単語とその意味を表示
            std::cout<<"Found! "<<sic<<" mean:"<<sintmp->smean<<" Passed node:"<<cmpcount<<std::endl;
            space();
            return 1;
        }
    }
    std::cout<<sic<<" isn't exist."<<std::endl;
    space();
    return 0;
}


//main

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

//delete from s
//sから単語を取り除く。
int s_delete(const char* dels){
    std::cout<<"Delete word:"<<dels<<std::endl;
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

void s_set();//資料で行った通りの操作をする

int main(){
    /*
    ここで関数を呼び出してs_inやs_incheckを自由に行える。
    各自で試して、改善案を考えると勉強になる。
    */
   /* test
    s_in(" "," ");
    s_in("one","ichi");
    s_in("two","ni");
    s_in("hello","konichiha");
    s_print();
    
    s_delete("one");
    s_incheck("one");
    s_in("one","ichi");
    s_incheck("one");
    s_print();
    */
   s_set();
   return 0;
}

//data set
void s_set(){
    std::cout<<"1 s_in"<<std::endl;
    space();
    s_in("","");
    s_in("one","ichi");
    s_in("two","ni");
    space();

    std::cout<<"data set.."<<std::endl;
    s_in("three","san");
    s_in("four","yon");
    s_in("god","kami");
    s_in("sky","sora");
    s_in("seven","nana");
    s_in("eight","hachi");
    s_in("nine","kyu");
    s_in("ten","juu");
    s_in("eleven","juuichi");
    s_in("twelve","juuni");
    s_in("threteen","juusan");
    s_in("fourteen","juuyo");
    s_in("five","go");
    s_in("six","roku");
    s_in("seventeen","juunana");
    s_in("eighteen","juuhachi");
    s_in("nineteen","juukyu");
    s_in("twenty","nujuu");
    s_in("twentyone","nijuuichi");
    s_in("twentytwo","nijuuni");
    s_in("twentythree","nijuusan");
    s_in("twentyfour","nijuuyon");
    s_in("twentyfive","nujuugo");
    s_in("twentysix","nijuuroku");
    s_in("twentyseven","nijuunana");
    s_in("twentyeight","nijuuhachi");
    s_in("twentynine","nijuukyu");
    s_in("win","katsu");
    //s_print();//test
    std::cout<<"data set complete."<<std::endl;
    space();

    std::cout<<"2 s_incheck"<<std::endl;
    s_incheck("one");
    s_incheck("five");
    s_incheck("six");
    s_incheck("win");
    space();

    std::cout<<"3 s_delete"<<std::endl;
    s_delete("one");
    s_delete("five");
    s_delete("six");
    s_delete("win");
    
    //s_print();//test

    std::cout<<"senkei hikaku completed!"<<std::endl;
}