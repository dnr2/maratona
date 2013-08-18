//http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=330&page=show_problem&problem=2216

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int N;

bool read(){
    scanf("%d", &N);
    return N != 0;    
}

int main(){
    freopen("in.txt", "r" , stdin);
    freopen("out.txt", "w" , stdout);
    int result;
    while (read()){
        result = 0;
        for(int y = N; y > 0; y--){
            result += y * y;
        }
        printf("%d\n", result);
    }
    return 0;
}
