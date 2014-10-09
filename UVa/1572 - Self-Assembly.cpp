//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=4364
//#tag search graphs
//#sol test if the underling graph has a cycle. connect the letter/sign with the adjacent of the molecules

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

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str(); }

const int MAXN = 60;
char str[100];
int dp[MAXN][MAXN];
int in[4];

int main(){
	int n;
	while(scanf("%d", &n) > 0){
		FILL(dp,1);		
		REP(i,0,n){
			scanf("%s", str);			
			REP(j,0,4){
				if( str[j*2] != '0') in[j] = (str[j*2]-'A') + ((str[j*2+1]=='-')?1:27);
				else in[j] = 0;
			}
			REP(j,0,4) REP(k,0,4) {
				if( in[j] == 0 || in[k] == 0 || j == k) continue;
				if( in[j] > 26){
					dp[in[j]-26][in[k]] = 0;
				} else{
					dp[in[j]+26][in[k]] = 0;
				}
			}
		}		
		REP(k,0,MAXN) REP(i,0,MAXN) REP(j,0,MAXN) dp[i][j] = min( dp[i][j], dp[i][k] + dp[k][j]);
		bool ok = false;
		REP(k,1,27){
			if( dp[k][k] == 0){ ok = true;  break; }
		}
		if( ok ) puts("unbounded");
		else puts("bounded");
	}
	return 0;
}