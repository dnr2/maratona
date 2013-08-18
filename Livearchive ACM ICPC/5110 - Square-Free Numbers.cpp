//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=380&page=show_problem&problem=3111
//#tag math matemática
//#tag crivo de eratótenes cieve
//#sol fazer a fatoração prima e pegar o maior dentre os expoentes dos fatores primos

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
#define MAXN 1001000
// #define umap unordered_map

using namespace std;

int crivo[MAXN];

int main(){
	
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	crivo[1] = 1;
	fr(i,2,MAXN) if( crivo[i] == 0) for(int j=i;j<MAXN;j+=i) crivo[j] = i;
	int t, n; cin >> t;
	while(t--){
		cin >> n;
		int cur = n, resp = 0, aux; map<int,int> mapa;
		while(cur != 1) {
			mapa[crivo[cur]]++; 
			resp = max(resp,mapa[crivo[cur]]);
			cur /= crivo[cur];
		}
		cout << resp << endl;
	}
	
	
	
	return 0;
}