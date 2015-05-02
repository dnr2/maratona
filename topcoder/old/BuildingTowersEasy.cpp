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

const int maxn = 200000;

struct BuildingTowersEasy {
    int maxHeight(int N, vector <int> x, vector <int> t) {		
		int resp = 0; int sz = x.size();		
		if( (sz > 0 && x[0] != 1 ) || sz == 0 ){
			x.insert( x.begin(), 1 );
			t.insert( t.begin(), 0 );		
			sz++;
			// DB( x.size() _ sz );
		}
		if( sz > 0 && x[0] == 1 ) t[0] = 0;
		if( sz > 1 ){
			bool change = true;
			while (change ){
				change = false;
				REP(i,1,sz){
					int dif = abs( x[i] - x[i-1] ) ;
					if( t[i] > t[i-1] + dif ){
						t[i] = t[i-1] + dif; change = true;
					}
				}
				REP(i,1,sz){
					REP(j,i+1,sz){
						if( i + 1 < sz && t[i+1] < t[i] ) {
							int dif = abs( x[j] - x[i] );
							if( t[i] > t[j] + dif ){
								t[i] = t[j] + dif; change = true;
							}
						}
					}
				}
			}
		}
		REP(i,1,sz){
			int dif = abs( x[i] - x[i-1] ) - 1;
			dif -= max( t[i] , t[i-1] ) - min( t[i], t[i-1]);
			if( dif < 0 ) dif = 0;
			resp = max( resp , max( t[i] , t[i-1] ) + (dif / 2) + (dif & 1) );					
		}		
		resp = max( resp , t[sz-1] + (N-x[sz-1] ));		
        return resp;
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
			int N                     = 10;
			int x[]                   = {3,8};
			int t[]                   = {1,1};
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = BuildingTowersEasy().maxHeight(N, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 100000;
			int x[]                   = {};
			int t[]                   = {};
			int expected__            = 99999;

			std::clock_t start__      = std::clock();
			int received__            = BuildingTowersEasy().maxHeight(N, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 2718;
			int x[]                   = {1,30,400,1300,2500};
			int t[]                   = {100000,100000,100000,100000,100000};
			int expected__            = 2717;

			std::clock_t start__      = std::clock();
			int received__            = BuildingTowersEasy().maxHeight(N, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 20;
			int x[]                   = {4,7,13,15,18};
			int t[]                   = {3,8,1,17,16};
			int expected__            = 8;

			std::clock_t start__      = std::clock();
			int received__            = BuildingTowersEasy().maxHeight(N, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 447;
			int x[]                   = {32,35,55,60,61,88,91,97,128,151,181,186,192,196,198,237,259,268,291,314,341,367,389,390,391,428,435};
			int t[]                   = {81,221,172,641,25,953,330,141,123,440,692,394,200,649,78,726,50,810,501,4,216,407,2,172,0,29,14};
			int expected__            = 120;

			std::clock_t start__      = std::clock();
			int received__            = BuildingTowersEasy().maxHeight(N, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int N                     = 97638;
			int x[]                   = {8,1749,4550,5388,6752,7089,9737,14891,16671,16821,17691,19753,24589, 25348,30114,32213,34376,36467,37699,41490,44784,44893,57316,58275,58567, 61122,61489,63195,64776,65905,68788,69908,72853,78152,78784,82779,84488, 86277,88611,92793,93214,97583};
			int t[]                   = {16610,6,497,14,42892,31,79,1203,518,31147,597,7846,1396,8309,12,14,1148, 433,23693,13,1939,244,19,46,27,611,412,10,27023,19141,34,15667,588,10,229, 83,390,14,38441,16021,4,39386};
			int expected__            = 6343;

			std::clock_t start__      = std::clock();
			int received__            = BuildingTowersEasy().maxHeight(N, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

		case 6: {
			int N                     = 39482;
			int x[]                   = {605, 873, 909, 1346, 3021, 4693, 4919, 4939, 5856, 7863, 10252, 11107, 11165, 11939, 12319, 15285, 15617, 18284, 18687, 19781, 20808, 21186, 21477, 21528, 21997, 24532, 25294, 25642, 26032, 26225, 27308, 27354, 27712, 28463, 29151, 29472, 30560, 31055, 32071, 32867, 33277, 33294, 33522, 33779, 34976, 35959, 36501, 36821, 39393};
			int t[]                   = {58, 2528, 476, 45, 6, 23, 1, 95, 18656, 4, 77, 290, 32155, 4329, 5, 12, 4031, 53656, 69933, 193, 19, 19, 31043, 3249, 4239, 9, 5, 74077, 184, 73, 109, 12256, 9705, 84620, 17675, 6483, 81243, 2, 5213, 18, 1, 3, 39, 2538, 62, 162, 2160, 2294, 5755};
			int expected__            = 3685;

			std::clock_t start__      = std::clock();
			int received__            = BuildingTowersEasy().maxHeight(N, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
      case 7: {
			int N                     = 93420;
			int x[]                   = {4005, 5533, 7131, 7902, 12354, 19354, 25872, 28579, 31592, 34086, 35505, 36169, 37204, 37611, 42279, 52596, 54243, 56553, 57794, 58587, 65802, 72733, 73864, 75871, 75886, 76538, 78011, 79511, 80645, 81325, 82604, 82873, 84556, 85238, 86005, 86212, 86842, 90019, 90189, 91749, 92368};
			int t[]                   = {134, 14, 43, 55, 605, 76, 1, 571, 6, 10, 1, 253, 89, 2, 169, 1, 2, 30, 2, 6, 4, 769, 476, 2, 11, 690, 10, 52, 17, 99, 725, 13, 1, 33, 1, 311, 10, 501, 437, 555, 1};
			int expected__            = 5243;

			std::clock_t start__      = std::clock();
			int received__            = BuildingTowersEasy().maxHeight(N, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
      case 8: {
			int N                     = 60459;
			int x[]                   = {779, 938, 3370, 4612, 6886, 7853, 8420, 14530, 15227, 15728, 16500, 18171, 21295, 21441, 22192, 26765, 26925, 27915, 28377, 29516, 33102, 35049, 35355, 35529, 37324, 37593, 37915, 38644, 39249, 42231, 43279, 44783, 45182, 47732, 49039, 49594, 51911, 52335, 53119, 53213, 56289};
			int t[]                   = {8424, 8166, 5697, 21181, 21777, 8780, 65091, 88483, 30136, 55683, 87419, 21498, 32912, 25340, 3512, 24235, 23823, 79778, 14931, 16280, 43424, 9489, 81941, 17608, 15867, 69841, 67557, 24396, 89995, 34551, 79113, 74631, 21622, 73516, 40529, 10460, 16606, 50636, 31072, 1759, 17201};
			int expected__            = 14706;

			std::clock_t start__      = std::clock();
			int received__            = BuildingTowersEasy().maxHeight(N, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
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
// 
The citizens of Byteland want to build N new buildings.
The new buildings will all stand in a line and they will be labeled 1 through N, in order.
The city regulations impose some restrictions on the heights of the new buildings.
You are given the parameters used in these restrictions: two vector <int>s x and t.
The restrictions are described below.


The height of each building must be a nonnegative integer.
The height of building 1 must be 0.
The absolute value of the difference between any two adjacent buildings must be at most 1.
For each valid i, the height of building x[i] must be t[i] or less.




Given these restrictions, the citizens of Byteland want to build a building that will be as tall as possible.
Return the largest possible height some of the N buildings may have.


DEFINITION
Class:BuildingTowersEasy
Method:maxHeight
Parameters:int, vector <int>, vector <int>
Returns:int
Method signature:int maxHeight(int N, vector <int> x, vector <int> t)


CONSTRAINTS
-N will be between 1 and 100,000, inclusive.
-x will contain between 0 and min(N,50) elements, inclusive.
-t will have exactly the same number of elements as x.
-Each element of x will be between 1 and N, inclusive.
-x[i] < x[i+1] for all valid i.
-Each element of t will be between 0 and 100,000, inclusive.


EXAMPLES

0)
10
{3,8}
{1,1}

Returns: 3


In this case we are going to build 10 buildings.
We have two constraints: the height of building 3 can be at most 1, and the height of building 8 can also be at most 1.
The tallest possible new building in this city can have height 3.
One optimal skyline looks as follows: {0,1,1,2,3,3,2,1,1,0}.


1)
100000
{}
{}

Returns: 99999

There are no additional constraints so, for each valid i, the height of building i can be (i-1).

2)
2718
{1,30,400,1300,2500}
{100000,100000,100000,100000,100000}

Returns: 2717



3)
20
{4,7,13,15,18}
{3,8,1,17,16}

Returns: 8



4)
447
{32,35,55,60,61,88,91,97,128,151,181,186,192,196,198,237,259,268,291,314,341,367,389,390,391,428,435}
{81,221,172,641,25,953,330,141,123,440,692,394,200,649,78,726,50,810,501,4,216,407,2,172,0,29,14}

Returns: 120



5)
97638
{8,1749,4550,5388,6752,7089,9737,14891,16671,16821,17691,19753,24589,
25348,30114,32213,34376,36467,37699,41490,44784,44893,57316,58275,58567,
61122,61489,63195,64776,65905,68788,69908,72853,78152,78784,82779,84488,
86277,88611,92793,93214,97583}
{16610,6,497,14,42892,31,79,1203,518,31147,597,7846,1396,8309,12,14,1148,
433,23693,13,1939,244,19,46,27,611,412,10,27023,19141,34,15667,588,10,229,
83,390,14,38441,16021,4,39386}

Returns: 6343



**/
// END CUT HERE
