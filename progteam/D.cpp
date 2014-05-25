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

struct edge{
	int a,b,c;
	edge( int _a= 0, int _b = 0, int _c =0) : a(_a) ,  b(_b), c(_c) {}
	const bool operator < ( const edge & in) const {
		return c < in.c;
	}
};

const int maxn = 1100;
int y[maxn];
int x[maxn][2];
int n;
int pai[maxn];
edge arr[maxn * maxn];

int rec( int a){
	if( a == pai[a]) return a;
	return pai[a] = rec( pai[a]);
}

int main(){
	int T; cin >> T;
	while(T--){
		cin >> n;
		REP(i,0,n){
			int a,b,c;
			scanf("%d%d%d", &a,&b,&c);
			y[i] = c;
			x[i][0] = a;
			x[i][1] = b;
		}
		y[n] = 0; x[n][0] = 0; x[n][1] = maxn * maxn;
		n++;
		int sz = 0;
		REP(i,0,n) pai[i] = i;
		REP(i,0,n) REP(j,i+1,n){
			if( x[i][1] < x[j][0] || x[i][0] > x[j][1] ) continue;
			edge a( i, j, abs( y[i] - y[j] ) );
			arr[sz++] = a;
		}
		sort( arr, arr+ sz);
		ll resp = 0;
		REP(i,0,sz){
			int a = rec( arr[i].a);
			int b = rec( arr[i].b);
			if( a == b) continue;
			resp += arr[i].c;
			pai[a] = b;
		}
		cout << resp << endl;
	}
	return 0;
}