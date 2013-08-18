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
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define ll long long
#define PI acos(-1)
#define EPS 1e-9

using namespace std;


int main(){
	
	string s,e;
	int sp = 0, ep =0;
	cin >> s >> e;
	fr(i,0,s.size()) if( s[i] == '1') sp++;	
	fr(i,0,e.size()) if( e[i] == '1') ep++;
	sp += sp%2;
	if( sp < ep ) printf("NO\n");
	else printf("YES\n");
	
	return 0;
}
