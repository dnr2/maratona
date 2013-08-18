//http://acm.timus.ru/problem.aspx?space=1&num=1452
//#tag dynamic programming pd
//#sol o estado da pd L[i][j] armazena o tamanho de uma sequência que tem como os dois primeiros 
//elementos in[i] e in[j] e a partir disso montamos a pd

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

int in[2003];
short pd[2003][2003];
short track[2003][2003];
// map<pii,int> track;
int  n, x, y;


int main(){
	cin >> n;
	map<int,int> index;
	n++;
	fr(i,1,n) { scanf("%d", &in[i]); index[in[i]] = i;}
	sort(in+1,in+n);
	n = unique(in+1,in+n) - (in+1);
	n++;
	// fr(i,1,n) db( in[i] );
	if( n == 2) {
		printf("1\n1"); return 0;
	}
	int resp = 2; x = 1; y = 2;
	for( int j = n-1; j >= 1; j--){
		int i = j-1, k = j+1;
		while(i >= 1 && k <= n){
			if( in[i] + in[k] < (in[j]<<1)){
				k = k + 1;
			} else if(in[i] + in[k] > (in[j]<<1) ){
				pd[i][j] = 2; i--;
			} else {
				pd[i][j] = pd[j][k] + 1;
				// track[mp(i,j)] = k;
				track[i][j] = k;
				if( resp < pd[i][j]){
					resp = pd[i][j];
					y = i; x = j;
				}
				// db( pd[i][j] _ k _ y _ x);
				i--;k++;
			}
		}
		while( i >= 1){
			pd[i][j] = 2; i--;
		}
	}
	// fr(i,1,n){ fr(j,1,n) cout << track[i][j] << " " ; cout << endl; }
	// cout << track.size() << endl;
	cout << resp << endl;
	printf("%d %d", index[in[y]] , index[in[x]]);
	resp -= 2;
	while(resp--){
		printf(" %d", index[in[track[y][x]]]);
		int aux = track[y][x];
		y = x; x = aux;
	}
	return 0;
}