//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2476
//#tag implicit stack
//#tag brackets
//#tag sorting
//#sol consider E as an '(' and X as an ')', you have to match the brackets. 
//the problem is with the '?', consider that it's always better to put as many '(' in the left as possible.
//so replace the '?' with the '(' as much as you can, and then count the biggest matching brackets depth 


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

const int MAXN = 64800;

char s[10];
PII in[MAXN];


int main(){
	
	int n;
	while(scanf("%d", &n) > 0 && n){
		int sum = 0;		
		REP(i,0,n){
			int a, b, c, val = 0;;
			scanf("%d:%d:%d %s", &a, &b, &c, s);
			if( s[0] == 'E') val = 1, sum++;
			if( s[0] == 'X') val = 2;
			in[i] = MP( a * (60*60) + b * 60 + c , val);
		}
		sort( in, in + n);
		REP(i,0,n){
			if( in[i].SD == 0){
				if( sum < n/2) in[i].SD = 1, sum++; 
				else in[i].SD = 2;
			}
		}
		int resp =0, stacksz = 0;
		REP(i,0,n){			
			if( in[i].SD == 1){			
				stacksz++; 
			} else {
				stacksz--;
			}
			resp = max(resp, stacksz);
		}
		cout << resp << endl;		
	}
	
	return 0;
}