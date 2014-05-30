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

struct MixingColors {
    int minColors(vector <int> colors) {
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
			int colors[]              = {1, 7, 3};
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = MixingColors().minColors(vector <int>(colors, colors + (sizeof colors / sizeof colors[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int colors[]              = {10};
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = MixingColors().minColors(vector <int>(colors, colors + (sizeof colors / sizeof colors[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int colors[]              = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = MixingColors().minColors(vector <int>(colors, colors + (sizeof colors / sizeof colors[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int colors[]              = {534, 251, 76, 468, 909, 410, 264, 387, 102, 982, 199, 111, 659, 386, 151};
			int expected__            = 10;

			std::clock_t start__      = std::clock();
			int received__            = MixingColors().minColors(vector <int>(colors, colors + (sizeof colors / sizeof colors[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int colors[]              = {4, 8, 16, 32, 64, 128, 256, 512, 1024};
			int expected__            = 9;

			std::clock_t start__      = std::clock();
			int received__            = MixingColors().minColors(vector <int>(colors, colors + (sizeof colors / sizeof colors[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int colors[]              = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = MixingColors().minColors(vector <int>(colors, colors + (sizeof colors / sizeof colors[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int colors[]              = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = MixingColors().minColors(vector <int>(colors, colors + (sizeof colors / sizeof colors[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int colors[]              = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = MixingColors().minColors(vector <int>(colors, colors + (sizeof colors / sizeof colors[0])));
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
	Danica is an artist. She would like to paint a picture, but currently she has no colors at all.



	For the purpose of this problem, colors are represented by positive integers. You are given a vector <int> colors. The elements of colors are the colors Danica needs to paint her picture.



	There is a store that sells colors. The store has an unlimited supply of all possible colors, including colors that Danica doesn't need. Danica will buy some colors in the store. Then, she will produce other colors by mixing the colors she bought.



	Danica can only mix two colors at a time. Mixing two different colors A and B produces the color (A XOR B). Colors obtained by mixing can later be used to produce other colors.



	Danica wants to buy as few distinct colors as possible. Note that she is allowed to buy colors she does not need for the picture.



	Return the smallest number of distinct colors Danica has to buy in order to be able to obtain all the colors she needs.


DEFINITION
Class:MixingColors
Method:minColors
Parameters:vector <int>
Returns:int
Method signature:int minColors(vector <int> colors)


NOTES
-XOR (exclusive or) is a binary operation, performed on two numbers in binary notation. First, the shorter number is prepended with leading zeroes until both numbers have the same number of digits (in binary). Then, the result is calculated as follows: for each bit where the numbers differ the result has 1 in its binary representation. It has 0 in all other positions.
-For example 15 XOR 55 is performed as follows. First, the numbers are converted to binary: 15 is 1111 and 55 is 110111. Then the shorter number is prepended with leading zeros until both numbers have the same number of digits. This means 15 becomes 001111. Then 001111 XOR 110111 = 111000 (the result has ones only in the positions where the two numbers differ). Then the result can be converted back to decimal notation. In this case 111000 = 56, so 15 XOR 55 = 56.


CONSTRAINTS
-colors will contain between 1 and 50 elements, inclusive.
-Each element of colors will be between 1 and 1,000,000,000, inclusive.
-All elements of colors will be distinct.


EXAMPLES

0)
{1, 7, 3}

Returns: 3

Obviously, Danica can just buy the three colors she needs. However, there are also other optimal solutions. For example, she could buy colors 1, 2, and 4 instead. Then, she can mix these colors as follows:

She already has color 1.
She can obtain color 3 by mixing colors 1 and 2: we have 1 XOR 2 = 3.
She can obtain color 7 by first mixing colors 1 and 4 to produce color 5 (as 1 XOR 4 = 5), and then mixing colors 5 and 2 (as 5 XOR 2 = 7).


1)
{10}

Returns: 1

Danica should buy color 10 only.

2)
{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}

Returns: 4

Danica can, for instance, buy colors 11, 13, 14, and 15.

3)
{534, 251, 76, 468, 909, 410, 264, 387, 102, 982, 199, 111, 659, 386, 151}

Returns: 10



4)
{4, 8, 16, 32, 64, 128, 256, 512, 1024}

Returns: 9



**/
// END CUT HERE
