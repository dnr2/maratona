//http://www.spoj.pl/problems/PHONELST/

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<iostream>
#include<string>

using namespace std;

struct no{
	no * arr[11];
	bool folha;
};	

no * root, * cur;

bool rec(no * a){
	bool resp = true;
	for( int i=0;i<10;i++){
		if( a->arr[i] == NULL) continue;
		if( a->folha ) return false;
		resp = resp & rec( a->arr[i]);
	}
	return resp;
}

int main(){

	int t,n;
	cin >>t;
	string str;
	while( t--){
		scanf("%d", &n);
		root = new no();
		for( int i=0;i<n;i++){
			cin >> str;
			cur = root;
			for( int j=0;j < str.size(); j++){
				if( cur->arr[str[j] -'0'] != NULL ){
					cur = cur->arr[str[j] -'0'];
				} else {
					cur->arr[str[j] -'0'] = new no();
					cur = cur->arr[str[j] -'0'];
				}
			}
			cur->folha = true;
		}
		if( rec( root) ) puts("YES");
		else puts("NO");
	}
	return 0;
}
