#include <bits/stdc++.h>
using namespace std;

#define fst first
#define snd second

typedef pair<int, int> pii;

typedef long long ll;

const int MAXN = 1000002, INF = 1e9+1;

int n, m;

set<pii> pe, ep;

map<string, int> pos;
map<string, int> len;

char s[MAXN];

int add(int t){
	if(ep.lower_bound(pii(t, -1)) == ep.end())
		return INF;
	pii esp = *ep.lower_bound(pii(t, -1));
	if(esp.fst > t){
		int tt = esp.fst - t;
		int ii = esp.snd + t;
		ep.insert(pii(tt, ii)); 
		pe.insert(pii(ii, tt));
	}
	int i = esp.snd;
	int tv = esp.fst;
	ep.erase(pii(tv, i));
	pe.erase(pii(i, tv));
	return i;
}

void rmv(int i, int tam){
	int dep, ant;
	dep = ant = 0;
	pii aft, bef;
	if(pe.upper_bound(pii(i, tam)) != pe.end()){
		dep = 1;
		aft = *pe.upper_bound(pii(i, tam));
	}
	if(pe.upper_bound(pii(i, tam)) != pe.begin()){
		ant = 1;
		bef = *(--pe.upper_bound(pii(i, tam)));
	}
	if(ant && bef.fst + bef.snd == i){
		i = bef.fst;
		tam += bef.snd;
		pe.erase(bef);
		ep.erase(pii(bef.snd, bef.fst));
	}
	if(dep && aft.fst == i + tam){
		tam += aft.snd;
		pe.erase(aft);
		ep.erase(pii(aft.snd, aft.fst));
	}
	pe.insert(pii(i, tam));
	ep.insert(pii(tam, i));
}

int main(){
	scanf("%d%d", &n, &m);
	pe.insert(pii(0, n));
	ep.insert(pii(n, 0));
	char t;
	for(int a=0;a<m;a++){
		scanf(" %c %s", &t, s);
		if(t == 'P'){
			int tam;
			scanf("%d", &tam);
			len[s] = tam;
			pos[s] = add(tam);
			if(pos[s] != INF)
				printf("%d\n", pos[s]);
			else
				puts("NIE");
		}
		else{
			if(pos[s] == INF)
				puts("BRAK");
			else{
				puts("OK");
				rmv(pos[s], len[s]);
			}
		}
	}
}
