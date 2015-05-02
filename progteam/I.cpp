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

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

const int maxn = 200;
int in[maxn];
int dist[(1<<16) + 11];

int main(){
	IOFAST();
	int T; cin >> T;
	REP(cn,1,T+1){
		int n, m; cin >> n >> m;
		REP(i,0,m){
			int mask = 0;
			REP(j,0,n){
				int a; cin >> a;
				mask <<= 1; mask += a;
			}
			in[i] = mask;
		}
		FILL(dist,INF);
		queue<int> fila;
		int mask = (1<<n)-1;
		dist[mask] = 0;
		fila.push( mask );
		int resp = -1;
		while( !fila.empty()){
			mask = fila.front(); fila.pop();
			if( mask == 0 ) {
				resp = dist[mask]; break;
			}
			REP(i,0,m){
				int nmask = mask ^ in[i];
				if( dist[nmask] == INF ){
					dist[nmask] = dist[mask] + 1;
					fila.push(nmask);
				}
			}
		}
		cout << "Case " << cn << ": ";
		if( resp == -1) cout << "IMPOSSIBLE" << endl;
		else cout << resp << endl;
		

	}
	
	return 0;
}