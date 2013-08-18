//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1597
//#tag max sum
//#sol apenas pegar os números maiores que zero, cuidado com o caso em que a entrada é só zero, pois a resposta é uma única linha com o '0'

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

int ant, act;

int main(){
	int n ;
	while(scanf("%d", &n) >0 && n){
		int a; bool prim = true, printed = false;
		fr(i,0,n) {
			scanf("%d", &a);
			if(a){
				if( prim) prim = false;
				else printf(" ");
				printf("%d", a); printed = true;
			}
		}
		if( !printed) puts("0");
		else puts("");
	}	
	return 0;
}