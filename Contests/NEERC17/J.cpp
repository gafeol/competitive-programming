#include <cstdio>

#define min(a,b) ((a) < (b) ? (a) : (b))

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
template<typename T> inline T abs(T t) { return t < 0? -t : t; }

const int N = 5007;
const int M = 10*N + 7;
const int oo = 1e9;

struct Edge {
	int to, x, u;
	struct Edge * nx;
} _E[M], *es = _E;
typedef struct Edge * edge;
inline int & x (edge e) { return e->x; }
inline int & u (edge e) { return e->u; }
inline edge rev (edge e) { return _E + (1^(e - _E)); }

int n, m;
int vs, r, s, y[N];
edge ad[N], hd[N];

void add (int i, int j){
	*es = {j, 0, 1, ad[i]}, ad[i] = es++;
	*es = {i, 0, 0, ad[j]}, ad[j] = es++;
}

int bfs ()
{
	static int q[N];
	int *qf = q, *qb = q, i;
	for (i = 0; i < vs; i++) y[i] = oo;
	y[*qb++ = r] = 0;
	while (qf != qb){
		hd[i = *qf++] = ad[i];
		for (edge e = ad[i]; e; e = e->nx)
			if (x(e) < u(e) && y[i] + 1 < y[e->to])
				y[*qb++ = e->to] = y[i] + 1;
	}
	return (y[s] < oo);
}

int dfs (int i, int f)
{
	int nf = 0;
	if (i == s) return f;
	for (edge e = hd[i]; e = hd[i]; hd[i] = hd[i]->nx)
		if (x(e) < u(e) && y[e->to] == y[i] + 1
		&& (nf = dfs (e->to, min (f, u(e) - x(e))))){
			x(e) += nf, x(rev(e)) -= nf;
			return nf;
		}
	return 0;
}

int maxflow (){
	int ans = 0, nf;
	while (bfs ())
		while (nf = dfs (r, oo))
			ans += nf;
	return ans;
}

int pair (int i, int j) { return (i < j) ? i*n + j : pair (j, i); }
int stu (int i) { return n*n + i; }

int attempt (int k)
{
	for (edge e = _E; e < es; e++) x(e) = 0;
	for (int i = 0; i < n; i++)
		for (edge e = ad[stu(i)]; e; e = e->nx)
			if (e->to == s) u(e) = k;
	return (m <= maxflow());
}


int main (){
	scanf(" %d%d", &n, &m);
	vs = n*n + n;
	r  = vs++; s = vs++;
	for (int k = 0; k < m; k++){
		int i, j; scanf (" %d%d", &i, &j); --i; --j;
		add (pair (i, j), stu (i));
		add (pair (i, j), stu (j));
		add (r, pair (i, j));
	}
	for (int i = 0; i < n; i++) add (stu (i), s);

	int lo = 1, hi = n;
	while (lo < hi){
		int mid = (lo + hi)/2;
		if (attempt (mid)) hi = mid;
		else               lo = 1 + mid;
	}
	printf ("%d\n", lo);
	attempt (lo);

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++){
			if (ad[pair (i, j)] == NULL) continue;
			fprintf (stderr, "[%d %d]\n", 1 + i, 1 + j);
			for (edge e = ad[pair (i,j)]; e; e = e->nx)
				if (x(e) == 1 && e->to != r){
					fprintf (stderr, "[%d]\n", 1 + e->to - n*n); 
					if (e->to == stu(i))
						printf ("%d %d\n", 1 + i, 1 + j);
					else
						printf ("%d %d\n", 1 + j, 1 + i);
				}
	}
}

