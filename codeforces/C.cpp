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

const int MAXN = 600000;


ll arr[MAXN];
ll suml[MAXN];
ll sumr[MAXN];
ll cont[MAXN];

int main(){
	IOFAST();
	ll n; 
	while( cin >> n ){
		ll sum = 0;
		
		REP(i,0,n){ 
			cin >> arr[i];
			sum += arr[i];
		}
		ll s = sum / 3; //TODO ll?
		
		REP(i,0,n){
			suml[i] = arr[i] + ((i > 0)? suml[i-1] : 0);		
			sumr[n-i-1] = arr[n-i-1] + ((i > 0)? sumr[n-i] : 0);			
		}
		REP(i,0,n){
			cont[n-i-1] = ((sumr[n-i-1] == s)? 1 : 0) + ((i > 0)?cont[n-i] : 0 );
		}
		if( sum % 3 != 0 || n < 3) cout << 0 << endl;
		else {			
			ll resp = 0;			
			REP(i,0,n){
				if( i + 2 == n) break;
				if( s == suml[i] ){
					resp += cont[i+2];
				}
			}
			cout << resp << endl;
		}
	}
	return 0;
}