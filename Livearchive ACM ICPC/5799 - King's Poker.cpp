//http:livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=531&page=show_problem&problem=3810

#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int i, j, k, a, b, c, n, m;
bool crivo[1100000];
int hand[3];
int main(){

	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	
	while(scanf( "%d %d %d", &a, &b , &c) > 0 && a != 0 || b != 0 || c != 0){
		if( a == b && a == c && b == c){
			if( a == 13) printf("*\n");
			else {
				printf("%d %d %d\n", a + 1, b + 1, c + 1 );
			}
		} else if( a == b || b == c || a == c){
			if( a == c){
				n = b;
				b = c;
				c = n;
			} else if( c == b){
				n = a;
				a = c;
				c = n;
			}
			if( c == 13 ){
				hand[0] = a + 1; 
				hand[1] = b + 1; 
				hand[2] = 1; 
				sort(&hand[0], &hand[3]);
				printf("%d %d %d\n", hand[0],hand[1],hand[2] );				
			} else if( c== 12 && a == 13){ 
				hand[0] = 1; 
				hand[1] = 1; 
				hand[2] = 1; 
				sort(&hand[0], &hand[3]);
				printf("%d %d %d\n", hand[0],hand[1],hand[2] );			
	
			} else {
				hand[0] = a; 
				hand[1] = b; 
				hand[2] = (c + 1 == a)? c + 2 : c + 1; 
				sort(&hand[0], &hand[3]);
				printf("%d %d %d\n", hand[0],hand[1],hand[2] );		
			}

		} else {
			printf("1 1 2\n");
		}
		
	}
	
	return 0;
}

