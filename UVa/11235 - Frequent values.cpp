//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2176
//#tag RMQ range maximum query
//#tag segtree arvore de segmentos
//#sol ver em http://www.algorithmist.com/index.php/UVa_11235
//basicamente tiramos proveito do fato que a entrada é monotonamente crescente
//criamos um array que armazena o número de vezes ue um determinado número aparece em seu intervalo
//criamos um array auxiliar que diz onde começa e termina a sequência de um determinado número
//fazemos uma query em log (e-s) pois usamos uma segtree para pegar o meior valor de frequência de
//um intervalo

#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <sstream>
#include <climits>

// #include <unordered_map>

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define F first
#define S second
#define fr(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define rep(i,n) for(int (i)=0;(i)<(n);++(i))
#define pb push_back
#define PI acos(-1)
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define mp make_pair
#define cl(x) memset(x,0,sizeof(x))
// #define umap unordered_map

using namespace std;

int arr[1<<21];
pii aux[100010];
int in[100010];

void update(int pos, int val, int node, int i, int j){
	if( i == j) arr[node] = val;
	else {
		int m = (i+j)/2;
		if( pos <= m ) update( pos, val, node*2, i, m);
		else update( pos, val, (node*2)+1, m+1, j);
		arr[node] = max( arr[node*2] , arr[(node*2)+1]);
	}
}

int query(int ini, int fim, int node, int i, int j){
	if( j < ini || fim < i ) return 0;
	if( ini <= i && j <= fim) return arr[node];
	int m = (i+j)/2;
	return max( query( ini, fim, node*2, i,m), query(ini,fim,(node*2)+1, m+1,j));
}

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	int n,q;
	while(scanf("%d", &n) >0 && n){
		cin >> q;
		fr(i,1,n+1) scanf("%d",in+i);
		int ini = 1; int cur = in[1]; int cont = 0; in[n+1] = 100001;
		fr(i,1,n+2) {
			if( in[i] != cur){
				fr(j,ini,i){
					update( j, cont, 1, 1, n); 
					aux[j].F = ini; aux[j].S = (i-1);
				}
				cont =0; cur = in[i]; ini = i;
			}
			cont++;
		}
		fr(i,0,q){
			int s,e;
			scanf("%d%d", &s, &e);
			int a =0, b= 0, c = 0;
			if( in[s] == in[e] ){ cout << ((e-s)+1) << endl; continue; }
			if( aux[s].F < s ) { a = (aux[s].S - s)+1; s = aux[s].S+1;}
			if( aux[e].S > e ) { c = (e - aux[e].F)+1; e = aux[e].F-1;}
			if( s <= e) b = query(s,e,1,1,n); 
			cout << max(a,max(b,c)) << endl;
		}
	}
	return 0;
}