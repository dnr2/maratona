//http://www.spoj.com/problems/TAP2013B/
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

const int MAXN = 100;
int in[MAXN];

int main(){
	int n; 
	while(cin >> n){
		REP(i,0,n) scanf("%d", in + i);
		sort( in, in+ n, greater<int>());
		int C = 0;		
		REP(i,0,n) C+= in[i];
		if( in[0] * 100 / C >= 45 || ( in[0] * 100 / C >= 40 && in[0] * 10 >= in[1] * 10 + C )) cout << 1 << endl;
		else cout << 2 << endl;
	}
	
	return 0;
}