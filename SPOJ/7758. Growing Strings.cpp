//http://www.spoj.com/problems/MGLAR10/
//#tag String
//#tag Aho Corasick
//#sol Concatenate the strings, separating them with a special character, e.g the '#'. This will be the text
// where you will search the other original strings, each occurrence will determine which strings are sub strings
// of others. create a DAG and compute the longest path in this DAG.

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

const int MAXN = 2000003;
const int MAXNUM = 20000;

vector<int> adj[MAXNUM];
char strs[MAXNUM][1010];
int inde[MAXN];

struct No{
	int fail;
	vector< pair< int,int > > out;
	map<char,int> lista;
	int next;
};

No arvore[MAXN];
int qtdNos, qtdPadroes;

void inic(){
	arvore[0].fail = -1;
	arvore[0].lista.clear();
	arvore[0].out.clear();
	arvore[0].next = -1;
	qtdNos = 1;
	qtdPadroes = 0;
}

void adicionar(char * padrao){
	int no = 0, len = 0;
	for( int i = 0; padrao[i]; i++, len++){
		if( arvore[no].lista.find(padrao[i]) == arvore[no].lista.end()){
			arvore[qtdNos].lista.clear(); arvore[qtdNos].out.clear();
			arvore[no].lista[padrao[i]] = qtdNos;
			no = qtdNos++;
		} else no = arvore[no].lista[padrao[i]];
	}
	arvore[no].out.push_back(pair<int,int>(qtdPadroes++, len));
}

void ativar(){
	int no, v, f,w;
	queue<int> fila;
	for(map<char,int>::iterator it = arvore[0].lista.begin(); it != arvore[0].lista.end(); it++){
		arvore[no = it->second].fail = 0;
		arvore[no].next = arvore[0].out.size()? 0 : -1;
		fila.push(no);
	}
	while( !fila.empty()){
		no = fila.front(); fila.pop();
		for(map<char,int>::iterator it = arvore[no].lista.begin(); it!= arvore[no].lista.end(); it++){
			char c = it->first;
			v = it->second;
			fila.push(v);
			f = arvore[no].fail;
			while( arvore[f].lista.find(c) == arvore[f].lista.end()){
				if( f == 0) { arvore[0].lista[c] = 0; break; }
				f = arvore[f].fail;
			}
			w = arvore[f].lista[c];
			arvore[v].fail = w;
			arvore[v].next = arvore[w].out.size()? w : arvore[w].next;
		}
	}
}
	
void buscar( char * input){
	int v, no = 0;
	for( int i =0; input[i]; i++){
		while( arvore[no].lista.find(input[i]) == arvore[no].lista.end()){
			if( no == 0) { arvore[0].lista[input[i]] = 0; break; }
			no = arvore[no].fail;
		}
		v = no = arvore[no].lista[input[i]];
		while( v != -1 ){
			for( int k = 0; k < (int) arvore[v].out.size(); k++){
				//printf("Padrao %d na posicao %d\n", arvore[v].out[k].first, i-arvore[v].out[k].second +1);
				int a1 = arvore[v].out[k].first;
				int a2 = i-arvore[v].out[k].second +1;
				int mysz = adj[arvore[v].out[k].first].size(); 
				if( mysz == 0 || inde[a2] != adj[a1][mysz-1] ){
					 adj[a1].PB( inde[a2] );
					// DB( a1 _ inde[a2]);
				}
			}
			v = arvore[v].next;
		}
	}
}

int dist[MAXNUM];

int rec(int no){
	if( dist[no] != -1) return dist[no];
	int ret = 0;
	REP(i,0,(int)adj[no].size()){
		if( adj[no][i] == no ) continue;
		ret = max( ret, rec( adj[no][i] ) + 1);
	}
	return dist[no] = ret;
}

int main(){
	IOFAST();
	int num;
	while( cin >> num){
		REP(i,0,num+1) adj[i].clear();
		if(num == 0) break;
		string tot = "";
		inic();
		REP(i,0,num){
			cin  >> strs[i];			
			adicionar( strs[i] );
			tot += strs[i];
			tot += "#";
		}
		ativar();
		int pat = 0;
		REP(i,0,(int)tot.size()){
			inde[i] = pat;
			if( tot[i] == '#' ) pat++;
		}
		char * ctot = new char[tot.size()+1];
		strcpy( ctot , tot.c_str() );
		buscar( ctot );
		FILL(dist,-1);
		int resp = 0;
		REP(i,0,num){
			resp = max( resp, rec( i));
		}
		cout << (resp+1) << endl;
			
	}
	
	return 0;
}