//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3879
//#tag pd dinamic programming
//#tag math matematica
//#tag combinatorics combinatoria
//#sol usar uma pd com os estados: quais valores já usei (2^10) e quantas vezes girou a roleta
// sol by stor

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

using namespace std;

int passo = 0;
int ps[1<<11][11]; 
ll pd[1<<11][11];
int a,b,c;

ll rec(int mask , int m){
	if( ps[mask][m] == passo) return pd[mask][m];
	ps[mask][m] = passo;
	ll ret= 0;
	if( m == b){
		ll aux = mask;
		while(aux > 0) {
			ret += (aux & 1);
			aux >>=1;
		}
		return pd[mask][m] = (ret == c)?1:0;
	}
	fr(i,0,a){
		ret += rec( mask | (1<<i) , m+1);
	}
	return pd[mask][m] = ret;
}

ll gdc( ll x, ll y){
	ll aux;
	while(y>0){
		aux = y;
		y = (x % y);
		// cout << "=> " << x << " " << y << " " << aux << endl;
		x = aux;
	}
	return x;
}

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	int t; cin >> t;
	cl(ps); cl(pd);
	while(t--){
		passo++;
		scanf("%d%d%d", &a, &b, &c);
		ll ret = rec( 0,0);
		ll pot = 1; fr(i,0,b) pot *= a;
		ll div = gdc( ret, pot );
		// cout << ret << " " << pot << " " << div << endl;
		if( ret == 0 ) puts("0");
		else if(ret == pot) puts("1");
		else {
			cout <<  (ret/div) << "/" << (pot/div) << endl;
		}
	}
	
	return 0;
}