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

struct BuildingHeightsEasy {
    int minimum(int M, vector <int> heights) {
		int sz = heights.size();
		sort(heights.begin(),heights.end(),greater<int>());
		
		int bestCost = INF;
		REP(i,1,51){
			int aux = 0, localCost = 0;
			REP(j,0,sz){
				if( heights[j] > i ) continue;
				localCost += i - heights[j];
				aux++;
				if( aux == M){
					if( bestCost > localCost ){
						bestCost = localCost;
					}
					break;
				}
			}
		}
        return bestCost;
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
			int M                     = 2;
			int heights[]             = {1, 2, 1, 4, 3};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = BuildingHeightsEasy().minimum(M, vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int M                     = 3;
			int heights[]             = {1, 3, 5, 2, 1};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = BuildingHeightsEasy().minimum(M, vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int M                     = 1;
			int heights[]             = {43, 19, 15};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = BuildingHeightsEasy().minimum(M, vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int M                     = 3;
			int heights[]             = {19, 23, 9, 12};
			int expected__            = 15;

			std::clock_t start__      = std::clock();
			int received__            = BuildingHeightsEasy().minimum(M, vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int M                     = 12;
			int heights[]             = {25, 18, 38, 1, 42, 41, 14, 16, 19, 46, 42, 39, 38, 31, 43, 37, 26, 41, 33, 37, 45, 27, 19, 24, 33, 11, 22, 20, 36, 4, 4};
			int expected__            = 47;

			std::clock_t start__      = std::clock();
			int received__            = BuildingHeightsEasy().minimum(M, vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			int M                     = 3;
			int heights[]             = {1,2,3};
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = BuildingHeightsEasy().minimum(M, vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 6: {
			int M                     = ;
			int heights[]             = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BuildingHeightsEasy().minimum(M, vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int M                     = ;
			int heights[]             = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BuildingHeightsEasy().minimum(M, vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
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
// Byteland is a city with many skyscrapers, so it's a perfect venue for BASE jumping. Danilo is an enthusiastic BASE jumper. He plans to come to Byteland and to jump off some of its buildings.

Danilo wants to make M jumps in Byteland. However, he has some rules. First, he never jumps off the same building twice. Second, all buildings he selects for his jumps must have the same number of floors. (This is for safety reasons: It is hard to get the timing right if each jump starts at a different height.)

Philipe is the mayor of Byteland. He welcomes Danilo's visit as he would like to use it as a publicity stunt. However, Philipe knows that Danilo will only come to Byteland if there are at least M buildings that each have the same number of floors. To ensure that, the mayor is willing to build additional floors on some of the skyscrapers in Byteland.

You are given the int M and a vector <int> heights. Each element of heights is the number of floors in one of Byteland's skyscrapers. Compute and return the smallest number of additional floors the mayor has to build so that there will be at least M buildings with the same number of floors.

DEFINITION
Class:BuildingHeightsEasy
Method:minimum
Parameters:int, vector <int>
Returns:int
Method signature:int minimum(int M, vector <int> heights)


CONSTRAINTS
-heights will contain between 1 and 50 elements, inclusive.
-M will be between 1 and the number of elements in heights, inclusive.
-Each element in heights will be between 1 and 50, inclusive.


EXAMPLES

0)
2
{1, 2, 1, 4, 3}

Returns: 0

Note that we already have two buildings that have the same number of floors. Hence, no additional floors need to be built.

1)
3
{1, 3, 5, 2, 1}

Returns: 2

We want to have at least three buildings with the same number of floors. The best way to reach this goal is to build one floor on building #0 and one floor on building #4 (0-based indices). After these changes, buildings #0, #3, and #4 will have two floors each.

2)
1
{43, 19, 15}

Returns: 0



3)
3
{19, 23, 9, 12}

Returns: 15



4)
12
{25, 18, 38, 1, 42, 41, 14, 16, 19, 46, 42, 39, 38, 31, 43, 37, 26, 41, 33, 37, 45, 27, 19, 24, 33, 11, 22, 20, 36, 4, 4}

Returns: 47



**/
// END CUT HERE
