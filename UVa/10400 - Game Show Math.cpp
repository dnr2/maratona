//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1341
//#tag DP dynamic programming
// 

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
#include <cassert> 

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

const int maxn = 110;
const int off = 32000;
int dp[maxn][(2*off)+10];
int forw[maxn][(2*off)+10];
int tar, p;
ll in[maxn];


int rec( int pos, ll num ){
	if( abs( num ) > off ) return 0;
	if( pos == p ){
		//TODO back here?
		return num == tar;		
	}
	if( dp[pos][num] != -1) return dp[pos][num];
	int ret= 0;
	if( rec( pos + 1, num + in[pos] ) ){ 
		ret = 1; forw[pos][num] = 0; //must include exp?
	}
	if( !ret && rec( pos + 1, num - in[pos] ) ){ 
		ret = 1; forw[pos][num] = 1;
	}
	if( !ret && rec( pos + 1, num * in[pos] ) ){ 
		ret = 1; forw[pos][num] = 2;
	}
	if( !ret && num % in[pos] == 0 && rec( pos + 1, num / in[pos] ) ){
		ret = 1; forw[pos][num] = 3;
	}
	return (dp[pos][num] = ret);
}

int main(){
	IOFAST();
	int T; cin >> T;
	REP(cn,0,T){
		cin >> p;
		REP(i,0,p){
			cin >> in[i];
		}
		cin >> tar;
		FILL(dp,-1); //TODO
		int ret = rec( 1, in[0] );
		if( !ret ) cout << "NO EXPRESSION" << endl;
		else {
			cout << in[0];
			ll nval = in[0];
			REP(pos,1,p){
				if( forw[pos][nval] == 0) {
					cout << "+";
					cout << in[pos];				
					nval = nval + in[pos];			
					
				} else if( forw[pos][nval] == 1) {
					cout << "-";
					cout << in[pos];
					nval = nval - in[pos];
				} else if( forw[pos][nval] == 2) {
					cout << "*";
					cout << in[pos];
					nval = nval * in[pos];
				} else if( forw[pos][nval] == 3) {
					cout << "/";
					cout << in[pos];
					nval = nval / in[pos];
				}				
			}
			assert( nval == tar);
			cout << "=" << tar << endl;			
		}
		
	}
	
	return 0;
}