//http://br.spoj.pl/problems/ESTAC/

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<list>
#include<iostream>


#define pii pair<int,int>
#define F first
#define S second

using namespace std;

list<pii> est;

bool cmp(pii x, pii y){
	return x.F < y.F;
}

int main(){
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	int n,m,a,b,c,d;
	char str[5];
	while(scanf("%d%d", &n,&m)>0 ){
		est.clear();
		int resp =0;
		est.push_back(pii(0,n));
		for( int i=0;i<m;i++){
			scanf("%s", str);
			if( str[0] == 'C'){
				scanf("%d%d", &a,&b);
				for( list<pii>::iterator it = est.begin(); it != est.end(); ++it){
					if( it->S >= b && it->F == 0) {
						int orilen = it->S;
						it = est.erase(it);
						est.insert(it, pii(a,b));
						resp += 10;
						if( orilen > b) est.insert(it, pii(0,(orilen -b)));
						break;
					}
				}
				// cout << est.size() << endl;
				
			} else {
				scanf("%d", &a);
				for( list<pii>::iterator it = est.begin(); it != est.end(); ++it){
					if( it->F == a) {
						list<pii>::iterator it1 = it, it2 = it;
						it1--;
						it2++;
						it->F = 0;
						if( it1->F == 0 && it != est.begin()){
							it->S += it1->S;
							est.erase(it1);
						}
						if( it2 != est.end() && it2->F == 0){
							it->S += it2->S;
							est.erase(it2);
						}
						break;
					}
				}
			}
		}
		printf("%d\n", resp);
		
		
	}
	return 0;
}