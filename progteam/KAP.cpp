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

const int MAXN = 300000;

#define PIII pair<int , PII >

PIII in[MAXN];
vector< PII > adj[MAXN];

int dx[] = {-1,1};

bool cmp1(PIII a, PIII b ){
	if( a.SD.FT == b.SD.FT) return a.SD.SD < b.SD.SD;
	return a.SD.FT < b.SD.FT;
}

bool cmp2(PIII a, PIII b ){
	if( a.SD.SD == b.SD.SD) return a.SD.FT < b.SD.FT;
	return a.SD.SD < b.SD.SD;
}

int cost[MAXN];

int main(){
	
	int n;
	cin >> n;
	DB( n );
	REP(i,0,n){
		in[i].FT = i;
		scanf("%d%d" , &in[i].SD.FT, &in[i].SD.SD);
	}
	sort( in, in + n, cmp1 );
	REP(i,0,n){
		REP(j,0,2){
			int ni = i + dx[j];
			if( ni < 0 || ni >= n ) continue;
			adj[in[i].FT].PB( MP( in[ni].FT, min( abs( in[i].SD.FT - in[ni].SD.FT) , abs( in[i].SD.SD - in[ni].SD.SD) )));
		}
	}
	
	sort( in, in + n, cmp2 );
	REP(i,0,n){
		REP(j,0,2){
			int ni = i + dx[j];
			if( ni < 0 || ni >= n ) continue;
			adj[ in[i].FT ].PB( MP( in[ni].FT, min( abs( in[i].SD.FT - in[ni].SD.FT) , abs( in[i].SD.SD - in[ni].SD.SD) )));
		}
	}
	
	priority_queue<PII> heap;
	memset(cost, INF, sizeof(cost));
	
	heap.push( MP( 0, 0));
	cost[0] = 0;
	
	while(!heap.empty()){
		int c = -heap.top().FT, v = heap.top().SD;		
		heap.pop();
		if( v == n-1) break;
		int sz = adj[v].size();
		REP(i,0,sz){
			int next = adj[v][i].FT;
			if( cost[next] > c + adj[v][i].SD ){
				cost[next] = c + adj[v][i].SD;
				heap.push(MP( -cost[next], next ));
			}
		}
	}
	cout << cost[n-1] << endl;
	
	return 0;
}