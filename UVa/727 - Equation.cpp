//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=668
//#tag stack pilha
//#tag infix to postfix 

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

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

char in[100];
char out[100];
char aux[4];

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	map<char,int> mapa; mapa['+'] = 1; mapa['-'] = 1; mapa['*'] = 2; mapa['/'] = 2;
	int t; scanf("%d\n", &t);
	bool prim = true;
	while(t--){
		cl(in); cl(out); 
		int cont = 0;
		while(gets(aux)){
			if( !(aux[0] >= '0' && aux[0] <= '9') &&  mapa[aux[0]] == 0 &&  
				aux[0] != '(' && aux[0] != ')') break;
			else in[cont++] = aux[0];
		}
		// db(in); db(cont); db(strlen(in));
		stack<char> pilha;
		int pont =0;
		fr(i,0,cont){
			// db(in[i]);
			if( in[i] == '('){
				pilha.push(in[i]);
			} else if( in[i] == ')'){
				while( !pilha.empty() ){
					if(pilha.top() == '(') { pilha.pop(); break;}
					out[pont++] = pilha.top(); pilha.pop();
				}
			} else if( mapa[in[i]] ){
				while(!pilha.empty() && mapa[pilha.top()] >= mapa[in[i]]  && pilha.top() != '('){
					out[pont++] = pilha.top(); pilha.pop();
				}
				pilha.push(in[i]);
			} else{
				out[pont++] = in[i];
			}
		}
		while(!pilha.empty()) {
			if(pilha.top() != '(' && pilha.top() != ')'){
				out[pont++] = pilha.top(); 
			}
			pilha.pop();
		}
		out[pont] = 0;
		if(!prim){ puts("") ;}
		else prim = false;
		printf("%s\n", out);
	}
	return 0;
}