//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2458
//#tag all pair shortest path
//#tag graph
//#sol compute APSP and then the maximum distance from source to i + i to destiny for all nodes i

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
//#include <sstream>
#include <climits>

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
#define IOFAST ios_base::sync_with_stdio(0);cin.tie(0)
// #define umap unordered_map

using namespace std;

const int maxn = 110;
int n, m;
int dist[maxn][maxn];

int main(){
	int T; cin >>T;
	REP(cn,1,T+1){
		REP(i,0,maxn) REP(j,0,maxn) dist[i][j] = INF;
		scanf("%d%d", &n,&m);
		REP(i,0,m){
			int a, b ; scanf("%d%d", &a,&b);
			dist[a][b] = dist[b][a] = 1;
		}
		REP(i,0,n) dist[i][i] = 0;
		int s, d; scanf("%d%d", &s,&d);
		REP(i,0,n) REP(j,0,n) REP(k,0,n){
			dist[j][k] = min( dist[j][k] , dist[j][i] + dist[i][k]);
		}
		int resp = 0;
		REP(i,0,n) {			
			resp = max( resp, dist[s][i] + dist[i][d]);
		}		
		printf("Case %d: %d\n", cn, resp);
	}
	return 0;
}



