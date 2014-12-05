//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2869
//#tag string
//#tag construction construcao
//#sol try all posible cases, as you can see the addition in the worst case wont be greater than 100000 because 
//the right side will "overflow" and become zero, and then you can add as much as you want to make the right side
//the reverse of the left side. (you can do it much faster considering calculating the jumps instead of iterating)

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

int main(){
	
	string str;
	while( cin >> str){
		if( str == "0" ) break;
		int sz = str.size();
		int num = 0;
		REP(i,0,sz){
			num *= 10;
			num += str[i] - '0';
		}
		int resp = 0;
		do{
			string a = tostr( num + resp );	
			int sz2= a.size();
			REP(i,0,sz - sz2 ){
				a.insert(0,"0");
			}
			string b = a;
			reverse( b.begin(), b.end());			
			if( a == b) break;
			resp++;
		} while( true );
		cout << resp << endl;	
	}
	
	return 0;
}