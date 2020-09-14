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

const int MAXN = 1000007;

class BobtheBuilder {
  public:
  int minimumPrice(int B, int K, int H) {
    vector<int> d(MAXN, -1); 
    d[B] = 0;
    set<pii> q;
    q.insert({0, B});
    while(!q.empty()){
        pii p = *q.begin();
        q.erase(q.begin());
        int u = p.snd;
        if(u == H)
            return d[u];
        for(int nxt=1;nxt<=sqrt(u)+1 && nxt < u;nxt++){
            if(u%nxt == 0){
                if(d[nxt] == -1 || d[nxt] > d[u]){
                    if(d[nxt] > d[u])
                        q.erase({d[nxt], nxt});
                    d[nxt] = d[u];
                    q.insert({d[nxt], nxt});
                }
                int o = u/nxt;
                if(d[o] == -1 || d[o] > d[u]){
                    if(d[o] > d[u])
                        q.erase({d[o], o});
                    d[o] = d[u];
                    q.insert({d[o], o});
                }
            }
        }
        if(u + K < MAXN && (d[u+K] == -1 || d[u+K] > d[u] + 1)){
            if(d[u+K] > d[u] + 1)
                q.erase({d[u+K], u+K});
            d[u+K] = d[u] + 1;
            q.insert({d[u+K], u+K});
        }
    }
    return d[H];
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
			int B                     = 65;
			int K                     = 5;
			int H                     = 6;
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = BobtheBuilder().minimumPrice(B, K, H);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int B                     = 3;
			int K                     = 2;
			int H                     = 2;
			int expected__            = -1;

			std::clock_t start__      = std::clock();
			int received__            = BobtheBuilder().minimumPrice(B, K, H);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int B                     = 5;
			int K                     = 6;
			int H                     = 79;
			int expected__            = 13;

			std::clock_t start__      = std::clock();
			int received__            = BobtheBuilder().minimumPrice(B, K, H);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int B                     = 94;
			int K                     = 1;
			int H                     = 25;
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = BobtheBuilder().minimumPrice(B, K, H);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int B                     = 289;
			int K                     = 5;
			int H                     = 17;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = BobtheBuilder().minimumPrice(B, K, H);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int B                     = 90;
			int K                     = 1;
			int H                     = 82;
			int expected__            = 37;

			std::clock_t start__      = std::clock();
			int received__            = BobtheBuilder().minimumPrice(B, K, H);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int B                     = 401;
			int K                     = 780;
			int H                     = 779;
			int expected__            = 30;

			std::clock_t start__      = std::clock();
			int received__            = BobtheBuilder().minimumPrice(B, K, H);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			int B                     = ;
			int K                     = ;
			int H                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BobtheBuilder().minimumPrice(B, K, H);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int B                     = ;
			int K                     = ;
			int H                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BobtheBuilder().minimumPrice(B, K, H);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int B                     = ;
			int K                     = ;
			int H                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BobtheBuilder().minimumPrice(B, K, H);
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
