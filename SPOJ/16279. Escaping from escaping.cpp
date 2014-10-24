//http://www.spoj.com/problems/TAP2013E/
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

const int MAXN = 500010;
char str[MAXN];
bool mark[MAXN];

int main(){
	
	int n; cin >> n;
	REP(cn,0,n){
		scanf("%s", str);
		int len = strlen( str );
		int pot = 2;
		REP(i,1,20){
			REP(j,0,(1<<i)+1) mark[j] = false;
			int val = 0;
			REP(j,0,i) val += (str[j]-'0') << j;			
			mark[val] = true;
			REP(j,i,len){
				val >>= 1;
				val += (str[j]-'0') << (i-1);
				mark[val] = true;
			}
			bool end = false;
			REP(j,0,pot){
				if( !mark[j] ){
					printf("%d\n", i );
					end = true;
					break;
				}
			}			
			if( end ) break;
			pot *= 2;
		}
	}
	return 0;
}