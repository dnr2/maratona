//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3520
//#tag binary search busca binaria
//#sol fazer busca binária sobre o tempo mínimo entre os pousos
//para testar se é possível com um determinado tempo mínimo (gap) basta gerar todas as permutações dos aviões e tentar
//ir de uma para o outro com um intervalo mínimo de gap
//atenção na hora de comparar doubles pois na entrada pode acontecer de: ai == bi !!

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
#define pdd pair<double,double>
#define pb push_back
#define mp make_pair
#define PI acos(-1)
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define ll long long
#define PI acos(-1)
#define EPS 1e-7
using namespace std;

pdd in[10]; int n;

bool rec( double gap, double pos, int mask){
	// db(gap _ pos _ mask );
	if( mask + 1 ==  (1<<n) ) return true;
	fr(i,0,n){			
		if( ( (mask >> i) & 1) == 0 ) {
			double lol = pos + gap; 
			if( lol < in[i].F ) lol = in[i].F;
			if( lol < (in[i].S + EPS)  && rec( gap, lol, mask | (1<<i) )) return true; //atenção
		}		
	}
	return false;
}

bool test(double gap) {
	bool resp = false;
	fr(i,0,n){  resp = rec( gap, in[i].F, (1<<i)) || resp; }
	// db( resp );
	return resp;
}

int main(){
	
	int caso =1;
	while(scanf("%d",&n ) > 0 && n){
		fr(i,0,n){ scanf("%lf %lf", &in[i].F,&in[i].S);}
		sort( in,in+n);		
		double ini = 0.0, fim = 100000.0, mid;
		fr(i,0,100){
			mid = (ini + fim) /2;
			// db( mid);
			if( test( mid ) ) ini = mid; 
			else fim = mid;
		}
		mid *= 60; mid = floor( mid + 0.5); //+EPS?
		int resp = (int) mid;
		if(resp%60 < 10) printf("Case %d: %d:0%d\n", caso++, resp/60, resp%60);
		else printf("Case %d: %d:%d\n", caso++, resp/60, resp%60);
	}
	
	return 0;
}