//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4371
//#tag dinamic programming dp
//#sol first consider the case of only one Matryoshka, to solve the problem use DP where DP[i][j]
// represents the minimum cost of assembling the dolls from i to j; so DP[i][j]= min( DP[i][k] + DP[k+1][j] 
// + C ), where k is in {i,...,j-1} and C is the cost of combining the two groups [i .. k] and [k+1 .. j].
// Now considering that there was more than one Matryoshka we can create another DP that finds the possible places
// of the initial Matryoshkas. Be careful with cases like: 1 3 2 1, where the answer is 2 not 3.

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
#include <unordered_map>
#include <unordered_set>

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
#define umap unordered_map
#define uset unordered_set

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str(); }

const int MAXN = 600;
int n;
int in[MAXN];
int dp[MAXN][MAXN];
int mem[MAXN][MAXN];

int rec(int l, int r){
	if( l >= r) return 0;
	if( dp[l][r] != -1) return dp[l][r];
	int ret = INF;
	// -----------------
	int a = INF, b = INF, c = 0;
	umap<int,int> cost; umap<int,bool> used;
	vector<int> v;
	REP(i,l,r+1) v.pb(in[i]);
	sort(v.begin(),v.end());
	int pt = 0;
	REP(i,0,(int)v.size()){
		cost[v[i]] = r-l+1-i; b = min(b,v[i]);
		if( v[i] == b) pt = i+1;
	}
	//------------------
	REP(i,l,r){
		a = min( a, in[i]);
		c = max( c, in[i]);
		used[in[i]] = true;
		if( b == in[i]){
			while( pt < (int) v.size()){
				if( !used[v[pt]]){ b = v[pt++]; break; }
				pt++;
			}
		}
		int aux = rec( l,i) + rec( i+1,r) + cost[max(a,b)];		
		ret = min( ret, aux );		
	}	
	return dp[l][r] = ret;
}

int go(int l, int r){
	if( l > r) return 0;
	if( mem[l][r] != -1) return mem[l][r];
	uset<int> used;
	int ret = INF;
	int m = 0;
	REP(i,l,r+1){
		if( used.count(in[i]) == 1) break;
		used.insert(in[i]);
		m = max( m , in[i]);		
		if( m == (int) used.size()){
			int a = rec(l,i), b = go( i+1,r);			
			if( b < INF ) ret = min( ret, a + b);
		}
	}
	return mem[l][r] = ret;
}

int main(){
	while(cin >> n){
		REP(i,0,n) scanf("%d", in+i);
		FILL(dp,-1); FILL(mem,-1);
		int resp = go( 0, n -1);
		if( resp >= INF) cout << "impossible" << endl;
		else cout << resp << endl;
	}
	return 0;
}