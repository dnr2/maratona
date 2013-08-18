//http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2889
//#tag: back tracking 
//#tag: memoization 

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include <utility>
#include <string>

using namespace std;

int i,j,k,a,b,c,d,t,n,m, caso =1;
int in1[1010], in2[1010], p[3010];
bool pd[1010][1010][2];

bool back(int x, int y, bool isF, int e){

	if(pd[x][y][isF]) return false;
	pd[x][y][isF] = true;

	// printf("%d %d error? = %d -> %d\n", x, y, e,  isF);  
	if( x >= n && y >= m) return true;	
	bool ok = false;
	if( isF){
		if( x < n && in1[x] == p[x+y] ){		
			ok = back( x + 1, y, true, 0);
			// cout << "habla -> " << ok << endl;
			if( ok ) return true;
		} 
		if( e == 0) return back( x , y, false, 1);
		else return false;
	} else {
		if( y < m && in2[y] == p[x+y] ){		
			ok = back( x , y + 1, false, 0);
			if( ok ) return true;
		}
		if( e == 0) return back( x , y, true, 1);
		else {
			return false;
		}
	}
	return false;
}



int main(){
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	while( scanf("%d%d", &n, &m) > 0 && n != 0){			
		memset( pd, false, sizeof(pd));
		for(i=0;i<n;i++){
			scanf("%d", &in1[i]);
		}
		for(i=0;i<m;i++){
			scanf("%d", &in2[i]);
		}
		
		for(i=0;i<n+m;i++){
			scanf("%d", &p[i]);
		}		
		if( back(0,0,true,0) || back(0,0,false,0)) printf("possible\n");
		else printf("not possible\n");
	}

	return 0;
}
