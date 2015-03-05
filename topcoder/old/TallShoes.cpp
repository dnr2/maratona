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

struct TallShoes {
    int maxHeight(int N, vector <int> X, vector <int> Y, vector <int> height, long long B) {
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
			int N                     = 3;
			int X[]                   = {0, 1, 0};
			int Y[]                   = {1, 2, 2};
			int height[]              = {3, 4, 2};
			long long B               = 1;
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = TallShoes().maxHeight(N, vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(height, height + (sizeof height / sizeof height[0])), B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 3;
			int X[]                   = {0, 1, 0};
			int Y[]                   = {1, 2, 2};
			int height[]              = {3, 4, 2};
			long long B               = 52;
			int expected__            = 9;

			std::clock_t start__      = std::clock();
			int received__            = TallShoes().maxHeight(N, vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(height, height + (sizeof height / sizeof height[0])), B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 8;
			int X[]                   = {0, 0, 3, 3, 4, 4, 4, 7, 7};
			int Y[]                   = {1, 2, 1, 2, 3, 5, 6, 5, 6};
			int height[]              = {1000, 1000, 1000, 1000, 1, 1000, 1000, 1000, 1000};
			long long B               = 3;
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = TallShoes().maxHeight(N, vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(height, height + (sizeof height / sizeof height[0])), B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 10;
			int X[]                   = {0,1,2,3,4,5,6,7,8};
			int Y[]                   = {1,2,3,4,5,6,7,8,9};
			int height[]              = {0,0,0,0,0,0,0,0,0};
			long long B               = 9876543210123LL;
			int expected__            = 1047565;

			std::clock_t start__      = std::clock();
			int received__            = TallShoes().maxHeight(N, vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(height, height + (sizeof height / sizeof height[0])), B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 6;
			int X[]                   = {0,0,0,0,0,1,1,1,1,2,2,2,3,3,4};
			int Y[]                   = {1,2,3,4,5,2,3,4,5,3,4,5,4,5,5};
			int height[]              = {999999,986588,976757,988569,977678,999999,967675,947856,955856,999999,975956,956687,999999,979687,999999};
			long long B               = 0;
			int expected__            = 999999;

			std::clock_t start__      = std::clock();
			int received__            = TallShoes().maxHeight(N, vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(height, height + (sizeof height / sizeof height[0])), B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int N                     = ;
			int X[]                   = ;
			int Y[]                   = ;
			int height[]              = ;
			long long B               = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TallShoes().maxHeight(N, vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(height, height + (sizeof height / sizeof height[0])), B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int N                     = ;
			int X[]                   = ;
			int Y[]                   = ;
			int height[]              = ;
			long long B               = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TallShoes().maxHeight(N, vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(height, height + (sizeof height / sizeof height[0])), B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int N                     = ;
			int X[]                   = ;
			int Y[]                   = ;
			int height[]              = ;
			long long B               = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TallShoes().maxHeight(N, vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(height, height + (sizeof height / sizeof height[0])), B);
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
A king of a mystical land likes to wear very tall shoes.
The tall shoes are sometimes an inconvenience as they make traveling through the kingdom's road network difficult.



There are N cities in the kingdom.
The cities are numbered 0 through N-1.
The road network in the kingdom is connected: it is possible to get from any city to any other city by taking one or more roads.
Each road in the network is bidirectional and connects two different cities.
You are given the description of the road network in three vector <int>s: X, Y, and height, each with the same number of elements.
For each valid i, there is a road that connects cities X[i] and Y[i].
The value height[i] is the height limit for that road:
The king can travel along that road if and only if the height of his shoes is height[i] or less.



The king wants to walk from city 0 to city N-1.
While doing so, he wants to wear shoes that are as tall as possible.
Before he goes for the walk, he can increase the height limits for some roads.
The king has a budget of B dollars for the modifications.
Increasing the height limit of any road by k costs k^2 dollars.
The height limit of each road can only be increased at most once.



You are given the int N, the vector <int>s X, Y and height, and the long long B.
Compute the maximum height of shoes the king may wear for his walk from city 0 to city N-1 after increasing the height limits appropriately.


DEFINITION
Class:TallShoes
Method:maxHeight
Parameters:int, vector <int>, vector <int>, vector <int>, long long
Returns:int
Method signature:int maxHeight(int N, vector <int> X, vector <int> Y, vector <int> height, long long B)


CONSTRAINTS
-N will be between 2 and 50, inclusive.
-from, to, height will have between N-1 and N*(N-1)/2 elements, inclusive.
-Each element of X, Y will be between 0 and N-1, inclusive.
-For all i, X[i] != Y[i].
-Each undirected edge X[i], Y[i] will appear at most once.
-Each element of height will be between 0 and 10^6, inclusive. 
-The graph described by X and Y will be connected. 
-B will be between 0 and 10^15, inclusive.


EXAMPLES

0)
3
{0, 1, 0}
{1, 2, 2}
{3, 4, 2}
1

Returns: 4


In this example there are three roads: 0-1 (height limit 3), 1-2 (height limit 4), and 0-2 (height limit 2).
The king has a budget of 1 dollar.
The optimal way to use that budget is to increase the height limit for the 0-1 road from 3 to 4.
After that change, the king can use shoes of height 4 and walk along the path 0-1-2.


1)
3
{0, 1, 0}
{1, 2, 2}
{3, 4, 2}
52

Returns: 9

Here we can increase the last road's height by 7 which will allow the king to wear shoes of height 9. Note that the king is not required to spend the entire budget.

2)
8
{0, 0, 3, 3, 4, 4, 4, 7, 7}
{1, 2, 1, 2, 3, 5, 6, 5, 6}
{1000, 1000, 1000, 1000, 1, 1000, 1000, 1000, 1000}
3

Returns: 2



3)
10
{0,1,2,3,4,5,6,7,8}
{1,2,3,4,5,6,7,8,9}
{0,0,0,0,0,0,0,0,0}
9876543210123

Returns: 1047565



4)
6
{0,0,0,0,0,1,1,1,1,2,2,2,3,3,4}
{1,2,3,4,5,2,3,4,5,3,4,5,4,5,5}
{999999,986588,976757,988569,977678,999999,967675,947856,955856,999999,975956,956687,999999,979687,999999}
0

Returns: 999999



**/
// END CUT HERE
