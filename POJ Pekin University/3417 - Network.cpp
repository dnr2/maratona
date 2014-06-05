//http://poj.org/problem?id=3417
//#tag graph grafos arvores tree
//#tag LCA least common ancestor
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
#define EPS 1e-9
#define INF 0x3f3f3f3f
#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0)
#define FILL(x,v) memset(x,v,sizeof(x))
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str(); }

const int MAXN = 100010;
int L[2], adj[MAXN], ext[MAXN];
int p[MAXN], vis[MAXN], ans[MAXN], rank[MAXN], n,m;
ll dp[MAXN];

struct list{
	int id,next;
} lists[2][2*MAXN];

void insertList(int &a, int b,int ln){
	lists[ln][L[ln]].id = b;
	lists[ln][L[ln]].next = a;
	a = L[ln]++;
}

int find(int u){
	if( p[u] == u) return u;
	return p[u] = find(p[u]);
}

void uni(int u, int v){
	int pu = find(u), pv = find(v);
	if( rank[pu] < rank[pv]) p[pu] = pv;
	else if( rank[pv] < rank[pu]) p[pv] = pu;
	else {
		p[pv] = pu;
		rank[pu]++;
	}
}

ll LCM(int u, int an ){
	p[u] = ans[u] = u;
	int t  = adj[u];
	while( t!= -1){
		int v = lists[0][t].id;
		if( v != an ){
			ll val = LCM(v, u);
			dp[u] += val;
			uni( u, v);
			ans[find(u)] = u;		
		}
		t = lists[0][t].next;
	}
	vis[u] = 1; ll ret = 0;
	t  = ext[u];
	while(t !=-1){
		ret++;
		int v = lists[1][t].id;
		if( vis[v] ) dp[ans[find(v)]] -= 2;
		t = lists[1][t].next;
	}	
	dp[u] += ret;
	return dp[u];
}

int main(){
	while( cin >> n >> m){		
		REP(i,0,n){ rank[i] = vis[i] = dp[i] = ans[i] = 0; }		
		L[0] = L[1] = 0; FILL(adj,-1); FILL(ext,-1);
		int a,b;
		REP(i,1,n){	
			scanf("%d%d", &a, &b);  a--; b--;
			insertList(adj[a],b,0);
			insertList(adj[b],a,0);
		}
		REP(i,0,m){
			scanf("%d%d", &a, &b);  a--; b--;
			if( a == b) continue;
			insertList(ext[a],b,1);
			insertList(ext[b],a,1);
		}
		LCM(0, -1);		
		ll resp = 0;
		REP(i,1,n){
			if( dp[i] == 0) resp += m;
			if( dp[i] == 1) resp += 1;
		}
		cout << resp << endl;		
	}
	return 0;
}