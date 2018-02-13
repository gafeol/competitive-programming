#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define GNU __gnu_pbds

using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;
namespace GNU { typedef tree<pii, null_type, less<pii>, rb_tree_tag,
	tree_order_statistics_node_update> ordered_set; }

using GNU::ordered_set;

ordered_set q;

const int MAXN = 112345;

int n;

char s[30];
char c[40];

char code[MAXN][40];

map<string, int> ind;

ll r[MAXN];

int deg;

void put(int u){
//	printf("put %d %d\n", u, r[u]);
//	printf("add q size %d\n", (int)q.size());
	q.insert(pii(-r[u], u));
//	printf("add q size %d\n", (int)q.size());
}

void rmv(int u){
//	printf("rmv %d %d\n", u, r[u]);
//	printf("rmv q size %d\n", (int)q.size());
	q.erase(pii(-r[u], u));
//	printf("rmv q size %d\n", (int)q.size());
}

int main(){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf(" %s", s);
		if(strcmp(s, "ISSUE") == 0){
			scanf(" %s", c);
			if(ind.find(c) == ind.end()){
				ind[c] = deg;
				strcpy(code[deg], c);
				assert(strcmp(code[deg], c) == 0);
				r[deg] = 0;
				put(deg);
				printf("CREATED %d 0\n", deg++);
			}
			else{
				int id = ind[c];
				printf("EXISTS %d %lld\n", id, r[id]); 
			}
		}
		else if(strcmp(s, "DELETE") == 0){
			scanf(" %s", c);
			if(ind.find(c) == ind.end()){
				printf("BAD REQUEST\n"); 
			}
			else{
				int id = ind[c];
				printf("OK %d %lld\n", id, r[id]);
				rmv(id);
				ind.erase(c);
			}
		}
		else if(strcmp(s, "RELIABILITY") == 0){
			ll x;
			scanf(" %s %lld", c, &x);
			if(ind.find(c) == ind.end()){
				printf("BAD REQUEST\n"); 
			}
			else{
				int id = ind[c];
				rmv(id);
				r[id] += x;
				put(id);
				printf("OK %d %lld\n", id, r[id]);
			}
		}
		else{
			int k;
			scanf("%d", &k);
			if(q.empty()){
				puts("EMPTY");
			}
			else{
				if(q.size() <= k)
					k = q.size()-1;
				pii u = (pii)*q.find_by_order(k);
				int id = u.second;
				printf("OK %s %d %lld\n", code[id], id, r[id]); 
			}
		}
	}
}
