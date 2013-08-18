//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=614
//#tag string
//#tag automatos
//#sol usar pilha para simular automato para resolver a seguinte linguagem: 
//S -> [S] | (S) | SS | ""

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

char str[130];

int main(){
	
	int t,n; scanf("%d\n", &t);	
	while(t--){
		gets(str);
		n = strlen(str);
		stack<char> pilha; bool ok = true;
		fr(i,0,n){
			if(str[i] == '(' || str[i] == '['){
				pilha.push(str[i]);
			} else {
				if(pilha.empty()){
					ok = false; break;
				}
				if( str[i] == ')' && pilha.top() != '(' || str[i] == ']' && pilha.top() != '[') {
					ok = false; break;
				}
				pilha.pop();
			}
		}
		if( !pilha.empty()) ok = false;
		if( ok) puts("Yes"); 
		else puts("No");
	}
	return 0;
}