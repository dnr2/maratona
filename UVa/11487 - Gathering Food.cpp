//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2482
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
#define FOREACH(i,v) for(typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define IOFAST ios_base::sync_with_stdio(0);cin.tie(0);

// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

const int MAXN = 20;
const int INF = 20000000;
char in[MAXN][MAXN];
int dp[MAXN][MAXN];
int ways[MAXN][MAXN];
int N;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int main(){
	int caso = 1;
	while(scanf("%d", &N) > 0 && N ){
		int MOD = 20437;
		REP(i,0,N) scanf("%s", in[i]);
		ll resp = 1;
		int cost = 0;
		int numdist = 0;
		pii ini(0,0);
		REP(i,0,N) REP(j,0,N){
			if( in[i][j] >= 'A' && in[i][j] <= 'Z') numdist++;
			if( in[i][j] == 'A') ini = mp( i,j); 			
		}
		int x, y;
		//db( numdist);
		REP(num,1,numdist){
			REP(i,0,N)REP(j,0,N) dp[i][j] =INF, ways[i][j] = 0;
			ways[ini.F][ini.S] = 1;
			dp[ini.F][ini.S] = 0;
			queue<pii> q;
			q.push( ini);
			in[ini.F][ini.S] = '.';
			while(!q.empty()){
				x = q.front().S, y = q.front().F; 
				if( in[y][x] == 'A' + num) {
					resp *= ways[y][x];
					resp = resp % MOD;
					cost += dp[y][x];
					ini = mp( y,x);
					break;
				}
				q.pop();
				REP(i,0,4){
					int nx = x+dx[i], ny = y+dy[i], nc =dp[y][x] + 1;
					if( nx <0 || nx >= N || ny < 0 || ny >= N || (in[ny][nx] != '.' && in[ny][nx] != 'A' + num) 
						 || nc > dp[ny][nx] ) continue;
					ways[ny][nx] += ways[y][x];
					ways[ny][nx] %= MOD;
					if( nc < dp[ny][nx]) {
						dp[ny][nx] = dp[y][x] + 1;
						q.push( mp( ny, nx));
					}
				}
			}
			if( q.empty()){ resp = 0; break; }
		}
		resp = resp % MOD;
		printf("Case %d: ", caso++);
		if( resp == 0) puts("Impossible");
		else printf("%d %lld\n", cost, resp );
	}	
}

