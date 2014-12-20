//
//#tag
//#sol

#include<bits/stdc++.h>

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

const int MAXN = 1000;
int in[MAXN];
int main(){
	int n; cin >> n;
	REP(i,0,n) cin >> in[i];
	int resp = INF;
	REP(k,1,n-1){
		int dif = 0;
		REP(i,1,n){
			if( i-1 == k) dif = max( dif, in[i] - in[i-2]);
			else dif = max( dif, in[i] - in[i-1]);
		}
		resp = min( resp, dif);
	}
	cout << resp << endl;
	return 0;
}
