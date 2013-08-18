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

char in[1010];
int pos[5];
char aux[5];

int main(){
	
	int n;
	memset(in,'.',sizeof(in));
	scanf("%d",&n);
	scanf("%s",in+1);		
	int cont = 0;
	char act = '.';
	for(int i=0; in[i]; i++){
		if( act != in[i] ){
			aux[cont] = in[i];
			pos[cont++] = i;
			act = in[i];
		}
	}
	if( cont == 2) {
		if( aux[0] == 'L') cout << (pos[1]-1) <<  " " << (pos[0]-1) << endl;
		if( aux[0] == 'R') cout << (pos[0]) <<  " " << (pos[1]) << endl;
	} else if( cont == 3 ){		
		cout << (pos[0]) <<  " " << (pos[1]-1) << endl;
	}	
	//db( in _ cont _ pos[0] _ pos[1] _ aux[0] _ aux[1]);
	return 0;
}
