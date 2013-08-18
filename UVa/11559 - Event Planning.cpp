//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2595
//#tag ad hoc
//#sol pegar o hotel que abriga todos os n participantes e que tenha menor custo

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

int price[20];
int beds[20][20];

int main(){
	// freopen("out.txt", "w", stdout);
	
	int n,b,h,w;
	int a;
	while(scanf("%d%d%d%d", &n,&b,&h,&w) >0){
		cl(price); cl(beds);
		int pr = 10000000;
		fr(i,0,h){
			scanf("%d", price+i);
			fr(j,0,w){
				scanf("%d", &beds[i][j]);
				if( beds[i][j] >= n) pr = min( pr, price[i]);
			}
		}
		
		if( n * pr <= b) {
			cout << (n * pr) << endl;
		} else {
			puts("stay home");
		}
	}
	return 0;
}
