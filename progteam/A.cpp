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
#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0)
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

struct st{
	string str;
	const bool operator < ( const st & in ) const {
		int ret1 = 0, ret2 = 0;
		REP(i,0,(int)str.size()){
			ret1 += str[i] -'A' + 1;
		}
		REP(i,0,(int)in.str.size()){
			ret2 += in.str[i] -'A' + 1;
		}
		if( ret1 == ret2) return str < in.str;
		return ret1 < ret2;
	}
};
const int maxn = 110;
st arr[maxn];

int main(){
	int T;
	cin >>T;
	bool prim = true;
	while(T--){
		int n; cin >> n;
		REP(i,0,n){
			string str;
			cin >> str;
			st cur;
			cur.str = str;
			arr[i] = cur;
		}
		sort( arr, arr+n);
		if( prim) prim =false;
		else puts("");
		REP(i,0,n){			
			cout<< arr[i].str << endl;
		}
	}
	
	
	return 0;
}