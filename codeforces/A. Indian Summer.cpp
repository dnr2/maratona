//http://www.codeforces.com/problemset/problem/44/A

#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstdlib>

#define FOR(i,n) for((i)=0;(i)<(n);(i)++)
#define FORN(i,n) for((i)=(n)-1;(i)>=0;(i)--)

using namespace std;

int n, m, a, b, c, d, i, j, h, len, x, y, vb, vs;
//int ar[2000005];
char sp[105][15], cor[105][15], aux1[15], aux2[15];
bool bit;

int main(){
    //freopen("in.txt", "r", stdin );
    //freopen("out.txt", "w", stdout );
	
	m = 0;
	
    scanf("%d", &n);
    for(i = 0; i < n; i++){
		bit = true;
        scanf("%s %s", &aux1, &aux2);
		for(j = i-1; j >= 0; j--){
			if( strcmp(aux1, sp[j]) == 0 && strcmp(aux2, cor[j]) == 0){
				bit = false;
				break;
			}			
		}
		if(bit){
			m++;
			FOR(j,11){sp[i][j] = aux1[j];}
			FOR(j,11){cor[i][j] = aux2[j];}
		} else{
			n--;
			i--;
		}
    }
		
    printf("%d", m);        
    
   
    return 0;

}
