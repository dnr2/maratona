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

const int MAXN = 1000000;
int arr[MAXN], val[MAXN], used[MAXN];

int main(){
	IOFAST();
	int n;
	while( cin >> n ){
		map<int,int> f, b;
		FILL(arr,0);
		FILL(used,0);
		REP(i,0,n){
			int x, y ; cin>> x >> y;
			f[y] = x;
			b[x] = y;
			val[i*2] =x;
			val[i*2+1] = y;
		}
		sort(val, val + 2*n);
		int sz = unique(val, val + 2*n) - val;
		
		int p1 = 0, p2 = b[0];
		REP(i,0,sz){
			if( b.count( val[i] ) == 1 && f.count( val[i] ) == 0){
				p1 = val[i]; break;
			}
		}
		int pos = 0, cur = p1;
		while ( pos < n ){
			arr[pos] = cur;
			cur = b[cur];
			pos+=2;
		}
		pos = 1, cur = p2;
		while ( pos < n ){
			arr[pos] = cur;
			cur = b[cur];
			pos+=2;
		}		
		REP(i,0,n) {
			cout << (( i > 0)? " ": "") << arr[i] ;
		}
		cout << endl;
	}
	
	return 0;
}