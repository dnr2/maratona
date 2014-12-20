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

PDD pts[MAXN];

int main(){
	
	double x,y,x1,x2, a,b,c,d, ang1, ang2;
	int cn = 1;
	while( cin >> x >> y >> a >> b >> ang1 >> x1 >> y1 >> c >> d >> ang2){
		if( a < 0 && b < 0 && c < 0 && d < 0) break;
		ang1 = (ang1 / 180.0) * PI;
		ang2 = (ang2 / 180.0) * PI;
		x1 = x1 - x;
		y1 = y1 - y;
		x = 0; y = 0;
		x1 = x1 * cos(-ang1) - y1 * sin(-ang1);
		y1 = y1 * sin(-ang1) + y1 * cos(-ang1);		
		ang2 -= ang1;
		ang1 = 0;
		
		
		
	}
	
	return 0;
}