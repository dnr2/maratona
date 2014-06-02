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



int main(){
	
	ull a; int b;
	while( cin >> a >> b){		
		ull tmp = a;
		vector<int> v;
		while( tmp > 0){
			v.pb( tmp % 10);
			tmp /= 10;
		}
		int sz = v.size();
		REP(i,0,sz/2) swap( v[i], v[sz-i-1]);
		REP(i,0,sz){
			int pos = i;
			REP(j,i+1,sz){
				if( v[j] > v[pos] && b >= j - i){
					pos= j;				
				}				
			}
			int val = v[pos];
			v.erase( v.begin() + pos);
			v.insert( v.begin() + i , val);
			b -= pos - i;
			if( b == 0) break;
		}
		REP(i,0,sz/2) swap( v[i], v[sz-i-1]);
		ull resp = 0, ten = 1;
		REP(i,0,sz){
			resp += ten * ((ull) v[i]);
			ten *= 10;
		}
		cout << resp << endl;
	}
	return 0;
}