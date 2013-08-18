//http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1617
//#tag: math, matematica
//#tag: geometry, geometria
//#tag: angulo entre vetores 3D


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

int  i, j, k, m, n, a, b, c, d;
double tel[60][4], stars[550][3];
bool mark[550];

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	while(scanf("%d", &n) > 0 && n){		
		memset(mark,false, sizeof(mark));
		
		for(i=0;i<n;i++) scanf("%lf %lf %lf" , &stars[i][0], &stars[i][1], &stars[i][2]); 
		scanf("%d", &m);
		for(i=0;i<m;i++) scanf("%lf %lf %lf %lf" , &tel[i][0], &tel[i][1], &tel[i][2], &tel[i][3]);
		double aux;
		int resp = 0;
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				if(mark[j]) continue;
				aux = ( tel[i][0]*stars[j][0] + tel[i][1]*stars[j][1] + tel[i][2]*stars[j][2] ) / 
					( pow(  pow(tel[i][0],2) + pow(tel[i][1],2) + pow(tel[i][2],2) , 0.5) 
						* pow(  pow(stars[j][0],2) + pow(stars[j][1],2) + pow(stars[j][2],2), 0.5));
				if( acos(aux) < tel[i][3]) {
					mark[j] = true;
					resp++;
				}
			}
		}
		printf("%d\n", resp);
	}
	return 0;
}
