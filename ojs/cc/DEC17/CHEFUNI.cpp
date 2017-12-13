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
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345, INF = 0x3f3f3f3f;

int n, m, k;
int s[MAXN];

int A, B, C, D;

int go(){
	int ans = INF;
	int cus = 0;

	for(int a=0;a<8;a++){
		if((a&1)){
			s[0]--;
			s[2]--;
			cus += B;
		}
		if((a&2)){
			s[1]--;
			s[2]--;
			cus += B;
		}
		for(int b=0;b<8;b++){
			if((b&1)){
				s[0]--;
				s[2]--;
				cus += B;
			}
			if((b&2)){
				s[1]--;
				s[2]--;
				cus += B;
			}
			int mn = *min_element(s, s+3);
			if(mn >= 0)
				ans = min(ans, cus + ((mn/2)*D + (mn&1)*C + (s[0] - mn)*A + (s[1] - mn)*A + (s[2] - mn)*A));
			if((b&1)){
				s[0]++;
				s[2]++;
				cus -= B;
			}
			if((b&2)){
				s[1]++;
				s[2]++;
				cus -= B;
			}
		}
		if((a&1)){
			s[0]++;
			s[2]++;
			cus -= B;
		}
		if((a&2)){
			s[1]++;
			s[2]++;
			cus -= B;
		}
	}
	return ans;
}

int ch[4];

int test(){
	s[0] -= ch[0];
	s[1] -= ch[1];
	s[2] -= ch[2];
	debug("go %d %d %d\n", s[0], s[1], s[2]);
	int r = go();	
	s[0] += ch[0];
	s[1] += ch[1];
	s[2] += ch[2];
	return r;

}

int ac(){
	int ans = 0;
	if(s[0] + s[1] <= s[2]){
		ch[0] = s[0];
		ch[1] = s[1];
		ch[2] = s[0] + s[1];
		ans = B*(s[0] + s[1]) + test();
		debug("B*%d + %d\n", s[0] + s[1], test());
	}
	else{
		assert(s[0] == s[1]);
		int k = s[2] - s[0];
		ch[0] = k; 
		ch[1] = k;
		ch[2] = 2*k;
		debug("test1 k %d\n", k); 
		ans = 2*B*k + test();
		debug("ans test %d\n", 2*B*k + test());
		if(k > 0){
			k--;
			ch[0] = k;
			ch[1] = k;
			ch[2] = 2*k;
			debug("test2 k %d\n", k); 
			ans = min(ans, 2*B*k + test());
			debug("ans test2 %d\n", 2*B*k + test());
		}
	}
	debug("ac %d\n", ans);
	return ans;
}

int main (){
	for_tests(t, tt){
		int res = 0;
		for(int a=0;a<3;a++)
			scanf("%d", s+a);
		sort(s, s+3);
		scanf("%d %d %d", &A, &B, &C);
		B = min(A*2, B);
		C = min(C, B+A);
		D = min(C*2, 3*B);
		res += B*(s[1] - s[0]);
		s[2] -= (s[1] - s[0]);
		s[1] -= (s[1] - s[0]);
		int ans = go(); 
		ans = min(ans, ac());
		printf("%d", res + ans);
		if(tt != t) puts("");
	}
}
