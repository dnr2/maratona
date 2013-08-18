//http://www.spoj.pl/problems/ABCD/
//pd dinamic programming

#include <algorithm> 
#include <cctype> 
#include <cmath> 
#include <cstdio> 
#include <cstdlib> 
#include <cstring> 
#include <deque> 
#include <iostream> 
#include <list> 
#include <map> 
#include <numeric> 
#include <queue> 
#include <set> 
#include <sstream> 
#include <stack> 
#include <string> 
#include <vector> 

using namespace std;

#define MAXN 100205
#define pii pair<int,int>
#define F first
#define S second
#define pb push_back
#define cl(a) memset(a, 0, sizeof(a))
#define FOR(i,j,k) for (int (i) = (j); (i)<(k); (i)++)

int n, pd[6][MAXN], choice[MAXN], cont[6];
pii aux[6];
char s[MAXN];

bool cmp(pii a, pii b){
	return a.F < b.F;
}

int solve(int prev, int pos) {
	if( pd[prev][pos] ) return pd[prev][pos];
	if (pos == 2*n) {
		if(cont[0] == cont[1] && cont[1] == cont[2] && cont[2] == cont[3]) return 1;
		else return 2;
	}
	
	for (int i = 0; i < 4; i++) if (cont[i] > n) return 2;
	
	if (pd[prev][pos] == 0) {
		for(int i=0;i<4;i++){
			aux[i].F = cont[i];
			aux[i].S =i;
		}
		sort(aux,aux+4,cmp);
		int i;
		for (int j = 0; j < 4; j++) {
			i = aux[j].S;
			if (i == prev || i == s[pos]-'A') continue;
			if (cont[i] == n) continue;
			cont[i]++;
			pd[prev][pos] = solve(i, pos+1);
			cont[i]--;
			
			if (pd[prev][pos] == 1) {
				choice[pos] = i;
				cont[i]++;
			}
		}
	}
	return pd[prev][pos];
}

int main() {
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	while(scanf("%d", &n) != EOF) {
		cl(cont);
		scanf("%s", s);
		
		for( int i=0;s[i];i++) cont[s[i]-'A']++;
		
		solve(5,0);
		FOR(i, 0, 2*n) printf("%c", choice[i]+'A');
		puts("");
	}
	
	return 0;
}
