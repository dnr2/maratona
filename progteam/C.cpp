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
#include <set>

// #include <unordered_map>

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define F first
#define S second
#define REP(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define pb push_back
#define PI acos(-1)
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define mp make_pair
#define EPS 1e-9
#define INF 0x3f3f3f3f
#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0)
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

char resp[4000][4000];

int off = 2000;

int main(){
	int n; 
	while( cin >> n){
		memset(resp,' ',sizeof(resp));
		int y = off, miny = INF, maxy = 0;
		int x = -1, maxx = 0;
		int turn = -1;
		maxx = x;
		miny = min( miny, y);
		maxy = max( maxy, y);
		REP(i,0,n){
			int a; scanf("%d", &a);
			x++;
			resp[y][x] = (turn == 1)? '\\' : '/';		
			maxx = x;
			miny = min( miny, y);
			maxy = max( maxy, y);
			REP(j,1,a){
				y += turn;
				x++;
				resp[y][x] = (turn == 1)? '\\' : '/';				
				maxx = x;
				miny = min( miny, y);
				maxy = max( maxy, y);
			}		
			maxx = x;
			miny = min( miny, y);
			maxy = max( maxy, y);
			if( turn == 1) turn = -1; 
			else turn = 1;
		}
		
		REP(i,miny,maxy+1){
			REP(j,0,maxx+1){
				printf("%c", resp[i][j]);
			}
			puts("");
		}
	}
	return 0;
}