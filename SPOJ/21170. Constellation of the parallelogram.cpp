//http://www.spoj.com/problems/TAP2014C/
//#tag geometry geometria 
//$tag vector vetor 
//$tag map mapa
//#sol you should count the number of sides that have the same size and same angle with the axis, this can be done by
// using a vector of the difference between points. since you have two equal vectors they will count as one possible
// parallelogram. You should be careful when two vectors are equal but they were initially in the same line on the
// 2D plane.


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
#define EPS 1e-5
#define INF 0x3f3f3f3f
#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0)
#define FILL(x,v) memset(x,v,sizeof(x))


// #define umap unordered_map
using namespace std;
template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

#define MAXN 2000


struct pt{
	ll x, y;
	pt( ll x = 0, ll y = 0): x(x), y(y) {}
	pt operator - ( pt & arg ){
		return pt( x - arg.x, y - arg.y);
	}
	bool operator < ( const pt & arg) const {
		if( y == arg.y ) return x < arg.x;
		return y < arg.y;
	}
};

struct st{
	double x;
	st( double x = 0) : x(x) {}
	bool operator < ( const st & arg) const {
		if( fabs( x - arg.x) < EPS) return false;
		return x < arg.x;
	}
};

pt in[MAXN];

int main(){
	IOFAST();
	int N; 	
	while(cin >> N){
		REP(i,0,N){
			cin >> in[i].x >> in[i].y;
		}
		map<pt, int> m1;
		map< pair< pt, pair< bool, st > > , int> m2; 
		REP(i,0,N){
			REP(j,i+1,N){
				pt aux = in[i] - in[j];
				if( aux.x < 0 ) aux = pt(-aux.x, -aux.y);
				if( aux.x == 0 && aux.y < 0 ) aux = pt( -aux.x, -aux.y);
				m1[aux]++;
				pt U = in[j] - in[i];
				if( U.y == 0 ) {
					double tmp = - ((double) in[i].x) / ((double)U.x);	
					m2[ MP( aux, MP( false, st( ((double) in[i].y) + tmp * U.y )  ))]++;
				} else {
					double tmp = - ((double)in[i].y) / ((double)U.y);					
					m2[ MP( aux, MP( true , st( ((double) in[i].x) + tmp * U.x ) ))]++;
				}
			}
		}
		ll resp =0;
		for( map<pt , int>::iterator it = m1.begin(); it != m1.end(); it++){ 
			ll aux = it->SD;			
			resp +=  (aux* (aux-1)) / 2;
		}		
		for( map< pair< pt, pair< bool, st > > , int>::iterator it = m2.begin(); it != m2.end(); it++){
			ll aux = it->SD;
			resp -=  (aux* (aux-1)) / 2;
		}
		cout << resp/2 << endl;
	}
	return 0;
}