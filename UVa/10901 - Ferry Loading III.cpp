//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1842
//#tag queue fila
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

// #define umap unordered_map

using namespace std;

pair<ll,int> in[10010];
ll out[10010];

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	int c; cin >> c;
	while(c--){
		cl(in); cl(out);
		int n , t, m;
		char str[10];
		scanf("%d%d%d", &n, &t, &m);
		fr(i,0,m) { 
			scanf("%lld%s", &in[i].F, str); 
			if( str[0] == 'l') in[i].S = 0;
			else in[i].S = 1;
		}
		queue<int> fila[2];
		stack<int> inside;
		ll time = in[0].F; int side = 0; int p = 0;
		while(true){
			while( p < m && in[p].F <= time){
				fila[in[p].S].push(p); p++;
			}
			while(!inside.empty()){ out[inside.top()] = time; inside.pop(); } 
			while( !fila[side].empty() && inside.size() < n){
				inside.push(fila[side].front());fila[side].pop();
			}
			if( inside.empty() && fila[0].empty() && fila[1].empty() && p >= m) break;
			if( inside.empty() && fila[0].empty() && fila[1].empty()) time = in[p].F;
			else { time += t; side = (side+1)%2;}
		}
		fr(i,0,m) printf("%lld\n", out[i]);
		if( c != 0) puts("");
	}
	return 0;
}