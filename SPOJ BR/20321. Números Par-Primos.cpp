//http://br.spoj.com/problems/PARPMG14/
//#tag number theory
//#tag binary search
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

const int maxn = 1000;

ll find(ll val){
	ll lo = 0, hi = 2000010000LL;
	while( lo + 1 < hi ){
		ll mid = (lo+hi) / 2;
		if( mid * mid <= val ){
			lo = mid;
		} else {
			hi = mid;
		}
	}
	return lo;
}

int main(){
	ll a, b;
	while( scanf("%lld %lld" , &a, &b ) > 0){
		if( a == 0 && b == 0) break;
		ll va = find( a );
		ll vb = find( b );		
		printf("%lld\n", (b-vb) - (a-va) + (( a == va * va)?0:1) );
	}
	return 0;
}