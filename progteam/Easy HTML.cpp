//
//#tag
//#sol

#include<bits/stdc++.h>

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

const int MAXN = 3000;

string in;

bool is_alphanum(char c){
	return (c >= 'A' && c <= 'Z' ) || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}

string process(int ini, int end);

string handle_simblings(int ini, int end){	
	string ret = "";
	if( in[ini] != '(' ){
		ret = process(ini, end);
	} else {
		int cont = 0;
		int begin = ini;
		REP(i,ini,end+1){
			if( in[i] == '('){ 
				cont++;
			} else if( in[i] == ')'){
				cont--;
			}
			if( cont == 0 ){
				ret += handle_simblings( begin + 1, i-1);
				begin = i+1;
				cont = 0;
			}
		}
	}
	return ret;
}

//TODO ver ponteiros e referencia, como copiar objeto?
string process(int ini, int end){	
	
	string nome = "";	
	vector<string> id;
	vector<string> classes;		
	string filhos = "";	
	int fact = 0;
	string ret = "";
	
	REP(i,ini,end+1){
		int sz = 0;
		if( in[i] == '>'){
			if( i + 1 < (int) in.size()) filhos = handle_simblings( i + 1 , end);
			break;
		} else if( in[i] == '#'){
			REP(j,i+1,end+1){
				if( !is_alphanum(in[j]) ) break;
				sz++;
			}			
			id.push_back( in.substr( i + 1, sz ) );			
		} else if( in[i] == '.'){		
			REP(j,i+1,end+1){
				if( !is_alphanum(in[j]) ) break;
				sz++;
			}			
			classes.push_back( in.substr( i + 1, sz ) );		
		} else if( in[i] == '*'){			
			REP(j,i+1,end+1){
				if( !is_alphanum(in[j]) ) break;
				sz++;
				fact *= 10;
				fact += (in[j]-'0');
			}
		} else {
			nome += in[i];
		}
		i += sz;
	}	
	ret += "<"; ret += nome;
	if( id.size() > 0){
		ret += " id=\""; ret += id[0]; ret += "\"";
	}
	if( classes.size() > 0){
		ret += " class=\""; ret += classes[0];
		REP(i,1,(int)classes.size()){
			ret += " ";
			ret += classes[i];
		}
		ret += "\"";
	}	
	ret += ">";
	ret += filhos;
	ret += "</"; ret += nome; ret += ">";
	if( fact > 0){
		string aux = ret;
		REP(i,1,fact) ret += aux;
	}
	return ret;
}

int main(){
	
	while( cin >> in){		
		cout << handle_simblings(0,(int)in.size()-1) << endl;
	}
	return 0;
}