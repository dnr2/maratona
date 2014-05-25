//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2958
//#tag merge sort
//#sol modified merge sort. use merge sort to count the number of times you swap

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
#include <set>

// #include <unordered_map>

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define F first
#define S second
#define REP(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define pb push_back
#define PI acos(-1)
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define mp make_pair
#define EPS 1e-9
#define INF 0x3f3f3f3f
#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0)
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

const int maxn = 1000010;
int in[maxn];
int aux[maxn];
int n;
ll resp;

void rec( int i, int j){
	if( i + 1 == j){
		if( in[i] > in[j] ){
			swap(in[i], in[j]);
			resp++;			
		}
	}
	else if( i + 1 < j){
		int m = (i+j)/2;
		rec( i, m);
		rec( m+1,j);
		int p1 = i, p2 = m+1, pos = 0;
		while( p1 <= m && p2 <= j){
			if( in[p1] <= in[p2]){
				aux[pos++]= in[p1++];
			} else {
				aux[pos++] = in[p2++];
				resp += m-p1+1;
			}
		}
		while( p1 <= m){
			aux[pos++]= in[p1++];
		}
		while( p2 <= j){
			aux[pos++]= in[p2++];
		}
		pos = 0;
		REP(x,i,j+1){
			in[x] = aux[pos++];
		}
	}
}


int main(){
	while(scanf("%d", &n) > 0){
		REP(i,0,n) scanf("%d", in + i);
		resp = 0;
		rec( 0, n-1);
		cout << resp << endl;
	}
	return 0;
}