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

int main(){
	int n;
	string str; 
	cin >> n >> str;
	vector<int> nums;
	REP(i,0,n){
		int aux = (str[i] -'0');
		if( aux > 1 ){
			if( aux == 4){
				nums.PB( 3 );
				nums.PB( 2 );
				nums.PB( 2 );
			} else if( aux == 6){				
				nums.PB( 3 );
				nums.PB( 5 );
			} else if( aux == 8){
				nums.PB( 2 );
				nums.PB( 2 );
				nums.PB( 2 );
				nums.PB( 7 );
			} else if( aux == 9){
				nums.PB( 2 );
				
				nums.PB( 3 );
				nums.PB( 3 );				
				
				nums.PB( 7 );
			} else {
				nums.PB( aux );
			}
		}
	}
	sort( nums.begin(), nums.end(), greater<int>());
	int sz = nums.size();
	REP(i,0,sz){
		cout << nums[i];
	}
	cout << endl;
	return 0;
}
