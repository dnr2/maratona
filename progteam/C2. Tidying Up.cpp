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

const int DOTS = 6405;

int N1, N2; // Number of nodes in $M_1$ and $M_2$
int ni2[DOTS]; // The node in $M_1$ that is matched to $a\in M_2$; -1 if unmatched
int praw[DOTS], aa[DOTS], bb[DOTS], slack[DOTS];
bool va[DOTS], vb[DOTS];
vector<PII> ad1[DOTS]; // ad1[a]: Pairs (b,w) with $b\in M_2$ that are connected to $a\in M_1$ with an edge of weight $w$

bool find(int x){
	if(va[x]) return 0;
	va[x] = 1;
	for (PII t : ad1[x]) {
		int y = t.first;
		if(!vb[y] && aa[x]+bb[y]==t.second){
			vb[y] = 1;
			if(ni2[y]==-1 || find(ni2[y])) {
				praw[x]=t.second; ni2[y]=x; return 1;
			}
		}
		slack[y] = min(slack[y], aa[x]+bb[y]-t.second);
	}
	return 0;
}
int km(){
	FILL(bb,0); FILL(praw,0); FILL(ni2, -1);
	REP(i,0,N1){
		aa[i] = -INF;
		for (PII t : ad1[i])
			aa[i] = max(aa[i], t.second);
	}
	REP(x,0,N1){
		while(1){
			FILL(va,0); FILL(vb,0);
			REP(j,0,N2) slack[j] = INF;
			if(find(x)) break;
			int d = INF;
			REP(j,0,N2) if(!vb[j] && slack[j]<d) d = slack[j];
			REP(i,0,N1) if(va[i]) aa[i] -= d;
			REP(j,0,N2){
				if(vb[j]) bb[j] += d;
				else slack[j] -= d;
			}
		}
	}
	int ans = 0;
	REP(i,0,N1) ans += praw[i];
	return ans;
}

int n, m;
int in[90][90];
#define GN( i , j ) (((i)*m)+(j))/2


int main(){
	while( cin >> n >> m ){
		REP(i,0,n) REP(j,0,m) {
			scanf("%d", in[i] + j);
		}		
		N1 = N2 = n * m / 2;				
		REP(i,0,n){
			REP(j,0,m){
				if( ((i + j) & 1) == 0){
					ad1[GN(i,j)].clear();					
					if( i + 1 < n)  ad1[GN(i,j)].PB(MP(GN(i+1,j), (in[i][j] == in[i+1][j]))); 
					if( i - 1 >= 0) ad1[GN(i,j)].PB(MP(GN(i-1,j), (in[i][j] == in[i-1][j]))); 
					if( j + 1 < m)  ad1[GN(i,j)].PB(MP(GN(i,j+1), (in[i][j] == in[i][j+1]))); 
					if( j - 1 >= 0) ad1[GN(i,j)].PB(MP(GN(i,j-1), (in[i][j] == in[i][j-1]))); 
				}
			}
		}
		cout <<  (n * m / 2) - km() << endl;
	}
	return 0;
}