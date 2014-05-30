//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1319
//#tag math 
//#tag complex numbers
//#tag math
//#sol De Moivre's theorem, pay attention when sorting the elements and when printing the results. (very annoying output format)

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
#define EPS 1e-6
#define INF 0x3f3f3f3f
#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0)
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

char aux[2][100];

bool comp( pdd a, pdd b){
	if( fabs( a.F - b.F) > EPS) return a.F > b.F;
	return a.S > b.S;
}

int main(){
	pdd num; int cn = 1, n;
	int a,b;
	vector<pdd> roots;
	while( scanf("%d%di", &a, &b) > 0){
		num = mp( a, b);
		printf("Case %d:\n", cn++);
		scanf("%d", &n);
		roots.clear();
		REP(i,0,n){
			double r = pow( sqrt( num.F * num.F + num.S * num.S), 1.0/((double)n));
			double beta = atan2( num.S, num.F);
			double theta = (beta + 2.0 * PI * ((double) i)) / ((double)n);
			pdd newnum = mp( r * cos( theta) , r * sin( theta));			
			roots.pb(newnum);
		}
		sort( roots.begin(), roots.end(), comp );		
		REP(i,0,n){
			sprintf(aux[0],"%.3lf",roots[i].F);
			sprintf(aux[1],"%+.3lf",roots[i].S);
			string s1(aux[0]), s2(aux[1]);
			if( s1 == "-0.000") s1 = "0.000";
			if( s2 == "-0.000") s2 = "+0.000";
			cout << s1 << s2 << "i" << endl;
		}
		puts("");
	}
	return 0;
}