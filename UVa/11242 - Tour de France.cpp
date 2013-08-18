//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2183
//#tag iterative 
//#tag sort

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


double in[20][2];
double arr[200];

int main(){
		
	int n,m;
	while(scanf("%d", &n) >0 && n){
		scanf("%d", &m);
		fr(i,0,n) scanf("%lf", &in[i][0]);
		fr(i,0,m) scanf("%lf", &in[i][1]);
		fr(i,0,n)fr(j,0,m) arr[i*m + j] =  in[j][1] / in[i][0];
		int size = n *m ;
		sort(arr,arr + size);
		// fr(i,0,size) db( arr[i]);
		double resp = 0;
		fr(i,1,size){
			resp = max( resp, arr[i]/arr[i-1]) ;
		}
		printf("%.2lf\n", resp);
	}
	
	return 0;
}