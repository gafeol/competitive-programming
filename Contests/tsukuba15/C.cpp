#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
const int N = 53;

int n, m, oo, T;

void dump (int A[N][N])
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			printf ("%d%c", A[i][j], " \n"[j + 1 == n]);
}

void multBy (int A[N][N], int B[N][N])
{
	static int ans[N][N];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ans[i][j] = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int m = 0; m < n; m++)
				ans[i][j] |= (A[i][m] && B[m][j]);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			A[i][j] = ans[i][j];
}

void fexp (int A[N][N], int k)
{
	static int loc[N][N];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			loc[i][j] = (i == j);
	
	for (; k; k >>= 1, multBy (A, A))
		if (k&1)
			multBy (loc, A);
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			A[i][j] = loc[i][j];
}

int c[3];
int r[3][N][N], aux[N][N], A[N][N];
int S[N * 100 + 7][N];
int s(int t, int i)
{
	if (i == n-1) return 0;
	S[t][i] = 0;
	for (int k = 0; k < 3; k++){
		int loc = oo;
		for (int j = 0; j < n; j++)
			if (r[k][i][j] && t + c[k] < T)
				loc = min (loc, 1 + S[t + c[k]][j]);
		S[t][i] = max (S[t][i], loc);
	}
	return S[t][i];
}

int main (){
	while (scanf (" %d%d%d%d%d", &n, &m, c, c + 1, c + 2) != EOF)
	{
		sort (c, c + 3);
		oo = 10*n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				A[i][j] = 0;

		while (m--){
			int i, j; scanf (" %d%d", &i, &j);
			A[--i][--j] |= 1;
		}
		for (int k = 0; k < 3; k++){
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					aux[i][j] = A[i][j];
			fexp (aux, c[k]);
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					r[k][i][j] = aux[i][j];

		}

		T = n * c[2] + 1;
		for (int t = T - 1; t + 1; t--)
			for (int i = 0; i < n; i++)
				S[t][i] = s(t,i);

		if (S[0][0] == oo) printf ("IMPOSSIBLE\n");
		else printf ("%d\n", S[0][0]);
	}
}
