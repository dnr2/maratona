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

const int MAXN = 100;

int arr[3][5001], p[3];

int main(){
	IOFAST();
	int n;
	while( cin >> n){		
		FILL(arr,0);
		FILL(p,0);
		int w = INF;
		REP(i,0,n){
			int a; cin >> a;
			a--;
			arr[a][p[a]++] = i+1;
		}
		REP(i,0,3) w = min( w, p[i]);
		cout << w << endl;
		REP(i,0,w){
			REP(j,0,3){
				if( j > 0) cout << " " ;
				cout << arr[j][i];
			}
			cout << endl;
		}
	}
	
	return 0;
}