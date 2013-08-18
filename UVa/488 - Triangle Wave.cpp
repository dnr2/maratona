//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=429

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <cstdio>
#include <string>

using namespace std;

int i, j, k, p , e;
int n , m, resp;
int a, b , c, d, sum, least;

int main(){

	//freopen( "in.txt", "r", stdin);
	//freopen( "out.txt", "w", stdout);
	scanf("%d", &a);
	while( a-- ){
		scanf("%d", &n);
		scanf("%d", &m);		
		for( i = 1; i <= m; i++){
			for( j = 1; j < n; j++){
				for( k = 0; k < j; k++){
					printf("%d", j);
				}
				printf("\n");
			}
			for( j = n; j > 0; j--){
				for( k = 0; k < j; k++){
					printf("%d", j);
				}
				printf("\n");
			}
			if( ! (a == 0 && i == m)) printf("\n");
		}		
		
			
	}	
	
	return 0;
}

