//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=890
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
// #include <unordered_set>

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
// #define umap unordered_set

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}


const int MAXN = 110;
const int INF = 10000000;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
bool grid[MAXN][MAXN][4];
int vis[MAXN][MAXN];

struct st{
	int x, y,c;
	st( int x=0,int y = 0, int c=0): x(x), y(y), c(c) {}
	const bool operator < ( const st & in ) const {
		if( x == in.x && y == in.y) return c < in.c;
		if( x == in.x) return y < in.y;
		return x < in.x;
	}
};

int main(){
	int n,m;
	while(scanf("%d%d", &m, &n) > 0){
		REP(i,0,MAXN) REP(j,0,MAXN){
			vis[i][j] = 0;
			REP(k,0,4) grid[i][j][k] = false;
		}
		int r; cin >> r;
		REP(i,0,r){
			int a,b,c,d;
			scanf("%d%d%d%d", &a,&b,&c,&d);
			REP(j,0,4){
				if( a + dx[j] == c && b + dy[j] == d){
					grid[b][a][j] = true;
				}
			}
		}
		int s; cin >> s;
		set<st> moni;
		REP(i,0,s){
			int a,b,c;
			scanf("%d%d%d", &a,&b,&c);
			moni.insert( st( b,c,a ));
		}

		queue<st> q;
		q.push(st( 0,0, 0));
		vis[0][0] = 1;
		int resp = 0;
		while( !q.empty()){
			int x= q.front().x, y = q.front().y, c = q.front().c; q.pop();
			if( y == n-1 && x == m-1) {
				resp = c; break;
			}
			REP(i,0,4){
				int nx = x + dx[i]; 
				int ny = y + dy[i];
				if( nx < 0 || nx >= m || ny < 0 || ny >= n || vis[ny][nx] || grid[y][x][i] ) continue;
				if( moni.count( st( nx, ny, c+1) ) > 0 ) {
					q.push( st( x, y , c+1));
				} else {
					vis[ny][nx] = 1;
					q.push(st( nx, ny, c+1));
				}
			}
		}
		cout << resp << endl;
	}
	return 0;
}