//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2294
//#tag number theory teoria dos numeros
//#tag gaussian elimination eliminacao de gauss
//#sol can use the gaussian elimination to solve the linear equation problem with the first 7 
//equations. or can notice that a_i <= 1000, so for the case of f(1001) we can discover a_i by 
//decomposing f(1001) in the base 1001, since a_1 + a_2 * 1001 + ... + a_6 * 1001 ^ 5

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
#define REP(i,j,k) for(ull (i)=(j);(i)<(k);++(i))
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

const ull maxn = 1500;
ull in[maxn+10];
ull out[10];

int main(){
	IOFAST();
	ull N; cin >> N;
	while(N--){
		REP(i,0,maxn) cin >> in[i];
		ull base = 1001;
		ull num = in[base-1];
		REP(i,0,7){
			out[i] = num % base;
			num -= out[i];
			num /= base;
		}
		bool ok = true;
		REP(i,0,maxn){
			num = in[i];
			REP(j,0,7){
				num -= out[j];
				if(  num % (i+1) != 0) {
					ok = false; goto end;
				}
				num /= (i+1);
			}
			if( num != 0){
				ok = false; goto end;
			}
		}
		end:
		if( ok){
			REP(i,0,7){
				cout << ((i==0)?"":" "); cout << out[i];
			}
			cout << endl;
		} else {
			cout << "This is a smart sequence!" << endl;
		}
	}
	return 0;
}