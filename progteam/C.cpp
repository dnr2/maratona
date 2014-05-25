//
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
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

const int maxn = 600;
ll dp[maxn][maxn];

ll in[60][3];

int main(){
	int cn; cin >> cn;
	while(cn--){		
		int T, M;
		cin >> T >> M;		
		int n; cin >> n;
		REP(i,0,n){
			REP(j,0,3){
				int a; scanf("%d", &a);
				in[i][j] = a;
			}
		}
		memset(dp,0,sizeof(dp));		
		ll resp = 0;
		REP(cur,0,n){
			for( int i = T; i >=0; i--){
				for( int j = M; j >=0; j--){
				
					int ni = i + in[cur][0];
					int nj = j + in[cur][1];
					if( dp[i][j] > 0 &&  ni <= T && nj <= M){
						dp[ni][nj] = max( dp[ni][nj], dp[i][j] + in[cur][2]);
						resp = max( resp ,dp[ni][nj]);
					}
				}
			}
			if( in[cur][0] <= T && in[cur][1] <= M){
				dp[in[cur][0]][in[cur][1]] = max( dp[in[cur][0]][in[cur][1]], in[cur][2]);				
				resp = max( resp ,dp[in[cur][0]][in[cur][1]]);
			}
		}
		cout << resp << endl;
	}
	return 0;
}