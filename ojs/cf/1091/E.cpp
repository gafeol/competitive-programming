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

const int MAXN = 512345;

int n, m, k;
vector<int> s;
ll som;

vector<int> dg;

const int MEN = 0, OK = 1, MAI = 2;

int go(int x){
	dg.clear();
	bool pt = false;
	int pos = -1;
	for(int v: s){
		if(!pt && x >= v){
			pos = dg.size();
			dg.pb(x);
			pt = true;
		}
		dg.pb(v);
	}
	if(!pt){
		pos = dg.size();
		dg.pb(x);
	}


	ll j = n;
	ll som = 0, somd = 0;
	for(ll k=1;k<=n+1;k++){
		som += dg[k-1];
		while(j > k-1  && dg[j] <= k-1){
			somd += dg[j];
			j--;
		}
		if(j < k-1){
			j++;
			somd -= dg[j];
		}

		if(som > k*(k-1) + somd + k*(j - k+1)){
			if(pos <= k-1){
//				puts("MAI");
				return MAI;
			}
			else{
//				puts("MEN");
				return MEN;
			}
		}
	}
	//puts("OK");
	return OK;
}

bool cmp(int a, int b){
	return a > b;
}

int main (){
	scanf("%d", &n);

	for(int a=0;a<n;a++){
		int x;
		scanf("%d", &x);
		s.pb(x);
		som += s[a];
	}
	sort(s.begin(), s.end(), cmp);
	int imp = (som&1);
	
	// GET MAX
	int i = 0, j = n;
	while(i < j){
		int m = (i + j + 1)/2;
		int foi = go(2*m + imp);
		if(foi == MAI)
			j = m-1;
		else if(foi == MEN)
			i = m+1;
		else 
			i = m;
	}

	int mai = 2*i + imp;
	if(go(mai) != OK){
		puts("-1");
		return 0;
	}

	// GET MIN
	i = 0, j = n;
	while(i < j){
		int m = (i+j)/2;
		int foi = go(2*m + imp);
		if(foi == MEN)
			i = m+1;
		else if(foi == MAI)
			j = m-1;
		else
			j = m;
	}

	int men = 2*i + imp;
	if(go(men) != OK){
		puts("-1");
		return 0;
	}

	while(men != mai){
		printf("%d ", men);
		men += 2;
	}
	printf("%d\n", men);
}

