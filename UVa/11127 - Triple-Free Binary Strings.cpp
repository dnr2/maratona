//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2068
//#tag backtracking
//#sol

#include <bits/stdc++.h>


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
#define DBDB(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define MP make_pair
#define EPS 1e-9
#define INF 0x3f3f3f3f
#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0)
#define FILL(x,v) memset(x,v,sizeof(x))
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str(); }

const int maxn = 1000;

string str;
int resp;
int n;
int val[5];


void pprint(int mask, int pos){
	REP(i,0,pos){
		cerr << (mask&1);
	}
	cerr << endl;
}
void rec( int mask, int pos ){
	if( pos == n ){
		resp++; return;
	}
	REP(i,0,2){
		if( str[pos]-'0' == i || str[pos] == '*'){
			bool ok = true;
			for(int sz = 1; sz * 3 <= (pos+1); sz++){
				int nmask = (mask << 1) | i;
				REP(j,0,3){
					val[j] = nmask & ((1<<sz)-1);
					nmask >>= sz;					
				}
				if( val[0] == val[1] && val[1] == val[2]){ 
					ok =false; break; 
				}
			}
			if( ok ){
				rec( (mask << 1) | i, pos + 1 );
			}
		}
	}
}

int main(){
	int cn = 1;
	while(cin>> n && n){
		cin >> str;		
		resp = 0;
		rec(0,0);		
		printf("Case %d: %d\n", cn++, resp);
	}
	return 0;
}