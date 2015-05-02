#include<bits/stdc++.h>

// #include <unordered_map>

#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
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

const int maxn = 400;

int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};

ll h[2], w[2];

int main(){
	
	ll c; 
	while( cin >> c){	
		REP(i,0,2) cin >> h[i];
		REP(i,0,2) cin >> w[i];		
		ll g = 0, l = 1;
		if( w[0] < w[1]  ) {			
			swap( w[0], w[1]);
			swap( h[0], h[1]);
		}		
		ll resp = 0;
		REP(kk,0,2){
			REP( r,0, w[0] * w[1] + 100 ){
				if( r * w[0] > c ) break;
				ll b = (c - r * w[l]) / w[g];
				ll val = r * h[l] + b * h[g];
				resp = max( val , resp );
			}
			swap( g, l );
		}
		cout << resp << endl;
	}
	return 0;
}
