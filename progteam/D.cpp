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
#define F first
#define S second
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

const int MAXN = 110;


double in[MAXN];

int main(){
	int n; 
	while(cin >> n){
		REP(i,0,n) cin >> in[i];
		sort(in,in+n,greater<double>());		
		double resp = in[0];
		DB(resp);
		REP(i,1,n){
			double nresp = 0;
			REP(j,0,i+1){
				double aux = in[j];
				REP(k,0,i+1){
					if( k != j) aux *= (1-in[k]);
				}
				nresp += aux;
			}
			if( nresp > resp) resp = nresp;
			else break;
		}
		printf("%.10lf\n", resp) ;
	}
	return 0;
}