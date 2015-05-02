//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1996
//#tag dynamic programming DP
//#tag programacao dinamica
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

const int maxn = 16;

int dp[maxn][maxn][(1<<maxn)+10];
int in[maxn][maxn];
int off = 10;
int n;

int rec( int i, int j , int mask){
	if( i >= n ) return 0;
	if( j >= n ) return rec( i + 1, 0, mask );
	if( dp[i][j][mask] >= off ) return dp[i][j][mask] - off;	
	int ret = 0;
	//not use current pos
	if( (mask & (1<< j)) > 0 ){
		ret = rec( i, j + 1, mask | (1 << j ) );
	}else if( j + 1 < n){
		ret = rec( i, j + 2, mask | (1 << j ) | (1 << (j+1)) );
	} else {
		ret = rec( i, j + 1, mask | (1 << j ) );
	}
	// use current pos
	if( (mask & (1 << j )) > 0 && ( j + 1 >= n || ( (mask & (1 << (j+1))) > 0 )) ){
		ret = max( ret , in[i][j] + rec( i, j + 2, mask ^ (1<<j)));
	}	
	dp[i][j][mask] = ret + off;
	return ret;
}

int main(){	
	IOFAST();
	string str;
	while( getline( cin, str ) ){
		
		n = 0; int a;
		stringstream ss( str );
		while( ss >> a ){
			in[0][n++] = a;
		}
		REP(i,1,n){
			REP(j,0,n){
				cin >> in[i][j];
			}
		}
		getline( cin, str );
		if( n > 1 ) getline( cin, str );
		int ret = rec( 0, 0, (1<<n) - 1 );
		cout << ret << endl;
		off += 100000;		
	}
	return 0;
}