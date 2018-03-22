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

const int MAXN = 212345;

int n, m, k;
int s[MAXN];

vector<int> pos, neg;

bool cmp(int a, int b){
	return a > b;
}

int gcd(int a, int b){
	if(a == 0) return b;
	return gcd(b%a, a);
}

int main (){
	int test = 0;
	while(scanf("%d%d", &n, &k) != EOF && n > 0){
		int res = 0;
		pos.clear();
		neg.clear();
		int z = 0;
		for(int a=0;a<n;a++){
			int x;
			scanf("%d", &x);
			if(x > 0)
				pos.pb(x);
			else if(x == 0)
				z++;
			else
				neg.pb(x);
		}
		sort(pos.begin(), pos.end());
		sort(neg.begin(), neg.end(), cmp);
		if(k < 0)
			res += z*(n-z)*2 + z*z;
		int j = pos.size();
		for(int a=0;a<pos.size();a++){
			if(pos[0]*pos[a] > k)
				j = min(a, j);
		}
		for(int i=0;i<pos.size();i++){
			while(j > 0 && pos[j-1]*pos[i] > k)
				j--;
			res += pos.size() - j;
		}
		j = neg.size();
		for(int a=0;a<neg.size();a++)
			if(neg[0]*neg[a] > k)
				j = min(a, j);
		for(int i=0;i<neg.size();i++){
			while(j > 0 && neg[j-1]*neg[i] > k)
				j--;
			res += neg.size() - j;
		}
		j = -1;
		for(int a=0;a<neg.size();a++)
			if(pos[0]*neg[a] > k)
				j = a;
		for(int i=0;i<pos.size();i++){
			while(j >= 0 && neg[j]*pos[i] <= k)
				j--;
			res += 2*(j+1);
		}
		int g = gcd(res, n*n);
		printf("Case %d: %d/%d\n", ++test, res/g, (n*n)/g);
	}
}

