const int N = ; typedef int num;
num X[N]; int en = 1, Y[N], sz[N], L[N], R[N];
void calc (int u) { // update node given children info
	sz[u] = sz[L[u]] + 1 + sz[R[u]];
	// code here, no recursion
    // Talvez precise chamar unlaze de u e dos filhos, pra garantir que voce vai conseguir calcular os parametros que quer com os filhos atualizados
}
void unlaze (int u) {
	if(!u) return;
}
void split_val(int u, num x, int &l, int &r) { // l gets <= x, r gets > x
	unlaze(u); if(!u) return (void) (l = r = 0);
	if(X[u] <= x) { split_val(R[u], x, l, r); R[u] = l; l = u; }
	else { split_val(L[u], x, l, r); L[u] = r; r = u; }
	calc(u);
}
void split_sz(int u, int S, int &l, int &r) { // l gets first s, r gets remaining
	unlaze(u); if(!u) return (void) (l = r = 0);
	if(sz[L[u]] < S) { split_sz(R[u], S - sz[L[u]] - 1, l, r); R[u] = l; l = u; }
	else { split_sz(L[u], S, l, r); L[u] = r; r = u; }
	calc(u);
}
int merge(int l, int r) { // els on l <= els on r
	unlaze(l); unlaze(r); if(!l || !r) return l + r; int u;
	if(Y[l] > Y[r]) { R[l] = merge(R[l], r); u = l; }
	else { L[r] = merge(l, L[r]); u = r; }
	calc(u); return u;
}
void init(int n=N-1) { // call before using other funcs
	for(int i = en = 1; i <= n; i++) { Y[i] = i; sz[i] = 1; L[i] = R[i] = 0; }
	random_shuffle(Y + 1, Y + n + 1);
}
