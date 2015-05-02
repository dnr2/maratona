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

int sum[(1<<10)+3];

struct Similars {
    int maxsim(int L, int R) {
		FILL(sum,0);
		REP(i,L,R+1){
			int aux = i;
			int mask = 0;
			while( aux > 0){
				mask |= (1<<(aux%10));
				aux /= 10;
			}
			aux = mask;			
			while( aux > 0){							
				sum[aux]++;				
				aux = (aux-1) & mask;
			}
		}
		int ret = 0;
		REP(mask,0,1<<10){
			if(sum[mask] > 1 ){
				int cont = 0, aux = mask;
				while( aux > 0){
					cont += (aux&1);
					aux >>= 1;
				}
				ret = max( ret, cont );
			}
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
			int L                     = 1;
			int R                     = 10;
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = Similars().maxsim(L, R);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int L                     = 1;
			int R                     = 99;
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = Similars().maxsim(L, R);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int L                     = 99;
			int R                     = 100;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = Similars().maxsim(L, R);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int L                     = 1000;
			int R                     = 1010;
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = Similars().maxsim(L, R);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int L                     = 444;
			int R                     = 454;
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = Similars().maxsim(L, R);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

		case 5: {
			int L                     = 1234;
			int R                     = 1239;
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = Similars().maxsim(L, R);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
      case 6: {
			int L                     = 1234;
			int R                     = 1234;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = Similars().maxsim(L, R);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 7: {
			int L                     = 11378;
			int R                     = 83117;
			int expected__            = 5;

			std::clock_t start__      = std::clock();
			int received__            = Similars().maxsim(L, R);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 8: {
			int L                     = 2;
			int R                     = 100000;
			int expected__            = 5;

			std::clock_t start__      = std::clock();
			int received__            = Similars().maxsim(L, R);
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
// Given two positive integers x and y, their similarity S(x, y) is defined as follows:
To compute S(x, y) we count all d between 0 and 9, inclusive, such that both x and y contain the digit d when written in base 10 (without any leading zeros).
For example, S(1123, 220181) = 2 since both numbers contain the digit 1 and both contain the digit 2.

You are given two ints L and R that define a range.
Find two distinct integers in this range that have the largest similarity.
Formally, return the maximum of S(a, b) over all a, b such that L <= a < b <= R.

DEFINITION
Class:Similars
Method:maxsim
Parameters:int, int
Returns:int
Method signature:int maxsim(int L, int R)


CONSTRAINTS
-R will be between 2 and 100,000, inclusive.
-L will be between 1 and R - 1, inclusive.


EXAMPLES

0)
1
10

Returns: 1

We have S(1, 10) = 1 since both numbers contain the digit 1. All other pairs of numbers within this range have similarity 0.

1)
1
99

Returns: 2

There are many pairs with similarity 2, for example pairs (23,32) and (38,83).

2)
99
100

Returns: 0

Here we have only one pair (99, 100) and its similarity is 0.

3)
1000
1010

Returns: 2



4)
444
454

Returns: 2



**/
// END CUT HERE
