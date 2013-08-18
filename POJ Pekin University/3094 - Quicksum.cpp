//http://poj.org/problem?id=3094

#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <set>


#define FOR(i,n) for((i) = 0; (i) < (n); (i) ++)
#define FORC(i,j, n) for((i) = (j); (i) < (n); (i) ++)
#define PINT(i) printf("%d\n", (i));
#define P2INT(i,j) printf("%d %d\n", (i), (j));
#define SINT(i) scanf("%d", &(i));
#define S2INT(i, j) scanf("%d %d", &(i), &(j));
#define SSTR(s) scanf("%s", &(s));


using namespace std;

int n, m, a, b, c, d, i, j, k, len, z, resp, t;
char str[290];


int main(){
    freopen("in.txt", "r", stdin );
    freopen("out.txt", "w", stdout );
        
    gets(str);
    while(str[0] != '#'){        
        resp = 0;
        a = 1;
        len = strlen(str);
        FOR(i,len){
            if( str[i] >= 'A' && str[i] <= 'Z'){
                resp += a * (str[i] - 'A' + 1);
            }
            a++;
        }
        PINT(resp); 
        gets(str);
    }    
    
    return 0;

}
