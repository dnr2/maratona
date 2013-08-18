//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3994
//#tag binary search busca binaria
//#tag pd dinamic programming
//#sol fazer uma busca binária sobre a força


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

int grid[510][510];
ll pd[510][510];
int n , m;
bool ok(int s){
	bool ret; cl(pd);
	pd[0][0] = s;
	fr(i,0,n){
		fr(j,0,m){
			if( i == 0 &&  j ==0 )continue;
			else if( i == 0 ) pd[i][j] = pd[i][j-1] + grid[i][j];
			else if( j == 0 ) pd[i][j] = pd[i-1][j] + grid[i][j];
			else pd[i][j] = max( pd[i][j-1] ,pd[i-1][j] ) + grid[i][j];
			if( pd[i][j] <= 0 ){
				pd[i][j] = -10010;
				pd[i][j] *= (500*500);
			}
		}
	}
	return pd[n-1][m-1] >= 0 ;
}


int main(){
	
	int t; cin >> t; int caso = 1; int a;
	while(t--){
		scanf("%d%d", &n, &m); int sum = 0;
		
		fr(i,0,n){
			fr(j,0,m) {
				scanf("%d", &a); 
				if( a < 0) sum -= a;
				grid[i][j] = a;		
			}			
		}
		int ini = 1, fim = sum + 1, mid, resp = 0;
		while(ini <= fim){
			if( ini == fim ){ resp = ini ; break; }
			mid = (ini+fim)/2;
			
			bool ret = ok(mid);
			if( ret) fim = mid;
			else ini = mid + 1;
		}
		printf("%d\n", resp);
	}
	return 0;
}