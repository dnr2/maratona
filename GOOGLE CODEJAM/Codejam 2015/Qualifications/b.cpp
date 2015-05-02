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

const int maxn = 1000;


map<  pair< vector<int>, int> , int > dp;

int maxval;

int rec( vector<int> & v, int num){
	if( num == maxval ) return maxval;
	int n = v.size(); int cont = 0;
	REP(i,0,n) cont += v[i];
	if( cont == 0){ return num; }

	sort( v.begin(), v.end());

	int ret = INF;
	
	// cerr << num << " -> " ;
	// REP(i,0,n) cerr << v[i] << " ";
	// cerr << endl;
	
	vector<int> vb = v;
	
	//special minute
	int bi = ((int)v.size())-1;
	if( v[bi] > 1 ){
		REP(rem,1,v[bi]-1){			
			v[bi] -= rem;
			v.PB( rem );
			ret = min ( ret, rec( v, num + 1 ));
			v = vb;
		}
	}
	
	//regular minute	
	REP(i,0,n){
		v[i]--; v[i] = max(0,v[i]);
	}
	ret = min ( ret, rec( v, num + 1 ) );
	v = vb;
	
	
	return ret;
}

int main(){
	int T; cin >> T;
	REP(cn,1,T+1){
		dp.clear();		
		vector<int> v;
		int q; cin >> q;
		maxval = 0;
		REP(i,0,q){
			int a; cin >> a;
			maxval = max(a,maxval);
			v.PB(a);
		}
		DB("");
		int resp = rec(v,0);
		printf("Case #%d: %d\n", cn, resp );
	}
	return 0;
}