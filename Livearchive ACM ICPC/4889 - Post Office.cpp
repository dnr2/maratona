//https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=2890
//#tag implementation
//#tag ad hoc
//#sol create a test for all the mailable and use next_permutation to test all of them

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
#define EPS 1e-11
#define INF 0x3f3f3f3f
#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0)
#define FILL(x,v) memset(x,v,sizeof(x))
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str(); }

const int MAXN = 100;

bool all(double l, double h, double t){
	return (125 - EPS <= l && 90 - EPS  <= h && 0.25 - EPS  <= t);
}

bool isletter(double l, double h, double t){
	return all( l, h ,t) && ( l - EPS  <= 290 ) && ( h - EPS <= 155 ) && ( t - EPS  <= 7 );
}

bool ispacket(double l, double h, double t){
	return all( l, h ,t) && ( l - EPS  <= 380 ) && ( h - EPS <= 300 ) && ( t - EPS <= 50 ) 
		&&  ( l - EPS > 290 || h - EPS > 155 || t - EPS > 7 );
}

bool isparcel(double l, double h, double t){
	return all( l, h ,t) && ( l - EPS > 380 || h - EPS > 300 || t - EPS > 50 ) && ((2 * (h + t)) + l - EPS <= 2100 );
}

double in[5];

int main(){
	IOFAST();
	while( cin >> in[0] >> in[1] >> in[2] ){
		if( fabs( in[0] ) < EPS && fabs( in[1] ) < EPS && fabs( in[2] ) < EPS) break;		
		
		bool ok = false;
		sort( in, in + 3 , greater<int>());
		do{
			if( isletter( in[0], in[1], in[2]) ){
				cout << "letter" << endl; ok = true; break;
			} else if( ispacket( in[0], in[1], in[2] ) ){
				cout << "packet" << endl; ok = true; break;
			} else if( isparcel( in[0], in[1], in[2] ) ){
				cout << "parcel" << endl; ok = true; break;
			} 
		} while( next_permutation(in, in+3) );
		if( !ok ){
			cout << "not mailable" << endl;
		}
	}
	
	return 0;
}