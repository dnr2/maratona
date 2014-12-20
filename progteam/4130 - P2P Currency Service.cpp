//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2131
//#tag graph / grafos
//#tag matching / emparelhamento
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
#define PSS pair<string,string>
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

#define DOTS 500

int N1, N2;
vector<int> ad1[DOTS];
int ni1[DOTS];
int ni2[DOTS];
bool vis[DOTS];

bool visit(int i) {
	if (vis[i])
		return false;
	vis[i] = true;
	REP(it,0,(int)ad1[i].size()){
		int k = ad1[i][it];
		if (k != ni1[i] && (ni2[k] == -1 || visit(ni2[k]))) {
			ni1[i] = k;
			ni2[k] = i;
			return true;
		}
	}
	return false;
}

int solve() {
	fill_n(ni1, N1, -1);
	fill_n(ni2, N2, -1);
	int numpairs = 0, pv;
	do {
		pv = numpairs;
		fill_n(vis, N1, false);
		REP(i,0,N1)
			if (ni1[i] == -1)
				numpairs += visit(i);
	} while(numpairs != pv);
	return numpairs;
}

const int MAXN = 110;

int main(){
	IOFAST();
	
	int cn; cin >> cn;
	while( cn--){
		int n; cin >> n;
		map< string , int > index[2];
		map< PII, vector<int> > mapa;
		set< PII > ex;
		REP(i,0,DOTS) ad1[i].clear();
		
		int num1 = 0,num2 = 0;
		string in[3];
		REP(i,0,n){
			REP(j,0,3) cin >> in[j]; 
			if( index[0].count(in[0]) == 0) index[0][in[0]] = num1++;
			REP(j,1,3) if( index[1].count(in[j]) == 0) index[1][in[j]] = num2++;
			int a = index[0][in[0]], b = index[1][in[1]], c = index[1][in[2]];
			mapa[ MP( b, c) ].PB( a );
			if( b > c ) swap( b, c );
			ex.insert( MP( b, c) );
		}
		N1 = N2 = index[0].size() + 1;		
		for( set< PII >::iterator it = ex.begin(); it != ex.end(); it++ ){
			PII p1 = *it;
			PII p2 = MP( p1.SD, p1.FT);
			vector<int> & m1 = mapa[p1], & m2 = mapa[p2];
			int s1 = m1.size(), s2 = m2.size();			
			if( s1 > 0 && s2 > 0){
				REP(i,0,s1){
					REP(j,0,s2){
						if( m1[i] != m2[j]){
							ad1[m1[i]].PB(m2[j]);
							ad1[m2[j]].PB(m1[i]);
						}
					}
				}
			}
		}		
		cout << (solve()/2)	<< endl;
	}	
	
	return 0;
}