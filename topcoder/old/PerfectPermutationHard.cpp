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

struct PerfectPermutationHard {
    vector <int> reorder(vector <int> P) {
        return vector <int>(0);
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
	
	template<typename T> std::ostream& operator<<(std::ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, std::clock_t elapsed) { 
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
			int P[]                   = {2, 0, 1};
			int expected__[]          = {2, 0, 1 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = PerfectPermutationHard().reorder(vector <int>(P, P + (sizeof P / sizeof P[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int P[]                   = {4, 0, 5, 2, 1, 3};
			int expected__[]          = {2, 0, 5, 4, 1, 3 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = PerfectPermutationHard().reorder(vector <int>(P, P + (sizeof P / sizeof P[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int P[]                   = {2, 7, 3, 0, 6, 4, 5, 1};
			int expected__[]          = {1, 7, 3, 0, 6, 2, 5, 4 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = PerfectPermutationHard().reorder(vector <int>(P, P + (sizeof P / sizeof P[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int P[]                   = {11, 8, 10, 1, 5, 4, 0, 7, 3, 9, 12, 6, 2};
			int expected__[]          = {1, 8, 10, 2, 5, 7, 0, 9, 3, 11, 12, 6, 4 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = PerfectPermutationHard().reorder(vector <int>(P, P + (sizeof P / sizeof P[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			int P[]                   = {0, 1, 4, 2, 3, 5};
			int expected__[]          = {1, 2, 4, 5, 3, 0 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = PerfectPermutationHard().reorder(vector <int>(P, P + (sizeof P / sizeof P[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 5: {
			int P[]                   = {0, 2, 6, 5, 7, 3, 1, 4};
			int expected__[]          = {1, 2, 6, 5, 7, 4, 3, 0 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = PerfectPermutationHard().reorder(vector <int>(P, P + (sizeof P / sizeof P[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int P[]                   = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = PerfectPermutationHard().reorder(vector <int>(P, P + (sizeof P / sizeof P[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			int P[]                   = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = PerfectPermutationHard().reorder(vector <int>(P, P + (sizeof P / sizeof P[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 8: {
			int P[]                   = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = PerfectPermutationHard().reorder(vector <int>(P, P + (sizeof P / sizeof P[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
// A permutation A[0], A[1], ..., A[N-1] is a sequence containing each integer between 0 and N-1, inclusive, exactly once.  Each permutation A of length N has a corresponding child array B of the same length, where B is defined as follows:


B[0] = 0
B[i] = A[B[i-1]], for every i between 1 and N-1, inclusive.


A permutation is considered perfect if its child array is also a permutation.

Below are given all permutations for N=3 with their child arrays. Note that for two of these permutations ({1, 2, 0} and {2, 0, 1}) the child array is also a permutation, so these two permutations are perfect.


Permutation		Child array
{0, 1, 2}		{0, 0, 0}
{0, 2, 1}		{0, 0, 0}
{1, 0, 2}		{0, 1, 0}
{1, 2, 0}		{0, 1, 2}
{2, 0, 1}		{0, 2, 1}
{2, 1, 0}		{0, 2, 0}


You are given a vector <int> P containing a permutation of length N.  Find a perfect permutation Q of the same length such that the difference between P and Q is as small as possible.  The difference between P and Q is the number of indices i for which P[i] and Q[i] are different.  If there are several such permutations Q, return the one among them that has the lexicographically smallest child array.

DEFINITION
Class:PerfectPermutationHard
Method:reorder
Parameters:vector <int>
Returns:vector <int>
Method signature:vector <int> reorder(vector <int> P)


NOTES
-vector <int> A comes before vector <int> B (with the same length) lexicographically if A has a smaller integer at the first position where the arrays differ.


CONSTRAINTS
-P will contain between 1 and 50 elements, inclusive.
-P will contain each integer between 0 and N-1, inclusive, exactly once, where N is the number of elements in P.


EXAMPLES

0)
{2, 0, 1}

Returns: {2, 0, 1 }

This permutation is already perfect.

1)
{4, 0, 5, 2, 1, 3}

Returns: {2, 0, 5, 4, 1, 3 }

Here the smallest possible difference between P and Q is 2. There are 9 possible choices for Q: {2,0,5,4,1,3}, {3,0,5,2,1,4}, {4,0,1,2,5,3}, {4,0,5,1,2,3}, {4,0,5,2,3,1}, {4,2,5,0,1,3}, {4,3,5,2,1,0}, {4,5,0,2,1,3} and {5,0,4,2,1,3}. Among them, {2,0,5,4,1,3} has the lexicographically smallest child array (this array is {0,2,5,3,4,1}).

2)
{2, 7, 3, 0, 6, 4, 5, 1}

Returns: {1, 7, 3, 0, 6, 2, 5, 4 }



3)
{11, 8, 10, 1, 5, 4, 0, 7, 3, 9, 12, 6, 2}

Returns: {1, 8, 10, 2, 5, 7, 0, 9, 3, 11, 12, 6, 4 }



4)
{0, 1, 4, 2, 3, 5}

Returns: {1, 2, 4, 5, 3, 0 }



5)
{0, 2, 6, 5, 7, 3, 1, 4}

Returns: {1, 2, 6, 5, 7, 4, 3, 0 }



**/
// END CUT HERE
