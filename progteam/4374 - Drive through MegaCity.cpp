//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=325&page=show_problem&problem=2375
//#tag shortest path
//#tag coordinate compression
//#sol use coordinate compression on the points, pre-calculate the values of the cost for each edge and then run 
//an shortest path algorithm to find the minimum distance. You could also use a A* to find the answer faster.

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
#include <cassert>

// #include <unordered_map>

#define ll long long
#define ull unsigned long long
#define PII pair<ll,ll>
#define PDD pair<double,double>
#define FT first
#define SD second
#define REP(i,j,k) for(ll (i)=(j);(i)<(k);++(i))
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

const int MAXN = 3000;

ll xx[MAXN], x[MAXN];
ll yy[MAXN], y[MAXN];
ll dist[MAXN][MAXN];
ll adj[MAXN][MAXN][4];
ll tempo[MAXN];
ll xi,yi,xf,yf;
ll n;

ll dy[] = {1,0,-1,0};
ll dx[] = {0,1,0,-1};

struct node{
	ll x,y,t;
	node( ll y = 0, ll x = 0, ll t = 0) : x(x), y(y), t(t) {}
	const bool operator < (const node & in ) const {
		return t > in.t;
	}
};

int main(){
	IOFAST();
	while( cin >> xi >> yi >> xf >> yf){
		cin >> n;		
		REP(i,0,n){
			ll pos = 2 * i;
			cin >> xx[pos] >> yy[pos];
			cin >> xx[pos+1] >> yy[pos+1];
			cin >> tempo[i];
			x[pos] = xx[pos], x[pos+1] = xx[pos+1];
			y[pos] = yy[pos], y[pos+1] = yy[pos+1];
		}
		ll nn = n*2;		
		y[nn] = yi, y[nn+1]= yf;
		x[nn] = xi, x[nn+1]= xf;	
		nn+=2;
		sort( x, x + nn);
		sort( y, y + nn);
		ll szx = unique( x, x + nn ) - x;
		ll szy = unique( y, y + nn ) - y;		
		map<ll,ll> mapx, mapy;
		REP(i,0,szx) mapx[x[i]] = i;
		REP(i,0,szy) mapy[y[i]] = i;
		
		REP(i,0,szy+1) REP(j,0,szx+1){			
			REP(k,0,4) adj[i][j][k] = 10;
		}		
		REP(k,0,n){
			ll pos = 2*k;
			ll bi = mapy[yy[pos]], bj = mapx[xx[pos]];
			ll ei = mapy[yy[pos+1]], ej = mapx[xx[pos+1]];
			ll t = tempo[k];		
			REP(i,bi+1,ei){
				REP(j,bj+1,ej){				
					adj[i][j][2] = adj[i-1][j][0] = t;
					adj[i][j][3] = adj[i][j-1][1] = t;
				}
			}
			REP(i,bi+1,ei) adj[i][ej][3] = adj[i][ej-1][1]=  t;
		
			REP(j,bj+1,ej) adj[ei][j][2] = adj[ei-1][j][0] = t; 				
			
		}
		priority_queue<node> heap;
		FILL(dist,INF);		
		heap.push( node( mapy[yi] , mapx[xi], 0));		
		dist[mapy[yi]][mapx[xi]] = 0;
		ll resp = -1;
		while( !heap.empty()){
			node cur = heap.top(); heap.pop();			
			if( cur.y == mapy[yf] && cur.x == mapx[xf]){
				resp = dist[cur.y][cur.x]; break;
			}			
			if( cur.t > dist[cur.y][cur.x]) continue;
			REP(k,0,4){
				ll ni = cur.y + dy[k];
				ll nj = cur.x + dx[k];				
				if( ni < 0 || nj < 0 || ni >= szy || nj >= szx ) continue;
				ll edge = adj[cur.y][cur.x][k] * (abs( y[ni] - y[cur.y]) + abs( x[nj] - x[cur.x]));								
				if( dist[ni][nj] > dist[cur.y][cur.x] + edge){					
					dist[ni][nj] =  dist[cur.y][cur.x] + edge;
					heap.push(node( ni,nj, dist[ni][nj]));
				}
			}
		}
		cout << resp << endl;
	}
	
	return 0;
}