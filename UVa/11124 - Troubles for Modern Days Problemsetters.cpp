//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2065

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

const int maxn = 1001000;
const int maxm = 1100;
ll arr[maxn];
string str;

int main(){
	int ind; int cn = 1;
	while(cin >> ind && ind){
		getline(cin,str);
		getline(cin,str);
		//DB( str _ ind);
		REP(i,0,(int)str.size()){
			if( str[i] == '(' || str[i] == ')' || str[i] == ',' || str[i] == '+' ){
				str[i] = ' ';
			}
		}
		ll it = 0;
		stringstream ss(str);
		string tok;
		while(ss >> tok){
			//DB( tok );
			if( tok == "NList" ) {
				ll n, num;
				ss >> n;
				REP(i,0,n){
					ss >> num;
					arr[it++] = num;
					
				}
			} else if( tok == "IList" ){
				ll n,s,inc, num;
				ss >> n >> s >> inc;
				num = s; arr[it++] = num;
				REP(i,1,n){
					num += inc;
					arr[it++] = num;
				}
			} else {
				ll n,l,h,s, num;
				ss >> n >> l >> h >> s;
				REP(i,0,n){
					s *= 17; s += 11; s &= (1LL << 32)-1;
					num = l + (s % ( h - l + 1));
					arr[it++] = num;
				}
			}	
		}
		ind--;
		sort(arr,arr+it);
		printf("Case %d: %lld\n", cn, arr[ind]);
		cn++;
	}	
	
	return 0;
}