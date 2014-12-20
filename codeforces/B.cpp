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
	string s; cin >> s;
	vector<string> v;
	REP(i,0,n){
		string cur = "";
		int pos = (i + 1) % n;
		cur += '0';
		int sum = (10 - (s[i]-'0')) % 10;
		while( pos != i){
			cur += (((s[pos]-'0')+sum) % 10)+'0';
			pos = (pos + 1) % n;
		}
		v.push_back(cur);
	}
	sort(v.begin(), v.end());
	cout << v[0] << endl;
	return 0;
}
