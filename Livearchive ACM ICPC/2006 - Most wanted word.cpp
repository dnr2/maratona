//http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=86&page=show_problem&problem=7

#include <stdio.h>
#include <cstring>
#include <iostream>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <map>
#include <stack>
#include <list>

using namespace std;

int n, m, i, j, k, len, resp, t, K;

int maior = 0, indexMaior = 1;
int num = 1;
char str[3000], buf[100];
int arr[2100];
map<string, int> hashIn;
map<int, string> hashOut;
string aux, patern = "";

char lower_case(char x) {
	if( x <= 'Z' ) return x + 'z' - 'Z';
	return x;
}

bool least = false;

int main(){

    //freopen("in.txt", "r", stdin );
	//freopen("out.txt", "w", stdout ); 

	memset(arr, 0 , sizeof(arr));
	memset(buf, 0 , sizeof(buf));
	memset( str, 0 , sizeof(str));
	
	for(int i = 1; i < 256; i++){
		if((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z')) continue;
		patern += i;
	}
	
	while( scanf("%s", str) > 0){
        
		if( str[0] == '#' ){
            //printf("FUCKK!!\n");
			if( num > 1 ) {
				if( maior < 10) printf("   ");
				else if( maior < 100) printf("  ");
				else if( maior < 1000) printf(" "); 
				printf("%d %s\n", maior, hashOut[indexMaior].c_str());
            }
			hashIn.clear();
			hashOut.clear();
			memset(arr, 0 , sizeof(arr));
			num = 1;
			maior = 0;
			indexMaior = 1;
		} else {
			least = false;
			
			for( int i = 0; str[i]; i++){
				if( !( str[i] >= 'a' && str[i] <= 'z') && !(str[i] >= 'A' && str[i] <= 'Z') ){
					str[i] = ' ';
				} else if(str[i] >= 'A' && str[i] <= 'Z') {
					str[i] = str[i] - 'A' + 'a';
				}
			}
			len = 0;
			
			
			
			while( str[len] && str[len] == ' '){
                    len++;
            }
			while(sscanf( str + len, "%s", buf ) > 0 ){
                //printf("%s\n", buf);
				aux = buf;
				if( hashIn[aux] == 0){
					hashOut[num] = aux;
					hashIn[aux] = num++;
				}
				arr[hashIn[aux]] += 1;
				if( maior < arr[hashIn[aux]] ) {
					maior = arr[hashIn[aux]];
					indexMaior = hashIn[aux];
				}
				len += strlen(buf);
				while( str[len] == ' '){
                    len++;
                }
                memset(buf, 0 , sizeof(buf));
			}
			
		} 
		memset( str, 0 , sizeof(str));
		
	}
	
}
