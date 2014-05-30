// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=943
//#tag convex hull
//#sol compute convex hull and calculate centroid for polygons

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

struct Point { ll x,y; bool operator<(const Point &p)const{
return(x==p.x) ? y<p.y : x<p.x; } };
ll cross(const Point &O, const Point &A, const Point &B)
{ return (A.x-O.x) * (B.y-O.y) - (A.y-O.y) * (B.x-O.x); }
// Returns a list of convex hull in counter-clockwise order.
// In case of collinear points, only end-points are taken (not middle).
// The last point is the same as the first one.
vector<Point> ConvexHull(vector<Point> P) {
int n = P.size(), k = 0; vector<Point> H(2*n);
sort(P.begin(), P.end());
for (int i = 0; i < n; i++)
{ while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--; H[k++] = P[i]; }
for (int i = n-2, t = k+1; i >= 0; i--)
{ while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--; H[k++] = P[i]; }
H.resize(k); return H; }

int main(){
	
	int n;
	vector<Point> v, ret;
	while(scanf("%d", &n) && (n > 2)){
		v.clear();
		REP(i,0,n){
			int a, b;
			scanf("%d%d", &a,&b);
			Point x;
			x.x = a; x.y = b;
			v.pb(x);
		}
		ret = ConvexHull( v );
		double A =0, Cx = 0, Cy=0, aux;
		REP(i,1,((int) ret.size())){
			aux = (ret[i-1].x * ret[i].y - ret[i].x * ret[i-1].y);
			A += aux;
			Cx += (ret[i-1].x + ret[i].x) * aux;
			Cy += (ret[i-1].y + ret[i].y) * aux;		
		}
		Cx /= A * 3;
		Cy /= A * 3;
		printf("%.3lf %.3lf\n", Cx, Cy);
	}
	return 0;
}