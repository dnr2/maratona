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

const int MAXN = 64800;

char s[10];
PII in[MAXN], sum[4];;

int main(){
	
	int n;
	while(scanf("%d", &n) > 0 && n){
		FILL(sum,0);
		REP(i,0,n){
			int a, b, c, val = 0;;
			scanf("%d:%d:%d %s", &a, &b, &c, &s);
			if( s[0] == 'E') val = 1;
			if( s[0] == 'X') val = 2;
			sum[val]++;
			in[i] = MP( a * (60*60) + b * 60 + c , val);
		}
		sort( in, in + n);
		REP(i,0,n){
			if( in[i] == 0){
				if( sum[1] < sum[2]) in[i] = 1, sum[1]++; 
				else in[i] = 2, sum[2]++;
			}
		}
		int resp =0, val = 0, stacksz = 0;
		REP(i,0,n){
			if( in[i] == 1){			
				stacksz++; val = 0;
			} else {
				stacksz--; val++;
			}
			resp = max(resp, val);
		}
		cout << resp << endl;
		
	}
	
	return 0;
}