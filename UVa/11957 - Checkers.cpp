//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=229&page=show_problem&problem=3108

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<queue>

using namespace std;

int i, j , k , n , m, resp, t, a, b;
char g[110][110];
int num[110][110];

int find(int y, int x){
	int r = 0;
	bool right = false, left = false;
	if( y <= 0 ){
		return 1;
	}
	if( num[y][x] ){
		return num[y][x];
	}
	if( x + 1 < n && g[y-1][x+1] == '.' ){
		r += find( y -1, x + 1);
		right = true;
	} else if( x + 2 < n && y - 2 >= 0 &&  g[y-2][x+2] == '.' )  {
		r +=  find( y - 2, x + 2);
		right = true;
	}
	r = r % 1000007;
	if( x - 1 < n && g[y-1][x - 1] == '.' ){
		r += find( y -1, x - 1);
		left = true;
	} else if( x - 2 < n && y - 2 >= 0 &&  g[y-2][x - 2] == '.' )  {
		r += find( y - 2, x - 2);
		left = true;
	}
	// if( left && right){
		// r += 1;
		// cout << "retorno " << y << " " << x << " -> " << r << endl;
	// }
	num[y][x] = r % 1000007;
	
	return num[y][x];
}


int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	scanf("%d", &t);
	int bla = 1;
	while(t--){
		scanf("%d", &n);
		a = 0; 
		b = 0;
		for( i = 0 ; i  < n; i++){
			scanf("%s", g[i]);		
			for( j = 0 ; j  < n; j++){
				if( g[i][j] == 'W'){
					a = i; b = j;
				}
 			}
		}
		printf("Case %d: %d\n", bla++ , find(a, b));
		memset(num, 0 , sizeof(num));
	}
	
	return 0;
}
