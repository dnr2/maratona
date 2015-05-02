//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2304
//#tag
//#sol

//NOT SOLVED YET!! D=

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

const int maxn = 1000;

struct st{
	int ants, dpos, dm;
	st( int ants = 0, int dpos = 0, int dm = 0) : ants(ants) , dpos(dpos), dm(dm) {}
	bool operator < ( const st & in ) const {		
		if( ants == in.ants && dpos == in.dpos) return dm < in.dm;
		if( ants == in.ants ) return dpos < in.dpos;
		return ants < in.ants;
	}	
};

char str[10];

map<st,int> dist;

//  4
//2 0 3 5
//  1
int dface[6][4] = { {4,3,1,2},{0,3,2,5},{4,0,1,5},{4,5,1,0},{1,3,2,0},{4,2,1,3}};
int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};

const int bsize = 4;

int main(){
	
	int T; cin >> T;
	REP(cn,0,T){
		int ants = 0, dpos = 0, dm = 0, pos =0;
		REP(i,0,bsize){
			scanf("%s", str );
			REP(j,0,bsize){					
				if( str[j] == 'X' ) {
					ants |= (1<< pos);
				}
				if( str[j] == 'D'){
					dpos = pos;
				}
				pos++;
			}
		}
		DB( ants _ dpos _ dm );
		st ini(ants, dpos, dm );
		queue<st> fila;
		fila.push( ini );
		dist.clear();
		dist[ini] = 0;
		int resp = -1;
		while( !fila.empty()){
			st cur = fila.front(); fila.pop();
			if( cur.ants == 0){
				resp = dist[cur]; break;
			}
			int y = cur.dpos / bsize;
			int x = cur.dpos % bsize;			
			REP(i,0,4){
				int ny = y + dy[i];
				int nx = x + dx[i];
				if( ny < 0 || ny >= bsize || nx < 0 || nx >= bsize ) continue;
				int ndpos = (nx + (ny * bsize));				
				int nants = cur.ants;
				int ndm = cur.dm;
				if( cur.dm & (1<<cur.face) ){
					nants |= (1<<cur.dpos); ndm ^= (1<<cur.dpos);
				}
				if( cur.ants & (1<<ndpos) ){
					nants ^= (1<<ndpos ); ndm |= (1<<nface);
				}
				st ncur( nants, ndpos, ndm, nface );
				if( dist.count( ncur ) == 0){
					dist[ncur] = dist[cur] + 1;
					fila.push( ncur );
				}
			}
		}
		if( resp == -1) cout << "impossible" << endl;
		else cout << resp << endl;
	}
	
	return 0;
}