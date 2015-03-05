#include<bits/stdc++.h>

// #include <unordered_map>

#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
#define I4 pair< PII , PII >
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

const int maxn = 2100;
char in[maxn][maxn];
int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};

int n, m;

PII go( int i, int j){

	PII pos; int cont = 0;
	pos = MP(-1,-1);
	if( in[i][j] == '*') return pos;
	REP(kk,0,4){
		int ni = i + dy[kk];
		int nj = j + dx[kk];
		if( ni < 0 || ni >= n || nj < 0 || nj >= m ) continue;
		if( in[ni][nj] == '.'){
			pos = PII( ni, nj );
			cont++;
		}
	}
	if( cont == 1){
		in[i][j] = in[pos.FT][pos.SD] = '*';
		return pos;
	}
	return PII(-1,-1);
}

int main(){

	
	cin >> n >> m;
	REP(i,0,n){
		scanf("%s", in[i]);
	}
	queue< I4 > q;
	REP(i,0,n){
		REP(j,0,m){
			if( ((i + j) & 1) == 0 && in[i][j] == '.'){

				PII ret = go( i, j);
				if( ret.FT != -1){
					q.push( MP( PII(i,j), ret ) );
	
				}
			}
		}
	}
	vector< I4 > resp;
	while( !q.empty()){
		resp.PB( q.front() );
		PII a = q.front().FT, b = q.front().SD;
		q.pop();
		
		int i = b.FT, j = b.SD;

		REP(kk,0,4){
			int ni = i + dy[kk];
			int nj = j + dx[kk];
			if( ni < 0 || ni >= n || nj < 0 || nj >= m ) continue;
			if( in[ni][nj] == '.'){
				PII aux = go(ni,nj);
				if( aux.FT != -1 ){	
					q.push( MP( PII(ni,nj), aux ));
				}
			}
		}
	}
	
	REP(i,0,n){
		REP(j,0,m){
			if( in[i][j] == '.'){
				puts( "Not unique"  );
				return 0;
			}
		}
	}
	int sz = resp.size();
	REP(i,0,sz){
		PII a = resp[i].FT, b = resp[i].SD;
		if( a > b ) swap(a,b);
		// DB(a.FT _ a.SD _ b.FT _ b.SD);
		if( a.FT == b.FT){
			in[a.FT][a.SD] = '<';
			in[b.FT][b.SD] = '>';
		} else {
			in[a.FT][a.SD] = '^';
			in[b.FT][b.SD] = 'v';
		}
	}
	
	REP(i,0,n) {
		REP(j,0,m){
			printf("%c", in[i][j]);
		}
		puts("");
	}
	
	return 0;
}
