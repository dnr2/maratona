//http://www.spoj.com/problems/TAP2014B/
//#tag math matematica
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
template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

#define MAXN 1000

int main(){
	
	int T; cin >> T;
	vector<char> v;
	while(T--){
		int N; cin >> N;
		v.clear();
		while( N > 0){
			if( N % 3 == 0){ v.PB( '0'); } 
			else if( (N + 1) % 3 == 0){ v.PB('-'); N += 1; }
			else { v.PB('+'); N-=1; }
			N /= 3;
		}
		for(int i = ((int)v.size()) -1; i>= 0; i--){
			cout << v[i];
		}
		cout << endl;
	}
	
	return 0;
}
