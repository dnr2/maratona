//http://codeforces.com/contest/155/problem/C
//#tag greedy guloso
//#sol para cada conjunto de seguido de caracteres que pertencem a uma restrição, somar a resposta
//o mínimo entre o número de cada um dos caracteres da restrição

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

using namespace std;

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	string str, aux;
	int n,m,t, resp =0;
	
	cin >> str;
	cin >> t;
	fr(i,0,t) {
		cin >> aux;
		fr(j,0,str.size()){
			if( str[j] == aux[0] || str[j] == aux[1]){
				n = 0, m = 0;
				fr(k,j,str.size()){
					if( str[k] != aux[0] && str[k] != aux[1]) break;
					if( str[k] == aux[0] ) n++;
					if( str[k] == aux[1] ) m++;
					j++;
				}
				resp += min(n,m);
			}
		}
	}
	cout << resp << endl;
	return 0;
}