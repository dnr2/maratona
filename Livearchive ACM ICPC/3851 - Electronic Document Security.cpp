//https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=1852

#include<bits/stdc++.h>
#define REP(i,j,k) for(int (i)=(j); (i) < (k); (i)++)
#define PB push_back
#define MP make_pair
#define FT first
#define SD second
#define FILL(a,b) memset(a,b,sizeof a)

using namespace std;

int main(){
	
	string str; int cn = 1;
	while( getline(cin,str) ){
		if( str== "#") break;
		REP(i,0,(int)str.size()){
			if( str[i] == ',' ) str[i] = ' ';
		}
		stringstream ss(str);
		string tok; 
		map<char, set<char> > mapa;
		vector< pair<char, set<char> > > vec;
		while( ss >> tok ){
			int sz = tok.size();	
			REP(i,0,sz){
				if( tok[i] == '-' || tok[i] == '+' || tok[i] == '=' ){
					REP(x,0,i){
						if( tok[i] == '+'){
							REP(y,i+1,sz){
								mapa[tok[x]].insert(tok[y]);
							}
						} else if(tok[i] == '-') {
							REP(y,i+1,sz){
								mapa[tok[x]].erase(tok[y]);
							}
						} else {
							set<char> news;
							REP(y,i+1,sz){
								news.insert(tok[y]);
							}
							mapa[tok[x]] = news;
						}
					}
				}
			}
		}
		
		for(map<char, set<char> >::iterator it = mapa.begin(); it != mapa.end(); it++){
			if( !(it->SD.empty()) ){
				vec.PB( MP( it->first, it->SD)); 
			}
		}
		
		printf("%d:", cn++);
		int sz = vec.size();
		REP(i,0,sz){
			printf("%c", vec[i].FT);
			if( i + 1 >= sz || vec[i].SD != vec[i+1].SD ){
				set<char> s = vec[i].SD;
				for(set<char>::iterator it = s.begin(); it!= s.end(); it++){
					printf("%c", *it);	
				}
			}
		}
		puts("");
	}
	
	return 0;
}	