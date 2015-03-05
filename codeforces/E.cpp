//
//#tag
//#sol

#include<bits/stdc++.h>

// #include <unordered_map>

#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
#define PDD pair<double,double>
#define F first
#define S second
#define REP(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define PB push_back
#define PI acos(-1)
#define DB(x) cerr << #x << " = " << x << endl;
#define _ << ", " <<
#define MP make_pair
#define EPS 1e-9
#define INF 0x3f3f3f3f
#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0)
#define FILL(x,v) memset(x,v,sizeof(x))

// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str(); }

const int MAXN = 300000;

vector<PII> adj[MAXN];
int cost[MAXN];
int pai[MAXN];

int main(){
	IOFAST();
	int n , m; cin >> n >> m;
	REP(i,0,m) {
		int a,b,c;
		cin >> a >> b >> c;
		adj[a].PB( MP( b, c) );
		adj[b].PB( MP( a, c) );
	}
	FILL(cost, INF);
	cost[0] = 0;
	queue<int> q;
	q.push( 0);
	int mindist = 0;
	while(!q.empty()){
		int cur = q.front(); q.pop();
		if( cur == n-1) {
			mindist = cost[cur];
			break;
		}
		REP(i,0,(int) adj[cur].size()){
			int next = adj[cur][i];
			if( dist[next] < INF) continue;
			dist[next] = dist[cur] + 1;
			q.push( next );
		}
	}
	FILL( cost, INF);
	priority_queue<PII> heap;
	heap.push( PII( 0, 0) );
	cost[0] = 
	
	return 0;
}
