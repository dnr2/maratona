//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1226

#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int i, j, k, n, m, t, mais, bla;
char str[1000];
int area[150][150];


int rec(int p, int y, int x){
	int a = 0, mai = 0;
	if( area[y][x] >= p && p != -1) return 0;	
	if( y > 0){
		a = 1 + rec( area[y][x],  y-1, x);
		if( a > mai){
			mai = a;
		}
	}
	if( y < n - 1 ){
		a = 1 + rec( area[y][x], y+1, x);
		if( a > mai){
			mai = a;
		}
	}	
	if( x > 0){
		a = 1 + rec( area[y][x], y, x-1);
		if( a > mai){
			mai = a;
		}
	}
	if( x < m - 1 ){
		a = 1 + rec( area[y][x],  y, x+ 1);
		if( a > mai){
			mai = a;
		}
	}
	
	return mai;	
}

int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int result;
	
	scanf("%d", &bla);
	while(bla--) {
		scanf("%s", &str);
		scanf("%d %d", &n, &m);
		for( i = 0 ; i < n; i++){
			for( j = 0 ; j< m; j++){
				scanf("%d", &area[i][j]);			
			}
		}
		mais = 0;
		for( i = 0 ; i < n; i++){
			for( j = 0 ; j < m; j++){
				t = rec( -1,  i , j );
				if( t > mais){
					mais = t;
				}
				
			}
		}
		printf("%s: %d\n", str, mais);
		
		
	}
	
	return 0;
}

