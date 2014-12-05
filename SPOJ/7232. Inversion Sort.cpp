//http://www.spoj.com/problems/INVESORT/
//#tag bfs breadth first search
//#tag bidirectional search
//#sol use bidirectional search and consider that the letters can be mapped to numbers such that all queries
//goes from (1,2,3,4,5,6,7,8,9,10) to some other state

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


#include <tr1/unordered_map>


#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
#define PDD pair<double,double>
#define FT first
#define SD second
#define REP(i,j,k) for(ll (i)=(j);(i)<(k);++(i))
#define PB push_back
#define PI acos(-1)
#define DB(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define MP make_pair
#define EPS 1e-9
#define INF 0x3f3f3f3f
#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0)
#define FILL(x,v) memset(x,v,sizeof(x))
#define umap unordered_map

using namespace std;
using namespace std::tr1;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a; return os.str(); }

const int MAXN = 100;

char str[2][100];
ll minus = -1, one = 1, digit = (1<<4)-1;
ll mask[11][11][3];
umap<ll,ll> dist[2];


ll bfs( ll start, int go){
	if( go == 0){
		if( dist[1][start] > 0) return dist[1][start] -1;
		dist[0].clear();
	}
	queue<ll> q;
	q.push(start);
	dist[go][start] = 1;
	while( !q.empty() ){
		ll cur = q.front(); q.pop();				
		ll distcur = dist[go][cur];
		REP(i,0,10){
			ll newst = cur;
			REP(j,i+1,10){
				ll a = newst & mask[i][j][0];
				ll b = newst & mask[i][j][1];
				ll c = newst & mask[i][j][2];
				newst = a | (b<<4) | (c >> ((j-i)*4));	
				if( go && dist[1][newst] == 0){
					dist[1][newst] = distcur+1;									
					if( distcur + 1 <= 5 ) q.push( newst);
				} else if( go == 0) {
					if( dist[1][newst] > 0 ) {
						return dist[1][newst] + distcur - 1;
					}
					else if(  dist[go][newst] ==0) {
						dist[go][newst] = distcur +1;			
						if( distcur +1 <= 3) q.push( newst);
					}
				}
			}
		}
	}
	return 9;
}

int main(){	
	FILL(mask,0);
	REP(i,0,10) REP(j,0,10) REP(k,0,10){
		if( k < i || k > j) mask[i][j][0] += digit << (k*4);				
		if( k >= i && k < j) mask[i][j][1] += digit << (k*4);
		if( j == k) mask[i][j][2] += digit << (k*4);
	}
	ll start = 0;
	REP(i,0,10) start += (i+1) << (i*4);
	bfs( start, 1 );
	while(scanf("%s%s", str[0], str[1]) > 0 ){		
		if( str[0][0] == '*') break;
		umap<char,ll> ma;
		REP(i,0,10) ma[str[0][i]] = i + 1;
		ll st = 0;
		REP(i,0,10) st +=  ma[str[1][i]] << (i*4);	
		cout <<  bfs( st, 0 ) << endl;
	}
	return 0;
}