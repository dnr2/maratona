//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1768
//#tag max sum

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<map>

using namespace std;

int i, j , k, n , m,a,b,c,d, t;
int in[100][100];
int aux[100];
bool cd1, cd2;
int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	cin >> t;
	while(t--){
		scanf("%d", &n);
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				scanf("%d", &in[i][j]);
			}
		}
		int resp = 0;
		for( i =0 ;i < n;i++){
			memset(aux, 0, sizeof(aux));
			cd1 = true;
			for( j = i ; cd1 || j!=i; j = (j + 1) %n){
				// printf("%d %d\n", i , j); 
				cd1 = false;
				for( k=0; k < n;k++){
					aux[k] += in[j][k];
					// printf("%d ", aux[k]);
				}
				// puts("");
				for( k =0 ;k< n;k++){
					a = k;
					b = 0;
					do{
						b = max(b + aux[a], aux[a]);
						resp = max(resp, b);
						// printf("->%d\n", resp);
						a = (a+1)%n;
					} while(a!=k);
				}
			}
		}
		printf("%d\n", resp);
	}
	return 0;
}
