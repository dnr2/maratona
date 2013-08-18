//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3878
//#tag ad-hoc 

#include <bits/stdc++.h>

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

using namespace std;

int n, cur,cont;

void rec(int pos){
	if( cont == 0) return;
	cur = (((~cur & (~(1<<pos)) ) | ((1<<pos) & cur )) & ( (1<<n) -1));
	printf("%d\n", cur);
	cont--;
	fr(j,0,pos){
		rec(j);
	}
}

int main(){
	
	int t; cin >> t;
	while(t--){
		scanf("%d", &n);
		if( n & 1) continue;
		cont = (1<<n) - 1;
		cur = 0;
		puts("0");
		fr(i,0,n){
			rec(i);
		}
	}
	return 0;
}