//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=123
//#tag
//#sol

#include <bits/stdc++.h>


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

const int maxn = 1000;

string ants[maxn];
string antn[maxn];
int antx[maxn];
char aux[maxn];

void printline(string nnn, string xxx, int xval ){	
	while(xxx.size() < string("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx").size()){
		xxx += " ";
	}
	int xval1 = abs(xval / 100);
	int xval2 = abs(xval % 100);
	sprintf(aux, "%7d.%02d", xval1, xval2 );
	if( xval < 0 && xval1 >= 0 ){
		// DB( xval _ xval1 );
		REP(i,0,strlen(aux)){
			if( aux[i] != ' '){
				assert( i > 0 );
				aux[i-1] = '-';
				break;
			}
		}
	}
	printf("%s %s %s\n", nnn.c_str(), xxx.c_str(), aux);
}

int main(){
	
	map<string,string> fsec;
	string str; 
	while(getline(cin, str)){		
		string nnn = str.substr(0,3);
		string xxx = str.substr(3);
		fsec[nnn] = xxx;
		if( nnn == "000") break;
	}
	int balance = 0;
	int pos = 0;
	while(getline(cin, str)){
		string sss = str.substr(0,3);
		string nnn = str.substr(3,3);
		string xxx = str.substr(6);
		int xval; sscanf(xxx.c_str(), "%d", &xval);
		int antxval = xval;
		if(  sss == "000" || ( pos > 0 && sss != ants[0] )){
			if( balance != 0){
				printf("*** Transaction %s is out of balance ***\n", ants[0].c_str() );
				REP(i,0,pos){
					printline(antn[i], fsec[antn[i]], antx[i]);				
				}
				balance = -balance;
				printline(string("999"), string("Out of Balance"), balance);
				puts("");
			}			
			pos = 0;
			balance = 0;		
		}
		ants[pos] = sss;
		antn[pos] = nnn;
		antx[pos] = antxval;
		pos++;
		balance += xval;
		
	}
	
	
	
	return 0;
}