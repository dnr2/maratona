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

using namespace std;

char str[110];
int main(){
    
	int t, caso = 1; scanf("%d\n", &t);
	while( t--){
		gets(str); int pilha = 0, mais = 0, menos = 0;
		bool resp = true;
		for(int i = 0; str[i]; i++){
			if( str[i] == '('){
				pilha++;
			} else if( str[i] == ')'){
				pilha--;
			} else if( str[i] == ':' ){
				if( str[i+1] == '(') {
					menos++;
				} else if( str[i+1] == ')' ){
					mais++;
				}
			}
			db( i _ mais _ pilha _ menos);
			if( pilha == 0) menos = 0;
			if( pilha == -1 && mais > 0) { mais--; pilha++; }
			if( pilha < 0 && mais <= 0){ resp = false; break; }
		}
		if( pilha - menos > 0) resp = false;
		if( resp ) printf("Case #%d: YES\n", caso++);
		else printf("Case #%d: NO\n", caso++);
	}
	return 0;
}

//%SystemRoot%\system32;%SystemRoot%;%SystemRoot%\System32\Wbem;%SYSTEMROOT%\System32\WindowsPowerShell\v1.0\;C:\Program Files\WIDCOMM\Bluetooth Software\;%PROGRAMFILES%\Internet Explorer;C:\Dev-Cpp\bin


