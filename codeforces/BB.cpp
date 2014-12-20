//
//#tag
//#sol

#include<bits/stdc++.h>

// #include <unordered_map>

#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
#define PDD pair<double,double>
#define F first
#define S second
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

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str(); }

const int MAXN = 2000;
int mark[MAXN];
int num[MAXN];


int main(){
	IOFAST();
	int n; cin >> n;
	int b; cin >>b;
	int pot = 1;
	REP(i,1,n) pot *= 10;
	// DB( pot);
	queue<int> q;
	mark[b] = true;
	q.push( b);
	int resp = INF;
	while( !q.empty()){
		int cur = q.front(); q.pop();
		// DB( cur );
		int aux = cur;
		REP(i,0,n){
			num[i] = aux % 10;
			aux /= 10;
		}
		int f = cur % 10;
		int next = (cur /10) + ( pot * f);
		// DB( cur _ next );
		if( !mark[next]){
			mark[next] = 1;
			resp = min(resp, next);
			q.push( next);
		}
		next = 0;
		for(int i = n-1;i >=0 ; i--){
			num[i] = (num[i]+1) % 10;
			next *= 10;
			next += num[i];
		}
		// DB( cur _ next );
		if( !mark[next]){
			mark[next] = 1;
			resp = min(resp, next);
			q.push( next);
		}
	}
	int aux = resp;
	REP(i,0,n){
		num[i] = aux % 10;
		aux /= 10;
	}
	for(int i = n-1; i >= 0; i--){
		cout << num[i];
	}
	cout << endl;
	return 0;
}
