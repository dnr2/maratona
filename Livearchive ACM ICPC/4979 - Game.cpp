//https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=2980
//#tag implementation
//#tag ad hoc
//#sol testar cada direcao para cada uma das posicoes no array 

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
string in[10];

int dx[] = {1,1,1,0};
int dy[] = {-1,0,1,1};
int resp[5];

int main(){
	IOFAST();
	int Z; cin >> Z;
	while(Z--){
		REP(i,0,5) cin >> in[i];
		FILL(resp,0);
		REP(p,0,2){
			char tar = (p == 0)?'A':'B';
			REP(i,0,5){
				REP(j,0,5){
					REP(k,0,4){
						int cont = 0;
						REP(l,0,3){
							int ni = i + dy[k] * l;
							int nj = j + dx[k] * l;
							if( ni < 0 || ni > 4 || nj < 0 || nj > 4 ) break;
							if( in[ni][nj] == tar ) cont++;
						}
						if( cont == 3){
							resp[p] = 1;
						}
					}
				}
			}
		}
		if( resp[0] && !resp[1]){
			cout << "A wins" << endl;
		} else if( resp[1] && !resp[0]){
			cout << "B wins" << endl;
		} else {
			cout << "draw" << endl;
		}
	}
	return 0;
}