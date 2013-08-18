//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=455
//#tag stack pilha
//#sol tentar ordenar como diz a questão

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

int in[111];

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	int n ;
	while(scanf("%d", &n ) > 0 && n){	
		while(true){
			scanf("%d", &in[0]);
			if(in[0] == 0) { puts(""); break;}
			fr(i,1,n) scanf("%d", in+i); 
			stack<int> pilha; int pont = 0;
			fr(i,1,n+1){
				pilha.push(i);
				while( !pilha.empty() && pilha.top() == in[pont]){
					pilha.pop(); pont++;
				}
			}
			if(pilha.empty()) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}