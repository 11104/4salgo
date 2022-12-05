/*!! issue
    t_incheck tmean can't find
*/

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

//typedef t_node
//t_nodeを定義します。
struct t_node{
    const char* tkey;//単語
    const char* tmean;//意味
    struct t_node *tnext[26];//次の単語への26分岐(t_node)
};
t_node *thead[26];//new t_node;

//tnext=NULLにする
void t_set(t_node *seth[]){
    for(int j=0;j<26;j++){
        t_node *tfn=(t_node*)malloc(sizeof(t_node));
        tfn->tkey=NULL;
        tfn->tmean=NULL;
        for(int k=0;k<26;k++){
            tfn->tnext[k]=NULL;
        }
        seth[j]=tfn;
    }
}

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
    t_node *ti=(t_node*)malloc(sizeof(t_node));
    ti=thead[numchar(tc[0])];
    int i=0;
    int flag=0;
    for(i=0;i<tlen-1;i++){
        if(flag||ti->tnext[numchar(tc[i+1])]==NULL){
            t_node *tnew=(t_node*)malloc(sizeof(t_node));
            tnew->tkey=NULL;
            tnew->tmean=NULL;
            t_set(ti->tnext);
            ti->tnext[numchar(tc[i+1])]=tnew;
            ti=ti->tnext[numchar(tc[i+1])];
            flag=1;
            //std::cout<<"newnode"<<std::endl;//test
        }else{
            ti=ti->tnext[numchar(tc[i+1])];
            //std::cout<<"already"<<std::endl;//test
        }
        ptnode++;
    }
    if(flag||ti->tnext[numchar(tc[i+1])]==NULL){
        t_node *tadd=(t_node*)malloc(sizeof(t_node));
        tadd->tkey=tc;
        tadd->tmean=tm;
        ti->tnext[numchar(tc[i+1])]=tadd;
        t_set(ti->tnext);
    }else{
        ti->tnext[numchar(tc[i+1])]->tkey=tc;
        ti->tnext[numchar(tc[i+1])]->tmean=tm;
    }
    t_count++;
    std::cout<<"Successed! Passed node:"<<ptnode<<std::endl;
}


//search t

//検索ヒットした単語と意味を表示する。
int t_incheck(const char* tic){
    std::cout<<"Search word:"<<tic<<std::endl;
    int tilen=strlen(tic);
    if(tilen<1)return 0;
    int cmpcount=0;
    t_node *tintmp=(t_node*)malloc(sizeof(t_node));
    tintmp=thead[numchar(tic[0])];
    int i=0;
    for(i=0;i<tilen-1;i++){
        if(tintmp->tnext[numchar(tic[i+1])]==NULL){
            std::cout<<tic<<" isn't exist."<<std::endl;
            space();
            return 0;
        }
        tintmp=tintmp->tnext[numchar(tic[i+1])];
        cmpcount++;
        //std::cout<<"Next"<<std::endl;//test
    }
    if(tintmp->tmean==NULL){
        std::cout<<tic<<" isn't exist."<<std::endl;
        space();
        return 0;
    }else{
        std::cout<<"Found! "<<tic<</*" mean:"<<tintmp->tmean<<*/" Passed node:"<<cmpcount<<std::endl;
        space();
        return 1;
    }

}

//delete from d
//dから単語を取り除く。
int t_delete(const char* delt){
    std::cout<<"Delete :"<<delt<<std::endl;
    int deltlen=strlen(delt);
    if(t_count==0){
        std::cout<<delt<<" isn't exist."<<std::endl;
        return 0;
    }
    int cmpcount=0;
    t_node *tdetmp=(t_node*)malloc(sizeof(t_node));
    tdetmp=thead[numchar(delt[0])];
    int i=0;
    for(i=0;i<deltlen-1;i++){
        cmpcount++;
        if(tdetmp->tnext[numchar(delt[i+1])]==NULL){
            std::cout<<delt<<" isn't exist."<<std::endl;
            //std::cout<<"Deleted. Passed node:"<<cmpcount<<std::endl;
            space();
            return 0;
        }
        tdetmp=tdetmp->tnext[numchar(delt[i+1])];
    }
    tdetmp->tnext[numchar(delt[i+1])]->tkey=NULL;
    tdetmp->tnext[numchar(delt[i+1])]->tmean=NULL;             
    std::cout<<"Deleted. Passed node:"<<cmpcount<<std::endl;
    space();
    return 1;
}


//main
/*
//tの中身をprintする。
void t_print(){
    //線形と同じ考えでは実行できない。その単語が含まれているかを値で算出してtableで管理する？(改善案)
}
*/

void t_first();

int main(){
    t_set(thead);//theadの初期設定
   ///* test
    t_in("one","ichi");
    t_in("two","ni");
    t_in("three","san");
    t_delete("three");
    /*
    
    
    t_incheck("one");
    t_in("one","ichi");
    t_incheck("one");
    //*/
   //t_first();
   return 0;
}

///*
void t_first(){
    std::cout<<"1 t_in"<<std::endl;
    space();
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
    std::cout<<"data set complete."<<std::endl;
    space();

    std::cout<<"2 t_incheck"<<std::endl;
    t_incheck("one");
    t_incheck("five");
    t_incheck("six");
    t_incheck("win");
    space();

    std::cout<<"3 s_delete"<<std::endl;
    t_delete("one");
    t_delete("five");
    t_delete("six");
    t_delete("win");

    std::cout<<"tabungi hikaku completed!"<<std::endl;
}
//*/