//http://www.spoj.com/problems/FBRIDGES/
//#tag Geometry geometria
//#tag Binary Search Busca binaria
//#sol Use Binary Search on the width of the river to see when the shores hit each other.

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

const int MAXN = 2000;

double cen[2][MAXN];
double rad[2][MAXN];
bool nor[2][MAXN];
int sz[2];
char str[10];

int main(){
	double A;
	while( cin >> A ){
		if( A < 0) break;
		REP(i,0,2){
			scanf("%d%s", &sz[i], str);
			int rdsum = 0;
			bool north = (str[0] == 'N');
			REP(j,0,sz[i]){
				int a; scanf("%d", &a);
				rdsum += a;
				cen[i][j] = rdsum;
				rad[i][j] = a;
				nor[i][j] = north;
				north = !north;
				rdsum += a;
			}
		}
		double mid, lo = 0, hi = A;
		while( fabs( hi - lo ) > EPS){
			mid = (lo+hi)/2;
			//DB( mid );
			bool touch = false;
			int i = 0, j = 0;
			while( i < sz[0] || j < sz[1]){
				double distrad = sqrt( pow( cen[0][i] - cen[1][j], 2) + pow(mid,2));
				if( !nor[0][i] && nor[1][j] ){
					if( distrad < rad[0][i] + rad[1][j] ){ //TODO EPS
						touch = true;
						goto leave;
					}
				} else if( nor[0][i] && !nor[1][j] ){
					if( mid < EPS ){
						 touch = true;  
						 goto leave;
					}
				} else  {
					double c1 , c2 , r1, r2;
					if( nor[0][i] && nor[1][j]){
						c1 = cen[0][i]; c2 = cen[1][j]; r1 = rad[0][i]; r2 = rad[1][j];
					} else {
						c1 = cen[1][j]; c2 = cen[0][i]; r1 = rad[1][j]; r2 = rad[0][i];
					}
					double distleft =  sqrt(pow( (c1+r1) - c2, 2) + pow(mid,2));
					double distright = sqrt(pow( (c1-r1) - c2, 2) + pow(mid,2));
					if( distleft < r2 || distright < r2 ){
						touch = true; 
						goto leave;
					}
				}
				if( i < sz[0] && j < sz[1] && 
					fabs( (cen[0][i] + rad[0][i]) - (cen[1][j] + rad[1][j]) ) < 1e-5){
					 i++, j++;
				} else if( cen[0][i] + rad[0][i] > cen[1][j] + rad[1][j] && j + 1 < sz[1]) { j++;
				} else {
					i++;
				}
			}
			leave :
			if( touch ) lo = mid;
			else hi = mid;
		}
		printf("%.2lf\n", (A - mid));
	}
	
	return 0;
}