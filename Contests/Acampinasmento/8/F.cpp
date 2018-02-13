#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int MAXN = 1123456;

char s[MAXN];

vector<char> b, e;

stack<char> q;

int clos(char c){
	return (c == ')' || c == ']' || c == '}');
}

char inv(char c){
	if(c == ')')
		return '(';
	if(c == ']')
		return '[';
	if(c == '}')
		return '{';
	if(c == '(')
		return ')';
	if(c == '[')
		return ']';
	if(c == '{')
		return '}';
}

int ok = 1;

void put(char c){
	if(!clos(c)){
		q.push(c);
		return;
	}
	if(q.empty())
		b.pb(inv(c));
	else{
		if(q.top() == inv(c))
			q.pop();
		else
			ok = 0;
	}
}

int main(){
	scanf(" %s", s);
	int n = strlen(s);
	for(int a=0;a<n;a++){
		put(s[a]);
	}
	if(!ok){
		puts("NIE");
		return 0;
	}
	while(!q.empty()){
		e.pb(inv(q.top()));
		q.pop();
	}
	for(int a=b.size()-1;a>=0;a--)
		printf("%c", b[a]);
	printf("%s", s);
	for(int a=0;a<e.size();a++)
		printf("%c", e[a]);
	puts("");
}

