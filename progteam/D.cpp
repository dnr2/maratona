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

const int MAXN = 200010;
const ll mod = 1000000007;
ll dp[MAXN], sum[MAXN];

int main(){
	IOFAST();
	ll t, k; cin >> t >> k;
	dp[0] = 1, sum[0] = 0;
	REP(i,1,MAXN){
		dp[i] = (dp[i-1] + i / k ) % mod;
		sum[i] = (dp[i] + sum[i-1]) % mod;
	}
	REP(i,0,t){
		ll a, b; cin >> a >> b;
		ll resp = (sum[b] - sum[a-1]);
		while( resp < 0) resp += mod;
		cout << resp % mod << endl;
	}
	
	return 0;
}