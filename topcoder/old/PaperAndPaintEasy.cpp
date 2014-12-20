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

struct PaperAndPaintEasy {
    long long computeArea(int width, int height, int xfold, int cnt, int x1, int y1, int x2, int y2) {	
		ll resp =0;
		ll w = width, h = height, x = min( xfold, width - xfold), c = cnt+1, a1 = x1, a2 = x2, b1 = y1, b2 = y2;
		if( a2 <= x ){
			resp += c * 2 * (a2 - a1) * (b2-b1); 
		} else if( a1 >= x ){
			resp += c * (a2 - a1) * (b2-b1);
		} else {
			resp += (c * 2 * (x - a1) * (b2-b1)) + (c * (a2 - x) * (b2-b1)); 
		}
		db( resp );
        return w * h - resp;
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, std::clock_t elapsed) { 
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
			int width                 = 5;
			int height                = 6;
			int xfold                 = 2;
			int cnt                   = 2;
			int x1                    = 1;
			int y1                    = 1;
			int x2                    = 3;
			int y2                    = 2;
			long long expected__      = 21;

			std::clock_t start__      = std::clock();
			long long received__      = PaperAndPaintEasy().computeArea(width, height, xfold, cnt, x1, y1, x2, y2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int width                 = 3;
			int height                = 13;
			int xfold                 = 1;
			int cnt                   = 0;
			int x1                    = 1;
			int y1                    = 8;
			int x2                    = 2;
			int y2                    = 12;
			long long expected__      = 35;

			std::clock_t start__      = std::clock();
			long long received__      = PaperAndPaintEasy().computeArea(width, height, xfold, cnt, x1, y1, x2, y2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int width                 = 12;
			int height                = 12;
			int xfold                 = 7;
			int cnt                   = 3;
			int x1                    = 3;
			int y1                    = 1;
			int x2                    = 6;
			int y2                    = 2;
			long long expected__      = 124;

			std::clock_t start__      = std::clock();
			long long received__      = PaperAndPaintEasy().computeArea(width, height, xfold, cnt, x1, y1, x2, y2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int width                 = 4;
			int height                = 5;
			int xfold                 = 4;
			int cnt                   = 0;
			int x1                    = 0;
			int y1                    = 0;
			int x2                    = 1;
			int y2                    = 1;
			long long expected__      = 19;

			std::clock_t start__      = std::clock();
			long long received__      = PaperAndPaintEasy().computeArea(width, height, xfold, cnt, x1, y1, x2, y2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int width                 = 4;
			int height                = 8;
			int xfold                 = 4;
			int cnt                   = 3;
			int x1                    = 0;
			int y1                    = 1;
			int x2                    = 2;
			int y2                    = 2;
			long long expected__      = 24;

			std::clock_t start__      = std::clock();
			long long received__      = PaperAndPaintEasy().computeArea(width, height, xfold, cnt, x1, y1, x2, y2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int width                 = 4;
			int height                = 8;
			int xfold                 = 3;
			int cnt                   = 0;
			int x1                    = 1;
			int y1                    = 1;
			int x2                    = 3;
			int y2                    = 2;
			long long expected__      = 30;

			std::clock_t start__      = std::clock();
			long long received__      = PaperAndPaintEasy().computeArea(width, height, xfold, cnt, x1, y1, x2, y2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int width                 = ;
			int height                = ;
			int xfold                 = ;
			int cnt                   = ;
			int x1                    = ;
			int y1                    = ;
			int x2                    = ;
			int y2                    = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = PaperAndPaintEasy().computeArea(width, height, xfold, cnt, x1, y1, x2, y2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int width                 = ;
			int height                = ;
			int xfold                 = ;
			int cnt                   = ;
			int x1                    = ;
			int y1                    = ;
			int x2                    = ;
			int y2                    = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = PaperAndPaintEasy().computeArea(width, height, xfold, cnt, x1, y1, x2, y2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int width                 = ;
			int height                = ;
			int xfold                 = ;
			int cnt                   = ;
			int x1                    = ;
			int y1                    = ;
			int x2                    = ;
			int y2                    = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = PaperAndPaintEasy().computeArea(width, height, xfold, cnt, x1, y1, x2, y2);
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
// Onise likes to play with paper and paint.  He has a piece of paper with dimensions width x height.  He does the following steps with the paper:


Fold the paper along the line x = xfold (the left side of the paper is folded over the right side).
Divide the paper vertically into cnt+1 equal sections.  Then, cnt times, take the topmost section and fold it over the section below it.
Paint a rectangle with the lower-left corner at (x1, y1) and the upper-right corner at (x2, y2).  Note that (0, 0) is now the lower-left corner of the paper in its current folded state, not its original state.  The paint will seep through all the layers of the folded paper.  See the image below for clarification.
Unfold the paper.


For example, let's say Onise has a piece of paper that is 5 x 6.  He performs the described steps where xfold is 2, cnt is 2, and the coordinates of the painted rectangle's corners are (1, 1) and (3, 2).  The following will happen (note that the paper starts out blue in the images and gets painted white):

 
 
 
 
 


You are given ints width and height, and ints xfold, cnt, x1, y1, x2 and y2.  Return the total area of of the paper that is not covered in paint after Onise is done.

DEFINITION
Class:PaperAndPaintEasy
Method:computeArea
Parameters:int, int, int, int, int, int, int, int
Returns:long long
Method signature:long long computeArea(int width, int height, int xfold, int cnt, int x1, int y1, int x2, int y2)


CONSTRAINTS
-width and height will be between 1 and 10^9, inclusive.
-xfold will be between 0 and width, inclusive.
-cnt will be between 0 and 1000, inclusive.
-cnt+1 will be a divisor of height.
-0 <= x1 < x2 <= max(xfold, width-xfold) and 0 <= y1 < y2 <= height/(cnt+1).


EXAMPLES

0)
5
6
2
2
1
1
3
2

Returns: 21

The example from the problem statement.

1)
3
13
1
0
1
8
2
12

Returns: 35

2)
12
12
7
3
3
1
6
2

Returns: 124

3)
4
5
4
0
0
0
1
1

Returns: 19

4)
4
8
4
3
0
1
2
2

Returns: 24

5)
4
8
3
0
1
1
3
2

Returns: 30

**/
// END CUT HERE
