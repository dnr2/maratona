//http://acm.timus.ru/problem.aspx?space=1&num=1651
//#tag pd

#include <cstring>
#include <cstdlib>
#include <climits>
#include <cstdio>
#include <cctype>
#include <cmath>
 
#include <iostream>
#include <algorithm>
#include <utility>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
 
//#include <bits/stdc++.h>
 
using namespace std;
 
#define fr(i,j,k) for (int (i) = (j); (i) < (k); (i)++)
#define frd(i,j,k) for (int (i) = (j); (i) >= (k); (i)--)
#define ms(ar,a) memset(ar, a, sizeof(ar))
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1.0);
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }
#define MAXN 100

int pd[100010];
int num[100010];
int in[100010];
bool pai[100010];

int main() {
	//cin.sync_with_stdio(false);
	int n;
	while(scanf("%d", &n) != EOF) {
		ms( pai, 0);
		fr(i,0,n) { scanf("%d", in+i); pd[i] = INF; num[in[i]] =INF; }
		pd[0] = 0; num[in[0]] = 0;
		fr(i,1,n){	
			if( num[in[i]] > pd[i-1] + 1){
				num[in[i]] = pd[i-1] + 1;
				pd[i] = pd[i-1] + 1;
				pai[i] = true;
			} else {
				pd[i] = num[in[i]];
			}
		}
		// fr(i,0,n) db( i _ pd[i] _ pai[i] );
		vector<int> resp; int cur = in[n-1]; resp.pb(cur);
		for( int i = n-1; i>=0; i--){
			if( pai[i] && in[i] == cur){ 
				resp.pb( in[i-1]); cur = in[i-1];
			} 
		}
		printf("%d", resp[resp.size()-1]);
		for( int i = resp.size()-2; i>=0; i--){
			printf(" %d", resp[i]);
		}
		puts("");
	}	
	return 0;
}