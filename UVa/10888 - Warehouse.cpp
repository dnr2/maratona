//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1829
//#tag graph grafos
//#tag weighted bipartite matching MCBM 
//#tag hungarian algorithm
//#sol We can compute the number of moves required to move each box to each target
// location using BFS. Then this is a minimum weight bipartite matching. We can use the KM
// algorithm with negated edge weight. For KM algorithm the graph must contain a perfect
// matching. This is the case because the number of target locations cannot be less than the
// number of boxes.
// You may notice that a box can block the way of another box. Then why we don't need
// to worry about that in the matching? This is because if a box blocks another's way in the
// optimal solution, this box must be an articulation point in the graph and another box is
// trying to move over it. However, all boxes are the same. Therefore we can always exchange
// the target locations of the two boxes without a problem.

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
#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0)
#define FILL(x,v) memset(x,v,sizeof(x))
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str(); }

const int maxn = 1000;
const int INF = 1E9 ; //be careful to make this big enough but not too big!!!
int N1, N2 ; // Number of nodes in M1 and M2
int ni2[maxn]; // The node in M1 that is matched to a M2; -1 if unmatched
int praw[maxn], aa[maxn], bb[maxn], slack[maxn];
bool va[ maxn ], vb[ maxn];
vector<PII> ad1 [maxn];

bool find ( int x ){
	if ( va[ x ] ) return 0 ;
	va[x] = 1 ;
	for( PII t : ad1 [ x ] ) {
		int y = t.first ;	
		if( !vb[ y ] && aa[x]+bb[y]==t.second ){
			vb[y] = 1;
			if( ni2[y] == -1 || find( ni2[y] )){
				praw[x]= t.second ; ni2[y]=x ; return 1 ;
			}
		}
		slack[y] = min(slack[y] , aa[x]+bb[y]-t.second );
	}
	return 0 ;
}
int off = 100000;
int km( ){
	FILL(bb,0) ; FILL(praw,0); FILL(ni2 ,-1);
	REP( i,0,N1){
		aa[ i ] = -INF;
		for ( PII t : ad1[i] )
			aa[i] = max( aa[i], t.second ) ;
	}
	REP( x , 0 , N1){
		while( 1 ){
			FILL(va,0); FILL(vb,0);
			REP( j , 0 , N2) slack[j] = INF ;
			if( find( x ) ) break ;
			int d = INF ;
			REP(j,0,N2) if( ! vb [j] && slack[j]<d ) d = slack[j] ;
			REP(i,0,N1) if( va[i]) aa[i] -= d ;
			REP(j,0,N2){
				if ( vb [ j ] ) bb [ j ] += d ;
				else slack [ j ] -= d ;
			}
		}
	}
	int ans = 0 ;
	REP(i,0,N1) ans += off - praw[i];
	return ans ;
}

char grid[50][50];
int dist[50][50];
int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};

int main(){
	
	int T; cin >> T;
	while(T--){
		REP(i,0,maxn) ad1[i].clear();
		int n, m ; cin >> n >> m;
		REP(i,0,n) scanf("%s", grid[i]);
		N1 = 0;
		REP(i,0,n){
			REP(j,0,m){
				if( grid[i][j] == 'B'){
					FILL(dist,-1);
					queue<PII> q; q.push(PII(i,j));
					dist[i][j] = 0;
					while(!q.empty()){
						int y = q.front().F, x = q.front().S; q.pop();
						REP(k,0,4){
							int nx = x + dx[k];
							int ny = y + dy[k];
							if( nx < 0 || nx >= m || ny < 0 || ny >= n || 
								dist[ny][nx] != -1 || grid[ny][nx] == '#') continue;
							dist[ny][nx] = dist[y][x] + 1;
							q.push( PII( ny, nx));
						}
					}
					N2 =0;
					REP(y,0,n) REP(x,0,m){
						if( grid[y][x] == 'X'){
							if( dist[y][x] >= 0 ) ad1[N1].pb( PII(N2, off - dist[y][x]));
							N2++;
						}
					}
					N1++;
				}
			}
		}
		cout << km() << endl;
	}
	return 0;
}