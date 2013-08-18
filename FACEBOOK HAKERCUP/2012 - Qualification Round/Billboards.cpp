

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int i, j, k, a, b, c, d, n ,m, w, h;
int e;
char str[2100];
char buf[1100];
int nums[1100];

int main(){

	freopen("billboards.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int maior;
	scanf("%d\n", &n);
	c = 1;
	while(n--){
		memset( str, 0 , sizeof(str));
		memset( nums, 0 , sizeof(nums));
		scanf("%d %d ", &w, &h); 
        gets(str);		
		int off = 0, maior = 0, line;
		a = 0;	
		bool achou = false;
		while(sscanf( str + off, "%s", buf) == 1){
			nums[a] = strlen(buf);
			// printf("%d ", nums[a]);
			maior = max( nums[a] , maior);
			off += nums[a++] + 1;			
		}		
		for( i = 1; i <= max(w, h) + 1 && !achou; i++){
			//testar se cabe com i
			line = 0;
			// puts("");
			for( j = 0; nums[j] && !achou;  j = j){
				int total = nums[j] * i;
				if( total > w){
					maior = i - 1 ;
					achou = true;
					break;
				}
				while( total + ((1 + nums[++j]) * i) <= w && nums[j]){					
					total += (1 + nums[j]) * i;		
				}
				line++;
				// printf("\ninch : %d line %d: %d", i , line , total);
				if( line * i > h) {
					maior = i - 1 ;
					achou = true;
					break;
				}
			}	
		}
		// puts("\n");
		printf("Case #%d: %d\n", c++, maior);
		// puts("");
	}
	
	return 0;
}
