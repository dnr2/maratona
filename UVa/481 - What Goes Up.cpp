//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=422
//#tag pd dinamic programming
//#tag lis longest increasing subsequence
//#sol algoritmo de lis + salvar o pai de cada posição da pd

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

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	int pd[100000], input[100000] , p[100000], pos[100000];
	int s = 0, in, cont =0; pos[0] = -1;
	while( scanf("%d", &in) >0 ) {
		input[cont] = in;
		int k = lower_bound( pd, pd+s, in) - pd;
		if( k == s) s++;
		pd[k] = in;
		pos[k] = cont;
		p[cont] = ( k > 0)? pos[k-1] : -1;
		// db( input[cont] _ pd[k] _ pos[k] _ k _ p[cont] _ s );
		cont++;
	}
	printf("%d\n-\n", s); int cur = (s>0) ? pos[s-1] : -1;
	stack<int> pilha;
	while(s--){
		pilha.push(input[cur]); cur = p[cur];
	}
	while(!pilha.empty()){
		printf("%d\n", pilha.top()); pilha.pop();
	}
	
	return 0;
}