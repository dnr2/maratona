//http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2937
//#tag: ad hoc

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include <utility>
#include <string>

using namespace std;

int i,j,k,a,b,c,d,t,n,m, caso =1;
int arr[100][100];
char in[100][100];

int main(){
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	while(scanf("%d %d", &n, &m) > 0 && n != 0){
		memset(arr, 0, sizeof(arr));		
		memset(in, 0, sizeof(in));
		for(i=1;i<=n;i++){
			scanf("%s", in[i]);			
		}
		t = 1;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if( in[i][j-1] =='.'){
					arr[i][j] = t++;
				}
			}
		}
		
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if( arr[i][j] != 0){
					printf("%d %d %d %d %d\n", arr[i][j], arr[i-1][j], arr[i][j+1], arr[i+1][j], arr[i][j-1]);
				}
			}
		}
		
		puts("");
	}
	return 0;
}
