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
//#include <sstream>
#include <climits>

// #include <unordered_map>

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define F first
#define S second
#define REP(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define pb push_back
#define PI acos(-1)
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define mp make_pair
#define EPS 1e-9
#define INF 0x3f3f3f3f
#define IOFAST ios_base::sync_with_stdio(0);cin.tie(0)
// #define umap unordered_map

using namespace std;

const int maxn = 200010;
int n, m;
pair< int, pair<int,int> > in[maxn];
int p[maxn];

int parent( int x){
	if( p[x] == x) return x;
	return p[x] = parent( p[x]);
}

void uni(int x, int y){
	p[ parent(x) ] = parent(y);
}

int main(){
	
	while( scanf("%d%d", &n,&m) > 0 && (n || m)){
		REP(i,0,maxn) p[i] = i;
		REP(i,0,m){
			int a, b, c; scanf("%d%d%d", &a,&b,&c);
			in[i] = mp( c, mp( a, b));
		}
		sort( in, in+m);
		ll resp = 0;
		REP(i,0,m){
			if( parent( in[i].S.F) != parent( in[i].S.S) ){
				uni( in[i].S.F, in[i].S.S);
			} else {
				resp += in[i].F;
			}
		}
		cout << resp << endl;
	}
	return 0;
}



