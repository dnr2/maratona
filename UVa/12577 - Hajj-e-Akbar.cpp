//http://uva.onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=4022

#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<cstring>

#define fr(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define cl(i) memset(i,0,sizeof(i))
#define F first
#define S second
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define PI acos(-1)
#define db(x) if(1) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define ll long long

using namespace std;

int main(){
	
	string s1 = "Hajj-e-Akbar", s2 = "Hajj-e-Asghar";
	
	string s;
		int caso = 1;
	while(cin >> s && s != "*"){
		printf("Case %d: ",caso++);
		if(s == "Hajj"){
			cout << s1 << endl;
		}else if (s == "Umrah"){
			cout << s2 << endl;
		}
	}
	
	return 0;
}