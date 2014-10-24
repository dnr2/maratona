//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=861&page=show_problem&problem=4676
//#tag ad hoc recursive
//#sol recursively solve the problem for a <expression-list>, considering that the stop point is either an "end" or "]"

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

struct st{ 
	ll a[3];	
	st() { REP(i,0,3) a[i] = 0; }
};

ll mod = 1000003;
string cmds[] = {"left", "right", "forward", "repeat"};

st solve(){
	string cmd, aux;
	cin >> cmd;
	st ret;
	REP(i,0,4){
		if( cmd == cmds[i]){
			ll val; cin >> val;
			if( i < 3 ){
				ret = solve();
				ret.a[i] = (ret.a[i] + val) % mod;
			}  else {
				cin >> aux;
				st tmp = solve();
				ret = solve();
				REP(i,0,3) tmp.a[i] = (tmp.a[i] * val) %mod;
				REP(i,0,3) ret.a[i] = (ret.a[i] + tmp.a[i]) %mod;
			}
		}
	}
	return ret;
}

int main(){
	IOFAST();
	int cn; cin >> cn;
	string str;
	while( cn--) {
		cin >> str;
		st r = solve();
		cout << r.a[0] << " " << r.a[1] << " " << r.a[2] << endl;
	}
	return 0;
}