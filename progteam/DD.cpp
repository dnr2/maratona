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
#define EPS 1e-9
#define INF 0x3f3f3f3f
#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0)
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

const int maxn = 1100;
int y[maxn];
int x[maxn][2];
int n; 
vector<int> adj[maxn];
bool mark[maxn];

void dfs( int cur){
	REP(i,0,(int)adj[cur].size()){
		if( !mark[adj[cur][i]] ){
			mark[adj[cur][i]] = true;
			dfs( adj[cur][i] );
		}
	}
}

int main(){
	int T; cin >> T;
	while(T--){
		cin >> n;
		REP(i,0,n){
			int a,b,c;
			scanf("%d%d%d", &a,&b,&c);
			y[i] = c;
			x[i][0] = a;
			x[i][1] = b;
		}
		y[n] = 0; x[n][0] = 0; x[n][1] = maxn * maxn;
		n++;
		db( n);
		int lo = -1, mid, hi = maxn * maxn;
		while( lo + 1 < hi ){
			mid = (lo+hi)/2;
			db( mid);
			REP(i,0,n) adj[i].clear();
			REP(i,0,n) REP(j,i+1,n){
				if( x[i][1] < x[j][0] || x[i][0] > x[j][1] || abs( y[i] - y[j] ) > mid) continue;
				adj[i].pb(j);
				adj[j].pb(i);
			}
			memset(mark, 0, sizeof(mark));
			mark[0] = true;
			dfs(0);
			bool go = true;
			REP(i,0,n){
				if( mark[i] == false){
					
					go = false;
					break;
				}
			}
			if( go ){
				hi = mid;
			} else {
				lo = mid;
			}
		}
		cout << hi << endl;
	}
	return 0;
}