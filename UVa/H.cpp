//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1613
//#rag trees arvores 
//#sol resolver por nível, do maior para o menor, considerando que depois de varrer um nível todos os nós devem ter 1 marble

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
#define EPS 1e-9
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}


int g[10010];
int mar[10010];
int mark[10010];
vector<int> nivel[10010];

int lev(int x){
	if( g[x] == 0) return mark[x] = 0;
	return mark[x] = lev(g[x]) + 1;
}

int main(){
	int n; int caso = 1;
	while(scanf("%d", &n) > 0 && n){
		cl(mar);  cl( mark); cl(g); fr(i,0,n+2) nivel[i].clear();
		int a,b,c,d,last = 0;
		fr(i,0,n){
			scanf("%d%d%d", &a, &b, &c);
			mar[a] = b;
			fr(i,0,c){
				scanf("%d", &d); 
				g[d] = a;
			}
		}
		fr(i,1,n+1){
			mark[i] = lev(i);
			nivel[mark[i]].pb(i);
			last = max(last, mark[i]);
		}
		int resp = 0;
		while(last > 0){
			fr(i,0,nivel[last].size()){
				int cur = nivel[last][i];
				if( mar[cur] < 1){
					mar[g[cur]] += mar[cur] -1; resp -= mar[cur] -1;
				} else if( mar[cur] > 1){
					mar[g[cur]] += mar[cur] -1; resp += mar[cur] -1;
				}				
			} 
			last--;
		}
		printf("%d\n" , resp);

	}
	return 0;
}