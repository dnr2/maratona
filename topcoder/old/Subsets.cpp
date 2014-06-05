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

int n,sz;
int num[1000];
int q[1000];
int ret;

void rec( int pos, int mul, int sum ){
	if( pos >= sz){
		if( mul < sum + n){
			ret += n + sum - mul;
		}
		return;
	}	
	REP(i,0,q[pos]+1){
		rec( pos + 1, mul, sum );		
		if(mul > sum + n) return;
		mul *= num[pos];
		sum += num[pos];
	}
}

struct Subsets {
    int findSubset(vector <int> numbers) {
		sz = 0;
		map<int,int> mapa;
		REP(i,0,numbers.size()) mapa[numbers[i]]++;
		for( map<int,int>::iterator it = mapa.begin(); it != mapa.end(); it++){
			if( it->F == 1 ) continue;
			num[sz] = it->F;
			q[sz] = it->S;
			// db( sz _ num[sz] _ q[sz]);
			sz++;
		}
		ret = 0;
		n = mapa[1];
	
		if( n == numbers.size()) return n - 1;
		rec( 0, 1, 0);
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
			int numbers[]             = {1,1,1};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = Subsets().findSubset(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int numbers[]             = {1,1,1,1,2,2,2,2};
			int expected__            = 13;

			std::clock_t start__      = std::clock();
			int received__            = Subsets().findSubset(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int numbers[]             = {1,2,3,4};
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = Subsets().findSubset(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int numbers[]             = {1,1,1,1,1,1,1,1,1,1,1,1,1,10,1000,1001,1002,1003};
			int expected__            = 77;

			std::clock_t start__      = std::clock();
			int received__            = Subsets().findSubset(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int numbers[]             = {1,1,1,1,1,1,1,1,1,1,1,2,3,4,2,2,2};
			int expected__            = 100;

			std::clock_t start__      = std::clock();
			int received__            = Subsets().findSubset(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int numbers[]             = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,2,2,2,3,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22};
			int expected__            = 8050;

			std::clock_t start__      = std::clock();
			int received__            = Subsets().findSubset(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int numbers[]             = {5,3};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = Subsets().findSubset(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 7: {
			int numbers[]             = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 39, 1, 1, 1, 1, 1, 1, 21, 1, 41, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 64, 1, 1, 1, 1, 27, 1, 1, 1, 1, 49, 1, 1, 1, 1, 1, 1, 1, 1, 1, 12, 1, 1, 1, 1, 1, 1, 1, 30, 1, 1, 1, 1, 1, 1, 1, 1, 1, 25, 1, 1, 1, 1, 39, 1, 1, 1, 1, 1, 26, 33, 1, 1, 1, 1, 1, 1, 1, 51, 4, 67, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 39, 1, 1, 1, 1, 1, 1, 1, 1, 44, 1, 57, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 32, 1, 1, 1, 1, 1, 1, 1, 1, 1, 62, 1, 1, 51, 1, 1, 1, 14, 1, 1, 1, 16, 1, 1, 1, 1, 39, 1, 1, 16, 1, 68, 1, 1, 39, 1, 1, 9, 1, 1, 1, 1, 43, 1};
			int expected__            = 4965;

			std::clock_t start__      = std::clock();
			int received__            = Subsets().findSubset(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 8: {
			int numbers[]             = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Subsets().findSubset(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int numbers[]             = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Subsets().findSubset(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
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
// You have a bag with some balls.
There is a positive integer written on each of the balls.
Balls with the same integer are identical.

A bag with balls is nice if the sum of numbers on all balls is strictly greater than the product of those numbers.
For example, if the numbers on balls are {1,1,2,3}, the bag is nice because 1+1+2+3 > 1*1*2*3.

You are given a vector <int> numbers.
Each element of numbers is a number written on one of the balls in your bag.
You are going to remove some (possibly none, but not all) balls from the bag.
After you do so, the bag must be nice.

Return the number of different nice bags you can obtain.

DEFINITION
Class:Subsets
Method:findSubset
Parameters:vector <int>
Returns:int
Method signature:int findSubset(vector <int> numbers)


NOTES
-You may assume that the return value always fits into a signed 32-bit integer variable.


CONSTRAINTS
-numbers will contain between 1 and 1000 elements, inclusive.
-Each element of numbers will be between 1 and 1000, inclusive.


EXAMPLES

0)
{1,1,1}

Returns: 2

The bag contains three identical balls, each with the number 1.
We can produce a nice bag in two ways:

Keep all three balls. The bag is nice because 1+1+1 > 1*1*1.
Throw away one ball. The bag is nice because 1+1 > 1*1.


1)
{1,1,1,1,2,2,2,2}

Returns: 13

Our bag contains 8 balls: four with a 1 and four with a 2.
All possible nice bags that can be produced by removing some of these balls are listed below, one per row.

1,1
1,1,1
1,1,1,1
1,2
1,1,2
1,1,1,2
1,1,1,1,2
1,2,2
1,1,2,2
1,1,1,2,2
1,1,1,1,2,2
1,1,1,2,2,2
1,1,1,1,2,2,2

2)
{1,2,3,4}

Returns: 3



3)
{1,1,1,1,1,1,1,1,1,1,1,1,1,10,20,30,40,50}

Returns: 77



4)
{1,1,1,1,1,1,1,1,1,1,1,2,3,4,2,2,2}

Returns: 100



5)
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
 1,1,1,1,1,1,2,2,2,3,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22}

Returns: 8050



6)
{5,3}

Returns: 0



**/
// END CUT HERE
