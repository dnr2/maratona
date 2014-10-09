//https://www.urionlinejudge.com.br/judge/en/challenges/view/21/5
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

const int MAXN = 100000;

bool si[MAXN];
int pri[MAXN];
int plen = 0;
vector<int> v[2];

int main(){
	REP(i,2,MAXN) { 
		if( si[i] ) continue;
		si[i] = true; pri[plen++] = i;
		for(int j = i + i; j < MAXN; j += i) si[j] = true;
	}
	
	int a,b,x,y;
	while(scanf("%d%d", &a, &b ) > 0){
		x = y = 1;
		REP(i,0,plen){
			while( a % pri[i] == 0 && b % pri[i] == 0 ){
				a /= pri[i]; b /= pri[i];
			}
			while( a % pri[i] == 0 ){
				x *= pri[i], a /= pri[i];
			}
			while( b % pri[i] == 0){
				y *= pri[i], b /= pri[i];
			}	
			if( a < pri[i] && b < pri[i] ) break;
		}
		if( a != b ){
			if( a > 1 ) x *= a;
			if( b > 1 ) y *= b;
		}
		cout << (y + x) * 2 << endl;
	}
	return 0;
}