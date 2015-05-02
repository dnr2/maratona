//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1816
//#tag implementation ad hoc
//parse the input, use stack tocalculate the expression result, be aware that the result can be negative or zero.

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

#define VS vector<string>

const int maxn = 100;
string in[10];
VS parse[10];

VS op[30];
string arr[10];

int main(){
	IOFAST();
	arr[0] = "000 .0. 000 000 0.0 000 0.. 000 000 000 .0. ... 0.0 .0.";
	arr[1] = "0.0 .0. ..0 ..0 0.0 0.. 0.. ..0 0.0 0.0 .0. ... 0.0 ...";
	arr[2] = "0.0 .0. 000 000 000 000 000 ..0 000 000 000 000 .0. 000";
	arr[3] = "0.0 .0. 0.. ..0 ..0 ..0 0.0 ..0 0.0 ..0 .0. ... 0.0 ...";
	arr[4] = "000 .0. 000 000 ..0 000 000 ..0 000 ..0 .0. ... 0.0 .0.";
	
	string str;
	REP(i,0,5){
		stringstream ss( arr[i] );
		REP(j,0,14){
			ss >> str;
			op[j].PB( str );
		}
	}
	while( true) {
		REP(i,0,5){
			getline( cin , in[i] );
		}
		int n = (in[0].size() + 1)/4;		
		//DB( n );
		REP(i,0,5){
			stringstream ss(in[i]);
			parse[i].clear();
			REP(j,0,n){
				ss >> str;
				parse[i].PB( str );
			}				
		}
		
		vector<PII> ops;
		int num = 0;
		
		REP(i,0,n){			
			REP(j,0,14){
				bool ok = true;
				REP(kk,0,5){
					if( parse[kk][i] != op[j][kk] ){
						ok = false; break;
					}
				}
				if( ok ){
					
					if( j < 10){
						num *= 10; num += j;
					} else {
						ops.PB( MP(0, num) );
						ops.PB( MP(1, j - 10) );
						num = 0;
					}
					break;
				}
			}
		}
		
		ops.PB( MP(0,num) );
		if( ops.size() == 1 && ops[0] == MP(0,0) ) break; //end of cases
		
		
		stack<PII> nops;
		REP(i,0,(int)ops.size()){
			//DB( i _ ops[i].FT _ ops[i].SD );
			if( ops[i].FT == 0){
				nops.push( ops[i] ); 
			} else if( ops[i].SD < 2){
				nops.push( ops[i] );
			} else {
				int topo = nops.top().SD; nops.pop();
				if( ops[i].SD == 2 ){
					i++;
					nops.push( MP( 0, topo * ops[i].SD));
				} else {
					i++;
					nops.push( MP( 0, topo / ops[i].SD ));
				}
			}
		}
		stack<PII> nn, nada; nn = nops; nops = nada; 
		while( !nn.empty()){
			nops.push( nn.top() ); nn.pop();		
		}
		while( (int) nops.size() > 2 ){
			int a = nops.top().SD; nops.pop();
			PII b = nops.top(); nops.pop();
			int c = nops.top().SD; nops.pop();
			//DB( b.SD _ a _ c);
			if( b.SD == 0) nops.push( MP(0, a + c) );
			if( b.SD == 1) nops.push( MP(0, a - c) );
		}
		int resp = nops.top().SD;
		//DB( resp );
		vector<int> nums; bool neg = false; 
		if( resp != 0){
			if( resp < 0 ) {
				neg = true; resp = abs(resp);
			}
			while( resp > 0){
				nums.PB( resp % 10);
				resp /= 10;
			}
		} else { 
			nums.PB(0);
		}
		
		
		reverse( nums.begin() , nums.end());
		REP(j,0,5){
			if( neg ){
				cout << op[11][j];
			}
			REP(i,0,(int)nums.size()){
				if( i > 0 || neg ) cout << " ";				
				cout << op[nums[i]][j];
			}
			cout << endl;
		}
		cout << endl;
		
		
		getline( cin , str  );
	}
	return 0;
}