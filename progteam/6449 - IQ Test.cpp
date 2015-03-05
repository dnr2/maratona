//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=588&page=show_problem&problem=4460
//#tag math matematica
//#tag linear system e quacoes lineares
//#sol test first with d = 1 then d = 2 otherwise assume d = 3. use Cramer's formula to solve the equation system.

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

const int maxn = 3000;
int in[maxn];

int main(){
	IOFAST();
	int T; cin >> T;
	while (T--){
	
		int n; cin >> n;
		REP(i,0,n) cin >> in[i];
		int x = 0, y = 0,z = 0;
		int div, upx, upy, upz;
		//caso 1
		if( in[0] != 0 && in[1] % in[0] == 0 ){
			x = in[1] / in[0]; 
			REP(i,2,n){
				if( in[i] != in[i-1] * x ) goto caso2;
			}
			cout << in[n-1] * x << endl;
			continue;
		}
		caso2:
		div = in[0] * in[2] - in[1] * in[1];		
		upx = in[2] * in[2] - in[1] * in[3];
		upy = in[0] * in[3] - in[1] * in[2];
		if( div != 0 && upx % div == 0 && upy % div == 0 ){
			x = upx / div, y = upy / div;
			REP(i,4,n){
				if( in[i] != in[i-2] * x  + in[i-1] * y) goto caso3;
			}
			cout << in[n-2] * x + in[n-1] * y << endl;
			continue;
		}
		caso3:		
		div = ( in[0] * in[2] * in[4] + in[1] * in[3] * in[2] + in[2] * in[1] * in[3] ) -
			  ( in[2] * in[2] * in[2] + in[3] * in[3] * in[0] + in[4] * in[1] * in[1] );
		upx = ( in[3] * in[2] * in[4] + in[1] * in[3] * in[5] + in[2] * in[4] * in[3] ) -
			  ( in[5] * in[2] * in[2] + in[3] * in[3] * in[3] + in[4] * in[4] * in[1] );
		upy = ( in[0] * in[4] * in[4] + in[3] * in[3] * in[2] + in[2] * in[1] * in[5] ) -
			  ( in[2] * in[4] * in[2] + in[5] * in[3] * in[0] + in[4] * in[1] * in[3] );
		upz = ( in[0] * in[2] * in[5] + in[1] * in[4] * in[2] + in[3] * in[1] * in[3] ) -
			  ( in[2] * in[2] * in[3] + in[3] * in[4] * in[0] + in[5] * in[1] * in[1] );
		x = upx / div, y = upy / div, z = upz/ div;
		cout << in[n-3] * x + in[n-2] * y + in[n-1] * z << endl;
	}
	return 0;
}