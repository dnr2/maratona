//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2067

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

const int maxn = 1000;
const int maxm = 279936;

int dp[maxm+10][19][14];
int in[10][10];
int draw[20];
int passo = 1;

int rec( int vals[], int d, int p){
	int sum = 0;
	REP(i,0,7){
		sum += (vals[i] == 5)? 1 : 0;
	}
	if( sum == 7 && d == 17 ) return passo + 1;
	int f = 0;
	REP(i,0,7){
		f *= 6;
		f += vals[i];
	}
	int & ret = dp[f][d][p];
	if( ret >= passo) return ret;
	
	int * arg = new int[7];
	REP(i,0,7) arg[i] = vals[i];
	
	int ok = passo;
	
	REP(i,0,7){
		int aux = in[arg[i]][i];
		if( arg[i] < 5 && abs( aux - p ) == 1 || (aux == 13 && p == 1) || (aux == 1 && p == 13) ) { 
			arg[i]++;
			int curret = rec( arg , d, aux ); 
			if( curret > passo ) ok = passo + 1;
			arg[i]--;
			if( ok == passo + 1 ) break;
		}
	}
	if( ok == passo + 1 ) return ret = ok;
	if( d < 17) return ret = rec( arg , d+1 , draw[d] );
	return ret = passo;
}

int main(){

	int T; cin >> T;
	REP(cn,1,T+1){
		REP(i,0,5){
			REP(j,0,7){
				scanf("%d", &in[5-i-1][j]);
			}
		}
		
		REP(i,0,17){
			scanf("%d", draw + (17-i-1));
		}
		passo += 10;
		int * args = new int[7];
		REP(i,0,7) args[i] = 0;
		int ret =  rec( args, 1, draw[0] );

		if( ret == passo + 1) {
			printf("Case #%d: Yes\n", cn);
		} else {
			printf("Case #%d: No\n", cn);
		}
	}
	return 0;
}