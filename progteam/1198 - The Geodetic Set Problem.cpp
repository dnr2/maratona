//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3639
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
#define FILL(x,v) memset(x,v,sizeof(x))
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str(); }


const int MAXN = 100;
int dp[MAXN][MAXN];
ll I[MAXN][MAXN];
string str;
int n,a,m; 

void print(ll x){
	REP(i,0,n){
		if( x & 1 << i ) cerr << 1;
		else cerr << 0;
	}
	cerr << endl;
}

int main(){	
	cin >> n;
	getline( cin , str);
	REP(i,0,n) { REP(j,0,n){ dp[i][j] = INF; I[i][j] = 0;} dp[i][i] = 0; }
	REP(i,0,n){
		getline( cin , str);
		stringstream ss(str);
		while( ss >> a) dp[i][a-1] = 1;		
	}
	REP(k,0,n) REP(i,0,n) REP(j,0,n) dp[i][j] = min ( dp[i][j] , dp[i][k] + dp[k][j] );
	REP(i,0,n) REP(j,i+1,n) REP(k,0,n) if( dp[i][k] + dp[k][j] == dp[i][j] ) I[i][j] |= 1L << k;
	cin >> m; getline( cin , str);
	vector<int> v; ll vset = 1; vset <<= n; vset--;
	REP(i,0,m){
		getline( cin, str);
		stringstream ss(str);
		v.clear();
		while( ss >> a) v.pb(a-1);		
		ll nodes = 0;
		sort(v.begin(),v.end());
		REP(i,0,((int)v.size())) REP(j,i+1,((int)v.size())) {
			nodes |= I[v[i]][v[j]];
		}
		if( nodes == vset) puts("yes");
		else puts("no");
	}
	return 0;
}