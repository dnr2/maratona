//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1499
//#tag pd dinamic programming programacão dinamica
//#tag bitmask
//#sol fazemos uma pd onde o estado é uma máscara de bits que diz quais botões podemos ainda apertar
// pegamos todos os subconjuntos dessa máscara (formas de apertar os botões) e calculamos recursivamente
// o número de formas para os botões não apertados


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

#define ll unsigned long long
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
ll resp[12];
ll pd[1<<11];
ll	rec(int mask){
	if( mask == 0) return 1;
	if( ((mask-1) & mask ) == 0)  return 2;
	if( pd[mask] ) return pd[mask];
	
	int m = mask; ll ret = 1;
	while(m){
		m = (m-1)&mask;
		ret += rec(m);	
	}
	return pd[mask] = ret;
}

int main(){
	
	int n;
	fr(i,1,12) {
		cl(pd);
		resp[i] = rec((1<<i)-1) - 1;
	}
	int t; cin >> t; int caso = 1;
	while(t--){
		scanf("%d", &n);
		printf("%d %d ",caso++, n );
		cout << resp[n] << endl;
	}
	return 0;
}