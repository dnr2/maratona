//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3988
//#tag string processing

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
#define ler(a) scanf("%d", &a)
#define ler2(a,b) scanf("%d%d", &a, &b)
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1.0);
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }
#define MAXN 100

char in[20000];
char buf[1000];

int main() {
	//cin.sync_with_stdio(false);
	string resp = "";
	int maior = 0;
	while(scanf("%s", in) > 0){
		int len = strlen(in);
		for(int i=0;in[i];i++) if( !isalpha(in[i]) && in[i] != '-'  ) in[i] = ' ';
		// cout << in << endl;
		int off = 0;
		while(off < len){
			while( off < len && !isalpha(in[off]) && in[off] != '-'  ) off++;
			sscanf( in + off, "%s", buf);
			// cout << buf << endl;
			string aux = buf;
			if( aux == "E-N-D") goto end;
			if( maior < aux.size()){
				resp = aux; maior = aux.size();
				// cout << "resp =" << maior << " " << resp << endl;
			}
			off += aux.size();
		}
	}
	end:;
	fr(i,0,resp.size()) resp[i] = tolower(resp[i]);
	cout << resp << endl;
	return 0;
}