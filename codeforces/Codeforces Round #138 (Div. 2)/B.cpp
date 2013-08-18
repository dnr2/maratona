#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
#include<stack>

#define fr(i,j,k) for(int (i)=(j);(i) <(k);++(i))
#define ms(i,j) memset((i),(j),sizeof((i)))
#define MAXN 101000
#define ll long long
#define MAP map<int,int>
#define pii pair<int,int>
#define F first
#define S second
#define PI acos(-1)
#define db(x) cout << x << endl;

using namespace std;

int arr[100100];

int main(){
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	int n, k, p;
	cin >> n >> k;
	fr(i,0,n) scanf("%d", &arr[i]);
	int s = 0;
	MAP mapa;
	fr(i,0,n) {
		// cout << arr[i] << endl;
		mapa[arr[i]]++;
		if( mapa.size() == k) {
			mapa.clear();
			for(int j= i; j >=0;j--){
				mapa[arr[j]]++;
				if( mapa.size() == k) {
					printf("%d %d\n", j+1 ,i+1);
					return 0;
				}
			}
		}
	}
	
	puts("-1 -1\n");
	
	return 0;
}