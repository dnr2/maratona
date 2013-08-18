#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

#define pii pair<int,int>
#define MAP map<int,int>
#define F first
#define S second

using namespace std;

MAP pd[100010];

bool napraia(pii x, const MAP & p  ){
	MAP::const_iterator it = p.lower_bound( x.F);
	if( it == p.begin()) return true;
	return (--it)->S >= x.S;
}

void update(MAP & p , pii x){
	
	MAP::iterator it = p.lower_bound(x.F), ini = it;
	if( it != p.end() && it->F == x.F && it->S <= x.S) return;
	if( it != p.begin() && (--it)->S <= x.S) return;
	it = ini;
	while( it != p.end() && it->S >= x.S) it++;
	p.erase( ini, it);
	p[x.F] = x.S;
}

int main(){

	// freopen("in.txt" , "r", stdin);
	// freopen("out.txt" , "w", stdout);
	
	int t, a,b,c,d,n,m;
	cin >> t;
	int len = 0, k;
	while( t--){
		scanf("%d%d", &a, &b);
		k = upper_bound( pd, pd + len, pii(a,b) , napraia) - pd;
		if( len == k) len++;
		update( pd[k] , pii(a,b));
	}
	cout << len << endl;
	
	return 0;
}
