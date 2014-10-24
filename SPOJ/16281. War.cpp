//http://www.spoj.com/problems/TAP2013G/
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

const int MAXN = 200000;

int in[2][MAXN];
int it[2];

int main(){
	
	int n;
	while(cin >> n){
		REP(i,0,2) REP(j,0,n) scanf("%d", in[i] + j);
		REP(i,0,2) sort( in[i], in[i] + n, greater<int>() );
		int resp = 0;
		it[0] = it[1] = 0;
		while( it[0] < n && it[1] < n){
			if( in[0][it[0]] < in[1][it[1]] ) {
				resp++;
				REP(i,0,2) it[i]++;
			} else {
				it[0]++;
			}
		}
		printf("%d\n", resp );
	}
	return 0;
}