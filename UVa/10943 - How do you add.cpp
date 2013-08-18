//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1884
//#tag: PD



#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<iostream>
#include<vector>
#include<set>
#include<queue>

using namespace std;

int i,j,k,n,m,a,b,c,d;

int pd[110][110];

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	for(i=0;i<=100;i++){
		pd[0][i] = 1;
		pd[i][1] = 1;
	}
	for(i=1;i<=100;i++){
		for(j=2;j<=100;j++){
			pd[i][j] = (pd[i-1][j] + pd[i][j-1]) % 1000000;
			// cout << pd[i][j] << " " ;
		}
		// cout <<endl;
	}
	
	
	while(scanf("%d %d", &n, &m) > 0 && (n!=0 || m!=0)){	
		printf("%d\n", pd[n][m]);
	}


	return 0;
}

