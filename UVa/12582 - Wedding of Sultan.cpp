//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4027
//#tag stac pilha
//#tag dfs depth first search busca em profundidade

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
bool cont[30][30];
bool aux[30];
int resp[30];

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	
	int t; cin >> t; int caso =1;
	while(t--){
		cl(cont); cl(aux); cl(resp);
		scanf("%s", in); int len = strlen(in);
		stack<char> p;
		fr(i,0,len) in[i] -= 'A';
		fr(i,0,len){
			if( !p.empty()) cont[p.top()][in[i]]  = cont[in[i]][p.top()] = true;
			if( !aux[in[i]]){
				p.push(in[i]);
				aux[in[i]] = true;
			} else p.pop();
		}
		fr(i,0,30)  fr(j,0,30) if( i != j && cont[i][j] ) resp[i]++;
		printf("Case %d\n", caso++);
		fr(i,0,30) if( resp[i] > 0) printf("%c = %d\n", i + 'A', resp[i] );
	}	
	return 0;
}