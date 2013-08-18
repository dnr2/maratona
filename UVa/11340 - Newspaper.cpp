//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2315
//#tag string
//#sol simular, tomar cuidado com a precisão e sempre verificar com o mapa se o char realmente está //valendo algo;

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

int cost[500];
char text[10005];

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	int t, m,n;
	char aux, cur;
	scanf("%d\n", &t);
	while(t--){
		fr(i,0,500) cost[i] = 0;
		scanf("%d\n", &m);
		int in;
		map<char,bool> mapa;
		fr(i,0,m) {
			scanf("%c %d\n", &aux, &in);
			cost[aux] = in;
			mapa[aux] = true;
		}
		scanf("%d\n", &n);
		double resp = 0;
		fr(i,0,n){		
			gets(text);
			int len = strlen(text);
			// cout << text << endl;
			fr(i,0,len){
				if( cost[text[i]] > 0 && mapa[text[i]] ) resp += cost[text[i]];				
				// if( cost[text[i]] != 0  ) resp += cost[text[i]];				
			}
		}
		printf("%.2lf$\n", resp/100.0);
	}
	return 0;
}


