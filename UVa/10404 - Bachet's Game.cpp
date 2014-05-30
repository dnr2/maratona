//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1345
//#tag dp dynamic programming
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
#define IOFAST ios_base::sync_with_stdio(0);cin.tie(0)
// #define umap unordered_map


using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

const int maxn = 1010000;
int n,m;
int st[20];
int dp[2][maxn]; 

int main(){
	
	while(scanf("%d%d", &n, &m) > 0){
		memset( dp, -1, sizeof( dp) );
		REP(i,0,m){
			scanf("%d", st + i);
		}		
		dp[0][0] = 1;
		dp[1][0] = 0;
		REP(j,0,n+1){
			REP(i,0,2){
				REP(k,0,m){
					if( j - st[k] >= 0){
						if( dp[i^1][j-st[k]] == i){
							dp[i][j] = i;
							break;
						}
					}
					dp[i][j] = i^1;
				}
			}
		}		
		if( dp[0][n] == 0) puts("Stan wins");
		else puts("Ollie wins");
	}
	return 0;
}