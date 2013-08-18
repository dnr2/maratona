//http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=296&page=show_problem&problem=1912

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int N, conjunto = 1;
char unit[3];    
double v;


int main(){
    //freopen("in.txt", "r" , stdin);
    //freopen("out.txt", "w" , stdout);
    
    
    scanf("%d", &N);
    while(conjunto <= N){
                    
            scanf("%lf %s", &v, unit);
            if( !strcmp( unit, "kg") ){ 
                v *= 2.2046L;
                printf("%d %.4lf lb\n", conjunto++,  v);
            } else if ( !strcmp( unit, "lb") ){
                v *= 0.4536L;
                printf("%d %.4lf kg\n", conjunto++,  v);
            } else if ( !strcmp( unit, "l") ){
                v *= 0.2642L;
                printf("%d %.4lf g\n", conjunto++,  v);
            } else {
                v *= 3.7854L;
                printf("%d %.4lf l\n", conjunto++,  v);
            }
    }
    
    return 0;
}
