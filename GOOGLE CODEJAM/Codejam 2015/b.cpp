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

ll in[maxn];

int main(){

	int T;cin >> T;
	REP(cn,1,T+1){
		ll b, n; cin >> b >> n;
		REP(i,0,b){
			cin >> in[i];			
		}		
		ll lo = -1, hi = 1e14 + 100000, mid;
		while( lo + 1 < hi ){
			mid = (lo+hi)/2;		
			ll sum = 0;
			REP(i,0,b){				
				sum += (mid/in[i]) + 1;
			}
			
			if( sum >= n ){
				hi = mid;
			} else {
				lo = mid;
			}
		}
		ll sum  = 0;
		mid = lo;
		REP(i,0,b){
			sum += (mid /in[i]) + 1;
		}		
		int resp = 1;		
		while( sum <= n){
			mid++;			
			REP(i,0,b){
				if( mid%in[i] == 0){
					sum++;
					if( sum == n){
						resp = i+1; goto presp;
					}
				}
			}
		}
		presp:		
		printf("Case #%d: %d\n", (int) cn , resp);
	}
	return 0;
}