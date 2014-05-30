//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1977
//#tag cycle finding
//#sol use stack to simulate the RPN expression and use any cycle detection algorithm

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
#define IOFAST ios_base::sync_with_stdio(0);cin.tie(0)
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

vector<string> func;
string str;
long long N, n;

ll f( ll x){
	stack<ll> s;		
	REP(i,0,(int)func.size()){		
		if( func[i] == "x"){
			s.push( x);
		} else if( func[i] == "N"){
			s.push( N);
		} else if( func[i] == "+" || func[i] == "*" || func[i] == "%") {	
			ll b = s.top(); s.pop();
			ll a = s.top(); s.pop();						
			if( func[i] == "+") a += b; 
			if( func[i] == "*") a *= b;
			if( func[i] == "%") a %= b;	
			a %= N;	
			s.push(a);
		} else {
			ll a; sscanf(func[i].c_str(), "%lld", &a);
			s.push(a);
		}
	}	
	return (s.top() % N);
}


int main(){
	
	while( scanf("%lld%lld", &N, &n) > 0 ){
		if( N == 0) break;
		func.clear();
		getline(cin, str);
		stringstream ss(str);
		while( ss >> str){
			func.pb(str);			
		}		
		ll tort = f(n), hare = f(f(n));
		while( tort != hare ){ tort = f(tort); hare = f(f(hare)); }
		hare = n;
		while( tort != hare ){ tort = f(tort); hare = f(hare); }
		ll lamb = 1; hare = f(tort);
		while( tort != hare){ hare = f(hare); lamb++; }
		printf("%lld\n", lamb);
	}
	return 0;
}