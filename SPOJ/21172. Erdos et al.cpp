//http://www.spoj.com/problems/TAP2014E/
//#tag BFS breadth first search / busca em largura
//#sol Run a BFS to find the distance from the groups with Erdos (the writer 1) and the other groups. 
//remember to mark not only the groups but the writers during the search.

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
#define PII pair<int,int>
#define PDD pair<double,double>
#define FT first
#define SD second
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

const int MAXN = 110000;

vector<int> adj[2][MAXN];
int vis[MAXN];
int dist[MAXN];
int num[MAXN];
int A, N;
int main(){
	
	while( cin >> A >> N){
		FILL(vis,0);
		FILL(num,INF);
		FILL(dist,-1);
		REP(i,0,A+1) adj[0][i].clear();
		REP(i,0,N+1) adj[1][i].clear();
		
		REP(i,0,A){
			int sz;
			scanf("%d", &sz);
			REP(j,0,sz){
				int a; scanf("%d", &a);
				adj[0][i].PB( a );
				adj[1][a].PB( i );
			}
		}
		
		queue<int> q;
		REP(i,0,(int) adj[1][1].size()){
			q.push( adj[1][1][i] );
			dist[adj[1][1][i]] = 1;
		}
		vis[1] = 1;
		while( !q.empty()){
			int group = q.front(); q.pop();
			REP(i,0,(int) adj[0][group].size()){
				int author =  adj[0][group][i];
				if( vis[author] ) continue;				
				REP(j,0,(int) adj[1][author].size()){
					int newg = adj[1][author][j];
					if( dist[newg] >= 0) continue;
					dist[newg] = dist[group] + 1;					
					q.push( newg );
				}
				vis[author] = 1;
			}
		}

		int D = 1, M = 0; ll S = 0;
		
		
		REP(i,0,A){
			REP(j,0,(int) adj[0][i].size()){
				if( dist[i] >= 0)  num[adj[0][i][j]] = min( num[adj[0][i][j]] , dist[i] );
			}
			M = max( M, dist[i] );
		}
		
		REP(i,2,N+1){			

			if( num[i] < INF){
				S += num[i], D++;
			}
		}
		cout << D << " " << M << " " << S << endl;
	}
	return 0;
}