//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3786
//#tag implementation

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

const int maxn = 2000;
#define PSS pair< string, string > 

PSS vals[20];
PSS in[maxn];

int main(){
	IOFAST();
	int n;
	vals[1] = MP("*.","..");
	vals[2] = MP("*.","*.");
	vals[3] = MP("**","..");
	vals[4] = MP("**",".*");
	vals[5] = MP("*.",".*");
	vals[6] = MP("**","*.");
	vals[7] = MP("**","**");
	vals[8] = MP("*.","**");
	vals[9] = MP(".*","*.");
	vals[0] = MP(".*","**");
	while(cin >> n){
		if( n == 0) break;
		string cmd, str; cin >> cmd;
		
		if( cmd == "S" ){
			cin >> str;
			REP(i,0,(int)str.size()){
				if(i >0 )cout << " ";
				cout << vals[ str[i]-'0'].FT;
			}
			cout << endl;
			REP(i,0,(int)str.size()){
				if(i > 0 )cout << " ";
				cout << vals[ str[i]-'0'].SD;
			}
			cout << endl;
			REP(i,0,(int)str.size()){
				if(i > 0) cout << " ";
				cout << "..";
			}
			cout << endl;
		} else {
			REP(i,0,n){
				cin >> in[i].FT;
			}
			REP(i,0,n){
				cin >> in[i].SD;
			}
			REP(i,0,n){
				cin >> str;
			}
			REP(i,0,n){
				REP(j,0,10){
					if( vals[j].FT == in[i].FT && vals[j].SD == in[i].SD){
						cout << j; break;
					}
				}
			}
			cout << endl;
		}
	}
	return 0;
}