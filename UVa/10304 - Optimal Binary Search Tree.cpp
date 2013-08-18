//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1245
//#tag dinamic programming programação dinâmica pd
//#sol Usar pd de duas dimensões para armazenar resultao ótimo da sub-arvore entre x e y
//solução ótima a partir da sub-árvore esquerda é a soma das frequências dos elementos à direita
//mais os da direita mais as as soluções ótimas já calculadas
//caso base é quando há um ou nenhum nó na árvore , onde o resultado é zero

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

ll pd[253][253];
ll sum[253][253];
ll in[253];

ll rec(int x , int y){
	if( x>=y ) return 0;
	if(pd[x][y]) return pd[x][y];
	ll best = 0x3F3F3F3F;
	fr(i,x,y+1){
		ll a = rec( x, i-1), b = rec( i+1, y);
		best = min( best , sum[x][i-1] + sum[i+1][y] + a + b);
	}
	return pd[x][y] = best;
}

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	int n;
	while(cin >> n) {
		cl(pd); cl(sum);
		fr(i,0,n) scanf("%d", in+i+1);
		fr(i,1,n+1) fr(j,i,n+1) sum[i][j] = sum[i][j-1] + in[j];
		cout << rec( 1, n) << endl;
	}
	return 0;
}