//http://www.spoj.com/problems/TAP2014H/
//#tag LIS longest increasing subsequence
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
#define PII pair<int,int>
#define PDD pair<double,double>
#define FT first
#define SD second
#define REP(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define PB push_back
#define PI acos(-1)
#define DB(x) cerr << #x << " = " << x << endl;
#define _ << ", " <<
#define MP make_pair
#define EPS 1e-9
#define INF 0x3f3f3f3f
#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0)
#define FILL(x,v) memset(x,v,sizeof(x))


// #define umap unordered_map
using namespace std;
template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

#define MAXN 1000

bool compare(int a, int b){
	return a>b;
}

int main(){

	int tc;
	scanf("%d",&tc);
	while(tc--){
		vector<int> my;
		int n;
		scanf("%d",&n);
		int aux;
		scanf("%d",&aux);
		my.push_back(aux);
		int tamanho=0;
		for(int i=1; i<n; i++){
			scanf("%d",&aux);
			if(aux<my[tamanho]){
			 	my.push_back(aux);
			 	tamanho++;
			}
			else{
				int pos= lower_bound(my.begin(),my.end(),aux,compare) - my.begin();
				my[pos]=aux;
				
			}
		}
		printf("%d\n",(int)my.size());
	}
	return 0;
}