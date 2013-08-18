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

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define F first
#define S second
#define fr(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define rep(i,n) for(int (i)=0;(i)<(n);++(i))
#define pb push_back
#define mp make_pair
#define PI acos(-1)
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define cl(x) memset(x,0,sizeof(x))

using namespace std;

#define MAXN 100010

vector<int> g[MAXN];
int comp[MAXN], vis[MAXN], stck[MAXN], t, high[MAXN], num, ncomp;
vector<int> touched[MAXN];
void dfscc(int u) {
	int i, v;
	high[u] = vis[u] = num--;
	stck[t++] = u;
	for (i = 0; i < g[u].size(); i++) {
		v = g[u][i];
		if (!vis[v]) {
			dfscc(v);
			high[u] = max(high[u], high[v]);
		} else if (vis[v] > vis[u] && !comp[v])
			high[u] = max(high[u], vis[v]);
	}
	if (high[u] == vis[u]) {

		ncomp++;
		do {
		v = stck[--t];
		comp[v] = ncomp;
		} while (v != u);
	}
}
void scc(int n) {
	int i;
	ncomp = t = 0; num = n;
	memset(vis, 0, sizeof(vis));
	memset(comp, 0, sizeof(comp));
	for (i = 0; i < n; i++)
		if (!vis[i])
			dfscc(i);
}


int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	int test;cin>>test;
	int n,m;
	while(test--){
		int i, u, v;
		scanf("%d%d", &n, &m);
		for(i=0;i<=n;i++){	
			g[i].clear(); touched[i].clear();
		}
		cl(touched);
		for (i = 0; i < m; i++) {
			scanf("%d%d", &u, &v);
			g[u].pb(v); 
			touched[v].pb(u);
		}
		scc(n);
		// printf("Numero componentes: %d\n", ncomp);
		int chosen = -1, bug;
		for (i = 0; i < n; i++){
			bug = 0;
			fr(j,0,touched[i].size()) if( comp[touched[i][j]] != comp[i] ){
				bug = 1; comp[i] = -1; break;
			}
			if( comp[i] == -1) bug = 1;
			// printf("componente[%d] = %d : bug = %d\n", i, comp[i], bug);
			if( bug == 0 && chosen == -1) chosen = comp[i];
			else if( chosen >= 0 && bug ==0 && comp[i] != chosen ) {
				chosen = -1; break;
			}
		}
			
		if( chosen == -1) puts("Confused");
		else {
			fr(i,0,n) if( comp[i] == chosen) printf("%d\n", i);
		}
		puts("");
	}
	
	
	return 0;
}
