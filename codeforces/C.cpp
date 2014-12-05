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

#define ll unsigned long long
#define ull unsigned long long
#define PII pair<int,int>
#define PDD pair<double,double>
#define F first
#define S second
#define REP(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define PB push_back
#define PI acos(-1)
#define DB(mod) cerr << #mod << " = " << mod << endl;
#define _ << ", " << 
#define MP make_pair
#define EPS 1e-9
#define INF 0x3f3f3f3f
#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0)
#define FILL(mod,v) memset(mod,v,sizeof(mod))

// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str(); }

const int MAXN = 100;




int main(){
	IOFAST();
	string s;
	while( cin >> s){
		int sz = s.size();	
		ll a, b;
		cin >> a >>b;
		map<int,int> pos;
		ll mod = 0;		
		REP(i,0,sz){
			mod = ((((mod%a) * (10%a)) %a) + ((s[i]-'0')%a)) % a;			
			if( mod == 0) pos[i]++;
		}		
		mod = 0; ll ten = 1 % b;
		for(int i = sz-1; i >= 1; i--){
			mod = (((((s[i]-'0')%b) * ten) % b ) + (mod%b)) % b;			
			ten = (ten * (10%b)) % b;			
			if( mod == 0 && s[i] != '0') pos[i-1]++;			
		}
		bool ok = false;
		for( map<int,int>::iterator p = pos.begin(); p != pos.end(); p++){
			if( p->S > 1){
				ok = true;
				cout << "YES" << endl;
				cout << s.substr( 0, p->F + 1) << endl << s.substr( p->F + 1, sz - p->F + 1) << endl;
				break;
			}
		}
		if( !ok ){
			cout << "NO" << endl; 
		}
		
	}
	return 0;
}