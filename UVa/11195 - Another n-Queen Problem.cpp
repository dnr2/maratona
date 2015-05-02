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

const int maxn = 20;
int cont, allset, n;
int used[maxn];

void rec( int cm, int ldm, int rdm , int lin){
	if( lin == n){ cont++; return; }
	int aval = allset & (~(cm|ldm|rdm));
	while( aval ){
		int pos = aval & -aval;
		aval -= pos;
		if( pos & used[lin] ) continue;
		rec( cm | pos, (ldm|pos) << 1, (rdm|pos) >> 1, lin + 1);
	}
}

char str[maxn];

int main(){	
	int cn = 1;
	while( scanf("%d", &n) > 0 && n){		
		REP(i,0,n){
			scanf("%s", str);
			used[i] = 0;
			REP(j,0,n){
				if( str[j] == '*') used[i] |= 1 << j;
			}
		}
		cont = 0; allset = (1<<n)-1;
		rec( 0, 0, 0, 0 );
		printf("Case %d: %d\n", cn++, cont);
	}
	
	return 0;
}