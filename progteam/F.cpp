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

const int maxn = 600;
ll in[maxn][maxn];
bool mark[maxn][maxn];

int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};

int main(){
	int T; cin >> T;
	while(T--){
		int R, C;
		cin >> R >> C;
		REP(i,0,R) REP(j,0,C){
			cin >> in[i][j];
		}
		R--; C--;
		ll lo = -1, mid, hi = 1e15L;
		while( lo + 1 < hi ){
			mid = (lo + hi ) / 2;
			// db( mid );
			bool go = false;
			memset( mark, 0, sizeof( mark));
			queue<pii> q;
			mark[0][0] = true;
			q.push( mp( 0, 0));
			while( !q.empty()){
				pii cur = q.front(); q.pop();
				// db( cur.F _ cur.S _ R _ C);
				if( cur.F == R && cur.S == C){
					go = true;
					break;
				}
				REP(i,0,4){
					int ny = cur.F + dy[i];
					int nx = cur.S + dx[i];
					if( ny >= 0 && ny <= R && nx >= 0 && nx <= C && mark[ny][nx] == false ){
						if( abs( in[ny][nx] - in[cur.F][cur.S]) > mid) continue;
						// db( abs( in[ny][nx] - in[cur.F][cur.S]) );
						mark[ny][nx] = true;
						q.push( mp(ny,nx));
					}
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