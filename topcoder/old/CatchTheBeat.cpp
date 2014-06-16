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

struct CatchTheBeat {
    int maxCatched(int n, int x0, int y0, int a, int b, int c, int d, int mod1, int mod2, int offset) {
        return int(0);
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
			int n                     = 3;
			int x0                    = 0;
			int y0                    = 0;
			int a                     = 1;
			int b                     = 1;
			int c                     = 1;
			int d                     = 1;
			int mod1                  = 100;
			int mod2                  = 100;
			int offset                = 1;
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = CatchTheBeat().maxCatched(n, x0, y0, a, b, c, d, mod1, mod2, offset);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 1;
			int x0                    = 0;
			int y0                    = 1234;
			int a                     = 0;
			int b                     = 0;
			int c                     = 0;
			int d                     = 0;
			int mod1                  = 1000000000;
			int mod2                  = 1000000000;
			int offset                = 1000;
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = CatchTheBeat().maxCatched(n, x0, y0, a, b, c, d, mod1, mod2, offset);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 1;
			int x0                    = 0;
			int y0                    = 999;
			int a                     = 0;
			int b                     = 0;
			int c                     = 0;
			int d                     = 0;
			int mod1                  = 1000000000;
			int mod2                  = 1000000000;
			int offset                = 1000;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = CatchTheBeat().maxCatched(n, x0, y0, a, b, c, d, mod1, mod2, offset);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int n                     = 100;
			int x0                    = 0;
			int y0                    = 0;
			int a                     = 1;
			int b                     = 1;
			int c                     = 1;
			int d                     = 1;
			int mod1                  = 3;
			int mod2                  = 58585858;
			int offset                = 1;
			int expected__            = 66;

			std::clock_t start__      = std::clock();
			int received__            = CatchTheBeat().maxCatched(n, x0, y0, a, b, c, d, mod1, mod2, offset);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int n                     = 500000;
			int x0                    = 123456;
			int y0                    = 0;
			int a                     = 1;
			int b                     = 0;
			int c                     = 1;
			int d                     = 1;
			int mod1                  = 1000000000;
			int mod2                  = 1000000000;
			int offset                = 0;
			int expected__            = 376544;

			std::clock_t start__      = std::clock();
			int received__            = CatchTheBeat().maxCatched(n, x0, y0, a, b, c, d, mod1, mod2, offset);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int n                     = 500000;
			int x0                    = 0;
			int y0                    = 0;
			int a                     = 0;
			int b                     = 0;
			int c                     = 0;
			int d                     = 0;
			int mod1                  = 1;
			int mod2                  = 1;
			int offset                = 0;
			int expected__            = 500000;

			std::clock_t start__      = std::clock();
			int received__            = CatchTheBeat().maxCatched(n, x0, y0, a, b, c, d, mod1, mod2, offset);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int n                     = 10;
			int x0                    = 999999957;
			int y0                    = 79;
			int a                     = 993948167;
			int b                     = 24597383;
			int c                     = 212151897;
			int d                     = 999940854;
			int mod1                  = 999999986;
			int mod2                  = 999940855;
			int offset                = 3404;
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = CatchTheBeat().maxCatched(n, x0, y0, a, b, c, d, mod1, mod2, offset);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			int n                     = ;
			int x0                    = ;
			int y0                    = ;
			int a                     = ;
			int b                     = ;
			int c                     = ;
			int d                     = ;
			int mod1                  = ;
			int mod2                  = ;
			int offset                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CatchTheBeat().maxCatched(n, x0, y0, a, b, c, d, mod1, mod2, offset);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int n                     = ;
			int x0                    = ;
			int y0                    = ;
			int a                     = ;
			int b                     = ;
			int c                     = ;
			int d                     = ;
			int mod1                  = ;
			int mod2                  = ;
			int offset                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CatchTheBeat().maxCatched(n, x0, y0, a, b, c, d, mod1, mod2, offset);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int n                     = ;
			int x0                    = ;
			int y0                    = ;
			int a                     = ;
			int b                     = ;
			int c                     = ;
			int d                     = ;
			int mod1                  = ;
			int mod2                  = ;
			int offset                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CatchTheBeat().maxCatched(n, x0, y0, a, b, c, d, mod1, mod2, offset);
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
// One of the modes in the game "osu!" is called "catch the beat".
In this mode, you control a character that catches falling fruit.



The game is played in the vertical plane.
For simplicity, we will assume that both your character and all pieces of fruit are points in that plane.



You start the game at the coordinates (0, 0).
Your character can only move along the x-axis.
The maximum speed of your character is 1 unit of distance per second.
For example, you need at least 3 seconds to move from (-2, 0) to (1, 0).



There are n pieces of fruit.
The pieces are numbered 0 through n-1.
For each i, fruit i starts at (x[i], y[i]).
All pieces of fruit fall down with constant speed of 1 unit of distance per second.
That is, a fruit currently located at (xf, yf) will move to (xf, yf-t) in t seconds.
You will catch a fruit if the character is located at the same point as the fruit at some moment in time.



The initial coordinates x[] and y[] are generated using the following pseudocode:



x[0] = x0
for i = 1 to n-1:
    x[i] = (x[i-1] * a + b) % mod1

for i = 0 to n-1:
    x[i] = x[i] - offset

y[0] = y0
for i = 1 to n-1:
    y[i] = (y[i-1] * c + d) % mod2

(In the pseudocode, '%' represents the 'modulo' operator.)


You are given all the ints used in the above pseudocode.
Return the maximum number of pieces of fruit you can catch.

DEFINITION
Class:CatchTheBeat
Method:maxCatched
Parameters:int, int, int, int, int, int, int, int, int, int
Returns:int
Method signature:int maxCatched(int n, int x0, int y0, int a, int b, int c, int d, int mod1, int mod2, int offset)


CONSTRAINTS
-n will be between 1 and 500,000, inclusive.
-mod1 and mod2 will be between 1 and 1,000,000,000, inclusive.
-x0, a and b will be between 0 and (mod1 - 1), inclusive.
-y0, c and d will be between 0 and (mod2 - 1), inclusive.
-offset will be between 0 and 1,000,000,000, inclusive.


EXAMPLES

0)
3
0
0
1
1
1
1
100
100
1

Returns: 2

There are 3 pieces of fruit.
Their initial coordinates are (-1, 0), (0, 1), and (1, 2).
Clearly you cannot catch fruit 0.
You can catch the other two.
One way of doing so:

Wait at (0, 0) for 1 second.
Catch fruit 1.
Move to (1, 0) in 1 second.
Immediately catch fruit 2.


1)
1
0
1234
0
0
0
0
1000000000
1000000000
1000

Returns: 1

The only fruit is located at (-1000, 1234). We can go to (-1000, 0) and then wait for 234 seconds to catch it.

2)
1
0
999
0
0
0
0
1000000000
1000000000
1000

Returns: 0

Now the only fruit is located at (-1000, 999). We can't catch it.

3)
100
0
0
1
1
1
1
3
58585858
1

Returns: 66



4)
500000
123456
0
1
0
1
1
1000000000
1000000000
0

Returns: 376544

The fruits are located in (123456, 0), (123456, 1), ..., (123456, 499999).

5)
500000
0
0
0
0
0
0
1
1
0

Returns: 500000

In this case all the fruits start at (0, 0).
Note that there can be more than one fruit at any position.
We can catch all such fruit at the same time.

6)
10
999999957
79
993948167
24597383
212151897
999940854
999999986
999940855
3404

Returns: 3

Watch out for integer overflow when generating the coordinates.

**/
// END CUT HERE
