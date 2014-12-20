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

const int MAXN = 101000;

int in[MAXN];

int main(){
	
	int n;
	cin >> n;
	REP(i,0,n) cin >> in[i];
	vector<PII> resp;
	REP(num,1,3){
		int cont = 0;
		REP(i,0,n){
			if( in[i] == num) cont++;
		}
		vector<int> fat;
		for(int i = 1; i<= cont;i++){
			DB( num _ i);
			fat.PB( i );
		}
		int sz = fat.size();
		REP(k,0,sz){
			int sum[] = {0,0}, vic[] = {0,0};
			REP(i,0,n){
				if( in[i] == num){
					sum[0]++;
				} else {
					sum[1]++;
				}
				if( sum[1] == fat[k]){
					vic[1]++;
					sum[0] = sum[1] = 0;
				} else if( sum[0] == fat[k]){
					vic[0]++;
					sum[0] = sum[1] = 0;
				}
			}
			if( fat[k] == 3) DB( vic[0] _ vic[1]);
			if( sum[1] > 0 || sum[0] > 0) continue;
			if( vic[0] > vic[1]){
				resp.PB( MP( vic[0] , fat[k] ));
			}
		}
	}
	sort( resp.begin(), resp.end());
	cout << resp.size() << endl;
	REP(i,0,(int)resp.size()){
		cout << resp[i].F << " " << resp[i].S << endl;
	}
	return 0;
}
