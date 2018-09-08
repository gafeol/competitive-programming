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

const int MAXN = 21234;
const ll INF = 1000000000LL;

int n, m, k;
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

pii X[MAXN], Y[MAXN];
pii aux[MAXN];

inline void merge(int i, int m, int j){
	int a=i, b=m+1;
	int cnt = 0;
	while(a <= m && b <= j)
		aux[cnt++] = (Y[a].snd < Y[b].snd ? Y[a++] : Y[b++]);
	while(a <= m)
		aux[cnt++] = Y[a++];
	while(b <= j)
		aux[cnt++] = Y[b++];
	for(int a=i;a<=j;a++)
		Y[a] = aux[a-i];
}

inline ll dist(pii a, pii b){
	return ((ll)a.fst - b.fst)*((ll)a.fst - b.fst) + ((ll)a.snd - b.snd)*((ll)a.snd - b.snd);
}

pii v[MAXN];
inline ll combina(int i, int j, ll d){
	int cnt = 0;
	int mid = X[(i+j)/2].fst;
	for(int a=i;a<=j;a++){
		if(((ll)Y[a].fst - mid)*((ll)Y[a].fst - mid) <= d){
			v[cnt++] = Y[a];
		}
	}

	for(int a=0;a<cnt;a++){
		for(int b=a+1;b<cnt && b < a + 8 && ((ll)v[b].snd - v[a].snd)*((ll)v[b].snd - v[a].snd) < d;b++){
			d = min(d, dist(v[a], v[b]));
		}
	}
	return d;
}

ll go(int i, int j){
	ll d = 100000000;
	if(j - i + 1 <= 2){
		for(int a=i;a<=j;a++)
			for(int b=a+1;b<=j;b++)
				d = min(d, dist(X[a], X[b]));
		Y[i] = X[i];
		if(i+1 <= j){
			Y[i+1] = X[i+1];
			if(Y[i+1].snd < Y[i].snd)
				swap(Y[i], Y[i+1]);
		}
		return d;
	}
	int m = (i + j)/2;
	d = min(go(i, m), go(m+1, j));
	merge(i, m, j);
	d = combina(i, j, d);
	return d;
}

int main (){
	while(scanf("%d", &n) != EOF && n != 0){
		for(int a=0;a<n;a++)
			scanf("%d%d", &X[a].fst, &X[a].snd);
		sort(X, X+n);
		ll ans = go(0, n-1);
		if(ans >= 100000000){
			puts("INFINITY");
		}
		else{
			double res = sqrt(ans);
			printf("%.4lf\n", res);
		}

	}
}

