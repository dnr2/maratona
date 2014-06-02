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

#define ll unsigned long long
#define ull unsigned long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define F first
#define S second
#define REP(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define pb push_back
#define PI acos(-1)
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define mp make_pair
#define EPS 1e-9
#define INF 0x3f3f3f3f
#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0)
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}


int sz;
vector<ll> digs;
ll dswap( int a ,int b, ll c){
	digs.clear();
	REP(i,0,sz){
		digs.pb( c % 10);
		c /= 10;
	}
	swap( digs[a], digs[b]);
	ll ten = 1;
	ll ret = 0;
	REP(i,0,sz){
		ret += digs[i] * ten;
		ten *= 10;
	}
	return ret;
}

map<pair<ll,int>, ll> dp;

ll rec(ll a, int b){
	if( b == 0) return a;
	if( dp[mp(a,b)] ) return dp[mp(a,b)];	
	ll best = a;	
	REP(j,1,sz){			
		ll tmp = dswap( j, j-1, a);
		if( tmp <= a) continue;
		tmp = rec( tmp, b-1);
		best = max(best, tmp);
	}
	return dp[mp(a,b)] = best;
}

int main(){
	
	ll a; int b;
	while( cin >> a >> b){
		dp.clear();
		ll tmp = a;
		sz = 0;
		while( tmp > 0){
			sz++; tmp /= 10;
		}
		cout << rec( a, b) << endl;
	}
	return 0;
}