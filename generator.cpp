#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<iostream>

using namespace std;

#define fr(i,j,k) for(int (i)=(j);(i)<(k);++(i))

int main(){
	srand( (unsigned int) time(0));	
	fr(i,0,100){
		int num = rand() % 99 + 1;
		printf("%d\n", num );
		printf("%d %d\n%d", (rand() % 99 + 1), (rand() % 99 + 1) );
		
		fr(i,0,num){
			int aux = rand() % 400;
			printf("%d %d\n", aux , aux+ (rand()%200));
		}
	}
	cout << 0 << endl;
	return 0;
}

