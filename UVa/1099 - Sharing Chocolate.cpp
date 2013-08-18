//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3540
//#tag pd dinamic programing programação dinamica
//#tag bitmask
//#sol http://f0rth3r3c0rd.wordpress.com/2012/05/11/uva-1099-sharing-chocolate/
//you have to divede and conquer. you must solve the subproblems for each slice in the current chocolate bar and for each subset of friends you want to share
//the pd could have the states [X][Y][Mask] , where x and y are the dimention of the chocolate, and mask is the bitmask of the unfeed friend.
//the above solution is too expensive, but you can memoaze only the states [Y][Mask] to solve the problem, considering that you can derivate X: 
//X = sumOfValues(mask) / y; once x * y must be equal to sumOfValues(mask) (you must check it before you call the function)


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

int in[20];
int pd[101][1<<15], passo = 0;
int presum[1<<15];
int prequant[1<<15];

int quant(int mask){
	int resp = 0;
	while(mask>0) { if(mask&1==1) resp++; mask >>= 1; }
	return resp;
}

int sum( int mask){
	int resp = 0; int i = 0;
	while(mask>0) { if(mask&1==1) resp+=in[i]; mask >>= 1; i++;}
	return resp;
}
// faço x < y sempre
// TODO LL?
bool rec(int y, int mask ){
	if( pd[y][mask] >= passo ) return (pd[y][mask] &1 ) == 1;	
	int x= presum[mask] / y;
	//db(  y _ x _ mask _ prequant[mask] );
	if( prequant[mask] == 1 && presum[mask] == x * y){		
		pd[y][mask] = passo + 1; return true;
	}
	fr(i,1,y){
		int s = mask; bool ret;	
		while(s) {
			s = (s -1) & mask;
			//corte horizontal 
			if(  x * (y-i) == presum[s] &&  x * (i)== presum[(~s)&mask] ) {
				ret = rec( max(x,y-i), s) && rec( max(x,i), ((~s)&mask));
				if( ret ) {
					pd[y][mask] = passo+1; return true;
				}
			}
			//corte vertical
			if( (i < x) && (x-i) * (y) == presum[s] &&  (i)*(y)==presum[(~s)&mask] ){
				ret = rec( max(x-i,y), s) && rec( max(i,y), ((~s)&mask));
				if( ret ) {
					pd[y][mask] = passo+1; return true;
				}
			}
		}
	}
	pd[y][mask] = passo;
	return false;
}

int main(){
	
	int n; int caso = 1;
	for(int i =0; i < (1<<15); i++) prequant[i] = quant(i);
	while(scanf("%d", &n) > 0 && n){
		passo+= 2;
		ll tsum = 0; int x, y; scanf("%d%d", &x, &y);		 
		fr(i,0,n) { scanf("%d", in+i); tsum += in[i]; }
		if( tsum != x * y) printf("Case %d: No\n", caso++);
		else {
			for(int i =0; i< (1<<n); i++) presum[i] = sum(i);
			if( rec( max( x,y), ((1<<n)-1)) ) printf("Case %d: Yes\n", caso++);
			else printf("Case %d: No\n", caso++);
		}
	}
	return 0;
}
