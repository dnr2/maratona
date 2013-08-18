//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3980
//#tag geometry geometria

#include <cstring>
#include <cstdlib>
#include <climits>
#include <cstdio>
#include <cctype>
#include <cmath>
 
#include <iostream>
#include <algorithm>
#include <utility>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
 
//#include <bits/stdc++.h>
 
using namespace std;
 
#define fr(i,j,k) for (int (i) = (j); (i) < (k); (i)++)
#define frd(i,j,k) for (int (i) = (j); (i) >= (k); (i)--)
#define ms(ar,a) memset(ar, a, sizeof(ar))
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
#define ler(a) scanf("%d", &a)
#define ler2(a,b) scanf("%d%d", &a, &b)
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define EPS 1e-9
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1.0);
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }
#define MAXN 100

double in[40010];

int main() {
	//cin.sync_with_stdio(false);
	
	ll n; double r; int caso = 1;
	while(scanf("%lld", &n) > 0 && n){
		ms(in,0);
		ll resp = 0;
		cin >> r;
		int a, b;
		fr(i,0,n){
			scanf("%d.%d",&a,&b);
			a = a*1000 + b;
			in[i] = a;;
		}
		sort(in,in+n);
		fr(i,n,2*n) in[i] = in[i-n] + 360000;
		fr(i,0,n){
			ll a = upper_bound( in, in +(2*n) , in[i]+180000.0) - in;
			ll x = (a-(i+1));
			// db( i _ in[i] _ a _ x);
			resp +=  (x * (x-1))/2;
		}  
		printf("Case %d: ", caso++);
		if( n == 1 || n == 2) cout << "0" <<endl;
		else cout << ((n * (n-1) * (n-2) / 6) - resp) << endl;
	}
	
	return 0;
}