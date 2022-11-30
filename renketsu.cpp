#include <stdio.h>
#include <iostream>
using namespace std;

//typedef node
struct node{
    char key[26];
    struct node *next_char[26];
};

//convert char to int
int numchar(char ch){
    int henkan;
    henkan=ch;
        return henkan-96;
}

//main
int main(){
    int p=numchar('a');
    std::cout<<p<<std::endl;
    return 0;
}