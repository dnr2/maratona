//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2807
//#tag implementation 
//#tag ad hoc
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

const int MAXN = 1000;

int in[MAXN], mark[MAXN];

int main(){
	IOFAST();
	int N, B;
	while( cin >> N >> B){
		if( N==0 && B == 0) break;
		FILL(mark,0);
		REP(i,0,B){
			cin >> in[i];
		}
		REP(i,0,B){
			REP(j,0,B){
				mark[ abs(in[i]-in[j]) ] = 1;
			}
		}
		bool ok = true;
		REP(i,0,N+1){
			if( mark[i] == 0) ok = false;
		}
		cout << ((ok)?"Y":"N" ) << endl;
	}
	
	return 0;
}