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

const int MAXN = 500000;
ll ten[20];
ll resp[MAXN];
int n, qsz, sz;
ll val;
string str;;

ll calcnval(ll mid){
	ll nval = 0;
	for( int i = sz-1; i >= 0; i--){
		ll digit = 0;
		if( str[i] == '?' ){
			digit = mid % 10;
			mid /= 10;
		} else {
			digit = str[i]-'0';
		}
		nval += digit * ten[sz-i-1];		
	}
	return nval;
}

int main(){
	IOFAST();
	ten[0] = 1;
	REP(i,1,11) ten[i] = ten[i-1] * 10;
	while( cin >> n ){
		val = 0;
		bool ok = true; int it;
		for( it = 0; it < n; it++){
			cin >> str;		
			qsz = 0, sz = str.size();
			REP(i,0,sz) if( str[i] == '?') qsz++;			
			if( qsz > 0){
				ll lo = ten[qsz-1] - 1, hi = ten[qsz] -1, mid; // TODO
				if( str[0] != '?' ) lo = -1; // can have leading 0;	
				ll nval = 0;
				while( lo + 1 < hi ){
					mid = (lo+hi)/2;
					nval = calcnval( mid );
					if( nval > val ) hi = mid;					
					else lo = mid;					
				}
				nval = calcnval( hi );
				if( nval > val ){					
					resp[it] = nval;
					val = nval;
				} else {
					ok = false; break;
				}
			} else {
				if( atoi(str.c_str()) > val ){
					val = atoi(str.c_str());
					resp[it] = val;
				} else {
					ok = false; break;					
				}
			}
		}
		if( ok ){
			cout << "YES" << endl;
			REP(i,0,n){
				cout << resp[i] << endl;
			}
		} else {
			cout << "NO" << endl;
			REP(i,it+1,n) cin >> str;
		}	
	}
	return 0;
}