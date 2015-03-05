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
#define EPS 1e-15
#define INF 0x3f3f3f3f
#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0)
#define FILL(x,v) memset(x,v,sizeof(x))
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str(); }

const int maxn = 2000000;

struct st{
	ll a, b;
	int i;
	st( ll a= 0, ll b = 0, int i = 0) : a(a), b(b), i(i) {}
	const bool operator < ( const st & arg ) const {
		if( b * arg.a == a * arg.b ) return i < arg.i;
		return b * arg.a < a * arg.b;
	}
};

st in[maxn];
st zeros[maxn];

int main(){
	IOFAST();
	int n; 
	while( cin >> n){
		int p1 = 0, p2 = 0;
		REP(i,0,n){
			ll a, b;
			cin >> a >> b;
			if( a == 0 && b == 0 ){
				zeros[p2++] = st( a, b, i+1);
			} else {
				in[p1++] = st( a, b, i+1);
			}
		}
		sort( in, in + p1);
		int it1= 0, it2 = 0;
		REP(i,0,p1+p2){
			if( i > 0) cout << " " ;
			if( it1 < p1 && it2 < p2 ){
				if( in[it1].i > zeros[it2].i ){
					cout << zeros[it2++].i;
				} else {
					cout << in[it1++].i;
				}
			} else if(it1 < p1){
				cout << in[it1++].i;
			} else if(it2 < p2){
				cout << zeros[it2++].i;
			}
		}
		cout << endl;
	}
	
	return 0;
}