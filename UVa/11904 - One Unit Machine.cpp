//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=229&page=show_problem&problem=3055
//#tag math 
//#tag combinatorics 
//#tag fast exponentiation 
//#tag inverse mod
//#sol This is a combinatorics problem also known as Stars and bars, you have to count the number of possible positions
//for each job, considering that the units are the stars and the space between the last units are the bars. 
//The first job will always have the same "permutation" since all the units don't differ among each other. 
//The i-th job will have k_i units as starts and SUM( k1 .. k_i-1 ) + 1 bars (or bins) to be placed in. 


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

const int MAXN = 2000;
const int MAXM = 2000000;
ll mod = 1000000007;
ll in[MAXN];
ll fat[MAXM];

ll poww( ll a , ll b){
	ll e = a, r = 1;
	for( int i = 0; (1ll << i) <= b; i++) { 
		if( b & (1ll<<i)) r = r * e %mod; 
		e = e*e%mod ; 
	}
	return r;
}

ll coef( ll n, ll k){
	return (fat[n] * poww( (fat[k] * fat[n-k]) % mod, mod -2 ) ) % mod;
}

int main(){
	IOFAST();
	fat[0] = 1;
	REP(i,1,MAXM) fat[i] = ( ((ll) i) * fat[i-1]) % mod;
	int K; cin >> K;
	REP(cn,1,K+1){
		cout << "Case " << cn << ": ";
		int n; cin >> n;
		REP(i,0,n) cin >> in[i];
		ll resp = 1, sum = in[0], x, y;
		REP(i,1,n){
			x = in[i] -1;
			y = sum + 1;
			if( x > 0){
				ll c = coef( x + y -1, x);				
				resp = resp * c % mod;			
			}
			sum += in[i];
		}
		cout << resp << endl;
	}
	return 0;
}