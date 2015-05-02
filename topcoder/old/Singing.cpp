#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <climits>
#include <cctype>
#include <cmath>
#include <cassert>
#include <ctime>

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <complex>
#include <limits>
#include <functional>
#include <numeric>

using namespace std;

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }

typedef long long ll;

#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
#define PDD pair<double,double>
#define FT first
#define SD second
#define REP(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define PB push_back
#define PI acos(-1)
#define DB(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define MP make_pair
#define EPS 1e-9
#define INF 0x3f3f3f3f
#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0)
#define FILL(x,v) memset(x,v,sizeof(x))

const int maxn = 2000;
vector<int> adj[maxn];
int A, B, n;
vector <int> p;

struct Singing {
	
    int solve(int N, int low, int high, vector <int> pitch) {
		p = pitch;
		A = high+1;
		B = low-1;
		n = pitch.size();
		if( A > N || B < 1 ) return 0;
		adj[A].clear();
		adj[B].clear();
		REP(i,low,high+1){
			adj[i].clear();			
		}
		REP(i,0,(int)p.size()){
			int a =-1, b =-1, c =-1;
			a = p[i]; 
			if( a < low ) a = B; if( a > high ) a = A;
			if( i - 1 >= 0 ){
				b = p[i-1]; 
				if( b < low ) b = B; if( b > high ) b = A;
			}
			if( i + 1 < n ){
				c = p[i+1]; 
				if( c < low ) c = B; if( c > high ) c = A;
			}
			
			if( b > 0 ){ adj[a].PB( b ); adj[b].PB( a ); }
			if( c > 0 ){ adj[a].PB( c ); adj[c].PB( a ); }
		}
        return ;
    }
};

// BEGIN CUT HERE
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
	using std::string;
	using std::vector;
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			std::cerr << "No test cases run." << std::endl;
		} else if (correct < total) {
			std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
		} else {
			std::cerr << "All " << total << " tests passed!" << std::endl;
		}
	}
	
	int verify_case(int casenum, const int &expected, const int &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		std::cerr << verdict;
		if (!info.empty()) {
			std::cerr << " (";
			for (size_t i=0; i<info.size(); ++i) {
				if (i > 0) std::cerr << ", ";
				std::cerr << info[i];
			}
			std::cerr << ")";
		}
		std::cerr << std::endl;
		
		if (verdict == "FAILED") {
			std::cerr << "    Expected: " << expected << std::endl; 
			std::cerr << "    Received: " << received << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int N                     = 3;
			int low                   = 2;
			int high                  = 2;
			int pitch[]               = {1,2,3,2,1,2};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = Singing().solve(N, low, high, vector <int>(pitch, pitch + (sizeof pitch / sizeof pitch[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 10;
			int low                   = 3;
			int high                  = 7;
			int pitch[]               = {4,4,5,5,6,5,3,6};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = Singing().solve(N, low, high, vector <int>(pitch, pitch + (sizeof pitch / sizeof pitch[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 6;
			int low                   = 2;
			int high                  = 5;
			int pitch[]               = {5,3,1,6,4,2};
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = Singing().solve(N, low, high, vector <int>(pitch, pitch + (sizeof pitch / sizeof pitch[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 10;
			int low                   = 4;
			int high                  = 5;
			int pitch[]               = {1,4,3,5,2,5,7,5,9};
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = Singing().solve(N, low, high, vector <int>(pitch, pitch + (sizeof pitch / sizeof pitch[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 100;
			int low                   = 20;
			int high                  = 80;
			int pitch[]               = {2,27,3,53,53,52,52,60,85,89,100,53,60,2,3,53,100,89,40,42,2,53,2,85};
			int expected__            = 5;

			std::clock_t start__      = std::clock();
			int received__            = Singing().solve(N, low, high, vector <int>(pitch, pitch + (sizeof pitch / sizeof pitch[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int N                     = ;
			int low                   = ;
			int high                  = ;
			int pitch[]               = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Singing().solve(N, low, high, vector <int>(pitch, pitch + (sizeof pitch / sizeof pitch[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int N                     = ;
			int low                   = ;
			int high                  = ;
			int pitch[]               = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Singing().solve(N, low, high, vector <int>(pitch, pitch + (sizeof pitch / sizeof pitch[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int N                     = ;
			int low                   = ;
			int high                  = ;
			int pitch[]               = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Singing().solve(N, low, high, vector <int>(pitch, pitch + (sizeof pitch / sizeof pitch[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}
 

#include <cstdlib>
int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
}
// END CUT HERE

// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// 
Alice and Bob are going to sing a song together.
You are given three ints: N, low, and high.
For simplicity, we will assign the numbers 1 through N to the pitches that occur in the song (from the lowest to the highest).
Alice is only able to sing pitches between low and N, inclusive.
Bob is only able to sing pitches between 1 and high, inclusive.
(It is guaranteed that the ranges of their voices overlap.)



You are also given a vector <int> pitch containing the pitches of all notes in the song, in order.



Each note of the song must be sung by exactly one person: either Alice or Bob.
Each person can only sing notes that are within their range.
All notes with the same pitch must be sung by the same person.
The number of times the singer changes during the song must be as small as possible.



Formally, a switch is a pair of consecutive notes that are sung by different persons.
Compute and return the smallest possible number of switches when Alice and Bob sing the song.


DEFINITION
Class:Singing
Method:solve
Parameters:int, int, int, vector <int>
Returns:int
Method signature:int solve(int N, int low, int high, vector <int> pitch)


NOTES
-A singer is not required to sing a consecutive sequence of pitches. For example, sometimes Bob may sing pitches 1 and 3 while Alice sings pitches 2 and 4.


CONSTRAINTS
-N will be between 1 and 1,000, inclusive.
-low will be between 1 and N, inclusive.
-high will be between low and N, inclusive.
-The number of elements in pitch will be between 1 and 1,000, inclusive.
-All elements of pitch will be between 1 and N.


EXAMPLES

0)
3
2
2
{1,2,3,2,1,2}

Returns: 2

There are 3 pitches.
Alice is able to sing pitches 2 and 3, while Bob is able to sing pitches 1 and 2.
Thus, there are only two different ways in which they can sing the notes of the given song:
Either they will sing in the order Bob-Alice-Alice-Alice-Bob-Alice (3 switches), or in the order
Bob-Bob-Alice-Bob-Bob-Bob (only 2 switches).
The second way of singing the song is better.

1)
10
3
7
{4,4,5,5,6,5,3,6}

Returns: 0

Alice can sing the entire song. In that case there are no switches.

2)
6
2
5
{5,3,1,6,4,2}

Returns: 1

In the optimal solution Bob sings the first three notes (pitches 5, 3, and 1), and Alice sings the next three notes.

3)
10
4
5
{1,4,3,5,2,5,7,5,9}

Returns: 3



4)
100
20
80
{2,27,3,53,53,52,52,60,85,89,100,53,60,2,3,53,100,89,40,42,2,53,2,85}

Returns: 5



**/
// END CUT HERE
