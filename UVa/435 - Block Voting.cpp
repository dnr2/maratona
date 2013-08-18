//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=376
//#tag pd
//#tag sub set sum
//#sol usar o subset sum para verificar como 

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

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	int t ; cin >>t;
	while(t--){
		ll aux, sum =0;
		int n;
		scanf("%d", &n);
		fr(i,0,n) {
			scanf("%lld", in+i);
			sum += in[i];
		}
		aux = (sum/2 + 1);
		fr(i,0,n){
			cl(pd);
			pd[0] = 1;
			fr(j,0,n){
				if(j==i) continue;
				for(int k=sum;k>=0;k--){
					if(pd[k]) pd[k + in[j]] += pd[k];
				}
			
			}
			ll resp = 0;
			fr(j, aux - in[i], aux){
				resp += pd[j];
			}
			printf("party %d has power index %lld\n", i+1, resp);
		}
		puts("");
	}
	
	return 0;
}


