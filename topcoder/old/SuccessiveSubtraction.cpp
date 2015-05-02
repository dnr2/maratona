#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define PII pair<int,int>
#define FT first
#define SD second
#define REP(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define PB push_back
#define PI acos(-1)
#define DB(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define MP make_pair
#define EPS 1e-9
#define INF 0x3f3f3f3f
#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0)
#define FILL(x,v) memset(x,v,sizeof(x))

struct SuccessiveSubtraction {
    vector <int> calc(vector <int> a, vector <int> p, vector <int> v) {
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
			int a[]                   = {1, 2, 3, 4, 5};
			int p[]                   = {1, 2, 0, 4, 3};
			int v[]                   = {3, 9, -10, 5, 1};
			int expected__[]          = {10, 16, 5, 5, 2 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = SuccessiveSubtraction().calc(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(p, p + (sizeof p / sizeof p[0])), vector <int>(v, v + (sizeof v / sizeof v[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int a[]                   = {-100, -100, -100, -100, -100};
			int p[]                   = {0, 1, 2, 3, 4};
			int v[]                   = {0, 0, 0, 0, 0};
			int expected__[]          = {400, 300, 200, 100, 0 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = SuccessiveSubtraction().calc(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(p, p + (sizeof p / sizeof p[0])), vector <int>(v, v + (sizeof v / sizeof v[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int a[]                   = {83, 0, 25, 21};
			int p[]                   = {0, 3, 2, 1, 3, 1, 2};
			int v[]                   = {10, -90, 33, 52, -100, 0, 45};
			int expected__[]          = {56, 125, 133, 81, 91, 143, 155 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = SuccessiveSubtraction().calc(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(p, p + (sizeof p / sizeof p[0])), vector <int>(v, v + (sizeof v / sizeof v[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int a[]                   = {1};
			int p[]                   = {0, 0, 0, 0};
			int v[]                   = {10, -10, 100, -100};
			int expected__[]          = {10, -10, 100, -100 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = SuccessiveSubtraction().calc(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(p, p + (sizeof p / sizeof p[0])), vector <int>(v, v + (sizeof v / sizeof v[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			int a[]                   = {-11, -4, 28, 38, 21, -29, -45, 11, -58, -39, 92, 35, -56, -6, 29, -2, 61, 10, -29, -63};
			int p[]                   = {19, 5, 3, 10, 4, 18, 5, 2, 0, 15};
			int v[]                   = {-19, 21, 7, -66, 38, -39, -22, 24, -32, 13};
			int expected__[]          = {451, 443, 412, 440, 457, 467, 468, 464, 443, 458 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = SuccessiveSubtraction().calc(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(p, p + (sizeof p / sizeof p[0])), vector <int>(v, v + (sizeof v / sizeof v[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int a[]                   = ;
			int p[]                   = ;
			int v[]                   = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = SuccessiveSubtraction().calc(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(p, p + (sizeof p / sizeof p[0])), vector <int>(v, v + (sizeof v / sizeof v[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int a[]                   = ;
			int p[]                   = ;
			int v[]                   = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = SuccessiveSubtraction().calc(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(p, p + (sizeof p / sizeof p[0])), vector <int>(v, v + (sizeof v / sizeof v[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			int a[]                   = ;
			int p[]                   = ;
			int v[]                   = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = SuccessiveSubtraction().calc(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(p, p + (sizeof p / sizeof p[0])), vector <int>(v, v + (sizeof v / sizeof v[0])));
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
// 
One day, Maki found an expression written on the blackboard in her high school. 
The expression had the following form: "a[0] - a[1] - ... - a[n-1]".
You are given the vector <int> a containing the numbers used in the expression, in order of appearance.
Note that some of these numbers may be negative.
For example, a={1,-3,5} represents the expression "1-(-3)-5".


Maki noticed she can change the value of the expression by inserting additional parentheses.
For example, she can change "1-3-3-4-5" (which equals -14) to "1-(3-3-(4-5))" (which equals 0), or to "1-(3-3-4-5)" (which equals 10).


To keep things simple, Maki decided that she may add at most two pairs of parentheses.
Given this rule, Maki wanted to produce a value that would be as large as possible.
She quickly found the optimal solution for the above expression.
(In this problem we do not care about its value.)


Then, her mischievous friend Niko entered the classroom and she started to alter the expression.
Niko applied several consecutive changes.
In the i-th change, she erased the number at position p[i] and replaced it by the new value v[i].
(Both changes and positions are numbered starting from 0.)
You are given the vector <int>s p and v, each containing the same number of elements.


After each of Niko's changes, Maki quickly solved her problem for the new sequence.
Note that she always solved it in her head, without actually adding any parentheses to the blackboard.


Return a vector <int> with as many elements as there were changes by Niko.
For each i, element i of the return value should be the largest value Mako can produce from the expression after Niko's change number i.


DEFINITION
Class:SuccessiveSubtraction2
Method:calc
Parameters:vector <int>, vector <int>, vector <int>
Returns:vector <int>
Method signature:vector <int> calc(vector <int> a, vector <int> p, vector <int> v)


NOTES
-Parentheses can only be used to change the order in which the subtractions are evaluated. For example, "1(-2-3)", ")(1-2-3", and "12(34-56)78" are not valid ways to add parentheses.


CONSTRAINTS
-a will contain between 1 and 2000 elements, inclusive.
-p will contain between 1 and 2000 elements, inclusive.
-p and v will contain the same number of elements.
-All numbers in a and v will be between -100 and 100, inclusive.
-All numbers in p will be between 0 and N-1, inclusive, where N is the number of elements in a.


EXAMPLES

0)
{1, 2, 3, 4, 5}
{1, 2, 0, 4, 3}
{3, 9, -10, 5, 1}

Returns: {10, 16, 5, 5, 2 }

This is how the expression looks like after each of Niko's changes:

    1 - 3 - 3 - 4 - 5
    1 - 3 - 9 - 4 - 5
(-10) - 3 - 9 - 4 - 5
(-10) - 3 - 9 - 4 - 5
(-10) - 3 - 9 - 1 - 5		(fixed)

One optimal solution for the first expression is given in the problem statement.

1)
{-100, -100, -100, -100, -100}
{0, 1, 2, 3, 4}
{0, 0, 0, 0, 0}

Returns: {400, 300, 200, 100, 0 }

One optimal solution for the expression "0 - (-100) - (-100) - (-100) - (-100)" is not to add any parentheses at all.
Alternately, we can change the expression to "((0 - (-100) - (-100) - (-100) - (-100)))" which still has the same value.

2)
{83, 0, 25, 21}
{0, 3, 2, 1, 3, 1, 2}
{10, -90, 33, 52, -100, 0, 45}

Returns: {56, 125, 133, 81, 91, 143, 155 }



3)
{1}
{0, 0, 0, 0}
{10, -10, 100, -100}

Returns: {10, -10, 100, -100 }

There is only one number. The value of the expression is always equal to this number.

4)
{-11, -4, 28, 38, 21, -29, -45, 11, -58, -39, 92, 35, -56, -6, 29, -2, 61, 10, -29, -63}
{19, 5, 3, 10, 4, 18, 5, 2, 0, 15}
{-19, 21, 7, -66, 38, -39, -22, 24, -32, 13}

Returns: {451, 443, 412, 440, 457, 467, 468, 464, 443, 458 }



**/
// END CUT HERE
