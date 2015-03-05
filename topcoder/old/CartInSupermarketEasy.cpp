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

struct CartInSupermarketEasy {
    int calc(int N, int K) {
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
			int N                     = 5;
			int K                     = 0;
			int expected__            = 5;

			std::clock_t start__      = std::clock();
			int received__            = CartInSupermarketEasy().calc(N, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 5;
			int K                     = 2;
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = CartInSupermarketEasy().calc(N, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 15;
			int K                     = 4;
			int expected__            = 6;

			std::clock_t start__      = std::clock();
			int received__            = CartInSupermarketEasy().calc(N, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 7;
			int K                     = 100;
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = CartInSupermarketEasy().calc(N, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 45;
			int K                     = 5;
			int expected__            = 11;

			std::clock_t start__      = std::clock();
			int received__            = CartInSupermarketEasy().calc(N, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int N                     = 100;
			int K                     = 100;
			int expected__            = 8;

			std::clock_t start__      = std::clock();
			int received__            = CartInSupermarketEasy().calc(N, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int N                     = ;
			int K                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CartInSupermarketEasy().calc(N, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int N                     = ;
			int K                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CartInSupermarketEasy().calc(N, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int N                     = ;
			int K                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CartInSupermarketEasy().calc(N, K);
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
// You have a sequence that consists of N shopping carts.
You want to remove all of them as quickly as possible.

The process of removing the carts will consist of one or more turns.
Each turn will take exactly one minute.
At the beginning of each turn, you will have some sequences of carts.
For each of those sequences you can choose between two options:

split it (in an arbitrary place) into two shorter sequences
remove one shopping cart from the sequence


There is one additional constraint: during the entire process you can only choose to split a sequence at most K times.

You are given the ints N and K.
Compute and return the smallest number of minutes in which it is possible to remove all the carts.

DEFINITION
Class:CartInSupermarketEasy
Method:calc
Parameters:int, int
Returns:int
Method signature:int calc(int N, int K)


CONSTRAINTS
-N will be between 1 and 100, inclusive.
-K will be between 0 and 100, inclusive.


EXAMPLES

0)
5
0

Returns: 5

As K=0, you can never split any sequence. In each turn you have to remove one cart from your sequence. Hence, it will take 5 minutes to remove all 5 carts.

1)
5
2

Returns: 4

One optimal solution: {5} -> {2,3} -> {1,2} -> {1,1} -> {}. We used two splits: once when splitting the sequence of 5 carts into 2+3 and the second time when  splitting the sequence of 2 carts into 1+1.

2)
15
4

Returns: 6



3)
7
100

Returns: 4

You don't have to split exactly K times.

4)
45
5

Returns: 11



5)
100
100

Returns: 8



**/
// END CUT HERE
