#include <cstdio>
#include <cstdlib>
#include <vector>
#include <utility>
#include <set>
#include <algorithm>
#include <cstring>
#include <cassert>
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

const int MAXN = 512345;
const int MAXX = 500010;

int n, m, k;

int timm;

int bit[MAXX], tim[MAXX];
int ind[MAXN];

pii pt[MAXN], qr[MAXN];

int qry(int i){
	i += 2;
	int ans = 0;
	while(i > 0) {
		if(tim[i] != timm){
			tim[i] = timm;
			bit[i] = 0;
		}
		ans += bit[i];
		i -= (i&-i);
	}
	return ans;
}

void upd(int i){
	i += 2;
	while(i < MAXX){
		if(tim[i] != timm){
			tim[i] = timm;
			bit[i] = 0;
		}
		bit[i] += 1;
		i += (i&-i);
	}
}


int res[MAXN];
int ans[MAXN];

bool cmp(int a, int b){
	return qr[a] < qr[b];
}

inline void count(){
	sort(ind, ind+m, cmp);
	int b = 0;
	for(int aa=0;aa<m;aa++){
		int a = ind[aa];
		while(b < n && pt[b].fst < qr[a].fst){
			upd(pt[b].snd);
			b++;
		}
		res[a] += qry(qr[a].snd);
	}
}

vector<int> X, Y;

inline void read(int &number){
	//variable to indicate sign of input number
	bool negative = false;
	register int c;

	number = 0;

	// extract current character from buffer
	while(1){
		c = getchar();
		if(c == ' ' || c == '\n') continue;
		else break;
	}
	if (c=='-')
	{
		// number is negative
		negative = true;

		// extract the next character from the buffer
		c = getchar();
	}

	// Keep on extracting characters if they are integers
	// i.e ASCII Value lies from '0'(48) to '9' (57)
	for (; (c>47 && c<58); c=getchar())
		number = number *10 + c - 48;

	// if scanned input has a negative sign, negate the
	// value of the input number
	if (negative)
		number *= -1;
}

int main (){
	for_tests(t, tt){
		timm = tt;
		read(n);
		read(m);
		X.clear();
		Y.clear();
		for(int a=0;a<n;a++){
			int i, j;
			read(i);
			read(j);
			pt[a] = pii(i, j);
			X.pb(i);
			Y.pb(j);
		}

		sort(pt, pt+n);

		sort(X.begin(), X.end());
		sort(Y.begin(), Y.end());

		for(int a=0;a<m;a++){
			int i, j;
			read(i);
			read(j);
			qr[a] = pii(i, j);
			debug("qr[%d] %d %d\n", a, i, j);
			ind[a] = a;
		}
		count();

		for(int a=0;a<m;a++){
			debug("a %d res %d\n", a, res[a]);
			debug("qr %d %d\n", qr[a].fst, qr[a].snd);
			debug("left %d down %d\n", (int)(lower_bound(X.begin(), X.end(), qr[a].fst) - X.begin()), (int)(lower_bound(Y.begin(), Y.end(), qr[a].snd) - Y.begin()));
			ans[a] = (lower_bound(X.begin(), X.end(), qr[a].fst) - X.begin()) - res[a] +
					 (lower_bound(Y.begin(), Y.end(), qr[a].snd) - Y.begin()) - res[a]; 
			printf("%d\n", abs(n - 2*ans[a]));
			res[a] = 0;
			ans[a] = 0;
		}
		if(tt < t)
			puts("");
	}
}
