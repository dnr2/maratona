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

int main(){
	int cn; string x, y;
	while( cin >> cn && cn != -1){
		cin >> x >> y;
		int a = 0, b = 0, c = 0;
		map<int,int> mapa;
		int sz = x.size();
		REP(i,0,sz){
			if( mapa[x[i]] == 0) c++;
			mapa[x[i]] = 1;
		}
		sz = y.size();
		REP(i,0,sz){
			if( mapa[y[i]] == 1){ a++; mapa[y[i]] = 0; }
			else { b++; }
			if( b == 7 || a == c ) break;
		}
		printf("Round %d\n", cn);
		if( b >= 7){
			printf("You lose.\n");
		} else if( a == c){
			printf("You win.\n");
		} else {
			printf("You chickened out.\n");
		}
	}	
	return 0;
}