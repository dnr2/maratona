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

const int maxn = 400;

int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};


int main(){
	
	string in; cin >> in;
	int sz = in.size();
	vector<int> resp;
	while(true){
		int cur = 0;
		REP(i,0,sz){
			cur *= 10;
			if(in[i] > '0'){
				cur += 1;
				in[i]--;
			}	
		}
		if( cur == 0) break;
		resp.PB( cur );
	}
	sort(resp.begin(), resp.end());
	
	cout << resp.size() << endl;
	REP(i,0,(int)resp.size()){
		if( i > 0 ) cout << " ";
		cout << resp[i] ;
	}
	return 0;
}
