//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2559
//#tag geometry geometria
//#tag convex Hull 

#include <map>
#include <set>
#include <bitset>

#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <string>
#include <algorithm>

#include <iostream>
#include <sstream>
#include <iterator>

#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define fr(a,b,c) for( int a = b ; a < c ; ++a )
#define rp(a,c) fr(a,0,c)
#define fr_(a,b,c) for( int a = b ; a > c ; --a )
#define rp_(a,b) fr_(a,b,-1)

#define cl(a,b) memset((a),(b), sizeof(a))
#define db(x) cerr << #x " == " << x << "\n"
#define _ << ", " <<
#define INF 0x3f3f3f3f

typedef long long 			ll;
typedef unsigned long long 	ull;
typedef vector<int> 		vi;
typedef pair<int,int> 		pii;

#define maxn 0

struct Point{
	ll x,y; 
	Point( ll x =0, ll y = 0) : x(x), y(y) {}
	bool operator < ( const Point & p ) const{
		return ( x== p.x)? y < p.y : x < p.x ; 
	}
};

ll cross(const Point &O , const Point &A, const Point &B){
	return (A.x - O.x) * ( B.y - O.y) - ( A.y - O.y) * (B.x - O.x);
}

vector<Point> ConvexHull( vector<Point> P){
	int n = P.size(), k = 0; vector<Point> H(2*n);
	sort(P.begin(), P.end());
	for( int i = 0; i < n ; i++){
		while( k >= 2 && cross( H[k-2], H[k-1], P[i] ) <= 0) k--; H[k++] = P[i]; 
	}
	for( int i=n-2, t = k+1; i>=0; i--){
		while( k >= t && cross( H[k-2], H[k-1], P[i]) <= 0 ) k--; H[k++] = P[i];
	}
	H.resize(k); return H;
}

vector<Point> in;

int main(){
	int  t;
	scanf("%d", &t);
	while(t--){
		in.clear();
		int c, n;
		ll	a, b;
		cin >> c >> n;
		fr(i,0,n){
			scanf("%lld %lld", &a, &b); in.pb( Point( a,b));
		}
		vector<Point> ret = ConvexHull( in);
		int pont = 0; Point aux(10000,-10000);
		fr(i,0,ret.size()-1){
			if( aux.y <= ret[i].y  ){ 
				if( aux.y == ret[i].y && aux.x < ret[i].x) continue; 
				aux = ret[i], pont = i; //db( aux.x _ aux.y);
			}
		}
		// db(pont);
		printf("%d %d\n", c,  (ret.size()-1));
		for( int  i = pont; i >=0 ; i--){
			printf("%lld %lld\n", ret[i].x, ret[i].y);
		}
		for( int  i = ret.size()-2; i > pont ; i--){
			printf("%lld %lld\n", ret[i].x, ret[i].y);
		}
		
	}
	
	
	return 0;
}

