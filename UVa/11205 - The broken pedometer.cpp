//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2146
//#tag bitmask
//#sol testar todas as possíveis configurações de leds e verificar se dois simbolos terão a mesma
//representação nessa configuração de leds

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

// #include <unordered_map>

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define F first
#define S second
#define fr(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define rep(i,n) for(int (i)=0;(i)<(n);++(i))
#define pb push_back
#define PI acos(-1)
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define mp make_pair
#define cl(x) memset(x,0,sizeof(x))
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}


int in[101][101];


int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	int t; cin >> t;
	while(t--){
		int p,n ;
		scanf("%d%d", &p, &n);
		fr(i,0,n) fr(j,0,p) scanf("%d", &in[i][j]);
		int resp = 100000;
		// db( n _ p);
		fr(mask,0,1<<p){
			// db(mask);
			map<string,bool> m; bool ok = true;
			
			fr(i,0,n) {
				string x = "";
				fr(j,0,p) if( (mask >> j) & 1 ) x.pb( in[i][j] +'0');
				// db(x);
				if( m[x] ) {ok = false; break; }
				m[x] = true;
			}
			if( ok ) {
				int aux = mask, cont = 0; 
				while(aux>0){  if( aux &1 ) cont++; aux >>= 1; }
				// db( resp _ cont);
				resp = min( resp, cont); 
			}
		}
		cout << resp << endl;
		
	}
	return 0;
}

