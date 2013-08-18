//http://poj.org/problem?id=2190

//ATENÇÃO COM OS CONDICIONAIS!!!!!
//ERRAR DETALHE SÓ FODE O CARA

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

int n, m, a, b, c, d, i, j, k, h, len, z, resp;
char str[20];
long long num;

int main(){
    //freopen("in.txt", "r", stdin );
    //freopen("out.txt", "w", stdout );

    scanf("%s", &str);
    len = strlen(str);
        
    int resp = 0;
    num = 0;    
    z = len;
    for( a = 0; a < len; a++){
        if(str[a] == '?') {
            b = z;
            a++;
            z--; 
        }
        num += (str[a] == 'X') ? 10 : (str[a]-48)* z;
        z--;
        
    }
    
    bool achou = false;            
    for( i = 0; i <= 10; i++){
        if((num + i*b)%11 == 0){
            if( i < 10) {
				printf("%d", i); 
				achou = true; 
				break;
			}
            else if( b == 1 && i == 10) { 
				printf("X"); 
				achou = true; 
				break;
			}            
        }
    }
    if( !achou) printf("-1");
    
    
    return 0;

}
