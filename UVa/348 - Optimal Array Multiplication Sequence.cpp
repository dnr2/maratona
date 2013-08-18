//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=284
//#tag dinamic prigramming prigramação dinâmica
//#sol pd[i][j] é o estado do melhor custo para multiplicar a entrada de i até j
// se i == j é o caso base, ou seja, não precisamos multiplicar nenhuma matriz e o custo é 0
// caso contrário podemos colocar um parênteses em qualquer posição entre i e j, calculando e melhor
// custo para isso

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
#define pis pair<ll,string>
#define pll pair<ll,ll>

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

pll in[11];
pis pd[11][11];

pis rec(int ini, int fim){
	if( ini == fim){
		char aux[10]; aux[0] ='A';
		sprintf(aux+1, "%d", (ini+1));
		string ret(aux);
		return pis( 0, ret);
	}
	if( pd[ini][fim].F ) return pd[ini][fim];
	ll ret = -1, pos =0; string e = "", d = "";
	fr(i,ini,fim){
		pis a =rec(ini,i); pis b =rec( i+1,fim);
		if( ret == -1 || ret > in[ini].F * in[fim].S * in[i].S + a.F + b.F){
			ret = in[ini].F * in[fim].S * in[i].S + a.F + b.F; 
			e = a.S; d = b.S;
		}
	}
	string str = "("; str+= e; str += " x "; str += d; str+= ")";
	return pd[ini][fim] = pis( ret, str);
}

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	int n, caso = 1;
	while(scanf("%d", &n) >0 && n	){
		fr(i,0,n)fr(j,0,n){ pd[i][j].F = 0, pd[i][j].S = "";}
		fr(i,0,n) cin >> in[i].F >> in[i].S;
		pis resp = rec( 0, n-1);
		printf("Case %d: ", caso++);
		cout << resp.S << endl;
	}
	return 0;
}