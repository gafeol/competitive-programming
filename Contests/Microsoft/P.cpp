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

const int MAXN = 212345;

int n, m, k;
char s[MAXN];

int ap;

vector<vector<char> > out;

vector<char> rd;

char c;

void trim(){
	while(!rd.empty() && (rd.back() == ' ' || rd.back() == '\t'))
		rd.pop_back();
}

int lines = 0, nodes = 0, emp, nemp;

void rc(){
	while(scanf("%c", &c) != EOF && (c == ' ' || c == '\t'));
	assert(c == '\n');
	rd.clear();
	nodes++;
	while(1){
		int bg = 0;
		while(scanf("%c", &c)!= EOF){
			if(c == '\n'){
				trim();
				lines++;
				if(rd.empty()){
					emp++;
				}
				if(!rd.empty() || !ap){
					if(rd.empty()){
						nemp++;
					}
					out.pb(rd);
				}
				rd.clear();
				bg = 0;
			}
			else{
				if(c == ']'){
					rd.clear();
					return;
				}
				if(c == ' ' || c== '\t')
					if(!bg) continue;
				bg = 1;
				rd.pb(c);	
			}
		}
	}
}

int main (){
	int val = 0;
	int t = 0;
	while(scanf("%c", &c) != EOF && c != '\n'){
		if(c == ':'){
			t = 1;
			n = val;
			continue;
		}
		if(!t){
			val *= 10;
			val += (c-'0');
		}
		else{
			if(c == 'T')
				ap = 1;
			else if(c == 'F')
				ap = 0;
		}

	}
	char p;
	scanf(" %c%c", &c, &p);
	assert(c == '[');
	assert(p == '\n');
	while(1){
		while(scanf(" %c", &c) != EOF && (c == ' ' || c == '\n' || c == '\t'));
		if(c == ']') break;
		else{
			assert(c == '[');
			rc();
		}
		lines = 0;
	}
	int nno = ((out.size()+n-1)/n);
	printf("%d\n", nno);
	int ndif = nno-nodes;
	printf("%d\n", ndif);
	nemp += nno*n - out.size();
	int empdif = nemp - emp;
	printf("%d\n", empdif);
	printf("%d\n", nemp);

	printf("[\n");
	for(int i=0;i<((out.size()+n-1)/n);i++){
		puts("[");
		for(int a=i*n;a<(i+1)*n;a++){
			if(a < out.size()){
				int bg = 0;
				for(int d=0;d<out[a].size();d++){
					c = out[a][d];
					if(c == ' ' || c== '\t')
						if(!bg) continue;
					assert(c != '\n');	
					printf("%c", c);
					bg = 1;
				}
			}
			puts("");
		}
		puts("]");
	}
	printf("]\n");
	puts("");
}

