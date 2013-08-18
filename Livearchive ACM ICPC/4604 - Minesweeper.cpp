//http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2605
//#tag adhoc

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>

using namespace std;

char in[111][111];
int out[111][111];

int main(){
	
	int n,m;
	while(scanf("%d%d", &n,&m) > 0 && (n || m)){
		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));
		for(int i=0;i<n;i++){
			scanf("%s", in[i]);
		}
		for(int i =0; i<n;i++){
			for( int j=0;j<m;j++){
				if( in[i][j] == '.'){
					for( int y = (-1) + i; y <= (1 + i); y++){
						for( int x = (-1) + j; x <= (1 + j) ;x++){
							if( y >=0 && y < n && x >=0 && x < m 
								&& in[y][x] == '*' && ( y != i || x != j)){
								out[i][j]++;
							}
						}
					}
				}
			}
		}
		for(int i =0; i<n;i++){
			for( int j=0;j<m;j++){
				if( in[i][j] == '*') printf("*");
				else printf("%d", out[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}