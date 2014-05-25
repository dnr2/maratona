//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2052
//#tag stack
//#tag data structures
//#sol use stack to keep track of the size of the toy and the sum so far

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

const int maxn = 2000000;
int in[maxn];

int main(){
	string str;
	while( getline( cin, str) ){
		stringstream ss(str);
		int sz = 0;
		while( ss >> str ){
			sscanf(str.c_str(), "%d", &in[sz++]);			
		}
		stack<int> st;
		stack<int> num;
		bool ok = true;
		REP(i,0,sz){
			if( in[i] < 0){
				if( !st.empty()){
					int v = num.top(); num.pop();
					num.push( v - in[i]);
				}
				st.push( -in[i]);
				num.push( 0);
			} else {
				if( st.empty() || st.top() != in[i] || num.top() >= st.top()){
					ok = false;
					break;
				}
				st.pop();
				num.pop();
			}
		}
		if( !st.empty()){
			ok = false;
		}
		if( ok ) puts(":-) Matrioshka!");
		else puts(":-( Try again.");
	}	
	return 0;
}