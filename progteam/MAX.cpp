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

const int maxn = 200000;

int in[maxn];
int m[maxn];

int main(){
		
	int n; 
	while( cin >> n){
		FILL(in,0); FILL(m,0);
		REP(i,0,n) scanf("%d", in + i);
		
		int fresp = -INF;
		
		REP(kk,0,2){
			if( kk == 1) reverse( in, in+n);
			int resp = -INF;		
			m[n-1] = 0; 
			for(int i = n-2; i >= 0; i--){
				m[i] = max( m[i+1], in[i+1]);
			}
			int meh, meh2, msf;
			meh = meh2 = msf = resp = in[0];
			REP(i,1,n){			
				meh2 = max( meh, max( meh + in[i], meh2 + in[i]));
				if( meh2 < in[i]){
					meh2 = in[i];			
				}
				meh = max( in[i], meh + in[i]);				
				if( i + 1 < n ) resp = max( resp, meh2 + m[i] );
				resp = max( resp, meh );				
			}
			fresp = max( resp, fresp);
		}
		cout << fresp << endl;
	}
	return 0;
}