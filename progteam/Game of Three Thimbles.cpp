#include <bits/stdc++.h>
#define REP(i,a,b) for (int i = (a); i < (b); ++i)
#define FT first
#define SD second
#define DB(x) cerr << #x << " = " << x  << endl
#define _ << " " <<
#define EPS 1e-9
#define INF 0x3f3f3f3f

using namespace std;

typedef pair<int,int> PII;
typedef long long ll;

const int maxn = 70000;
const int maxm = 800;
double dp[maxm+10][2];

int main() {
    int N; double prob;
    while( cin >> prob >> N){
        double resp = 0;
		
        memset(dp,0,sizeof(dp));
		
        REP(b,0,maxn){
			int bpos = b & 1;
			if( b == 0){
				dp[0][bpos] = 1;
			} else {
				REP(x,0,maxm){
					if( x == 0){
						dp[x][bpos] = 0;
					} else {
						dp[x][bpos] = 
							dp[x+2][bpos^1] * prob +
							dp[x-1][bpos^1] * (1-prob);
					}
				}
			}
			resp += dp[N][bpos];
        }		
        printf("%.9lf\n", resp );
    }
    return 0;
}
