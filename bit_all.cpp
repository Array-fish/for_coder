#include<iostream>
#include<vector>
using namespace std;
int main(){
    int num=5;
    for(int bit=0;bit<(1<<num);++bit){// ここで全てのビットのパターンを作りだす
        for(int i=0;i<num;++i){
            if(bit & (1<<i)){// i+1番目のビットが1かどうか

            }
        }
    }
    return 0;
}