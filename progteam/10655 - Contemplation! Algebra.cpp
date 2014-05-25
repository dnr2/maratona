//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1596
//#tag math matematica
//#sol sneak recursive (a^n+b^n) = (a+b)*(a^(n-1)+b^(n-1)) - (a*b)*(a^(n-2)+b^(n-2)) 
// with base case n=0 => (a^n+b^n) = 2 and n = 1 (a^n+b^n) = a+b

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

vector<ll> mult( vector<ll> a, vector<ll>  b){
	vector<ll> ret;
	REP(i,0,4) ret.pb(0);
	REP(i,0,2) REP(j,0,2) REP(k,0,2){
		ret[i*2+j] += a[i*2+k] * b[k*2+j];
	}
	return ret;
}

vector<ll> fast(vector<ll> a, ll b){
	vector<ll> x;
	x.pb(1); x.pb(0); 
	x.pb(0); x.pb(1);
	vector<ll> y = a;
	while(b){
		if( b & 1 ) x = mult( x, y);
		y = mult( y, y);
		b /= 2;
	}
	return x;
}

int main(){
	ll p,q,n;
	while( cin >> p >> q >> n ){
		vector<ll> mat;
		if( n == 0) {
			puts("2");
			continue;
		}
		mat.pb(p); mat.pb(-q); 
		mat.pb(1); mat.pb(0);
		mat = fast( mat, n-1);
		cout << p * mat[0] + 2 * mat[1] << endl;
	}
	return 0;
}