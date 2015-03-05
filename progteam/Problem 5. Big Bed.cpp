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

const int maxn = 504;

vector<int> adj[maxn];
int hh[maxn];
int ww[maxn];

bool mark[maxn];

int n;

bool go(int h, int w){	
	
	if( hh[0] < h || ww[0] < w ) return false;
	memset(mark,0,sizeof(mark));
	queue<int> fila;
	fila.push( 0);
	mark[0] = true;
	int ok = false;
	while( !fila.empty()){
		
		int cur =fila.front(); fila.pop();
		if( cur == n-1) {
			ok = true; break;
		}
		REP(i,0,(int) adj[cur].size()){
			int v = adj[cur][i];
			if( mark[v] || hh[v] < h || ww[v] < w) continue;
			mark[v] = true;
			fila.push( v );
		}
	}
	return ok;
}

int arr[3];

int main(){
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	
	int a, b, c;
	while( scanf("%d%d%d", &a, &b, &c ) > 0){
		scanf("%d", &n);
		
		REP(i,0,n) adj[i].clear();
		
		REP(i,0,n){
			int w, h, k;
			scanf("%d%d%d", &w, &h, &k);
			hh[i] = h; ww[i] = w;
			REP(j,0,k){
				int next; scanf("%d", &next);
				next--;
				adj[i].PB(next);
			}
		}
		
		int lo = -1, hi = maxn, mid;
		while( lo + 1 < hi ){
			mid = (lo+hi) / 2;			
			if( go( mid, mid ) ) lo = mid;
			else hi = mid;
		}
		
		int minhw = lo;
		
		lo = -1, hi = maxn;
		while( lo + 1 < hi ){
			mid = (lo+hi) / 2;			
			if( go( minhw, minhw + mid ) ) lo = mid;
			else  hi = mid;
		}
		
		int addw = lo;
		
		lo = -1, hi = maxn;
		while( lo + 1 < hi ){
			mid = (lo+hi) / 2;			
			if( go( minhw + mid, minhw ) ) lo = mid; 
			else hi = mid;			
		}
		
		int addh = lo;
		
		PII ans;
		if( addw < addh){
			ans = PII(minhw, minhw + addh);
		} else {
			ans = PII(minhw + addw, minhw);
		}
		
		arr[0] = a, arr[1] = b, arr[2] = c;
        sort(arr, arr+3);
        int maxV = 0.0;
        int maxH = 0, maxW = 0, maxL = 0;
        do {
            int H = min(arr[0], ans.FT);
            int W = min(arr[1], ans.SD);
            int L = arr[2];
            if(maxV < H*W*L) {
                maxV = H*W*L;
                maxH = H;
                maxW = W;
                maxL = L;
            }
        }while(next_permutation(arr, arr+3));
		
		arr[0] = maxH, arr[1] = maxW, arr[2] = maxL;
		sort( arr, arr + 3 );
        printf("%d %d %d\n", arr[0], arr[1], arr[2]);
		
	}
	
	return 0;
}