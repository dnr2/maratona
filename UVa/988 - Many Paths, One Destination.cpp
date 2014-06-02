//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=929
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
#define FOREACH(i,v) for(typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define IOFAST ios_base::sync_with_stdio(0);cin.tie(0);

// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

const int SIZE = 1000000;
int dp[SIZE];

int main(){
	int n; bool f = true;
	while(scanf("%d", &n) > 0){
		int resp = 0;
		fill_n(dp,SIZE,0);
		dp[0] = 1;
		REP(i,0,n){
			int m; scanf("%d", &m);
			REP(j,0,m){
				int a; scanf("%d", &a);
				dp[a] += dp[i];
			}
			if( m == 0) resp += dp[i];
		}
		if(f) f=false;
		else puts("");
		printf("%d\n", resp);
	}
	return 0;
}