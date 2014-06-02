//http://poj.org/problem?id=1860
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
#define EPS 1e-9
#define IOFAST ios_base::sync_with_stdio(0);cin.tie(0);

// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

const int MAXN = 110;
const double INF = 1e20;

struct st{
	int n;
	double r,c;
	st( int n =0, double r =0, double c =0) :n(n), r(r), c(c) {}
};

int N,M,S;
double V;
vector<st> adj[MAXN];
double cost[MAXN];
bool in[MAXN];
int cont[MAXN];

int main(){
	while(scanf("%d", &N) > 0){
		REP(i,0,N){ adj[i].clear(); cost[i] = 0; in[i] = false; cont[i] = 0;}
		scanf("%d%d%lf", &M,&S,&V);
		REP(i,0,M) {
			int a,b; 
			double x,y,z,w;
			scanf("%d%d%lf%lf%lf%lf", &a,&b,&x,&y,&z,&w);
			adj[a].pb(st(b,x,y));
			adj[b].pb(st(a,z,w));
		}
		queue< int > q; q.push(S);
		cost[S] = V, in[0] = true; 
		bool resp = false;
		while(!q.empty() && !resp){
			int cur = q.front(); q.pop();
			in[cur] = false;
			REP(i,0,((int)adj[cur].size())){
				int next = adj[cur][i].n;
				double nc = (adj[cur][i].r) * ( cost[cur] - adj[cur][i].c); 
				if( nc > cost[next]){
					cost[next] = nc;
					if( !in[next] && cont[next] < N){
						in[next] = true;
						q.push(next);
						cont[next]++;
					} else if( cont[next] >= N){
						resp = true;
					}
				}
			}
		}
		puts(resp?"YES":"NO");
	}
	return 0;
}