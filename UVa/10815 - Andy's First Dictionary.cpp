//10815 - Andy's First Dictionary
//#tag map
//#tag data structure estrutura de dados
//#sol ler cada palavra, botar em lowercase e armazenar em um map, depois varrer o map com um iterator
// imprimindo as respostas

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

// #include <unordered_map>

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define F first
#define S second
#define fr(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define rep(i,n) for(int (i)=0;(i)<(n);++(i))
#define pb push_back
#define PI acos(-1)
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define mp make_pair
#define cl(x) memset(x,0,sizeof(x))

// #define umap unordered_map

using namespace std;

int main(){
	
	map<string, bool> mapa;
	char in; int len =0;
	string str="";
	while(scanf("%c",&in)>0){
		// cout << in << endl;
		if( ('a' <= in && in <= 'z') || ('A' <= in && in <= 'Z')) str.pb( tolower(in));
		else{
			mapa[str] = true;
			str = "";
		}
	}	
	for( map<string,bool>::iterator it = mapa.begin(); it != mapa.end() ; it++){
		if( it->F.size() >0) cout << it->F << endl;
	}
	return 0;
}