//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1007
//#tag: longest common subsequence
//#tag: Problem solving paradigm 
//#tag: PD - Dinamic Programing


#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<iostream>
#include<vector>

using namespace std;

int  i, j, k, m, n, a, b, c, d;
int pd[110][110];
int in[2][110];

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	c= 1;
	while( scanf("%d%d", &n,&m) > 0 && n != 0){
		for(i=1;i<=n;i++){
			scanf("%d", &in[0][i] );
		}
		for(i=1;i<=m;i++){
			scanf("%d", &in[1][i] );
		}
		memset(pd,0,sizeof(pd));		
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if(in[0][i]==in[1][j])
					pd[i][j] = pd[i-1][j-1] + 1;
				else 
					pd[i][j] = max(pd[i-1][j], pd[i][j-1]);									
			}
		}
		printf("Twin Towers #%d\nNumber of Tiles : %d\n\n", c++, pd[n][m]);
			
	}
	return 0;
}
