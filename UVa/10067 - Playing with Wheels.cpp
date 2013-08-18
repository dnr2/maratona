//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1008
//#tag bfs breadth first search
//#sol cada estado pode ser representado por um inteiro e teremos no máximo 10000 estados, assim 
//podemos achar o menor caminho entre o estado inicial e final usando fazeno umas busca em largura, 
//já que o custo de apertar o botão é unitário

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


int main(){
	// freopen("out.txt", "w", stdout);
	int t,n,m; cin>>t;
	int passo = 1, mark[10001];
	cl(mark);
	while(t--){	
		int start, end, aux, resp = 1000000;
		start = end = aux = 0;
		fr(i,0,4) {
			if( i != 0) start *= 10;
			cin >> aux; start+=aux;
		}
		fr(i,0,4) {
			if( i != 0) end *= 10;
			cin >> aux; end+=aux; 
		}
		int r = 0;
		cin >> r;
		fr(i,0,r){
			int f =0;
			fr(j,0,4) {
				if( i != 0) f *= 10;
				cin >> aux; f+=aux; 
			}
			mark[f] = passo;
		}
		queue<pii> fila; 
		fila.push( mp(start,0));
		while(!fila.empty()){
			pii cur = fila.front(); fila.pop();
			// cout << "-> " << cur.F << endl;
			if( cur.F == end) {
				resp = cur.S; break;
			}
			if( mark[cur.F] == passo) continue;
			mark[cur.F] = passo;
			int ori = cur.F;
			for(int pot = 1; pot <= 1000;pot*=10){
				fila.push( mp(((ori + (((ori%10) == 9)? -9 : 1) ) * pot + (cur.F % pot) ), cur.S+1));
				fila.push( mp(((ori - (((ori%10) == 0)? -9 : 1)) * pot + (cur.F % pot) ), cur.S+1));
				ori /= 10;
			}
		}
		if(resp == 1000000) puts("-1");
		else cout << resp << endl;
		passo++;
	}
	return 0;
}