//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=4018
//#tag number theory
//#sol temos que x - y - 2 = m*k, logo m deve ser divisor de (x - y - 2) e maior que y

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


int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	int t; cin >>t;
	while(t--){
		ll x, y;
		cin >> x >> y;
		y -= 2;
		if( y == x ){ cout << (x+1) << endl; continue; }
		ll num = x - y; ll resp = x + y + 1; bool achou = false;
		for( ll i = 1; i*i <= num; i++){
			if( num % i == 0){
				if( i > y) { resp = min( resp, i); achou = true; }
				if( num/i > y){ resp = min(resp, num/i); achou = true; }
			}
		}
		if( achou )cout << resp << endl;
		else puts("Impossible") ;
	}
	return 0;
}