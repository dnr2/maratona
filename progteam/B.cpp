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

int main(){
	
	ll c1, c2, x, y ;
	while( cin >> c1 >> c2 >> x >> y){
		ll mid, hi = 1e14, lo = 0;
		while( lo + 1 < hi){
			mid = (lo+hi)/2;
			ll a = mid - (mid/x) - (mid/y) + (mid/(x*y)); 
			ll b = (mid - (mid/x)) - a;
			ll c = (mid - (mid/y)) - a;
			if( c1 + c2 <= a + b + c && c1 <= a + b && c2 <= a + c  ){
				hi = mid;
			} else {
				lo = mid;
			}
		}
		cout << hi << endl;		
	}
	
	return 0;
}