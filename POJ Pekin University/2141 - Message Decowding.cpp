//http://poj.org/problem?id=2141

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

int n, m, a, b, c, d, i, j, k, h, len, z;
char str[100], crip[30], resp[100];
long long num;

int main(){
    //freopen("in.txt", "r", stdin );
    //freopen("out.txt", "w", stdout );

    scanf("%s\n", &crip);
    gets(str);
    for( i = 0; str[i]; i++){
        if( str[i] > 96 && str[i] <=122){
            resp[i] = crip[str[i] - 97];
        } else if( str[i] > 64 && str[i] <=90){ 
            resp[i] = crip[str[i] - 65] - 32;
        } else {
            resp[i] = ' ';
        }
    }
    printf("%s", resp);
    
    return 0;

}
