//http://www.spoj.com/problems/TAP2014G/
//#tag DP dynamic programming programacao dinamica
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

#define MAXN 2000
int in[MAXN];
int aux[MAXN];
int main(){
	
	int N;
	while( cin >> N){
		FILL(aux,0);
	
		REP(i,0,N){
			scanf("%d", in + i);
		}
		sort(in , in + N, greater<int>());
		REP(i,0,N/2){
			aux[i] = max(in[2*i],in[2*i+1]) - min(in[2*i],in[2*i+1]);
		}
		sort( aux, aux + N/2, greater<int>());
		int ela = 0, ele = 0; REP(i,0,N/2) ela += aux[i];
		int resp = N/2;
		int it= 0;
		while( ele <= ela && it < N/2){
			ele += aux[it];
			ela -= aux[it];
			it++;
			resp--;
		}
		if( ele > ela) cout << resp << endl;
		else cout << "-1" << endl;
	}
	
	return 0;
}