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
#define F first
#define S second
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
ll LLINF = (ll) 1e15;

int main(){
	ll  n, a, b;
	while( cin >> n >> a >> b){
		bool swaped = false;
		if( a > b ){ swap( a, b); swaped = true; }
		n *= 6;
		if( a * b >= n){
			cout << a * b << endl << a << " " << b << endl;
		} else {
			ll r = LLINF, ra = a, rb = b;
			for(ll newa = a; newa * newa < n * 2; newa++){
				ll newb = n / newa + (( n % newa > 0 )? 1 : 0);
				if( newa * newb < r && newb >= b ){
					r = newa * newb;
					ra = newa;
					rb = newb;
				}
			}
			if( swaped ) swap( ra, rb);
			cout << r << endl << ra << " " << rb << endl;
		}
	}
	return 0;
}