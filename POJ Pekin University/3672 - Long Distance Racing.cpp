//http://poj.org/problem?id=3672

#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstdlib>


#define FOR(i,n) for((i) = 0; (i) < (n); (i) ++)
#define FORC(i,j, n) for((i) = (j); (i) < (n); (i) ++)
#define PINT(i) printf("%d\n", (i));
#define P2INT(i,j) printf("%d %d\n", (i), (j));
#define SINT(i) scanf("%d", &(i));
#define S2INT(i, j) scanf("%d %d", &(i), &(j));
#define SSTR(s) scanf("%s", &(s));


using namespace std;

int n, m, a, b, c, d, i, j, k, h, len, z, t, u, f;   
long long num;
char str[10];
int path[100009];

int main(){
    //freopen("in.txt", "r", stdin );
    //freopen("out.txt", "w", stdout );

    scanf("%d %d %d %d %d", &m, &t, &u, &f, &d);
    for(i = 0; i  <  t; i++){
        scanf("%s", str);
        if( str[0] == 'u'){
            path[i] = 1;
        } else if( str[0] == 'd' ){
            path[i] = -1;
        } else {
            path[i] = 0;
        }
    }
    num = 0;
    len = 0;
    for( i = 0; i  <  t; i++){
        if( path[i] != 0 ){
            if(num + u + d <= m){
                num += u + d;
                len++;
            } else {
                break;
            }            
        } else {
            if( num + 2 * f <= m){
                num += 2 * f;
                len++;
            } else {
                break;
            }
        }
    }
    printf("%d", len);
    
    return 0;

}
