//https://www.urionlinejudge.com.br/judge/en/challenges/view/21/5
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

const int MAXN = 100000;

bool si[MAXN];
int pri[MAXN];
int plen = 0;
vector<int> v[2];
int in[2];

int main(){
	REP(i,2,MAXN) { 
		if( si[i] ) continue;
		si[i] = true; pri[plen++] = i;
		for(int j = i + i; j < MAXN; j += i) si[j] = true;
	}
	while(scanf("%d%d", in, in+1 ) > 0){
		
		REP(i,0,2){
			v[i].clear();
			REP(j,0,plen){
				while( pri[j] <= in[i] && in[i] % pri[j] == 0  ){
					v[i].PB(pri[j]);
					in[i] /= pri[j];
				}	
				if( pri[j] > in[i] ) break;
			}
			if( in[i] > 1 ) v[i].PB(in[i]);
		}
		int x =0, y =0;
		int a = 1, b = 1;
		while( x < (int) v[0].size() && y < (int) v[1].size()){
			if( v[0][x] == v[1][y] ) x++, y++;
			else if( v[0][x] < v[1][y]) a *= v[0][x], x++;
			else if( v[0][x] > v[1][y]) b *= v[1][y], y++;
		}
		
		while( x < (int) v[0].size()){
			a *= v[0][x]; x++;
		}
		while( y < (int) v[1].size()){
			b *= v[1][y]; y++;
		}		
		cout << (a + b) * 2 << endl;
	}
	return 0;
}