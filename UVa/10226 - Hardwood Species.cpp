//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1167
//#tag map mapa
//#sol usar um mapa para contar o número de ocorrência de cada árvore e depois calcular a porcentagem

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

char str[50];

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	int t; scanf("%d\n\n", &t);
	while(t--){
		map<string,int> mapa;
		int cont = 0;
		while( gets(str) ){
			if( str[0] ){
				mapa[string(str)]+=100;
				cont++;
			} else {
				break;
			}
		}
		double c = ((double) cont);
		for( map<string,int>::iterator it = mapa.begin(); it != mapa.end();it++){
			cout << it->F;
			printf(" %.4lf\n" , ((double)it->S) / c);
		}
		if(t) puts("");
	}
	return 0;
}