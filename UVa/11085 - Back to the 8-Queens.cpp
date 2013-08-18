//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2026
//#tag 8 queens puzzle
//#tag backtracking
//#sol gerar todas as possíveis configurações do problema das oito rainhas e depois 
// comparar cada uma das 92 configurações geradas com a desejada para ver quantos moviementos são
// necessários ( atenção pois a entrada eh 1-based)

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

int pos[10];
int conf[100][8], cont = 0;
int act[8];

void rec(int dep){
	if( dep == 8) {
		fr( i,0,8) {
			conf[cont][i] = act[i];
			// printf("%d ", act[i]);			
		}
		// cout << endl;
		cont++; return;
	}
	fr(i,0,8){		
		bool ok = true;
		fr(j,0,dep){
			if( i == act[j] || abs( i -act[j]) == abs( dep - j)  ) ok = false; 
		}
		if(!ok) continue;
		act[dep] = i;
		rec(dep+1);			
	}	
}

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	rec(0);
	int caso = 1;
	while(scanf("%d", pos) >0) {
		fr(i,1,8) scanf("%d", pos+i);
		int resp = 1000;
		fr(i,0,cont){
			int aux = 0;
			fr(j,0,8){
				if((pos[j]-1) != conf[i][j]) aux++;				
			}			
			resp = min(resp,aux);
		}
		printf("Case %d: %d\n", caso++, resp);
	}
	return 0;
}