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
#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0)
#define FILL(x,v) memset(x,v,sizeof(x))
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str(); }

const int MAXN = 600;
int n;
int in[MAXN];
int dp[MAXN][MAXN];
int pos[MAXN];
bool used[MAXN];

int rec(int l, int r){
	if( l <= r) return 0;
	if( dp[l][r] != -1) return dp[l][r];
	int ret = INF;
	// -----------------
	int a = in[l], b = *min_element(in+1,in+r+1);
	FILL(pos,-1); FILL(used,false); 
	vector<int> st;
	REP(i,l,r+1){
		pos[in[i]] = i-l+1;
		if( i> l ) st.pb( in[i]);
	}
	sort(st.begin(), st.end(),greater<int>());
	int pt = 0;
	REP(i,0,(int)st.size()){
		pt = i+1; 
		if( st[i] == b) break;
	}
	//	-----------------
	REP(i,l,r){
		int aux= rec( l,i) + rec( i+1,r);		
		ret = min( aux , ret) + (r-l+1) - pos[max(a,b)];
		a = min( a, in[i]);
		used[in[i]] = true;
		if( b == in[i]){
			while( pt < (int)st.size()){			
				b = st[pt++];				
				if( !used[st[pt]] ) break;
			}
		}
	}
	return dp[l][r] = ret;
}


int main(){
	while(cin >> n){
		REP(i,0,n) scanf("%d", in+i);
		int resp[2] = {0,0};
		REP(t,0,2){
			if( t == 1) reverse( in, in + n);			
			FILL(dp,-1);
			set<int> s;
			int m = 0, ini = 0;
			db(t);
			REP(i,0,n+1){				
				if( i == n || s.count(in[i]) == 1 ){
					
					if( m != (int)s.size()){ db( m _ s.size()); resp[t] = INF; break; }
					// resp[t] += rec( ini, i-1);
					db( ini _ (i-1));
					m = 0; ini = i;	s.clear();		
				}
				db( i _ in[i]);
				m = max( m , in[i]);
				s.insert(in[i]);				
			}			
		}
		if( resp[0] == INF && resp[1]  == INF) cout << "impossible" << endl;
		else cout << min(resp[0], resp[1]) << endl;
	}
	return 0;
}