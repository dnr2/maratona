//
//#tag
//#sol

#include <bits/stdc++.h>


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
#define EPS 1e-7
#define INF 0x3f3f3f3f
#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0)
#define FILL(x,v) memset(x,v,sizeof(x))
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str(); }

const int maxn = 1000;

struct pt { 
	double x,y; 
	pt( double x = 0, double y = 0):x(x), y(y) {}
	bool operator<(const pt &p) const{
		return( fabs(x -p.x) < EPS) ? y<p.y : x<p.x; 
	}
	pt operator + (pt arg) { return pt( x + arg.x, y + arg.y); } 
	pt operator - (pt arg) { return pt( x - arg.x, y - arg.y); } 
	double operator !() {return sqrt( x*x + y*y );}
	double operator *(pt arg) {return x*arg.x + y*arg.y; }
	pt operator / (pt arg) { 
		pt clone = pt(x,y); 
		double fact = (clone*arg)/(arg*arg);
		return pt( arg.x * fact, arg.y * fact);
	}
};

double comp( double x, double y){
	return fabs( x - y ) > EPS;
}

double cross( pt a, pt b){
	return a.x * b.y - a.y * b.x; 
}

pt in[maxn];

vector<pt> vec;

pt ini;

bool comp(pt a, pt b){
	cross( a - ini, b - ini ) < 0;
}

int main(){

	int T; cin >> T;
	REP(cn,1,T+1){
		int n;cin >> n;
		REP(i,0,n){
			cin >> in[i].x >> in[i].y ;
		}
		
		printf("Case #%d:\n", cn);
		REP(i,0,n){	
			vec.clear();
			REP(j,0,n){
				if( j == i ) continue;
				vec.PB( in[j] );
			}
			ini = vec[0] - in[i];			
			sort( vec.begin(),vec.end() , cmp);
			
		}
	}
	return 0;
}