#include<bits/stdc++.h>

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
#define DB(x) if(0) cerr << #x << " = " << x << endl;
#define _ << ", " <<
#define MP make_pair
#define EPS 1e-9
#define INF 0x3f3f3f3f
#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0)
#define FILL(x,v) memset(x,v,sizeof(x))

// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str(); }

const int maxn = 400000;

int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};

vector<int> adj[maxn];

int dp[maxn][2];
int cont[maxn];
int n,m;
int pm;

void reccont(int no ){
	if( (int)adj[no].size() == 0) {
		cont[no] = 1; return;
	}
	REP(i,0,(int)adj[no].size()){
		int next = adj[no][i];
		reccont( next );
		DB( no _ next _ cont[next] );
		cont[no] += cont[next];
	}	
}

int rec( int no, int mm){
	if( (int)adj[no].size() == 0){		
		return 1;
	}	
	if( dp[no][mm] > -1) return dp[no][mm];	
	
	int sumd = 0, mind = m;
	int sumv = 0, minv = m;
	REP(i,0,(int)adj[no].size()){
		int next = adj[no][i];
		int ret = rec( next , mm ^ 1 );		
		mind = min(mind, cont[next] - ret);
		sumd += cont[next] - ret;
		minv = min(minv, ret);
		sumv += ret;
		
	}	
	int ret = 0;
	if( pm == 1 && mm){
		ret = (cont[no]-mind);
	} else if( pm == 1 && !mm) {
		ret =  cont[no] - (sumd + ((int)adj[no].size()) - 1);
	} else if( pm == 0 && mm ){
		ret = sumv;
	} else {
		ret = minv;
	}
	
	DB( no _ mm _ pm _ cont[no] _ ret );
	return dp[no][mm] = ret;
}


int main(){
	IOFAST();
	cin >> n;
	m = 0;
	REP(i,1,n){
		int a, b; cin >> a >> b;
		adj[a].PB( b);
	}	
	REP(i,0,n){
		if( (int)adj[i].size() == 0) m++;
	}
	FILL(cont,0);
	reccont( 1 );
	
	FILL(dp,-1); pm = 1;	
	cout << rec( 1, 1 ) << " ";
	DB( "\n" );
	FILL(dp,-1); pm = 0;
	cout << rec( 1, 1 ) << endl;
	
	return 0;
}
