//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=269
//#tag string
//#tag ad hoc, implementation

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

const int maxn = 100;

int s1[maxn], s2[maxn];

int main(){
	
	string line;
	while( getline( cin , line) ){
		FILL(s1,0); FILL(s2,0);
		stringstream ss(line);
		string str;
		bool ok = true;
		ss >> str;
		int it = 0;
		
		//TODO it > str.size()
		REP(i,0,10){
			if( it >= (int) str.size()) {
				ok = false; goto answer;
			}
			while(str[it] == '-'){
				it++; 
				if( it >= (int) str.size()) {
					ok = false; goto answer;
				}
			}
			if( i == 9 && str[it] == 'X') {
				s1[i+1] = s1[i] + 10;
				s2[i+1] = s2[i] + s1[i+1];
			} else {
				if( str[it] < '0' || str[it] > '9' ){
					ok = false; goto answer;
				} else {
					s1[i+1] = s1[i] + (str[it] - '0');
					s2[i+1] = s2[i] + s1[i+1];
				}
			}
			it++;
		}
		if( it < (int) str.size() ){
			while(str[it] == '-'){
				it++; 
				if( it >= (int) str.size()) {
					break;
				}
			}
		}
		if( it != (int)str.size()) ok = false;
		if( ss >> str ) ok = false;
		if( s2[10] % 11 != 0 ) ok = false; 
		
		answer:
		
		//TODO if incorrect string has spaces
		str = line;
		while( str.size() > 0 && str[0] == ' '){
			str = str.substr( 1, ((int)str.size()) - 1) ;
		} 
		while( str.size() > 0 && str[((int)str.size())-1] == ' '){
			str = str.substr( 0, ((int)str.size()) - 1) ;		
		}
		cout << str; 
		if( ok ) {
			cout << " is correct." << endl;
		} else {
			cout << " is incorrect." << endl;
		}
		
	}
	
	return 0;
}