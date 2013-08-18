/**
 * UVa 624 CD
 * Author: chchwy
 * Last Modified: 2011.07.30
 * Tag: Dynamic Programming, 0/1 Knapsack
 */
#include<cstdio>
#include<cstring>
using namespace std;

enum {MAX=20};

void solve(int total_length, int * song, int song_len )
{
    int pack[MAX+1][MAX+1];
    memset(pack, 0, sizeof(pack));

    for(int i=n-1;i>=0;--i) {
        for(int j=0;j<total_length)
    }
}

int main()
{
    
    freopen( "in.txt", "r", stdin);
	freopen( "out.txt", "w", stdout);
    
    int total_length;

    while( scanf("%d", &total_length)==1 ) {

        int song_len;
        int song[MAX];

        // input
        scanf("%d", &song_len);
        for(int i=0; i<song_len; +=i)
            scanf("%d", &song[i]);

        solve(total_length, song, song_len);

    }

}
