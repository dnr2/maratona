//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=588&page=show_problem&problem=4462
//#tag implementation ad hoc
//#sol caution, problem statment is wrong, there is no trailing spaces after off lines.

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
#include <cassert>

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

const int maxn = 300;

string str[maxn];
int mark[maxn][maxn];
vector<PII> in[maxn];

int main(){
	IOFAST();
	int m, n;
	while( cin >> m ){
		if( m == 0) break;
		n = 0;
		REP(i,0,m){
			in[i].clear();
			int aux;
			cin >> aux;
			REP(j,0,aux) {
				int a, b;
				cin >> a >> b;
				if( i == 0) n += b;
				in[i].PB( MP( a , b ));
				
			}		
		}				
		// DB( m _ n );
		REP(i,0,2*m+1){
			str[i] = "";
			REP(j,0,3*n+1){
				if( i % 2 == 0 && j % 3 != 0){
					str[i] += '-';
				} else if( i % 2 == 1 && j%3 == 0){
					str[i] += '|';
				} else {
					str[i] += ' ';
				}
			}
			// DB( i _ str[i]);
		}
		
		FILL( mark, 0 );
		REP(i,0,m){
			int pos = 0;
			REP(j,0,(int)in[i].size()){
				while( true  ){
					assert ( pos < n );
					if( mark[i][pos] ) pos++; 
					else  break;			
				}
				int a = in[i][j].FT, b = in[i][j].SD;
				REP(y,0,a){
					REP(x,0,b){
						int ni = y+i, nj = x+pos;
						mark[ni][nj] = 1;
					}
				}				
				REP(y,0,a*2-1){
					REP(x,0,b*3-1){
						int ni = y+(i*2)+1, nj = x+(pos*3)+1;
						str[ni][nj] = ' ';
						if(y ==0 && x == 0){
							str[ni][nj] = '0' + i + 1;
						}
						if(y ==0 && x == 1){
							str[ni][nj] = '0' + pos + 1;
						}
					}
				}
				
			}
		}		
		
		REP(i,0,2*m+1){						
			if( (i & 1) == 0){
				str[i] = str[i].substr( 0, str[i].find_last_of('-') + 1);
			}
			cout << str[i] << endl;
		}	
		cout << endl;
	}
	return 0;
}