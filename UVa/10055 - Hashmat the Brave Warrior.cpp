//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=94&page=show_problem&problem=996

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

long long X, Y;
int s;

bool read(){
    s = scanf("%lld %lld", &X, &Y);
    return s > 0;    
}

int main(){
    //freopen("in.txt", "r" , stdin);
    //freopen("out.txt", "w" , stdout);
    while (read()){
        printf("%lld\n", abs(Y - X));
    }
    return 0;
}
