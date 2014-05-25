//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1742
//#tag Djkstra
//#tag graph grafos
//#sol use djkstra where the nodes are represented by the floor number and the elevator number. 
//be careful because the graph can have multiple beginning states (elevators that reach floor 0)

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

// #define umap unordered_map

using namespace std;

const int maxn = 200;
int n, k;

bool adj[10][maxn];
int dist[10][maxn];
int cost[10];

int main(){
	
	while( scanf("%d%d", &n,&k) > 0 ){		
		memset( adj, 0 ,sizeof( adj));
		REP(i,0,10) REP(j,0,maxn) dist[i][j] = INF;
		REP(i,0,n) scanf("%d", cost+ i );
		string str; getline( cin, str);
		REP(i,0,n){
			getline( cin, str);
			stringstream ss(str);			
			int a;
			while( ss >> a){				
				adj[i][a] = true;
			}
		}
		priority_queue< pair< int, pair<int,int> > > heap;
		REP(i,0,n) {
			if( adj[i][0] ){
				heap.push( mp( 0, mp( i, 0) ) );
				dist[i][0] = 0;				
			}
		}
		int resp = -1;
		while( !heap.empty()){
			pair< int, pair<int,int> > cur = heap.top(); heap.pop();
			int x = cur.S.F;
			int y = cur.S.S;			
			if( y == k) { resp = dist[x][y]; break ;}
			REP(i,0,100){				
				if( adj[x][i] && dist[x][i] > cost[x] * abs(i -y) + dist[x][y] ){
					dist[x][i] = cost[x] * abs(i - y) + dist[x][y];
					heap.push( mp( -dist[x][i], mp( x, i)) );
				}
			}
			REP(i,0,n){
				if( adj[x][y] && adj[i][y] && dist[i][y] > dist[x][y] + 60 ){
					dist[i][y] = dist[x][y] + 60;
					heap.push( mp( -dist[i][y], mp( i, y)) );
				}
			}
		}
		if( resp >= 0){
			printf("%d\n", resp);
		} else {
			puts("IMPOSSIBLE");
		}
	}
	return 0;
}



