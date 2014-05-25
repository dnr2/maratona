//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2621
//#tag math
//#sol For each pair of boats, accurately solve a corresponding quadratic equation. 

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
#define REP(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define pb push_back
#define PI acos(-1)
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define mp make_pair
#define FILL(x,y) memset(x,y,sizeof(x))
#define EPS 1e-9
#define FOREACH(i,v) for(typeof((v).begin()) i=(v).begin();i!=(v).end();i++)

// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

int n; double r;

double x[1010];
double y[1010];
double d[1010];
double s[1010];

int colision( int A, int B){
	double cx = x[B] - x[A];
	double cy = y[B] - y[A];
	double v1x = sin(d[A]) * s[A];
	double v1y = cos(d[A]) * s[A];
	double v2x = sin(d[B]) * s[B];
	double v2y = cos(d[B]) * s[B];
	double vx = v2x - v1x;
	double vy = v2y - v1y;
	// db( cx _ cy _ v1x _ v1y _ v2x _ v2y );
	double deno = 2 * (vx * vx) + 2 * (vy * vy);
	
	double nomi = -1.0 * (2.0 * cx* vx + 2.0 * cy * vy);
	double t = nomi / deno;
	
	double ox = cx + vx * t; 
	double oy = cy + vy * t;
	double dist = sqrt( ox*ox + oy*oy);
	
	if( fabs(deno) < EPS || t < EPS){
		double dist = sqrt( cx*cx + cy*cy);
		if( dist <= r + EPS){
			return 0;
		} else {
			return 1000000000;
		}
	}
	if( dist <= r + EPS ){
		// binary search from 0 to t
		double ini = 0, end = t, mid = 0;
		int cont = 100;
		while(cont--){
			mid = (ini + end)/2.0;
			double ox = cx + vx * mid; 
			double oy = cy + vy * mid;
			double dist = sqrt( ox*ox + oy*oy);
			if( dist < r + EPS){
				end = mid;
			} else {
				ini = mid;
			}
		}
		return round(mid);
	} else {
		return 1000000000;
	}
}

int main(){
	int T; cin >> T;
    while(T--){
		cin >> n >> r;
		REP(i,0,n){
			scanf("%lf%lf%lf%lf", &x[i], &y[i], &d[i], &s[i]);
			d[i] *= PI/180.0;
		}
		int resp = 1000000000;
		REP(i,0,n){
			REP(j,i+1,n){
				resp = min ( resp , colision(i,j));
			}
		}
		if( resp == 1000000000){
			puts("No collision.");
		} else {
			printf("%d\n", resp);
		}
	}
	return 0;
}