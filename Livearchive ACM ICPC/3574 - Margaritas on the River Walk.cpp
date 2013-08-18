//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=376
//#tag pd
//#tag sub set sum
//#sol usar o subset sum para verificar todas as vezes que somando um certo número a uma determinada 
//combinação será menor ou igual ao máximo que posso gastar e maior que o valor mínimo dentre os
//valores que não foram usados

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

ll in[40];
ll pd[30001];
bool cmp(ll x, ll y){
	return x > y;
}
int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	int t ; cin >>t;
	fr(c,0,t){
		ll aux, sum =0;
		int n,m;
		cl(in);
		scanf("%d %d", &n, &m);
		// cout << "n m = " << n << " " << m << endl;
		fr(i,0,n) {
			scanf("%lld", in+i);
		}
		sort(in,in+n,cmp);
		int mini = in[n-1];
		ll resp = 0;		
		cl(pd);
		pd[0] = 1;
		if( n == 1) {	
			cout << (c+1) << " " << ((in[0]<=m)? 1:0) << endl;
		}
		fr(i,0,n-1){
			for(int k=m;k>=0;k--){
				if(pd[k]){
					if( k + in[i] > m - mini && k + in[i] <= m)	resp += pd[k];
					pd[k + in[i]] += pd[k];
				}
			}
		}
		int cur = in[n-1];		
		for(int i = n-2; i >=0; i--){
			mini = in[i];
			fr(k,0,m) if(pd[k]) pd[k+in[i]] -= pd[k];
			fr(k,0,m) if(pd[k] && k + cur > m -mini && k+cur <= m) resp += pd[k];
			cur += in[i];
		}
		cout << (c+1) << " " << resp << endl;
	}
	
	return 0;
}


