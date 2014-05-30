//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=242
//#tag cycles ciclos
//#tag ad hoc
//#sol find for each position the period where the position goes back to itself, k can be large.

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

const int maxn = 210;
int seq[maxn];
int period[maxn];
int nums[2][maxn];
char msg[2][maxn];

int main(){
	int n;
	while(scanf("%d", &n) > 0 && n){
		REP(i,0,n){
			scanf("%d", seq+i);
			seq[i]--;
		}
		REP(i,0,n) nums[0][i] = i, period[i] = INF;
		REP(i,0,n){
			REP(j,0,n){
				nums[(i+1)%2][j] = seq[nums[i%2][j]];
				if( nums[(i+1)%2][j] == j && period[j] == INF ) period[j] = i+1;
			}
		}
		int k;
		while( scanf("%d", &k) > 0 && k){
			memset( msg, 0, sizeof( msg));
			gets(msg[0]);			
			int len = strlen(msg[0]);
			REP(i,1,len){				
				msg[0][i-1] = msg[0][i];
			}
			len--;
			while( len < n){
				msg[0][len++] = ' ';
			}
			msg[0][len] = 0;			
			REP(i,0,n){
				int moves = k % period[i];
				int pos = i;
				REP(j,0,moves){
					pos = seq[pos];
				}
				msg[1][pos] = msg[0][i];
			}
			printf("%s\n", msg[1]);
		}
		puts("");
	}
	return 0;
}