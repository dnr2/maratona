//
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

const int MAXN = 3000;

double x[2], y[2], r[2];
double dist, tlen, delta, center_ang, uang[2], dang[2];

int main(){
	
	while( cin >> x[0] ){
		REP(i,0,2){
			if( i == 1) cin >> x[i];
			cin >> y[i] >> r[i];		
			dist = sqrt( x[i] * x[i] + y[i] * y[i]);
			tlen = sqrt( dist * dist - r[i] * r[i]);
			delta = acos(((r[i] * r[i]) - (tlen * tlen) - (dist * dist)) / ( -2 * tlen * dist )); 
			center_ang = atan2( y[i] ,x[i]);
			uang[i] = center_ang + delta;
			dang[i] = center_ang - delta;
		}
		int A = 0, B = 1;		
		//TODO usar EPS?
		if( uang[B] < dang[A] || dang[B] > uang[A]){
			puts("1");
		} else if( uang[B] <= uang[A] && dang[B] >= dang[A]){ 
			puts("4");
		} else if( uang[A] < uang[B] && dang[A] > dang[B] ){
			puts("3");
		} else {
			puts("2");
		}
	}	
	return 0;
}