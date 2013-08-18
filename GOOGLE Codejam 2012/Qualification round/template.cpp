#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<iostream>
#include<vector>
#include<set>
#include<queue>

using namespace std;

int i,j,k,n,m,c,d,topo, caso = 1, t;
char in1[150], in2[150];
char map[] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
// bool used[30];s


int main(){
	
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("out.txt", "w", stdout);

	scanf("%d\n" , &t);
	// memset(used,false,sizeof(used));
	while(t--){
		gets(in1);
		// gets(in2);
		printf("Case #%d: ", caso++);
		for(i=0; in1[i];i++){
			if( in1[i] != ' ') {
				printf("%c", map[in1[i] - 'a']);
				// map[in1[i]-'a'] = in2[i];
				// used[in2[i]-'a'] = true;
				// printf("%c ->%c\n", in1[i], map[ in1[i]-'a']);
			} else {
				printf(" ");
			}
		}
		cout << endl;
		// cout << "FuCK" << endl;
	}
	
	// for(i=0;i<26;i++){
		// if(!used[i]) printf("naum usou: %c\n", 'a' + i);
	// }
	// for(i=0;i<25;i++){
		// printf("'%c',", map[i]);
	// }
	// printf("'q'");
	return 0;
}

