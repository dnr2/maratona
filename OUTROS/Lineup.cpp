//http://maratona.cin.ufpe.br/local/gcpc2010/G.pdf
//#tag min cost max flow 
//#tag pd dinamic programing
//#sol usar o algoritmo de mincost max flow para descobrir a soma máxima possível

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


// -- notebook russo -- 
#define REP(i,n) for(int i=0, _e(n); i<_e; i++)
#define FOR(i,a,b) for(int i(a), _e(b); i<=_e; i++)
#define FORD(i,a,b) for(int i(a), _e(b); i>=_e; i--)
#define FORIT(i, m) for (__typeof((m).begin()) i=(m).begin(); i!=(m).end(); ++i)
#define SET(t,v) memset((t), (v), sizeof(t))
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize( unique( ALL(c) ) - (c).begin() )

#define sz size()
#define pb push_back
#define VI vector<int>
#define VS vector<string>

typedef long long LL;
typedef long double LD;

#define D(x) if(1) cout << __LINE__ <<" "<< #x " = " << (x) << endl;
#define D2(x,y) if(1) cout << __LINE__ <<" "<< #x " = " << (x) \
<<", " << #y " = " << (y) << endl;

// -- -- 
using namespace std;

#define N 50

int n, nE;
int d[N], pre[N];

struct edge {
	int to, cost, cap;
	int back;
};

edge E[N*N];
vector< int > e[N];

int mincost( int s, int t, int lim ) {
	int flow = 0, ret = 0;
	while( flow < lim ) {
		SET( d, -1 ); SET( pre, -1 );
		d[s] = 0;
		// cout <<"source "<< s <<" sink " << t << endl;
		// bellman ford
		int jump = n-1;
		bool done = 0;
		while( !done && --jump >= 0) {
			done = 1;
			REP(i,n) if( d[i] != -1 ) REP(j,e[i].sz) {
				edge& x = E[ e[i][j] ];
				int v = x.to;
				if( x.cap > 0 && ( d[v] == -1 || d[v] > d[i] + x.cost )) {
					d[v] = d[i] + x.cost;
					pre[v] = x.back;
					done = 0;
					// cout<<v<<" "<<d[v]<<endl;
				}
			}
			if( done ) break;
		}
		// cout << d[t] << endl;
		if( d[t] == -1 ) break;
		// cout <<"found one path "<<endl;
		// traverse back
		int x = t, cflow = 1<<30;
		while( x != s ) {
			edge& ed = E[ pre[x] ];
			cflow = min( cflow, E[ ed.back ].cap );
			// cout << ed.to <<" to "<< x << endl; 
			x = ed.to;
		}
		if( !cflow ) break;
		int take = min( lim - flow, cflow );
		ret += d[t] * take;
		flow += take;
		// cout <<"taken flow "<< take <<" with cost "<< d[t] * take <<endl ;
		x = t;
		while( x != s ) {
			edge& back = E[ pre[x] ];
			edge& forw = E[ back.back ];
			back.cap += take;
			forw.cap -= take;
			x = back.to;
		}
	}
	// cout << "total flow " << flow << endl;
	if( flow < lim ) return -1;
	return ret;
}
// remember to add -cost in the opposite direction
void add( int u, int v, int uv, int vu, int fuv, int fvu ) {
	int a = nE, b = nE+1;
	nE += 2;
	E[ a ].to = v, E[ a ].cost = uv, E[ a ].cap = fuv, E[ a ].back = b;
	E[ b ].to = u, E[ b ].cost = vu, E[ b ].cap = fvu, E[ b ].back = a;
	e[ u ].pb( a ), e[ v ].pb( b );
}



int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	int t,z = 11,a,b,c;
	cin >> t;
	while(t--){
		n = 24; nE = 0;
		memset(d,0,sizeof(d));
		memset(pre,0,sizeof(pre));
		memset(E,0,sizeof(E));
		FOR(i,0,N-1) e[i].clear();
		FOR(i,0,(z-1)) FOR(j,0,(z-1)){
			scanf("%d", &a) ;
			if(a==0) continue;
			add(i,(j+11), (100-a), a-100, 1, 0);
			// cout << i << " -> " << (j+11) << " : " << (100-a) << endl;
		}
		FOR(i,0,(z-1)) {
			add(22, i, 0, 0, 1, 0);
			add(i+11, 23, 0, 0, 1, 0);
		}
		cout << (1100 - mincost(22, 23, 11)) << endl;
		
	}
	return 0;
}