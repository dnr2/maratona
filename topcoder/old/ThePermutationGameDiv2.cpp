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



ll lcm( ll a, ll b){
	return (a*b)/__gcd(a,b);
}

struct ThePermutationGameDiv2 {
    long long findMin(int N) {
		ll ret = 1;
		REP(i,2,N+1){
			ret = lcm( ret, i );			
		}
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
			int N                     = 2;
			long long expected__      = 2;

			std::clock_t start__      = std::clock();
			long long received__      = ThePermutationGameDiv2().findMin(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 3;
			long long expected__      = 6;

			std::clock_t start__      = std::clock();
			long long received__      = ThePermutationGameDiv2().findMin(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 6;
			long long expected__      = 60;

			std::clock_t start__      = std::clock();
			long long received__      = ThePermutationGameDiv2().findMin(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 11;
			long long expected__      = 27720;

			std::clock_t start__      = std::clock();
			long long received__      = ThePermutationGameDiv2().findMin(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 25;
			long long expected__      = 26771144400LL;

			std::clock_t start__      = std::clock();
			long long received__      = ThePermutationGameDiv2().findMin(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

			case 5: {
			int N                     = 35;
			long long expected__      = 144403552893600;

			std::clock_t start__      = std::clock();
			long long received__      = ThePermutationGameDiv2().findMin(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int N                     = 1;
			long long expected__      = 1;

			std::clock_t start__      = std::clock();
			long long received__      = ThePermutationGameDiv2().findMin(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 7: {
			int N                     = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = ThePermutationGameDiv2().findMin(N);
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
Alice and Bob are playing a game called "The Permutation Game".
The game is parameterized with the int N.
At the start of the game, Alice chooses a positive integer x, and Bob chooses a permutation of the first N positive integers.
Let p be Bob's permutation.
Alice will start at 1, and apply the permutation to this value x times.
More formally, let f(1) = p[1], and f(m) = p[f(m-1)] for all m >= 2.
Alice's final value will be f(x).

Alice wants to choose the smallest x such that f(x) = 1 for any permutation Bob can provide.

Compute and return the value of such x.


DEFINITION
Class:ThePermutationGameDiv2
Method:findMin
Parameters:int
Returns:long long
Method signature:long long findMin(int N)


NOTES
-The return value will fit into a signed 64-bit integer.
-A permutation of the first N positive integers is a sequence of length N that contains each of the integers 1 through N exactly once. The i-th (1-indexed) element of a permutation p is denoted by p[i].


CONSTRAINTS
-N will be between 1 and 35 inclusive.


EXAMPLES

0)
2

Returns: 2

 
Bob can choose the permutations {1,2} or {2,1}.
If Alice chooses 1, then, Bob can choose the permutation {2,1}, which would would make f(1) = 2.
However, if Alice chooses 2, no matter which permutation Bob chooses, Alice will get f(2) = 1.
Thus the answer in this case is 2.


1)
3

Returns: 6



2)
6

Returns: 60



3)
11

Returns: 27720



4)
25

Returns: 26771144400



**/
// END CUT HERE
