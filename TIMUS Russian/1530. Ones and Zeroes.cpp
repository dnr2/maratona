//http://acm.timus.ru/problem.aspx?space=1&num=1530

#include <cctype>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <cstdio>
#include <cmath>

#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <map>
#include <list>

using namespace std;

#define ms(ar,a) memset(ar, a, sizeof(ar))
#define frd(i,j,k) for (int (i) = (j); (i) >= (k); (i)--)
#define fr(i,j,k) for (int (i) = (j); (i) < (k); (i)++)
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define MAXN 100

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

const double PI = acos(-1.0);

template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

char in1[100010];
char in2[100010];
int n; 

int conflict(){
	fr(i,0,n){
		if( in1[i] == '1' && in2[i] == '1' ) return i;
	}
	return -1;
}

bool sum(char aux[]){
	for(int i = n -1; i >=0; i--){
		if(aux[i] == '0')  {
			aux[i] = '1';
			for(int j=i+1; j<n;j++){
				aux[j] = '0';
			}
			return false;
		}
	}
	return true; // overflow
}

int findZero(int pos){
	for(int i = pos-1; i >=0; i--){
		if( in1[i] == '0' && in2[i] == '0') return i;
	}
	return -1;
}


void op(int conf){
	int pos = findZero( conf);
	// db( pos);
	if( pos >= 0){
		in2[pos] = '1';
		fr(i,pos+1,n) in2[i] = '0';
		puts(in1); puts(in2);
	} else { 
		fr(i,0,n) in2[i] = '0';
		// db(in1);
		if( sum( in1) == true){
			fr(i,0,n) in1[i] = '0'; 
		}
		puts(in1); puts(in2);
	}
}
int main() {
	scanf("%d\n", &n);
	gets(in1);gets(in2);
	int conf = conflict();
	if( conf >= 0){
		op( conf);
	} else {
		bool over = sum( in2) ;
		if( !over){
			int kk = conflict();
			if( kk >= 0) op( kk);
			else {
				puts(in1); puts(in2);
			}
		} else {
			fr(i,0,n) in2[i] = '0';
			bool lol = sum( in1);
			if( lol ) fr(i,0,n) in1[i] = '0';
			puts(in1); puts(in2);
		}
	}
	return 0;
}