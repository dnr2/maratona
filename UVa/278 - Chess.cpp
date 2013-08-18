//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=214
//#tag ad hoc
//#sol para os casos da rainha e da torre, apenas imprima min entre n e m
//para o caso dos cavalos, a melhor solução vai ser colocalos nas diagonais, ou seja, pegar metade das
//céculas, cuidado com o caso de m&1 && n&1 pq podemos pegar um a mais

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

int n, m, resp ;

int main(){
	
	int t; scanf("%d\n", &t);
	while(t--){
		char str[5], c;
		scanf("%s %d %d\n", &str, &n, &m);
		c = str[0];
		if( n < m){ int aux = n; n = m; m = aux;}		
		if( c == 'r' || c == 'Q'){
			printf("%d\n", min( n , m));
		} else if( c== 'k'){
			printf("%d\n", (n*m)/2 + (( n&1 && m&1)? 1:0));
		} else {
			printf("%d\n", ((n+1)/2) * ((m+1)/2));
		}
	}
	return 0;
}