//http://uva.onlinejudge.org/external/12/1248.pdf
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
#define EPS 1e-9
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

int in[1010][3];

int main(){
	
	int ca; cin >> ca;
	while(ca--){		
		int n;
		scanf("%d", &n);
		fr(i,0,n){
			scanf("%d%d%d", &in[i][0], &in[i][1], &in[i][2]);
		}
		
		ll resp =0;
		int aux;
		fr(i,0,n){
			if( i > 0 && in[i-1][0]	<= in[i][0] && in[i][1] > 0){
				aux = min( in[i][2], in[i-1][1]);
				in[i][2] -= aux; in[i-1][1] -= aux;
				resp += aux * in[i-1][0];
			}
			aux = min( in[i][2], in[i][1]);
			in[i][2] -= aux; in[i][1] -= aux;
			resp += aux * in[i][0];
			int j = i -1;
			while( j >= 0 && in[i][2] > 0){
				aux = min( in[i][2] , in[j][1]);
				in[i][2] -= aux; in[j][1] -= aux;
				resp += aux * in[j][0];
				j--;		
			}
		}
		printf("%lld\n", resp);
	}
	return 0;
}