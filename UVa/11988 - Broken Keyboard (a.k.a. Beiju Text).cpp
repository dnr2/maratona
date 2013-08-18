//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3139
//#tag string

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
	
	list<char> lista;
	char in[100000];
	while(scanf("%s", in)>0){
		lista.clear(); list<char>::iterator it = lista.begin();
		for(int i=0;in[i]; i++){
			if( in[i] =='[') it = lista.begin();
			else if( in[i] ==']') it = lista.end();
			else{
				lista.insert(it,in[i]);
			}
		}
		 for (it=lista.begin(); it!=lista.end(); it++)
			printf("%c", (*it));
		puts("");
	}
	
	return 0;
}