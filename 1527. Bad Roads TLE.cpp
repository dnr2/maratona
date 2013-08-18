//http://acm.timus.ru/print.aspx?space=1&num=1527
//#tag djkstra 2D
//#sol

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
#include <time.h>

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

#define MAXN 110

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

struct rod{
	int num,v,c,t,h;
	rod( int num=0, int  v=0, int c=0,int t=0,int h =0) : num(num), v(v), c(c), t(t), h(h) {}
};

struct tri{
	int v,c,num;
	tri( int v =0, int c=0, int num=0) : v(v), c(c), num(num) {}
};

struct state{
	int v,c,t;
	tri ant;
	state( tri ant, int  v=0, int c=0, int t=0) : ant(ant), v(v), c(c), t(t) {}
	bool operator < ( const state & in) const {
		if( c == in.c) return t < in.t;
		else return c < in.c;
	}
};

int n,m,ns,nt;
int money, maxtime;
vector<rod> g[MAXN];
int dist[MAXN][MAXN];
tri ant[MAXN][MAXN];

bool bfs( int init, int end){
	bool mark[MAXN];
	fr(i,0,MAXN) mark[i] = false;
	queue<int> fila;
	fila.push(init);
	while(!fila.empty()){
		int v = fila.front(); fila.pop();
		if( mark[v] ) continue;
		mark[v] = true;
		fr(i,0,g[v].size()){
			fila.push(g[v][i].v );
		}
	}
	return mark[end];
}

int main(){ int maxc = 0;

	int u,v,c,t,h;
	int ini = 0,fim = 0, mid;
	cin >> n >> m>> ns >> nt;
	cin >> money >> maxtime;
	fr(i,0,m){
		scanf("%d%d%d%d%d", &u,&v,&c,&t,&h);
		fim = max(fim, h);
		g[u].pb( rod( i + 1,v,c,t,h));
	}
	fim++;
	// if( !bfs(ns,nt)){ cout << -1 << endl; return 0; }
	while(true){
		mid = (ini + fim) /2;
		priority_queue<state> heap;
		heap.push( state( tri( -1, -1, -1), ns, 0, 0));
		state aux ( tri( -1, -1, -1) ); bool ok = false;
		memset( dist, 0x3f,sizeof(dist));
		while(!heap.empty()){
			aux = heap.top(); heap.pop();
			maxc++;
			// if( aux.c > money || aux.t > maxtime || aux.c > 105) continue;
			if( aux.v == nt ) { ok =true; break; }
			// if( dist[aux.v][aux.c] <= aux.t ) continue;// pd
			dist[aux.v][aux.c] = aux.t; 
			ant[aux.v][aux.c] = aux.ant;
			fr(i,0,g[aux.v].size()){
				state in = state( tri(aux.v, aux.c, g[aux.v][i].num ), 
					g[aux.v][i].v, g[aux.v][i].c + aux.c ,  g[aux.v][i].t + aux.t );
				if ( g[aux.v][i].h <= mid && dist[in.v][in.c] > in.t && in.c <= money && in.t <= maxtime && in.c <= n){
					heap.push( in );
				}
			}
		}
		if( ok && ini == fim){
			cout << mid << endl;
			stack<int> p; tri cur = aux.ant;		
			while( cur.v != -1 ) {
				p.push( cur.num);
				cur = ant[cur.v][cur.c];
			}
			cout << p.size() << endl; bool prim = true;
			while(!p.empty()) {
				if( !prim) printf(" ");
				else prim = false;
				printf("%d", p.top()); p.pop();
			}
			break;
		} else if( ok && ini < fim  )  {
			fim = mid;
		} else if( !ok && ini < fim){
			ini = mid + 1;
		} else {
			cout << -1 << endl; break;
		}
	}
	cout << "\n" << "maxc = " << maxc << endl;
	return 0;
}