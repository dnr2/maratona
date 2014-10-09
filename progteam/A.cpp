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
	double x, y;
	pt( double x = 0, double y = 0): x(x), y(y) {}
	pt operator - ( pt & arg ){
		return pt( x - arg.x, y - arg.y);
	}
	bool operator < ( const pt & arg) const {	
		if( fabs(x -arg.x) < EPS && fabs( y - arg.y ) < EPS ) return false;
		if( fabs(x - arg.x) < EPS ) return y < arg.y;
		return x < arg.x;
	}
};

double dot( pt a, pt b){
	return a.x * b.x + a.y * b.y;
}

pt in[MAXN];

int main(){
	int N; 	
	while(cin >> N){
		REP(i,0,N){
			scanf("%lf%lf", &in[i].x , &in[i].y);
		}
		map<pt, int> m1;
		map< pair<pt,pt> , int> m2; 
		REP(i,0,N){
			REP(j,i+1,N){
				pt aux = in[i] - in[j];
				if( aux.x < 0 ) aux = pt(-aux.x, -aux.y);
				if( fabs(aux.x) < EPS && aux.y < 0 ) aux = pt( aux.x, -aux.y);
				m1[aux]++;
				pt A = in[i] - in[j];
				pt B = pt(0,0) - in[j];
				double val = dot( A, B) / dot( A, A);
				pt aux2 = pt( in[j].x + A.x * val, in[j].y + A.y * val);
				m2[MP( aux, aux2)]++;
			}
		}
		ll resp =0;
		for( map<pt , int>::iterator it = m1.begin(); it != m1.end(); it++){ 
			ll aux = it->SD;			
			resp +=  (aux* (aux-1)) / 2;
		}
		for( map< pair<pt,pt> , int>::iterator it = m2.begin(); it != m2.end(); it++){
			ll aux = it->SD;
			resp -=  (aux* (aux-1)) / 2;
		}
		cout << resp/2 << endl;
	}
	return 0;
}
