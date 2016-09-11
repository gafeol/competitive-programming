#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
struct pt{
	int d, f;
	pt(int dd, int ff){
		d = dd; f = ff;
	}
	pt(){}
};
struct nst{
	int i, j, k;
	nst(int ii, int jj, int kk){
		i = ii; j = jj; k = kk;
	}
	nst(){}
};
bool comp(nst a1, nst a2){
	return a1.k<a2.k;
}

int n, m, b, e, c, tp=0, cont=0;
nst v[5020];
int pai[102], h[102]; pt y[5020];

int raiz(int x){
	if(pai[x]==x) return x;
	else return pai[x]=raiz(pai[x]);
}
void join(int v1, int v2){
	v1 = raiz(v1); v2 = raiz(v2);
	if(h[v1]>h[v2]){
		pai[v2]=v1;
	}else{
		if(h[v2]>h[v1]){
			pai[v1]=v2;
		}else{
			pai[v1]=v2;
			h[v1]++;
		}
	}
}

int main(){
	int var=0;
	do{
		if(var) cout<<endl;
		var = 1;
		scanf("%d %d", &n, &m); if(n+m==0)break;
		for(int a=0; a<m; a++){
			scanf("%d %d %d", &b, &e, &c);
			v[a]=nst(b,e,c);
			h[b]=1; h[e]=1;
			pai[b]=b; pai[e]=e;
		}
		sort(v, v+m, comp);
		for(int a=0; a<m; a++){
			int uu = raiz(v[a].i); int vv = raiz(v[a].j);
			if(uu!=vv){
				join(v[a].i,v[a].j);
				y[tp] = pt(min(v[a].i, v[a].j), max(v[a].i, v[a].j)); tp++;	
			}
		}
		cont++; printf("Teste %d\n", cont);
		for(int a=0; a<tp; a++){
			printf("%d %d\n", y[a].d, y[a].f);
		}
		tp=0;
	}while(n+m!=0);
}
