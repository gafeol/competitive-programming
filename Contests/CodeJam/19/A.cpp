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

const int MAXS = 2123;

void print(queue<int> q){
	while(q.size() > 1 && q.front() == 0)
		q.pop();
	while(q.size()){
		printf("%d", q.front());
		q.pop();
	}
}

int main (){
	int t;
	scanf("%d", &t);
	int cnt = 1;
	while(t--){
		char s[MAXS];
		scanf(" %s", s);
		int n = strlen(s);
		queue<int> na, nb;
		for(int i=0;i<n;i++){
			if(s[i] == '4'){
				na.push(2);
				nb.push(2);
			}
			else{
				na.push(s[i]-'0');
				nb.push(0);
			}
		}

		printf("Case #%d: ", cnt++);
		print(na);
		printf(" ");
		print(nb);
		puts("");
	}
}

