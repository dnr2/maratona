//
//#tag
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
#include <set>

// #include <unordered_map>

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define F first
#define S second
#define REP(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define pb push_back
#define PI acos(-1)
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define mp make_pair
#define FILL(x,y) memset(x,y,sizeof(x))
#define EPS 1e-9
#define FOREACH(i,v) for(typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define IOFAST ios_base::sync_with_stdio(0);cin.tie(0);

// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}


#define MAXN 1010
#define MAXM 1010*1010
#define VIZ(u, i) (orig[adj[u][i]] != (u) ? orig[adj[u][i]] : dest[adj[u][i]])

int n, m;
int adj[MAXN][MAXN], nadj[MAXN];
int orig[MAXM], dest[MAXM];
int low[MAXN], part[MAXN], ponte[MAXM], ncomp, comp[MAXM];
int dt;
int vis[MAXN];
stack<int> stck;

int dfsbcc(int u, int p) {
	int ch = 0;
	vis[u] = dt++;
	low[u] = vis[u];
	for (int i = 0; i < nadj[u]; i++) {
		int e = adj[u][i], v = VIZ(u, i);
		if (!vis[v]) {
			stck.push(e);
			dfsbcc(v, u); ch++;
			low[u] = min(low[u], low[v]);
			if (low[v] >= vis[u]) {
				part[u] = 1;
				ncomp++;
				while (stck.top() != e) {
					comp[stck.top()] = ncomp;
					stck.pop();
				}
				comp[stck.top()] = ncomp; stck.pop();
			}
			if (low[v] == vis[v]) ponte[e] = 1;
		} else if (v != p) {
			if (vis[v] < vis[u]) stck.push(e);
			low[u] = min(low[u], vis[v]);
		}
	}
	return ch;
}

void bcc() {
	memset(low, 0, sizeof(low));
	memset(vis, 0, sizeof(vis));
	memset(part, 0, sizeof(part));
	memset(ponte, 0, sizeof(ponte));
	memset(comp, 0, sizeof(comp));
	dt = 1;
	ncomp = 0;
	for (int i = 0; i < n; i++)
		if (!vis[i])
			part[i] = dfsbcc(i, -1) >= 2;
}

int marc[MAXN];

void rec(int i, int num){
	if( marc[i] ) return;
	marc[i] = num;
	for (int j = 0; j < nadj[i]; j++){
		if( !ponte[adj[i][j]] ){
			rec(VIZ(i, j),num);
		}
	}
}

int main(){
	while(scanf("%d%d", &n,&m) > 0){
		memset(nadj, 0, sizeof(nadj));
		memset(marc, 0, sizeof(marc));
		for (int i = 0; i < m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			u--; v--;
			orig[i] = u; dest[i] = v;
			adj[u][nadj[u]++] = adj[v][nadj[v]++] = i;
		}
		
		bcc();
		REP(i,0,n) rec(i,i+1);
		map<int,int> mapa;
		
		for (int i = 0; i < n; i++){
			for (int j = 0; j < nadj[i]; j++){
				if( ponte[adj[i][j]] && i < VIZ(i, j)){
					mapa[marc[i]]++; mapa[marc[VIZ(i, j)]]++;
				}
			}
		}
		int resp =0;
		for(map<int,int>::iterator i = mapa.begin(); i != mapa.end(); i++){
			if( i->S == 1) resp++; 
		}
		printf("%d\n", (resp/2) + (resp & 1));
	}
	return 0;
}