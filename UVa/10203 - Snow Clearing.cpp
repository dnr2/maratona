//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1144
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
#define FOREACH(i,v) for(typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define IOFAST ios_base::sync_with_stdio(0);cin.tie(0);

// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}


int main(){
	int T; cin >> T; 
	string str;
	getline(cin,str);
	getline(cin,str);
	REP(TT,0,T){
		double a,b,c,d;
		scanf("%lf%lf", &a,&b);
		getline(cin,str);
		double resp = 0;
		while( getline(cin,str)){
			if( str == "") break;
			stringstream ss(str);
			ss >> a >> b >> c >> d;
			resp += sqrt( (a-c) * (a-c) + (b-d) * (b-d));
		}
		resp *= 2;
		resp /= 20000.0/60.0;
		ll out = round(resp);
		if( TT > 0) puts("");
		printf("%lld:%02lld\n", out/60, out % 60);
	}
	return 0;
}