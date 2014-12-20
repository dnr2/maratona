
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <complex>
#include <limits>
#include <functional>
#include <numeric>

using namespace std;

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }

typedef long long ll;

#define ll long long
#define pii pair<int,int>
#define F first
#define S second
#define REP(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define PI acos(-1)
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define EPS 1e-9
#define INF 1e9


int main(){
		
	vector<int> v,b;
	set<int> ss;
	REP(sz,4,15){
		v.clear();
		REP(i,0,sz) v.push_back( i);
		int cont = 0;
		do{
			b.clear();
			ss.clear();
			b.push_back( 0);
			REP(i,1,sz){
				b.push_back( v[b[i-1]]);
			}
			REP(i,0,sz){
				ss.insert( b[i]);
			}
			if( ss.size() == sz) cont++;
		} while( next_permutation( v.begin(), v.end())) ;
		cout << sz << " " << cont << endl;
	}
	
	return 0;
}