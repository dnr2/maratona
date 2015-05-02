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

const int maxn = 1010;

double dp[maxn][maxn][27][2];
double sum[maxn][2];


struct SquareScores {
    double calcexpectation(vector <int> p, string s) {
		int sz = p.size(); 
		REP(i,0,sz) p[i] /= 100.0;
		FILL(dp,0);
		
		if( s[0] == '?' ){
			REP(l,0,sz){
				dp[0][0][l][0] = 1;
				dp[0][0][l][1] = p[l];
			}
		} else {			
			dp[0][0][s[0]-'a'][0] = 1;
			dp[0][0][s[0]-'a'][1] = 1;
		}
		REP(l,0,sz){
			REP(kk,0,2){
				sum[0][kk] += dp[0][0][l][kk];
			}
		}
		REP(pos,1,(int)s.size()){
			REP(cont,0,pos+1){
				if( s[pos] == '?' ){
					REP(l,0,sz){						
						dp[pos][cont][l][0] += sum[pos-cont][0];
						dp[pos][cont][l][0] += sum[pos-cont][0] * p[l];
					}
				} else {
					dp[pos][cont][s[pos]-'a'][0] += sum[pos-cont][0];
					dp[pos][cont][s[pos]-'a'][1] += sum[pos-cont][1];					
				}
				REP(l,0,sz){
					REP(kk,0,2){
						sum[pos][kk] += dp[pos][cont][l][kk];
					}
				}
			}
			
		}
		int ssz = s.size();
        return sum[ssz-1][0] * sum[ssz-1][1];
    }
};

// BEGIN CUT HERE
#include <algorithm>
#include <cmath>
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
	
	static const double MAX_DOUBLE_ERROR = 1e-9;
	static bool topcoder_fequ(double expected, double result) {
		if (std::isnan(expected)) {
			return std::isnan(result);
		} else if (std::isinf(expected)) {
			if (expected > 0) {
				return result > 0 && std::isinf(result);
			} else {
				return result < 0 && std::isinf(result);
			}
		} else if (std::isnan(result) || std::isinf(result)) {
			return false;
		} else if (std::fabs(result - expected) < MAX_DOUBLE_ERROR) {
			return true;
		} else {
			double mmin = std::min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR));
			double mmax = std::max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR));
			return result > mmin && result < mmax;
		}
	}
	double moj_relative_error(double expected, double result) {
		if (std::isnan(expected) || std::isinf(expected) || std::isnan(result) || std::isinf(result) || expected == 0) {
			return 0;
		}
		return std::fabs(result-expected) / std::fabs(expected);
	}
	
	int verify_case(int casenum, const double &expected, const double &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (topcoder_fequ(expected, received)) {
			verdict = "PASSED";
			double rerr = moj_relative_error(expected, received); 
			if (rerr > 0) {
				std::sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			int p[]                   = {1, 99};
			string s                  = "aaaba";
			double expected__         = 8.0;

			std::clock_t start__      = std::clock();
			double received__         = SquareScores().calcexpectation(vector <int>(p, p + (sizeof p / sizeof p[0])), s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int p[]                   = {10, 20, 70};
			string s                  = "aa?bbbb";
			double expected__         = 15.0;

			std::clock_t start__      = std::clock();
			double received__         = SquareScores().calcexpectation(vector <int>(p, p + (sizeof p / sizeof p[0])), s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int p[]                   = {10, 20, 30, 40};
			string s                  = "a??c?dc?b";
			double expected__         = 11.117;

			std::clock_t start__      = std::clock();
			double received__         = SquareScores().calcexpectation(vector <int>(p, p + (sizeof p / sizeof p[0])), s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int p[]                   = {25, 25, 21, 2, 2, 25};
			string s                  = "a??b???????ff??e";
			double expected__         = 21.68512690712425;

			std::clock_t start__      = std::clock();
			double received__         = SquareScores().calcexpectation(vector <int>(p, p + (sizeof p / sizeof p[0])), s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int p[]                   = {4, 4, 4, 3, 4, 4, 4, 4, 4, 4, 3, 4, 4, 4, 3, 4, 4, 4, 4, 4, 4, 4, 3, 4, 4, 4};
			string s                  = "??????????????????????????????";
			double expected__         = 31.16931963781721;

			std::clock_t start__      = std::clock();
			double received__         = SquareScores().calcexpectation(vector <int>(p, p + (sizeof p / sizeof p[0])), s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int p[]                   = {4, 3, 4, 3, 8, 2, 4, 3, 4, 4, 3, 2, 4, 4, 3, 4, 2, 4, 7, 6, 4, 4, 3, 4, 4, 3};
			string s                  = "makigotapresentfromniko";
			double expected__         = 23.0;

			std::clock_t start__      = std::clock();
			double received__         = SquareScores().calcexpectation(vector <int>(p, p + (sizeof p / sizeof p[0])), s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int p[]                   = ;
			string s                  = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = SquareScores().calcexpectation(vector <int>(p, p + (sizeof p / sizeof p[0])), s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int p[]                   = ;
			string s                  = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = SquareScores().calcexpectation(vector <int>(p, p + (sizeof p / sizeof p[0])), s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int p[]                   = ;
			string s                  = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = SquareScores().calcexpectation(vector <int>(p, p + (sizeof p / sizeof p[0])), s);
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
A substring of a string is a contiguous sequence of characters from the string.
For example, each of the strings "ab", "bcd", and "e" is a substring of "abcde". 
On the other hand, "cba", "ace", and "f" are not substrings of "abcde".


The score of a string S is the number of ways in which we can select a non-empty substring of S such that all characters in the substring are the same.
If two substrings consist of the same letters but occur at different places in S, they are still considered different.
For example, the score of "aaaba" is 8: there are four occurrences of the substring "a", two occurrences of "aa", one occurrence of "aaa", and one of "b".


On her birthday, Maki got a string s from her friend Niko as a present.
Each character in this string is either a lowercase letter or a question mark ('?').


Maki is going to randomly change each question mark into a letter.
For each question mark and each i, the probability that she changes it into the (i+1)-st letter of the alphabet is p[i] percent.
(I.e., she will change it into an 'a' with probability p[0]/100, into a 'b' with probability p[1]/100, and so on.)
The choices for different question marks are mutually independent.


You are given the vector <int> p.
Note that p may have fewer than 26 elements.
In that case we assume that the missing probabilities are 0.


Calculate and return the expected score of the string after all the question marks are changed into letters.


DEFINITION
Class:SquareScores
Method:calcexpectation
Parameters:vector <int>, string
Returns:double
Method signature:double calcexpectation(vector <int> p, string s)


NOTES
-The solution is correct if the relative error or the absolute error is at most 1e-9.


CONSTRAINTS
-s will contain between 1 and 1,000 elements, inclusive.
-Each character in s will be '?' or a lowercase letter ('a'-'z').
-If a character in s is j'th lowercase letter(1-indexed), j will be between 1 and (the size of p), inclusive.
-p will contain between 1 and 26 characters, inclusive.
-Each element in p will be between 0 and 100, inclusive.
-The sum of all elements in p will be exactly 100.


EXAMPLES

0)
{1, 99}
"aaaba"

Returns: 8.0



1)
{10, 20, 70}
"aa?bbbb"

Returns: 15.0



2)
{10, 20, 30, 40}
"a??c?dc?b"

Returns: 11.117



3)
{25, 25, 21, 2, 2, 25}
"a??b???????ff??e"

Returns: 21.68512690712425



4)
{4, 4, 4, 3, 4, 4, 4, 4, 4, 4, 3, 4, 4, 4, 3, 4, 4, 4, 4, 4, 4, 4, 3, 4, 4, 4}
"??????????????????????????????"

Returns: 31.16931963781721



5)
{4, 3, 4, 3, 8, 2, 4, 3, 4, 4, 3, 2, 4, 4, 3, 4, 2, 4, 7, 6, 4, 4, 3, 4, 4, 3}
"makigotapresentfromniko"

Returns: 23.0



**/
// END CUT HERE
