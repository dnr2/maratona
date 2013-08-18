//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2423
//#tag ad hoc
//#tag math matematica
//#sol gerar todos os cubos até que o intervalo entre eles seja menor que 10^4
//tentar para cada i= 0..n  tentar achar um i um j tal que j^3 - i^3 


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

int pot[1000];

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	int cont = 1, a =2;
	pot[0] = 0, pot[1] =1;
	while(pot[cont] - pot[cont-1] <= 10000) pot[++cont] = a*a*a, a++;	
	cont++;
	int n;
	while(scanf("%d", &n) >0 && n){
		bool ok = false;
		fr(i,0,cont){
			if( i > 0 && pot[i] - pot[i-1] > n ) break;
			for( int j = i + 1; j < cont && pot[j] - pot[i] <= n; j++){
				if( pot[j] - pot[i] == n) {
					printf("%d %d\n", j , i);
					ok = true; break;
				}
			}
			if( ok ) break;
		} 
		if( !ok) puts("No solution");
	}
	
	return 0;
}