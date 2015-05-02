#include<bits/stdc++.h>

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

const int maxn = 400000;

int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};

ll in[maxn][2];

int main(){
	IOFAST();
	ll n,m; cin >> n >> m;
	
	REP(i,0,m){
		cin >> in[i][0] >> in[i][1];
	}
	ll resp = 0;
	REP(i,1,m){
		ll d = in[i][0] - in[i-1][0];
		ll dh = abs(in[i][1] - in[i-1][1]);
		if( dh > d ){
			cout << "IMPOSSIBLE" << endl; 
			return 0;
		}
		ll h = max( in[i][1], in[i-1][1]) + ((d-dh)/2);
		resp = max( resp, h );
	}
	resp = max( resp, (in[0][0]-1)  + in[0][1] );
	resp = max( resp, ( n - in[m-1][0])  + in[m-1][1] );
	cout << resp << endl;
	return 0;
}
