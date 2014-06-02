//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1070
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
#define FOREACH(i,v) for(typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define IOFAST ios_base::sync_with_stdio(0);cin.tie(0);

// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

const int MAXN = 30;
set<int> adj[MAXN];
int in[MAXN];
int out[MAXN];
char str[10100];

int vis[MAXN];

void dfs(int x){
	if( vis[x] ) return;
	vis[x] = 1;
	FOREACH(i,adj[x]){
		dfs( *i );
	}
}

bool conected( int x ){
	fill_n( vis, MAXN, 0);
	dfs( x);
	REP(i,0,MAXN){
		if( vis[i] == 0 && (in[i] > 0 || out[i] > 0)) return false;
	}
	return true;
}

int main(){
	int T; cin >> T;
	while(T--){
		int n; scanf("%d", &n);
		fill_n( in, MAXN, 0); fill_n( out, MAXN, 0);
		REP(i,0,MAXN) adj[i].clear();
		REP(i,0,n){
			scanf("%s", str);
			int len = strlen(str);
			int a = str[0]-'a', b = str[len-1]-'a';
			out[a]++, in[b]++;
			adj[a].insert(b);
		}
		bool ok = true;
		int x=0,y=0;
		REP(i,0,MAXN){
			if( abs( in[i] - out[i]) > 1) { ok = false; break; }
			if( in[i] - out[i] == 1 ){
				x++;
				if( x > 1) { ok = false; break; }
			}
			if( out[i] - in[i] == 1 ) {
				y++;	
				if( y > 1){ ok = false; break; }
			}
		}
		if( ok ){
			ok = false;
			REP(i,0,MAXN){
				if( conected(i) ) { ok = true; break; }
			}
		}
		if( ok ) puts("Ordering is possible.");
		else puts("The door cannot be opened.");
	}
	return 0;
}