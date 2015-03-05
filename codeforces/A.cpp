#include<bits/stdc++.h>

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

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str(); }

const int maxn = 100;

int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};
const ll mod = 1000000007;

int main(){
	
	IOFAST();
	string str;
	int sz; cin >> sz;
	cin >> str;	
	map<char,int> m;
	vector< pair<int,char> > v;
	REP(i,0,sz){
		m[str[i]]++;
	}
	v.PB( MP(m['A'], 'A'));
	v.PB( MP(m['C'], 'C'));
	v.PB( MP(m['G'], 'G'));
	v.PB( MP(m['T'], 'T'));
	
	sort( v.begin(),v.end(), greater< pair<int,char> >() );

	ll cont = 1;
	REP(i,1,4){
		if( v[i].FT == v[i-1].FT){
			cont++;
		} else {
			break;
		}
	}	
	ll resp = 1;

	REP(i,0,sz){
		resp *= cont;
		resp = resp % mod;
	}
	cout << resp << endl;
	return 0;
}
