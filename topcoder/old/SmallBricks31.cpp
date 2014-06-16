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
#define pii pair<int,int>
#define F first
#define S second
#define REP(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define PI acos(-1)
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define EPS 1e-9
#define INF 1e9

ll mod = 1000000007;

ll dp[20][1<<11];

int maxh, w;

ll rec( int h, int mask){
	if( dp[h][mask] != -1) return dp[h][mask];
	if( h >= maxh ) return 0;
	ll ret = 0;
	REP(j,0,1<<w){	
		REP(i,0,w){
			
		}
	}
}

struct SmallBricks31 {
    int countWays(int _w, int h) {
		memset(dp,-1,sizeof(dp));
		maxh = h;
		w = _w;
        return rec( 0, 0 ) + 1;
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
			int w                     = 1;
			int h                     = 3;
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = SmallBricks31().countWays(w, h);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int w                     = 3;
			int h                     = 1;
			int expected__            = 13;

			std::clock_t start__      = std::clock();
			int received__            = SmallBricks31().countWays(w, h);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int w                     = 3;
			int h                     = 2;
			int expected__            = 84;

			std::clock_t start__      = std::clock();
			int received__            = SmallBricks31().countWays(w, h);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int w                     = 4;
			int h                     = 9;
			int expected__            = 132976888;

			std::clock_t start__      = std::clock();
			int received__            = SmallBricks31().countWays(w, h);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int w                     = 5;
			int h                     = 5;
			int expected__            = 11676046;

			std::clock_t start__      = std::clock();
			int received__            = SmallBricks31().countWays(w, h);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int w                     = ;
			int h                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = SmallBricks31().countWays(w, h);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int w                     = ;
			int h                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = SmallBricks31().countWays(w, h);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int w                     = ;
			int h                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = SmallBricks31().countWays(w, h);
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
// NOTE: This problem statement contains images that may not display properly if viewed outside of the applet.

We have three kinds of construction bricks. Those of dimensions 1x1x1, 1x1x2 and 1x1x3. We also have a special brick of dimensions 1x1xw which we will call the base.



We would like to use the bricks and the base to build structures. For the bricks to connect to each other and to the base, they all have to be aligned properly. Placing a brick at a non-integer position is not allowed. Also, to ensure stability, the longer bricks (1x1x2 and 1x1x3) must be placed in a way that their extremes both rest on top of another brick or bricks, including the base. There may be an empty space directly below the middle part of a 1x1x3 brick. The following image shows a valid structure and the other image shows a structure that is invalid for three reasons.





The height of a structure is the number of layers of bricks it contains. The base is not counted into the height of the structure.

Two structures are different if there is a position where they differ in any way. (There are two ways in which two given structures may differ: First, there may be a position where one structure has a brick and the other does not. Second, there may be a position where both structures have bricks, but the bricks are of different types.)

Given are two ints w and h. Count the total number of different structures that can be created using any number of 1x1x1, 1x1x2 and 1x1x3 bricks and a base of width w such that the height of the structure is at most h units. Since the result can be large, return the count modulo 1000000007.
For example, the following image shows the 84 different structures for w=3, h=2:



DEFINITION
Class:SmallBricks31
Method:countWays
Parameters:int, int
Returns:int
Method signature:int countWays(int w, int h)


CONSTRAINTS
-w will be between 1 and 10, inclusive.
-h will be between 1 and 10, inclusive.


EXAMPLES

0)
1
3

Returns: 4



1)
3
1

Returns: 13

The leftmost column in the picture above shows the 13 different structures of width 3 and at most 1 unit of height.

2)
3
2

Returns: 84

The picture above shows the 84 different structures of width 3 and at most 2 unit of height.

3)
4
9

Returns: 132976888

4)
5
5

Returns: 11676046

**/
// END CUT HERE
