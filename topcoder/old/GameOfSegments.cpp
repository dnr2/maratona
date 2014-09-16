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

int table[] = {1,2,2,2,1,2,2,2,1};

int dp[2000];

int rec(int n){
	if(dp[n]!=0) return dp[n];
	if( n == 0 ) return dp[n] = 2;
	if( n == 1 ) return dp[n] = 2;
	if( n == 2 ) return dp[n] = 1;
	int ret = 0;
	REP(i,0,n-1){
		int j = n-2-i;
		ret |= table[(rec(i)-1)*3+(rec(j)-1)];
	}
	return dp[n] = ret;
}

struct GameOfSegments {
    int winner(int N) {
		int ret = (rec(N)&1)?1:2;
		if( N == 191 ) REP(i,0,20) db( i _ dp[i] _  (dp[i]&1));
        return ret;
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
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = GameOfSegments().winner(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 4;
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = GameOfSegments().winner(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 15;
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = GameOfSegments().winner(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 191;
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = GameOfSegments().winner(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

		case 4: {
			int N                     = 7;
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = GameOfSegments().winner(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		
		case 5: {
			int N                     = 8;
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = GameOfSegments().winner(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		
		case 7: {
			int N                     = 9;
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = GameOfSegments().winner(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		
		case 8: {
			int N                     = 10;
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = GameOfSegments().winner(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		
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
// Rijél is a very wise teacher. He loves mathematics, especially games and geometry problems. Recently one of his students challenged him to the following game:

Initially, there is a polygon with N vertices drawn in the plane. The polygon is strictly convex, i.e., each internal angle is strictly smaller than 180 degrees. The vertices of the polygon are numbered 1 through N, in clockwise order.

Two players play the game on this polygon. The players take alternating turns. In each turn, the current player chooses a diagonal or a side of the polygon and draws it as a straight line segment. (A diagonal of the polygon is a line segment that connects any two non-adjacent vertices of the polygon.) The player is only allowed to choose a diagonal or a side that does not intersect any of the previously drawn segments (it must not share endpoints with any of them either). The player who cannot draw a diagonal or a side according to the above rules loses the game.

You are given the int N.

We assume that both players play the game optimally. Return 1 if the first player wins and 2 otherwise.

DEFINITION
Class:GameOfSegments
Method:winner
Parameters:int
Returns:int
Method signature:int winner(int N)


CONSTRAINTS
-N will be between 3 and 1,000, inclusive.


EXAMPLES

0)
3

Returns: 1

This polygon has zero diagonals and three sides. The first player will always win no matter which side he picks.

1)
4

Returns: 1

This polygon has four sides and two diagonals. The first player wins the game if he takes one of the diagonals, because he will leave no choice for the second player.

2)
15

Returns: 2



3)
191

Returns: 2



**/
// END CUT HERE
