//https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=2937
//#tag implementation
//#tag ad hoc
//#sol 

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

const int MAXN = 100;

string in[MAXN];
int val[MAXN][MAXN];

int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};

int main(){
	IOFAST();
	int r,c;
	while(cin >> r >> c){
		REP(i,0,r) cin  >> in[i];
		int cont = 1;
		REP(i,0,r){
			REP(j,0,c){
				val[i][j] = (in[i][j] == '.') ? cont++ : 0;
			}
		}
		REP(i,0,r){
			REP(j,0,c){
				if( val[i][j] > 0){
					cout << val[i][j];
					REP(k,0,4){
						int ni = i + dy[k];
						int nj = j + dx[k];
						if( ni < 0 || ni >= r || nj < 0 || nj >= c ) cout << " " << 0;
						else {
							cout << " " << val[ni][nj];
						}
					}
					cout << endl;
				}
			}
		}
		cout << endl;
	}
	return 0;
}