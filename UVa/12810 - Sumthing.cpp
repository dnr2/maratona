//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=861&page=show_problem&problem=4675
//#tag math 
//#sol notice that the formula is equivalent to: ((1 + 2* A1) * ( 1 + 2 * A2) * ... * (1 + 2*An))/2 -1

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

const int MAXN = 100;
ll mod = 1000000009;

ll fastexp( ll a, ll b){
	ll r = 1;
	for( ; b > 0; b >>= 1, a = (a*a)%mod ) if(b&1) r = (r*a)%mod;
	return r;
}

int main(){
	int cn; cin >> cn;
	while(cn--){
		ll inv = fastexp( 2, mod -2 );
		int n; cin >> n;
		ll resp = 1, a;
		REP(i,0,n){
			scanf("%lld", &a);
			resp = (resp * ((((a*2)%mod) + 1) % mod) ) % mod;
		}
		resp = (((resp - 1) % mod) + mod) % mod;
		resp = resp * inv % mod;
		printf("%lld\n", resp);
	}
	
	return 0;
}