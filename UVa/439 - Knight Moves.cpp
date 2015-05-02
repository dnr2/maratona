//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=380
//#tag DFS 
//#tag shortest path 
//#sol dfs to find shortest path

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

char in[2][10];
int dp[10][10];

int dx[] = {1,2,2,1,-1,-2,-2,-1};
int dy[] = {-2,-1,1,2,2,1,-1,-2};

int main(){
	while( scanf("%s%s" , in[0] , in[1]) > 0 ){
		pii ini = mp( in[0][0]-'a', in[0][1]-'1');
		pii end = mp( in[1][0]-'a', in[1][1]-'1');
		REP(i,0,10)REP(j,0,10) dp[i][j] = 1e8;
		queue<pii> q;
		q.push( ini );
		dp[ini.F][ini.S] = 0;
		while( !q.empty()){
			pii cur = q.front(); q.pop();
			if( cur == end){
				printf("To get from %s to %s takes %d knight moves.\n", in[0], in[1], dp[cur.F][cur.S]);
				break;
			}
			REP(i,0,8){
				int ny = cur.F + dy[i];
				int nx = cur.S + dx[i];
				if( ny < 0 || ny >= 8 || nx < 0 || nx >= 8 || dp[ny][nx] != 1e8) continue;
				dp[ny][nx] = dp[cur.F][cur.S] + 1;
				q.push( mp( ny, nx));
			}
		}
	}	
	return 0;
}