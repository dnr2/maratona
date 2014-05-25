//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2037
//#tag convex hull
//#sol use convex hull and compute the perimeter

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
#define IOFAST ios_base::sync_with_stdio(0);cin.tie(0)
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

struct Point { 
	double x,y; 
	bool operator<(const Point &p) const{
		return (x==p.x) ? y<p.y : x<p.x; 
	} 
};

double cross(const Point &O, const Point &A, const Point &B) { 
	return (A.x-O.x) * (B.y-O.y) - (A.y-O.y) * (B.x-O.x); 
}

vector<Point> ConvexHull(vector<Point> P) {
	int n = P.size(), k = 0; vector<Point> H(2*n);
	sort(P.begin(), P.end());
	for (int i = 0; i < n; i++)
	{ while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--; H[k++] = P[i]; }
	for (int i = n-2, t = k+1; i >= 0; i--)
	{ while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--; H[k++] = P[i]; }
	H.resize(k); return H; 
}


int main(){
	int T; cin >> T;
	vector<Point> v, ret;
	while( T--){
		int n, m ;
		scanf("%d%d", &n, &m);
		v.clear(); ret.clear();
		REP(i,0,m){
			Point aux;			 
			scanf("%lf%lf", &aux.x, &aux.y);						
			v.pb( aux);
		}
		ret = ConvexHull( v);
		double resp = 0;
		REP(i,1,ret.size()){
			resp += sqrt( ( ret[i].x - ret[i-1].x) * ( ret[i].x - ret[i-1].x) +  ( ret[i].y - ret[i-1].y ) * ( ret[i].y - ret[i-1].y ));
		}
		printf("%.5lf\n", max(resp, (double)n));
	}
	
	return 0;
}