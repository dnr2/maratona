//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=585&page=show_problem&problem=4188
//#tag bit mask mascara de bit
//#tag pd dinamic programming programacao dinamica
//#sol fazer pd para precalcular os valores de 1 a 20. Consideramos que o problema para n teremos soldados de tamanhos de 1 até n
//os estados da pd são: [mask][last][sobe] onde mask é a mascara que diz quais soldados já foram usados, last é o último soldado usado
// e sobe indica se a sequencia está subindo ou descendo

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
#define EPS 1e-9
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

ll resp[] = {
0,
1,
2,
4,
10,
32,
122,
544,
2770,
15872,
101042,
707584,
5405530,
44736512,
398721962,
3807514624,
38783024290,
419730685952,
4809759350882,
58177770225664,
740742376475050,
};

// ll pd[1<<20][23][3];
// int n;
// ll rec(int mask , int last, int sobe){
// 	if( mask == (1<<n)-1) return 1;
// 	if( pd[mask][last][sobe]) return pd[mask][last][sobe];
// 	ll resp = 0;
// 	fr(i,0,n){
// 		if( last == 21){
// 			resp += rec( mask | (1<<i) , i, 2 );
// 		} else if( (sobe ==1) && !(mask&(1<<i)) && (i>last) ){
// 			resp += rec( mask | (1<<i) , i, !sobe );
// 		} else if( (sobe==0) && !(mask&(1<<i)) && (i<last)){
// 			resp += rec( mask | (1<<i) , i, !sobe );
// 		} else if( (sobe==2) && !(mask&(1<<i))){
// 			resp += rec( mask | (1<<i) , i, (last > i) );
// 		}
// 	}
// 	return pd[mask][last][sobe] = resp;
// }


int main(){
	
	// fr(i,2,21){
	// 	ll resp = 0;
	// 	n = i;
	// 	cl(pd);
	// 	resp += rec( 0, 21, 2);		
	// 	cout <<resp << endl;
	// }

	int t; cin >> t; int caso = 1;
	while(t--){
		int n;
		scanf("%d%d", &caso, &n);
		printf("%d %lld\n", caso, resp[n]);
	}
	return 0;
}