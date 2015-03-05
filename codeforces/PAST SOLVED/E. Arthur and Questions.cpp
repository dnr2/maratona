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
// #define INF 0x3f3f3f3f
#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0)
#define FILL(x,v) memset(x,v,sizeof(x))
#define INF 0x3f3f3f3f
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str(); }

const int maxn = 300000;

int in[maxn];
bool mark[maxn]; 
vector<int> vals;
int n, k;

bool build(int b, int e){
	int sz = (e/k) - (b/k) + 1;
	int ini = (b>=k && !mark[b-k])?in[b-k]:-INF, end = (e+k < n && !mark[e+k])?in[e+k]:INF;
	if( ini == 0 && end == 0) return false;
	vals.clear();
	int pos = 0 ;
	if( ini >= 0 && end > 0 ){
		pos = ini + 1;
		REP(i,0,sz){
			if( pos < end ) vals.PB( pos++ );
			else  return false;			
		}
	} else if ( ini < 0 && end <= 0 ){
		pos = end - 1;
		REP(i,0,sz){
			if( pos > ini ) vals.PB( pos-- );
			else return false;
		}
	} else {
		while( (int) vals.size() < sz){
			int bsize = vals.size();
			if( pos == 0 ) vals.PB( pos );
			else{				
				if( pos < end && pos > ini ){
					vals.PB( pos );
				}
				if( (int) vals.size()  < sz && -pos < end && -pos > ini ){
					vals.PB( -pos );
				}
			}
			if( bsize  == (int) vals.size()) return false;
			pos++;
		}
	}
	sort( vals.begin(), vals.end());
	pos = b;
	REP(i,0,sz){		
		in[pos] = vals[i];
		pos += k;
	}
	return true;
}

int main(){
	IOFAST();
	string str;
	cin >> n >> k;
	REP(i,0,n){
		cin >> str;
		if( str[0] == '?' ){
			mark[i] = 1;
		} else {
			int aux; sscanf(str.c_str(),"%d", &aux );\
			in[i] = aux;
		}
	}
	bool ok = true;
	REP(i,0,k){		
		int pos = i, ini = -1, end = -1;
		while( pos < n ){
			if( pos + k < n){
				if( !mark[pos] && !mark[pos+k] && in[pos] >= in[pos+k] ) {
					ok = false; goto fim;
				}
			}
			if( ini == -1 && mark[pos] ){
				ini = pos;
			}
			if( ini != -1 && !mark[pos]){
				end = pos - k;
				if( !build( ini, end) ){
					ok = false;
					goto fim;
				}
				ini = end = -1;
			}
			pos+= k;
		}
		if( ini != -1 ){
			end = pos -k;
			if( !build( ini, end) ){
				ok = false;
				goto fim;
			}
		}
	}
	
	fim :
	
	if( ok ){
		REP(i,0,n) cout << ((i>0)?" ":"") << in[i];		
		cout << endl;
	} else {
		cout << "Incorrect sequence" << endl;
	}
	
	
	return 0;
}
