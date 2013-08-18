//
//#tag
//#sol

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

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

ll primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197};

ll fast( ll x, ll y){
	if( y == 0) return 1;
	if( y & 1) return x * fast(x,y-1);
	ll ret = fast( x, y/2);
	return ret*ret;
}

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	int bigest = 0;
	fr(i,0,0){
		int cont = 0;
		for(int j =1; j*j <= i; j++){
			if( i % j == 0){
				if( j*j == i) cont++;
				else cont+=2;
			}
		}
		if( bigest < cont) {
			bigest = cont;
			printf("%d -> %d\n", i, cont);
		}
	}
	priority_queue<int> resp;
	fr(i,1,1000){
		vector<int> nums; int aux = i;
		for( int j=2; j*j<=i && aux > 1;j++){
			while( aux%j == 0) nums.pb(j), aux/=j;
		}
		if(aux > 1) nums.pb(aux);
		sort(nums.begin(), nums.end(), greater<int>() );
		ll val = 1;
		bool ok = true; int pont = 0; int dois = 1;
		fr(i,0,nums.size()){
				val *= fast( primes[pont++], (nums[i]-1));			
			if(  val == 0 || val > 100000000){ ok = false; break;}
		}
		if( ok ) {
			while(!resp.empty() && resp.top() >= val) resp.pop();
			resp.push(val);			
		}
	}
	stack<int> pilha;
	while(!resp.empty()) pilha.push(resp.top()), resp.pop();
	while(!pilha.empty()) {
		cout << pilha.top() << endl; pilha.pop();
	}
	
	return 0;
}