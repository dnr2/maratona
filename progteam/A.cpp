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

ll gdc( ll a, ll b) { 
	while( b ){
		a = a % b;
		swap( a, b);
	}
	return a;
}

int main(){
	ll l, r;
	while( cin >> l >> r){
		bool ok = false;
		for(ll a = l; a <= r; a++) for( ll b = a+1; b <= r; b++) for( ll c = b+1; c <= r; c++){
			if( gdc( a , b) == 1 && gdc( b,c) == 1 && gdc( a , c) != 1){
				cout << a << " " << b << " " << c << endl; ok = true;
				goto end;
			}
		}
		end:
		if( !ok )  cout << -1 << endl;
	}
	
	return 0;
}