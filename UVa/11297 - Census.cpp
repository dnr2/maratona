//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2272

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

const int maxn = 510;

int NSEG;

struct segtree{

	int maxin[maxn*10];
	int off[maxn*10];

	void relax(int i ){
		maxin[i] += off[i];
		off[2*i+1] += off[i];
		off[2*i+2] += off[i];
		off[i] = 0;
	}

	void add( int a, int b, int v, int i = 0, int s = 0, int e = NSEG){
		if( b <= s || e <= a ){
			return;
		}
		if( a <= s && e <= b){
			off[i] += v;
			return;
		}
		relax(i);
		add(a,b,v,2*i+1,s,(s+e)/2);
		add(a,b,v,2*i+2,(s+e)/2,e);
	
		maxin[i] = max( 
			maxin[2*i+1] + off[2*i+1], 
			maxin[2*i+2] + off[2*i+2]);
	}

	int query( int a, int b, int i =0 , int s = 0, int e =NSEG){
		if( b <= s || e <= a ){
			return -1e9;
		}
		if( a <= s && e <= b ){
			return off[i] + maxin[i];
		}
		relax(i);
		return max(
			query(a,b,2*i+1,s,(s+e)/2),
			query(a,b,2*i+2,(s+e)/2,e) );
	}
};

struct segtree2{

	int maxin[maxn*10];
	int off[maxn*10];

	void relax(int i ){
		maxin[i] += off[i];
		off[2*i+1] += off[i];
		off[2*i+2] += off[i];
		off[i] = 0;
	}

	void add( int a, int b, int v, int i = 0, int s = 0, int e = NSEG){
		if( b <= s || e <= a ){
			return;
		}
		if( a <= s && e <= b){
			off[i] += v;
			return;
		}
		relax(i);
		add(a,b,v,2*i+1,s,(s+e)/2);
		add(a,b,v,2*i+2,(s+e)/2,e);
	
		maxin[i] = min( 
			maxin[2*i+1] + off[2*i+1], 
			maxin[2*i+2] + off[2*i+2]);
	}

	int query( int a, int b, int i =0 , int s = 0, int e =NSEG){
		if( b <= s || e <= a ){
			return 1e9;
		}
		if( a <= s && e <= b ){
			return off[i] + maxin[i];
		}
		relax(i);
		return min(
			query(a,b,2*i+1,s,(s+e)/2),
			query(a,b,2*i+2,(s+e)/2,e) );
	}
};

segtree seg[maxn];
segtree2 seg2[maxn];

int in[maxn][maxn];
char cmd[10];

int main(){
	
	int n, m; cin >> n >> m;
	NSEG = max(n,m);
	
	REP(i,0,n){
		FILL(seg[i].maxin,0);
		FILL(seg[i].off,0);
		FILL(seg2[i].maxin,0);
		FILL(seg2[i].off,0);
		REP(j,0,m){
			scanf("%d", &in[i][j]);
			seg[i].add( j, j+1, in[i][j] );
			seg2[i].add( j, j+1, in[i][j] );
		}
	}
	
	int q; cin >> q;
	
	REP(qn,0,q){
		scanf("%s", cmd);		
		
		if( cmd[0] == 'q' ) {
			int x,y,xx,yy;
			scanf("%d%d%d%d", &y, &x, &yy,&xx);
			x--; xx--; y--; yy--;
			int a = 0;
			int b = INF;
			
			REP(i,y,yy+1){
				a = max( a, seg[i].query( x, xx+1 ));
				b = min( b, seg2[i].query( x, xx+1 ));
			}
			printf("%d %d\n", a, b);
		} else {
			int x,y,v;
			scanf("%d%d%d", &y, &x, &v);
			x--, y--;
			int a = seg[y].query(x,x+1);
			int b = seg2[y].query(x,x+1);						
			seg[y].add(x,x+1,v-a);
			seg2[y].add(x,x+1,v-b);			
		}
	}
	
	
	return 0;
}
