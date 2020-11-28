#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 212345;

class ColorWheel {

vector<string> colors = {"Yellow", "Green", "Blue", "Purple", "Red", "Orange"};
  public:
  string describePair(string color1, string color2) {
      int i, j;
      for(int a=0;a<colors.size();a++){
          if(color1 == colors[a])
              i = a;
          if(color2 == colors[a])
              j = a;
      }
      if(i == j) return "Same";
      if((i+1)%colors.size() == j || (j+1)%colors.size() == i)
          return "Adjacent";
        if((i+3)%colors.size() == j)
            return "Complementary";
    return "None";
      
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
	
	int verify_case(int casenum, const string &expected, const string &received, std::clock_t elapsed) { 
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
			std::cerr << "    Expected: \"" << expected << "\"" << std::endl; 
			std::cerr << "    Received: \"" << received << "\"" << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			string color1             = "Red";
			string color2             = "Green";
			string expected__         = "Complementary";

			std::clock_t start__      = std::clock();
			string received__         = ColorWheel().describePair(color1, color2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string color1             = "Red";
			string color2             = "Purple";
			string expected__         = "Adjacent";

			std::clock_t start__      = std::clock();
			string received__         = ColorWheel().describePair(color1, color2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string color1             = "Orange";
			string color2             = "Orange";
			string expected__         = "Same";

			std::clock_t start__      = std::clock();
			string received__         = ColorWheel().describePair(color1, color2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string color1             = "Yellow";
			string color2             = "Blue";
			string expected__         = "None";

			std::clock_t start__      = std::clock();
			string received__         = ColorWheel().describePair(color1, color2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string color1             = ;
			string color2             = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = ColorWheel().describePair(color1, color2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string color1             = ;
			string color2             = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = ColorWheel().describePair(color1, color2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string color1             = ;
			string color2             = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = ColorWheel().describePair(color1, color2);
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
