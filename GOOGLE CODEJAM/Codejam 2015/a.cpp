//
//#tag
//#sol

#include <bits/stdc++.h>


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

const int maxn = 2000;
int in[maxn];

int main(){
	int T; cin >> T;
	REP(cn,1,T+1){
		int n; cin >> n;
		REP(i,0,n){
			cin >> in[i];
		}
		int x = 0, yy = 0, y = 0;
		REP(i,1,n){
			if( in[i] < in[i-1] ){
				x += in[i-1] - in[i];
				yy = max( yy, in[i-1] - in[i] );
			}
		}
		REP(i,0,n-1){
			y += min( in[i], yy );
		}
		printf("Case #%d: %d %d\n", cn, x, y);
	}
	
	return 0;
}