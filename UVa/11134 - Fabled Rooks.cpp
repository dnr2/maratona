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

const int maxn = 5010;

int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};

struct st {
	int x, y , pos;
	st ( int x = 0, int y = 0 , int pos = 0) : x(x), y(y), pos(pos) {}
	bool operator < (const st & in ) const {
		if( y == in.y ) return pos > in.pos;
		return y > in.y;
	}
};

bool cmp( st a, st b){
	return a.x < b.x;
}

int in[maxn][4];
int out[maxn][2];
st vec[maxn];


int main(){
	
	int n;
	while(cin >> n){
		if( n == 0 )break;
		REP(i,0,n){
			REP(j,0,4){
				scanf("%d", &in[i][j] );
				in[i][j]--;
			}
		}
		bool ok = true;
		REP(kk,0,2){
			REP(i,0,n){
				vec[i] = st( in[i][kk], in[i][kk+2], i );
			}
			sort( vec, vec +n , cmp);
			priority_queue< st > heap;
			int it = 0;
			REP(i,0,n){
				while( it < n && vec[it].x == i ) heap.push( vec[it++] );
				if( heap.empty()){ ok = false; goto end; }
				st cur =heap.top(); heap.pop();
				if( cur.y < i ){ ok = false; goto end; }				
				out[cur.pos][kk] = i;
			}
		}
		end :
		if(!ok){
			puts("IMPOSSIBLE");
		} else {
			REP(i,0,n){
				printf("%d %d\n", out[i][0]+1, out[i][1]+1 );
			}
			
		}
	}
	
	return 0;
}
