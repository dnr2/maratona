//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3426
//#tag BFS 
//#tag state space search
//#sol Initially the monkey can be in any tree, let's say that the tree is marked if the monkey could be there
// in a given moment. So after you shoot in a certain tree, the next marked trees will be the ones that 
// adjacent to the ones that where marked before (excluding the one you just shot). Conside that you can 
// save the states as a bitmask, use a BFS to find a state where there is no tree marked with the shortest 
// sequence of shots. and traverse the possible shots from 1 to N to guarantee that the states that will be 
// visited are in lexicographical order. (need some bits optimization to run it fast enough)

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

const int maxn = 22;

int adj[maxn];
int mark[(1 << maxn) + 10];
int back[(1 << maxn) + 10][2];
int reach[(1 << maxn) + 10];
int opt[maxn];
int bits_id[(1 << maxn) + 10];
int n, m;

int cone( int aux ){
	int ret = 0;
	while( aux ) {
		ret += aux & 1;
		aux >>= 1;
	}
	return ret;
}

int main(){	
	vector<int> resp;
	int a, b ;
	REP(i,0,maxn) bits_id[1<<i] = i;
	
	int off = 0;
	while( scanf("%d%d", &n , &m ) > 0){
		if( !(n||m) ) break;
		resp.clear();
		REP(i,0,n+1) adj[i] = 0;
		REP(i,0,m){
			scanf("%d%d", &a , &b );
			adj[a] |= 1<<b;
			adj[b] |= 1<<a;
		}
		
		queue<int> fila;
		int all =  (1 << n ) - 1;
		fila.push( all );
		mark[all] = off + 1;
		back[all][0] = back[all][1] = -1;
		
		reach[0] = 0;
		REP(i,1,1<<n){
			reach[i] = reach[ i - ( i & -i)] | adj[ bits_id[ (i & -i) ] ];			
		}		
		while( !fila.empty()){
			int cur = fila.front(); fila.pop();
			if( cur == 0){
				while( back[cur][0] != -1 ){					
					resp.PB( bits_id[ back[cur][1] ] );
					cur = back[cur][0];					
				}
				break;
			}
			int aux = cur;
			while( aux ){
				int pos= ( aux & -aux );
				aux -= pos;
				int next = reach[cur ^ pos];
				if( mark[next] != off + 1){
					mark[next] = off + 1;
					back[next][0] = cur;
					back[next][1] = pos;
					fila.push( next );
				}				
			}
		}
		if( resp.size()){
			printf("%d:", (int)resp.size());
			for(int i = ((int) resp.size())-1; i >= 0 ; i--){
				printf(" %d", resp[i]);
			}
			puts("");
		} else {
			printf("Impossible\n");
		}
		off += 10;
	}
	
	
	return 0;
}