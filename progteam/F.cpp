//
//#tag
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

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

const int maxn = 8;

int board[maxn][maxn];


int main(){
	
	int a,b,c,d;
	string str1, str2;
	while (cin >> str1 ){
		a = str1[0] -'a'; b = str1[1] - '1';
		cin >> str2;
		c = str2[0] -'a'; d = str2[1] - '1';
		FILL(board,INF);
		queue<PII> fila;
		board[a][b] = 0;
		fila.push( PII( a ,b  ));
		int resp = -1;
		while( !fila.empty()){
			int x = fila.front().FT, y = fila.front().SD; 
			if( x == c && y == d ){
				resp = board[x][y]; break;
			}
			fila.pop();
			REP(i,-2,2+1){
				REP(j,-2,2+1){
					if( abs(i) + abs(j) == 3){
						int nx = x+ i;
						int ny = y+ j;
						if( nx < 0 || nx >= 8 || ny < 0 || ny >= 8) continue;
						if( board[nx][ny] == INF ){
							board[nx][ny] = board[x][y] + 1;
							fila.push( PII( nx, ny ));
						}
					}
				}
			}
		}
		
		printf("To get from %s to %s takes %d knight moves.\n", 
			str1.c_str(), str2.c_str(), resp );
		
	}
	
	
	return 0;
}