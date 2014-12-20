//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=342&page=show_problem&problem=437
//#tag string
//#sol the complicated part is to make sure you are reading the input and printing the output correctly.
//"rotate" the string form the output and use a stringstream or similar so separate words in a line;

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
#include <cassert>

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

const int MAXN = 41;

string in[MAXN];
string inv[MAXN];


int main(){
	IOFAST();
	int L, W;
	while( cin >> L >> W ){		
		int pn = 1, N;
		string NN;
		while (cin >> NN){
			if( NN == "##") break;
			N = atoi( NN.c_str());
			string str;
			int pos = 0;
			getline( cin  , str);			
			while( getline( cin, str )){
				if( str == "#" ){
					cout << "Page number " << (pn++) << endl;					
					REP(i,0,N) inv[i] = "";
					REP(i,0,N){
						REP(j,0,pos){
							inv[i] += in[j][i];
						}
					}
					stringstream ss[MAXN];
					REP(i,0,N){					
						ss[i].str(inv[i]);
					}
					int cont = 0, linepos = 0;;
					
					string aux;
					
					while( true){
						REP(i,0,N){
							bool ok = ss[i] >> aux;							
							if( ok ){								
								if( linepos + (linepos > 0) + (int)aux.size() > W && linepos > 0){
									cout << endl;
									linepos = 0;
								}
								if( linepos > 0){
									cout << " ";									
									linepos++;
								}
								cout << aux;								
								cont++;
								linepos += aux.size();							
							} else {								
								goto end;
							}
						}
					}
					end :
					if( cont == 0 ){
						cout << "This page is empty." << endl;
					} else if( linepos > 0) cout << endl; 
					break;
				}			
				in[pos++] = str;
			}			
		}		
	}	
	return 0;
}