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


bool dp[20*200000];

struct NumbersChallenge {
    int MinNumber(vector <int> S) {
		memset( dp, false ,sizeof( dp));
		int ret = 0, m = 0;
		REP(i,0,S.size()){
			for( int j = m; j >= 1; j--){
				if( dp[j] ){
					dp[j+S[i]] = true;
					m = max( m, j+S[i]);
				}
			}
			dp[S[i]] = true;
			m = max( m , S[i]);
		}
		REP(i,1,m+10){
			if( !dp[i] ){ ret = i; break; }
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
			int S[]                   = {5, 1, 2};
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = NumbersChallenge().MinNumber(vector <int>(S, S + (sizeof S / sizeof S[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int S[]                   = {2, 1, 4};
			int expected__            = 8;

			std::clock_t start__      = std::clock();
			int received__            = NumbersChallenge().MinNumber(vector <int>(S, S + (sizeof S / sizeof S[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int S[]                   = {2, 1, 2, 7};
			int expected__            = 6;

			std::clock_t start__      = std::clock();
			int received__            = NumbersChallenge().MinNumber(vector <int>(S, S + (sizeof S / sizeof S[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int S[]                   = {94512, 2, 87654, 81316, 6, 5, 6, 37151, 6, 139, 1, 36, 307, 1, 377, 101, 8, 37, 58, 1};
			int expected__            = 1092;

			std::clock_t start__      = std::clock();
			int received__            = NumbersChallenge().MinNumber(vector <int>(S, S + (sizeof S / sizeof S[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int S[]                   = {883, 66392, 3531, 28257, 1, 14131, 57, 1, 25, 88474, 4, 1, 110, 6, 1769, 220, 442, 7064, 7, 13};
			int expected__            = 56523;

			std::clock_t start__      = std::clock();
			int received__            = NumbersChallenge().MinNumber(vector <int>(S, S + (sizeof S / sizeof S[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int S[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = NumbersChallenge().MinNumber(vector <int>(S, S + (sizeof S / sizeof S[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int S[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = NumbersChallenge().MinNumber(vector <int>(S, S + (sizeof S / sizeof S[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int S[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = NumbersChallenge().MinNumber(vector <int>(S, S + (sizeof S / sizeof S[0])));
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
// Your friend Lucas gave you a sequence S of positive integers.

For a while, you two played a simple game with S:
Lucas would pick a number, and you had to select some elements of S such that the sum of all numbers you selected is the number chosen by Lucas.
For example, if S={2,1,2,7} and Lucas chose the number 11, you would answer that 2+2+7 = 11.

Lucas now wants to trick you by choosing a number X such that there will be no valid answer.
For example, if S={2,1,2,7}, it is not possible to select elements of S that sum up to 6.

You are given the vector <int> S.
Find the smallest positive integer X that cannot be obtained as the sum of some (possibly all) elements of S.

DEFINITION
Class:NumbersChallenge
Method:MinNumber
Parameters:vector <int>
Returns:int
Method signature:int MinNumber(vector <int> S)


CONSTRAINTS
-S will contain between 1 and 20 elements, inclusive.
-Each element of S will be between 1 and 100,000, inclusive.


EXAMPLES

0)
{5, 1, 2}

Returns: 4

These are all the positive integers that can be obtained: 1, 2, 3, 5, 6, 7, and 8.
(We can obtain 3 as 1+2, 6 as 1+5, 7 as 2+5, and 8 as 1+2+5.)
The smallest positive integer not present in the above list is 4.

1)
{2, 1, 4}

Returns: 8

We can obtain each of the sums from 1 to 7, inclusive. The smallest impossible sum is 8.

2)
{2, 1, 2, 7}

Returns: 6

The example given in the problem statement.

3)
{94512, 2, 87654, 81316, 6, 5, 6, 37151, 6, 139, 1, 36, 307, 1, 377, 101, 8, 37, 58, 1}

Returns: 1092



4)
{883, 66392, 3531, 28257, 1, 14131, 57, 1, 25, 88474, 4, 1, 110, 6, 1769, 220, 442, 7064, 7, 13}

Returns: 56523



**/
// END CUT HERE
