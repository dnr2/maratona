#include <bits/stdc++.h>

#define REP(i,a,b) for (ll i = (a); i < (b); ++i)
#define st first
#define nd second
#define DB(x) cerr << #x << " = " << x << endl
#define _ << " " <<

using namespace std;

typedef pair<int,int> PII;
typedef long long ll;

const int maxn = 5;
ll in[maxn];
ll	adj[maxn][maxn];
ll saves, n;

void rec(ll node, ll next){

	if( node >= n - 1 ){
		ll tmp = 0;
		set<ll> s;
		REP(i,0,n){
			s.clear();
			REP(j,i+1,n){
				if( adj[i][j] != -1) s.insert( adj[i][j] );
			}
			tmp += s.size();
		}
		saves = max( saves, tmp);
	}
	else if( next >= n ){
		rec( node+1, node + 2);
	} else {
	
		REP(i,-1,min(in[node],n)){
			bool ok = true;
			REP(j,0,node){			
				if( adj[j][node] != -1 && adj[j][node] == adj[j][next]) {
					ok = false; break;
				}
			}
			if( ok ){
				adj[node][next] = i;	
				rec( node, next + 1);
				adj[node][next] = -1;		
			}
		}
	}
}

int main() {
    while( cin >> n ){
		ll sum = 0;
		memset(adj,-1,sizeof(adj));
		REP(i,0,n){
			cin >> in[i];
			sum += in[i];
		}
		sort( in, in + n, greater<int>() );
		rec( 0, 1 );
		cout << (sum - saves) << endl;
    }
    return 0;
}
