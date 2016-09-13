#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m, k;

struct pti{
	int i, j;
	pti(int ii, int jj){
		i = ii;
		j = jj;
	}
	pti(){}
} e, d, e2, d2;

int res;
int test(int a, int b, int c, int d){
	printf("? %d %d %d %d\n", a, b, c, d);
	fflush(stdout);
	scanf("%d", &res);
	return res;
}

bool valid(int x, int y, int xx, int yy){
	return (xx - x > 0 && yy - y > 0 && x > 0 && xx > 0 && y > 0 && yy > 0 && x <= n && xx <= n && y <= n && yy <= n) ;
}

int main (){
	scanf("%d", &n);
	int found = 0, end = 0;
	int i = 1, ii = n;
	int niv = 0;
	int j = 1, jj = n;
	int l = i, r = ii, m;
	while(l < r){
		m = (l+r+1)/2;
		test(j, m, jj, ii);
		if(res > 0)
			l = m;
		else
			r = m - 1;
	}
	i = l;
//	printf("achei i %d\n", i);
	l = i;
	r = ii;
	while(l < r){
		m = (l + r)/2;
		test(j, i, jj, m);
		if(res > 0)
			r = m;
		else
			l = m+1;
	}
	ii = l;
//	printf("achei ii %d\n", ii);
	l = j;
	r = jj;
	while(l < r){
		m = ((l + r+1)/2);
		test(m, i, jj, ii);
		if(res > 0)
			l = m;
		else
			r = m - 1;
	}
	j = l;
//	printf("achei j %d\n", j);
	l = j;
	r = jj;
	while(l < r){
		m = ((l+ r)/2);
		test(j, i, m, ii);
		if(res > 0)
			r = m;
		else
			l = m + 1;
	}
	jj = l;
//	printf("achei jj %d\n", jj);
//	printf("%d %d %d %d\n", j, i, jj, ii);
	int j2 = j, i2 = i, jj2 = jj, ii2 = ii;
	j = 1; jj = n;
	i = 1; ii = n;
	if(valid(1, 1, j2-1, n) && test(1, 1, j2-1, n))
		jj = j2-1;
	else if(valid(1, 1, n, i2-1) && test(1, 1, n, i2-1))
		ii = i2 - 1;
	else if(valid(jj2+1, 1, n, n) && test(jj2+1, 1, n, n))
		j = jj2+1;
	else
		i = ii2+1;
	
	l = i;
	r = ii;
	while(l < r){
		m = (l+r+1)/2;
		test(j, m, jj, ii);
		if(res > 0)
			l = m;
		else
			r = m - 1;
	}
	i = l;
//	printf("achei i %d\n", i);
	l = i;
	r = ii;
	while(l < r){
		m = (l + r)/2;
		test(j, i, jj, m);
		if(res > 0)
			r = m;
		else
			l = m+1;
	}
	ii = l;
//	printf("achei ii %d\n", ii);
	l = j;
	r = jj;
	while(l < r){
		m = ((l + r+1)/2);
		test(m, i, jj, ii);
		if(res > 0)
			l = m;
		else
			r = m - 1;
	}
	j = l;
//	printf("achei j %d\n", j);
	l = j;
	r = jj;
	while(l < r){
		m = ((l+ r)/2);
		test(j, i, m, ii);
		if(res > 0)
			r = m;
		else
			l = m + 1;
	}
	jj = l;
//	printf("achei jj %d\n", jj);
	printf("! %d %d %d %d %d %d %d %d\n", j, i, jj, ii, j2, i2, jj2, ii2);
	fflush(stdout);
}
