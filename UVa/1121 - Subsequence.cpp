//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3562
//#tag sliding window
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
#define pii pair<int,int>
#define pdd pair<double,double>
#define F first
#define S second
#define REP(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define pb push_back
#define PI acos(-1)
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define mp make_pair
#define EPS 1e-9
#define INF 0x3f3f3f3f
#define IOFAST ios_base::sync_with_stdio(0);cin.tie(0)
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

const int maxn = 100010;
int in[maxn];

int main(){
	int n, s;
	while(scanf("%d%d", &n,&s) >0 ){
		REP(i,0,n) scanf("%d", in+i);
		int b=0, e=0, resp = 0; 
		ll sum =0;
		while( sum < s && e < n){
			sum+=in[e++];	
		}
		if( sum >=s ) resp = e-b;
		while(true){
			while( b <= e && sum >= s){				
				sum-=in[b++];				
				if( sum >= s) resp = min( resp, e-b);
			}
			if( e >= n ) break;
			while( e < n && sum < s) sum+=in[e++];	
		}
		printf("%d\n", resp );
	}
	return 0;
}