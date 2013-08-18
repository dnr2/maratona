//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2859
//#tag geomtry geometria
//#sol calcular o nível de cada cercado comparando quantos cercados estão acima dele 
//devemos utilizar um algoritmo eficiente O(log x) para verificar se um cercado está dentro do outro
//para isso usa-se uma busca binária, cosiderando que os polígonos são convexos

#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<cstring>

#define fr(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define cl(i) memset(i,0,sizeof(i))
#define F first
#define S second
#define pii pair<int,int>
// #define pdd pair<double,double>
#define pb push_back
#define mp make_pair
#define PI acos(-1)
#define db(x) if(1) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define ll long long


using namespace std;

struct pdd {
	double F, S;
	pdd( double F = 0, double S = 0) : F(F) , S(S) {}
	pdd operator - ( const pdd in ) const { return pdd ( F - in.F, S - in.S ) ; }
	double operator % ( const pdd in ) const { return F * in.S - S * in.F; };
	
};

vector<pdd> in[501];
int pai[501];
double p[501];

bool insidetri(pdd P, pdd A, pdd B ,pdd C){
	pdd a = C - A, b = B - A, c = P - A ;
	double under = a%b, u = c % b, v = a % c;
	return u >= 0 && v >= 0 && u+v <= under || u <= 0 && v <= 0 && u+v >= under ;
}

bool dentro( pdd a, int b ){
	int ini= 1, fim = in[b].size() -1;
	pdd pivo = in[b][0];
	while( (fim - ini) > 1){
		int mid = (ini + fim)/2;
		pdd x = in[b][ini] - pivo, y = a - pivo, z = in[b][mid] - pivo;
		if( (x % y) * (y % z) >= 0 ) { fim = mid; }
		else { ini = mid;  }
	}
	return insidetri(a, pivo, in[b][fim], in[b][ini] ); 
}

int main(){
	
	int n,m; int caso =1;

	while(scanf("%d",&n ) && n> 0){

		fr(i,0,n){
			scanf("%d", &m);
			double a, b;
			fr(j,0,m){
				scanf("%lf %lf", &a, &b);
				in[i].pb( pdd( a, b));
			}
			fr(j,0,m) p[i] += hypot( in[i][j].F -  in[i][(j+1)%m].F , in[i][j].S -  in[i][(j+1)%m].S );
		}
		fr(i,0,n){
			fr(j,i+1,n){
				if( dentro( in[i][0], j) ) pai[i]++;
				else if( dentro( in[j][0], i) ) pai[j]++;
			}
		}
		int resp = 0;
		double s = 0, w =0;
		fr(i,0,n){
			if( pai[i] == 0) resp++;
			if( pai[i] & 1)  w += p[i] * 50;
			else s += p[i] * 100;
		}
		printf("Case %d:\n" , caso++);
		printf("Total Number of Communities %d\n", resp);
		puts("Total Cost:");
		printf("Steel Fence: %.8lf Million Yuan\n", s / 1000000 );
		printf("Wooden Fence: %.8lf Million Yuan\n\n", w / 1000000 );
		
		fr(i,0,n) { in[i].clear(); p[i]= 0; } 
		cl( pai ); 
	}

	return 0;
}