#include<bits/stdc++.h>
#define y1 uaessueh
using namespace std;

const int N = 200005;

int n, q, g;
int x1[N], y1[N], x2[N], y2[N], c[4*N], tree[4*N], lazy[4*N], p[N];

struct event {
	int x, y1, y2, id;
	bool open;
	event() {}
	event(int id, int x, int y1, int y2, bool open) : id(id), x(x), y1(y1), y2(y2), open(open) {}
	bool operator<(const event &o) {
		return x < o.x;	
	}
} ev[2*N];

void build(int k = 1, int l = 0, int r = g-1) {
	lazy[k] = -2;
	tree[k] = -1;
	if(l == r) return;
	int m = (l + r) / 2;
	build(2*k, l, m);
	build(2*k+1, m+1, r);
} 

void unlazy(int k, bool leaf) {
	if(lazy[k] == -2) return;
	if(leaf) {
		tree[k] = lazy[k];
		lazy[k] = -2;
		return;
	}
	lazy[2*k] = lazy[k];
	lazy[2*k+1] = lazy[k];
	lazy[k] = -2;
}

int query(int id, int k = 1, int l = 0, int r = g-1) {
	unlazy(k, l == r);
	if(l == r) return tree[k];
	int m = (l + r) / 2;
	if(id <= m) return query(id, 2*k, l, m);
	return query(id, 2*k+1, m+1, r);
}

void update(int fl, int fr, int val, int k = 1, int l = 0, int r = g-1) {
	unlazy(k, l == r);
	if(l > fr || r < fl) return;
	if(l >= fl && r <= fr) {
		lazy[k] = val;
		unlazy(k, l == r);
		return;
	}	
	int m = (l + r) / 2;
	update(fl, fr, val, 2*k, l, m);
	update(fl, fr, val, 2*k+1, m+1, r);
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
		c[q++] = x1[i];
		c[q++] = y1[i];
		c[q++] = x2[i];
		c[q++] = y2[i];
		p[i] = -1;
	}
	sort(c, c+q);
	g = unique(c, c+q) - c;
	for(int i = 0; i < n; i++) {
		x1[i] = lower_bound(c, c+g, x1[i]) - c;
		y1[i] = lower_bound(c, c+g, y1[i]) - c;
		x2[i] = lower_bound(c, c+g, x2[i]) - c;
		y2[i] = lower_bound(c, c+g, y2[i]) - c;
		ev[2*i] = event(i, x1[i], y1[i], y2[i], true);
		ev[2*i+1] = event(i, x2[i], y1[i], y2[i], false);
	}
	sort(ev, ev+2*n);
	build();
	for(int i = 0; i < 2*n; i++) {
		int l = ev[i].y1;
		int r = ev[i].y2;
		int id = ev[i].id;
		bool open = ev[i].open;
		if(open) { 
			p[id] = query(l);
			update(l, r, id);
		} else { 
			update(l, r, p[id]); 
		}
	}
	for(int i = 0; i < n; i++) printf("%d\n", p[i]);
}
