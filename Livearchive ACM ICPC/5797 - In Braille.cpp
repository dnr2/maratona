//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3808
//#tag implementation
//#tag ad hoc
//#sol use a array of string to help you print the number and discover the input braile numbers

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

const int MAXN = 500;

string str[11][2];
string in[MAXN][3];

int main(){
	
	IOFAST();
	
	str[0][0] = ".*";
	str[0][1] = "**";
	
	str[1][0] = "*.";
	str[1][1] = "..";
	
	str[2][0] = "*.";
	str[2][1] = "*.";
	
	str[3][0] = "**";
	str[3][1] = "..";
	
	str[4][0] = "**";
	str[4][1] = ".*";
	
	str[5][0] = "*.";
	str[5][1] = ".*";
	
	str[6][0] = "**";
	str[6][1] = "*.";
	
	str[7][0] = "**";
	str[7][1] = "**";
	
	str[8][0] = "*.";
	str[8][1] = "**";
	
	str[9][0] = ".*";
	str[9][1] = "*.";
	
	
	int n;
	while( cin >> n){
		if( n == 0) break;
		string s;
		cin >> s;
		
		if( s == "S"){
			cin >> s;
			int sz = s.size();
			REP(j,0,3){
				REP(i,0,sz){
					if( i > 0 ) cout << " " ;
					if( j < 2 ) cout << str[s[i]-'0'][j];
					else cout << "..";
				}
				cout << endl;
			}
		} else {
			REP(j,0,3){
				REP(i,0,n){
					cin >> in[i][j];
				}
			}
			REP(i,0,n){
				REP(j,0,10){					
					if( in[i][0] == str[j][0] && in[i][1] == str[j][1] ){
						cout << j; break;
					}
				}
			}
			cout << endl;
		}
		
	}
	return 0;
}