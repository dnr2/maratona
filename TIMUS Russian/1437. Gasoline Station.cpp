//http://acm.timus.ru/problem.aspx?space=1&num=1437
//#tag dinamic programming dp pd
//#tag memoization
//#sol estados: volume de cada pote. A partir desses estados podemos ir para os demais.

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

int in[3];
map<int,bool> pd;
map<int,bool> cont;
int resp = 0;

struct s{
	int x[3];
	s( int a =0, int b =0, int c =0){
		x[0] = a; x[1] = b; x[2] = c;
	}
};

void rec( s arg){
	int sum = arg.x[0] + (arg.x[1] << 9) + (arg.x[2] << 18);
	if( pd[sum]) return;
	pd[sum] = true;
	fr(i,0,(1<<3)) {
		sum = 0; int aux = i;
		fr(j,0,3){
			if( aux & 1) sum += arg.x[j]; aux >>=1;
		}
		if( cont[sum] == false) { resp++; cont[sum] = true;}
	}
	fr(i,0,3) if( arg.x[i] < in[i]){
		s aux; aux = arg; aux.x[i] = in[i];
		rec( aux);
	}
	fr(i,0,3){
		fr(j,0,3){
			if( i != j && arg.x[i] > 0 && arg.x[j] < in[j] ){
				s aux = arg; int a = min( arg.x[i] , in[j] - arg.x[j]);
				aux.x[i] -= a; aux.x[j] += a;
				rec( aux );
			}
		}
	}
}

int main(){
	cin >> in[0] >> in[1] >> in[2];
	rec(0);
	if( resp > 0)cout << (resp -1) << endl;
	else puts("0");
	return 0;
}