//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2682
//#tag Graph grafos
//#tag dijkstra 
//#tag bfs breadth first search busca em largura
//#tag Two Components 
//#sol primeiro adicionar os nós 1 e n no conjunto de hotéis. Depois devemos rodar o dijkstra para 
//cada hotel. Por fim devemos fazer uma bfs entre os hotéis considerando que um hotéis com distância
// menor ou igual a 600 são vizinhos.

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
// #define mp make_pair
#define cl(x) memset(x,0,sizeof(x))
#define MAXN 10010

// #define umap unordered_map

using namespace std;

int n, m, h;
int hot[MAXN], hp = 0;
vector<pii> g[MAXN];
vector<int> hg[MAXN], hots;
int mark[MAXN], mp = 0;

struct st{
	int F, S;
	st(int F =0, int S=0) : F(F), S(S) {}
	bool operator < ( const st & in ) const {
		return S > in.S;
	}
};

int main(){

	int a,b,c;
	
	while(scanf("%d", &n)>0 && n){
		fr(i,0,n+1) g[i].clear(), hg[i].clear();
		hp++; hots.clear();
		cin >> h;
		hots.pb(1); hots.pb(n);
		fr(i,0,h){
			scanf("%d", &a);
			hot[a] = hp;
			hots.pb(a);
		}
		hot[1] = hot[n] = hp;
		cin >> m;
		fr(i,0,m){
			scanf("%d%d%d", &a,&b,&c);
			// db( a _ b _ c);
			g[a].pb( pii(b,c));
			g[b].pb( pii(a,c));
		}
		
		fr(t,0,hots.size()){
			int i = hots[t];
			mp++;
			priority_queue<st> heap;
			heap.push(st(i,0));
			st aux;
			while(!heap.empty()){
				aux = heap.top(); heap.pop();
				// db( aux.F _ aux.S );
				if( aux.S > 600 || mark[aux.F] == mp) continue;
				if( aux.F != i && hot[aux.F] == hp) hg[i].pb(aux.F);// db( i _ aux.F);
				mark[aux.F] = mp;
				fr(j,0,g[aux.F].size()){
					// cout << aux.F << " -> " << g[aux.F][j].F << endl;
					if( aux.S + g[aux.F][j].S <= 600 && g[aux.F][j].F != mp) 
						heap.push( st( g[aux.F][j].F, aux.S + g[aux.F][j].S ) );
				}
			}
		}
		
		queue<pii> fila;
		fila.push(pii(1,0)); pii aux;
		mp++; int resp = 0;
		while(!fila.empty()){			
			aux = fila.front(); fila.pop();
			if( mark[aux.F] == mp) continue;
			// db( aux.F _ aux.S);
			if( aux.F == n ){ resp = aux.S; break; }			
			mark[aux.F] = mp;
			fr(i,0,hg[aux.F].size()){
				fila.push( pii( hg[aux.F][i], aux.S+1));
			}
		}
		printf("%d\n", resp -1 );		
	}
	return 0;
}