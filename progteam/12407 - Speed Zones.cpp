//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3838
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
#include <cassert>
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
#define EPS 1e-11
#define INF 0x3f3f3f3f
#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0)
#define FILL(x,v) memset(x,v,sizeof(x))
// #define umap unordered_map
using namespace std;
template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str(); }

const int MAXN = 3000;

double s[MAXN];
int n;
double calc( double ang){
	double ret = 0;
	REP(pos,0,n){
		double x = 100;
		if( ang > PI -EPS) x = 0;
		else x /= sin(ang) / cos(ang);
	
		double nang = PI;
		if( pos + 1 != n){
			nang = (ang * s[pos]) / s[pos+1];
		}
		ang = nang;
		ret += x;
	}
	return ret;
}

double calctime( double ang){
	double ret = 0;
	REP(pos,0,n){
		double x = 100;
		if( ang > PI -EPS) x = 0;
		else x /= tan(ang);
		double nang = PI;
		if( pos + 1 != n){
			nang = (ang * s[pos]) / s[pos+1];
		}
		ang = nang;
		ret += (sqrt( pow(x,2) + pow(100,2)) /s[pos]);
	}	
	return ret;
}


int main(){
	int T; cin >> T;
	REP(cn,1,T+1){
		double d; cin >> n >> d;
		REP(i,0,n) scanf("%lf", &s[i]);
		double lo = 0, hi = PI/2 + EPS, m1, m2;
		int cont = 200;
		while ( fabs( lo - hi) > EPS && (cont-- > 0)){
			m1 = lo + ((hi-lo)/3);
			m2 = hi - ((hi-lo)/3);
			double d1 = 0, d2= 100;
			d1 = calc( m1);
			d2 = calc( m2);
			if( fabs( d1 - d) < fabs( d2 - d)){
				hi = m2;
			} else {
				lo = m1;
			}
		}
		double resp = calctime((lo+hi)/2);
		if (resp <= 0) resp = 0;
		printf("Case %d: %.8lf\n", cn, resp);
	}
	
	
	return 0;
}

void function(int n, int x) {
	
}
