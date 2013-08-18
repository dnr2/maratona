//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1282
//#tag binary search busca binária
//#sol busca binária no x

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

// #include <unordered_map>

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define F first
#define S second
#define fr(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define rep(i,n) for(int (i)=0;(i)<(n);++(i))
#define pb push_back
#define PI acos(-1)
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define mp make_pair
#define cl(x) memset(x,0,sizeof(x))
// #define umap unordered_map
#define EPS 1e-8

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}


int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	double p, q, r, s, t, u;
	while( scanf("%lf%lf%lf%lf%lf%lf", &p,&q,&r,&s,&t,&u) > 0){
		double ini = 0.0, fim = 1.0, x;
		fr(i,0,50){
			x=(ini+fim)/2;
			double aux = p * exp(-x) + q * sin(x) + r*cos(x) + s*tan(x) + t*pow(x,2) + u;
			if( aux < 0) fim = x;
			else if( aux > 0) ini = x;
			else break;
		}
		double aux = p * exp(-x) + q * sin(x) + r*cos(x) + s*tan(x) + t*pow(x,2) + u;
		if( fabs(aux) > EPS) puts("No solution");
		else printf("%.4lf\n", x);
	}
	return 0;
}