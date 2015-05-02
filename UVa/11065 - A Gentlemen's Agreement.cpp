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

const int maxn = 70;

int  n, m;
ll allbits; 
int best, cont;

ll adj[maxn];

void rec( int u, ll used, int dep){
	if( used == allbits ){
		cont++; if( best < dep ) best = dep;
	} else {
		REP(v,u,n){
			if( (used & (1LL << v )) == 0){
				rec( v, used | adj[v] | (1LL << v ) , dep+1);
			}
		}
	}
}

int main(){
	int T; scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &m );
		allbits = (1LL << n)-1;
		REP(i,0,n) adj[i] = 0;
		REP(i,0,m){
			int a, b; scanf("%d%d", &a,&b);
			adj[a] |= 1LL << b;
			adj[b] |= 1LL << a;
		}
		best = cont = 0;
		rec(0,0,0);
		printf("%d\n%d\n",cont, best );
	}	
	return 0;
}