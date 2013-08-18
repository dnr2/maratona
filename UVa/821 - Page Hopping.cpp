//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=762
//#tag: Graph
//#tag: Floyd's Algorithm
//#tag: All pairs Sortest Path

#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<iostream>
#include<vector>
#include<queue>
#include<map>

#define INF 100000

using namespace std;

int i,j,k,n,m,num,a,b,c,d, caso =1;
int pd[110][110];
map<int,int> mapa;


int main(){
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	while(scanf("%d%d", &a,&b)>0 && a!=0 && b!=0){
		mapa.clear();
		num =1;
		for(i=1;i<=100;i++){
			for(j=1;j<=100;j++){
				if(i!=j)pd[i][j] = 100000;
				else pd[i][j] = 0;
			}
		}
		mapa[a] = num++;
		mapa[b] = num++;		
		pd[ mapa[a] ][ mapa[b]] = 1;

		while(scanf("%d%d", &a,&b) > 0 && a!=0 && b!=0){	
			if(mapa[a] == 0) mapa[a] = num++;
			if(mapa[b] == 0) mapa[b] = num++;
			pd[ mapa[a] ][ mapa[b] ] = 1;
		}
		num--;
		for(k=1;k<=num;k++){
			for(i=1;i<=num;i++){
				for(j=1;j<=num;j++){		
					pd[i][j] = min(pd[i][j] , pd[i][k] + pd[k][j]);
				}
			}
		}
		/*for(i=1;i<=num;i++){
			for(j=1;j<=num;j++){		
				printf("\t %d", pd[i][j]);
			}
			cout << endl;
		}*/
		int sum =0, comb = ((num * num) - num) ;
		for(i=1;i<=num;i++){
			for(j=1;j<=num;j++){
				sum += pd[i][j];
			}
		}
		printf("Case %d: average length between pages = %.3lf clicks\n", caso++, ((double)sum)/((double)comb));
	}
	return 0;
}
