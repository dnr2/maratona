//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2121
//#tag complex numbers numeros complexos
//#tag math
//#sol use the fact that the inverse multiplicative of (i-1) = (-i-1)/2
// so for the complex number n = b_0 + b_1 (i-1) + ... => (n - b_0) / (i -1) = b_1 + ... =>
// (n - b_0) * (-i -1) / 2

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

int main(){
	int T; cin >>T;
	vector<int> resp;
	REP(cn,1,T+1){
		int a, b;
		scanf("%d%d", &a, &b);
		printf("Case #%d: ", cn);
		if( a == 0 && b == 0){
			puts("0"); continue;
		}
		resp.clear();
		while( true ){
			if( a == 0 && b == 0) break;
			int r = 1;
			if( (a - b) % 2 == 0) r = 0;
			int na = (b-(a-r)) / 2;
			int nb = ((r-a)-b) / 2;
			a = na;
			b = nb;
			resp.pb(r);
		}
		int sz = (int) resp.size();
		REP(i,0,sz) printf("%d", resp[sz-1-i]);
		puts("");
	}
	return 0;
}