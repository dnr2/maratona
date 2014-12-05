//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4295
//#tag palindrome string
//#tag map
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

#define inf 0x3f3f3f3f
#define fr REP

#define umap unordered_map

using namespace std;
using namespace std::tr1;


template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

const int MAXN = 400000;
char str[MAXN];
const int maxchar = 52;
const ll one = 1;
int n; 

int main(){
	umap<ll,ll> f; umap<char,ll> mapa;
	while(scanf("%d%s", &n, str) > 0){		
		f.clear(); mapa.clear();
		ll charsz = 0, r1 = 0, val = 0;
		f[val] = 1;
		REP(i,0,n){
			if( mapa.count( str[i] ) == 0) mapa[str[i]] = (one << charsz), charsz++;
			val ^= mapa[str[i]];			
			f[val]++;
		}
		for( umap<ll,ll>::iterator it = f.begin(); it != f.end(); it++){
			ll sec = it->SD;
			r1 += sec * (sec - one);
			REP(j,0,charsz+1){
				val = it->FT ^ (one << j);	
				if( f.count(val) > 0){
					r1 += sec * f[val];
				}
			}
		}		
		printf("%lld\n", r1 / 2);
	}
}