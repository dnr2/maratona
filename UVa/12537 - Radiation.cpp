//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3982
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
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1.0);
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }
#define MAXN 100
#define pdd pair<double,double>
#define F first 
#define S second 
pdd in[200002];
double d1[200002];
double d2[200002];

int main() {
	//cin.sync_with_stdio(false);
	int n; double a, b; int caso = 1;
	double  ax, ay, bx, by; int q;
	while(scanf("%d", &n ) >0 && n ){
		printf("Case %d:\n", caso++);
		fr(i,0,n) scanf("%lf%lf", &in[i].F, &in[i].S);
		cin >> ax >> ay >> bx >>  by >> q;
		fr(i,0,n){
			d1[i] = hypot( in[i].F - ax, in[i].S - ay);
			d2[i] = hypot( in[i].F - bx, in[i].S - by);
		}
		sort( d1, d1+n); sort( d2, d2+n);
		fr(i,0,q){
			cin >> a >> b ;
			int x = upper_bound(d1, d1+n, a) - d1;
			int y = upper_bound(d2, d2+n, b) - d2;
			cout << max( 0 , n - (x+y)) << endl;
		}
	}
	
	return 0;
}