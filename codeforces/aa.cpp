#include<bits/stdc++.h>

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

const int maxn = 100;

int main(){
	
	string s;
	while( cin >> s ){
		sort( s.begin(), s.end());
		int sz = s.size(); bool ok = false;
		do {
			int val = 0;
			if( s[0] == '0') continue;
			REP(i,0,sz){
				
				val *= 10;
				val += s[i] - '0';
			}
			if( val % 7 == 0) {
				cout << val << endl;
				ok = true; break;
			}
		} while( next_permutation( s.begin(), s.end()) );
		if( !ok ) cout << 0 << endl;
			
	}
	return 0;
}
