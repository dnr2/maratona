//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2139
//#tag BFS
//#tag state space search
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
#define VI vector<int>
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str(); }

const int maxn = 1000;
const int nbits = 3;

map< int ,int> dist;
int gend[10];
bool prim[20];
int buff[10];

int main(){
	
	IOFAST();
	int aa, cn = 1; ll fim = 0; 
	ll mask = (1<<nbits)-1;
	REP(i,0,8){ fim <<= nbits; fim += i;  }
	prim[2] = prim[3] = prim[5] = prim[7] = prim[11] = prim[13] = prim[17] = true;	
	while( true ){
		ll cur = 0;
		REP(i,0,8) {
			cin >> aa;
			if( i == 0 && aa == 0) return 0;
			cur <<= nbits; cur += abs(aa) - 1;
			gend[abs(aa)-1] = (aa>0)?1:-1;
		}
		queue< ll > fila;
		fila.push( cur );
		dist.clear();
		dist[cur] = 0; int resp = -1;
		while( !fila.empty() ){
			cur = fila.front(); fila.pop();
			if( cur == fim ){
				resp = dist[cur]; break;
			}
			REP(i,0,8){
				REP(j,0,8){
					if( i == j ) continue;
					ll a = (cur >> (nbits * (8-i-1))) & mask;
					ll b = (cur >> (nbits * (8-j-1))) & mask;
					if( gend[a] * gend[b] < 0 && prim[abs(a) + abs(b) + 2]) {
						REP(kk,0,2){
							ll ncur = 0; int nj = j + kk - ((i < j)?1:0), pp = 0;
							REP(pos,0,8){			
								ncur <<= nbits;
								if( pp == i) pp++;
								if( pos != nj ){
									ncur += (cur >> (nbits * (8-pp-1))) & mask;
									pp++;
								} else {
									ncur += a;
								}								
							}
							if( dist.count( ncur ) > 0 ) continue;
							dist[ncur] = dist[cur] + 1;
							fila.push( ncur );
						}
					}
				}
			}
		}
		printf("Case %d: %d\n", cn++, resp);
	}
	
	

	return 0;
}