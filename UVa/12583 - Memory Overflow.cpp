//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4028
//#tag
//#sol

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

// template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

char in[600];

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	int t;cin >> t; int caso = 1;
	while(t--){
		map<char,int> number;
		map<char,int> rec;
		int n,k;
		scanf("%d%d", &n, &k);
		scanf("%s", in);
		int len = strlen(in);
		int resp = 0;
		fr(i,0,n) {
			if( rec[in[i]] > 0 )resp++;
			rec[in[i]]++;
			if( i >= k ) rec[in[i-k]]--;
		}
		printf("Case %d: %d\n", caso++, resp);
	}
	return 0;
}