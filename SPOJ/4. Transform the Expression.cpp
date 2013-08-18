//http://www.spoj.pl/problems/ONP/
//#tag string
//#tag postfix notation posfixada
//#sol transformar expressão para notação posfixada

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
#define db(x) if(0) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define mp make_pair
#define cl(x) memset(x,0,sizeof(x))

// #define umap unordered_map

using namespace std;

map<char,int> mapa;
string rpn;

void rec(string x){
	stack<char> pilha;
	fr(i,0,x.size()){
		db(i);
		if( x[i] >= 'a' && x[i] <= 'z'){
			rpn.pb(x[i]);
		} else if( x[i] == '(' ){
			int k = 0, j = i, cont = 0;
			while(true){
				if( x[j] =='(') cont++;
				if( x[j] ==')') cont--;
				if( x[j] == ')' && cont == 0) break;
				j++;
				k++;
			}
			db( x.substr(i+1,k-1) _ k );
			rec( x.substr(i+1, (k-1) ));
			db( rpn);	
			i = j;
		} else {
			if( pilha.empty() || mapa[pilha.top()] < mapa[x[i]]){
				pilha.push(x[i]);
			} else {
				while( !pilha.empty() && mapa[pilha.top()] >= mapa[x[i]]){
					rpn.pb( pilha.top()) ;pilha.pop(); 
				}
			}
		}
	}
	while(!pilha.empty()){
		rpn.pb(pilha.top()); pilha.pop();
	}
}

int main(){
	
	mapa['+'] = 1; mapa['-'] = 2; mapa['*'] = 3; mapa['/'] = 4; mapa['^'] = 5;
	int t; cin >> t;
	while(t--){		
		string exp; rpn = "";
		cin >> exp;
		rec(exp);
		cout << rpn << endl ;
	}
	return 0;
}