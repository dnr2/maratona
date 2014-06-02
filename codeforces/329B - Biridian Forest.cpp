//http://codeforces.com/blog/entry/8417
//#tag graph
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

const int maxn = 1010;
char grid[maxn][maxn];
int dist[maxn][maxn];

int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};

int main(){
	int n, m; cin >> n >> m;
	REP(i,0,n){
		scanf("%s", grid[i]);
	}
	pii ini;
	REP(i,0,n) REP(j,0,m){
		if( grid[i][j] == 'E' ){
			ini = pii( i, j);
			i = n; j = m;
		}
	}
	queue<pii> q;
	REP(i,0,n+1) REP(j,0,m+1) dist[i][j] = INF;
	dist[ini.F][ini.S] = 0;
	q.push(ini);
	int mindist = INF;
	while(!q.empty()){
		pii cur = q.front(); q.pop();
		if( grid[cur.F][cur.S] == 'S') mindist = dist[cur.F][cur.S];
		REP(i,0,4){
			int ny = cur.F + dy[i];
			int nx = cur.S + dx[i];
			if( ny < 0 || ny >= n || nx <0 || nx >= m || grid[ny][nx] == 'T' || dist[ny][nx] != INF ) continue;
			dist[ny][nx] = dist[cur.F][cur.S]+1;
			q.push( pii( ny, nx));
		}
	}
	int resp = 0;	
	REP(i,0,n) REP(j,0,m){
		if( dist[i][j] <= mindist && grid[i][j] >= '0' && grid[i][j] <= '9'){
			resp += grid[i][j] - '0';
		}
	} 
	cout << resp << endl;
	return 0;
}