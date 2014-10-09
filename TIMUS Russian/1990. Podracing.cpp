//http://acm.timus.ru/problem.aspx?space=1&num=1990
//#tag geometry geometria
//#tag adhoc adhoc
//#sol Add the points p on the polylines if there is another any given point p2 where p2.y = p.y.
// consider for each different level (y) the maximum "gate" the podracer can go through 
// get the minimum of these gates

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

const int MAXN = 200000;

struct pt{
	double x, y;
	pt( double x = 0, double y = 0) : x(x) , y(y) {}
	bool operator < ( const pt & in ) const {
		if( x == in.x ) return y < in.y;
		return x < in.x;
	}
};

pt p[3][MAXN];
int n[3];
int cord[3*MAXN];

int main(){
	while( scanf("%d", &n[0] ) > 0 ){		
		int csz = 0;
		int miny = (-1e9) - 1, maxy = 1e9 + 1;
		REP(i,0,3){
			if( i > 0) scanf("%d", n + i);
			REP(j,0,n[i]) {
				int a, b;
				scanf("%d%d", &a, &b);	
				if( i == 0 && j == 0) miny = b;
				if( i == 0 && j == n[i] - 1) maxy = b;
				if( i < 2 || (b >= miny && b <= maxy ) ){
					p[i][j] = pt( a, b);
					cord[csz++] = b;
				} else {
					j--; n[i]--;
				}
			}
		}
		sort( cord, cord + csz);
		csz = unique( cord, cord + csz) - cord;	
		int it[3] = {0, 0, 0};
		double resp = 1e20;
		REP(i,0,csz){
			pt bound[2];			
			REP(j,0,2){
				if( fabs( p[j][it[j]].y - ((double)cord[i]) ) < EPS ) bound[j] = p[j][it[j]++];
				else{
					double frac = (cord[i] - p[j][it[j]-1].y) / (p[j][it[j]].y - p[j][it[j]-1].y);					
					bound[j] = pt( p[j][it[j]-1].x + (frac * (p[j][it[j]].x - p[j][it[j]-1].x))  , cord[i]);
				}
			}			
			vector<pt> v;
			v.PB( bound[0] );
			while( it[2] < n[2] && fabs( p[2][it[2]].y - ((double)cord[i]) ) < EPS ) {
				if( p[2][it[2]].x >= bound[0].x + EPS  && p[2][it[2]].x <= bound[1].x + EPS ) v.PB( p[2][it[2]] );
				it[2]++;
			}
			v.PB( bound[1] );
			double wide = 0;
			sort( v.begin(), v.end());	
			REP(i,1,(int)v.size()){
				wide = max( wide, v[i].x - v[i-1].x);
			}
			resp = min( resp, wide );
		}
		printf("%.7lf\n", resp );
	}
	return 0;
}