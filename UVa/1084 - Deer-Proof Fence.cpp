//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3525
//#tag pd dinamic programming
//#tag geometry geometria
//#tag convexHull 
//#sol testar todas as possívies combinações de grupos de arvores

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
#define fr(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define rep(i,n) for(int (i)=0;(i)<(n);++(i))
#define pb push_back
#define PI acos(-1)
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define mp make_pair
#define cl(x) memset(x,0,sizeof(x))
#define EPS 1e-9
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}


struct point{
	double x, y;
	point ( double x= 0, double y = 0 ) : x(x), y(y) {}
	bool operator < (const point & p) const {  return (x == p.x)? y<p.y : x <p.x ; } 
	double operator * ( point & p ) { return  x*p.x + y*p.y ; } 
	point operator - ( point & p) { return point( x -p.x, y-p.y); } 
	double dist( point p) { return sqrt( pow(x - p.x,2.0) + pow(y - p.y,2.0) ); }
};

double cross( const point & O, const point &A, const point &B) { 
	return (A.x - O.x) * (B.y - O.y) - (A.y -O.y) * (B.x-O.x); 
}

vector<point> convexHull(vector<point> P){
	int n = P.size(),k =0; vector<point> H(2*n);
	sort(P.begin(), P.end());
	for( int i =0; i< n; i++){
		while( k>=2 && cross(H[k-2], H[k-1] , P[i]) <= 0) k--; H[k++] = P[i];
	}
	for( int i=n-2, t=k+1; i>=0; i--){
		while( k>=t && cross(H[k-2], H[k-1] , P[i]) <= 0) k--; H[k++] = P[i];
	}
	H.resize(k); return H;	
}

int n, caso =1; double m,a,b;
point in[11];
int cont[1<<9];
double length[1<<9];
double dp[1<<9];

int contFunc(int mask){
	int resp = 0; 
	while(mask) { if( mask & 1) resp++; mask >>=1; }
	return resp;
}


double rec(int mask){
	if( mask & (mask-1) == 0) return length[mask];
	if( dp[mask] > -1) return dp[mask];
	double best = length[mask];
	int m = (mask-1) &mask;
	while(m){
		best = min( best , rec(m) + rec( mask ^ m ) );
		m = (m-1) & mask;
	}
	return dp[mask] = best;
}

int main(){
	
	for(int i = 0; i<(1<<9); i++) cont[i] = contFunc(i);
	while(scanf("%d %lf", &n, &m) > 0 && n){
		
		fr(i,0,n) scanf("%lf%lf", &in[i].x, &in[i].y); 
		for(int k = 0 ; k < (1<<n); k++){
			vector<point> v; int aux = k; int j = 0; dp[k] = -1;
			while(aux) {
				if( aux &1) v.pb(in[j]);
				j++; aux >>= 1;
			}
			v = convexHull(v); 			
			double len = 0;
			if( v.size() > 1) fr(i,0,v.size()-1) len += (v[i].dist(v[i+1])); 
			if( k > 0) len += PI * 2 * m;
			length[k] = len;
		}		
		printf("Case %d: length = %.2lf\n", caso++, rec(((1<<n)-1) ));
	}
	return 0;
}