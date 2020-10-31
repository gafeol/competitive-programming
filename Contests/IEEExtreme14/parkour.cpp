#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define pii pair<long long, long long>
#define INF INT_MAX
const int logn = 17;
const int maxn = 112345;
const int mod = 1000000007;
 
struct point {
	int x, y, id;
	point( int x = 0, int y = 0, int id = 0 ) : x( x ), y( y ), id( id ) {};
};
 
struct fenwick {
	int limit, value[ maxn ], id[ maxn ]; inline void init( int items ) {
		limit = items + 10;
		for ( int i = 0; i < limit; i++ ) value[i] = 2000000002, id[i] = -1; 
	}
	inline void upd( int pos, int _value, int _id ) {
		while ( pos < limit ) {
			if ( value[ pos ] > _value ) {
				value[ pos ] = _value;
				id[ pos ] = _id; 
			}
			pos = pos + pos - ( pos & ( pos - 1 ) );
		}
	}
	inline int query( int pos ) {
		int _value = 2000000002, _id = -1;
		while ( pos ) {
			if ( value[ pos ] < _value ) {
				_value = value[ pos ];
				_id = id[ pos ];
			}
			pos = pos & ( pos - 1 );
		}
		return _id;
	}
};
 
int n, x[ maxn ], y[ maxn ], e = 0;
int yy[ maxn ], m;
fenwick fw;
point p[ maxn ];
pair< int, int > edges[ 8 * maxn ], weight_id[ 8 * maxn ];
int pr[ maxn ], f[ logn ][ maxn ], g[ logn ][ maxn ];
int tin[ maxn ], tout[ maxn ], timer = 0;
vector< int > graph[ maxn ]; 
 
inline void add_edge( int a, int b )
{
	edges[ e ] = make_pair( a, b );
	weight_id[ e ] = make_pair( max( x[a] - x[b], x[b] - x[a] ) + max( y[a] - y[b], y[b] - y[a] ), e );
	++e;
}    
 
inline bool cmp_x_y( point a, point b )
{
	return make_pair( a.x - a.y, a.y ) > make_pair( b.x - b.y, b.y );
}
 
inline bool cmp_y( point a, point b )
{
	return a.y > b.y;
}
 
inline int get_pos( int y )
{
	int l = 1, r = m - 1, result = 0;
	while ( l <= r )
	{
		int x = (l + r) / 2;
		if ( yy[x] >= y )
		{
			result = max( result, x );
			l = x + 1;
		} else r = x - 1;
	}
	return result + 1;
}
 
inline void process( point p[] )
{
	sort( p, p + n, cmp_y );
	int _last = (int)2000000002; m = 0;
	for ( int i = 0; i < n; i++ )
	{
		if ( p[i].y == _last ) continue;
		yy[ m++ ] = p[i].y;
		_last = p[i].y;
	}
	fw.init( m );
	sort( p, p + n, cmp_x_y );
	for ( int i = 0; i < n; i++ )
	{
		int pos = get_pos( p[i].y );
		int closest_id = fw.query( pos );
		if ( closest_id != -1 ) add_edge( p[i].id, closest_id );
		fw.upd( pos, p[i].x + p[i].y, p[i].id );
	}
}

inline bool cmp_edges( int a, int b )
{
	return max( x[a] - x[b], x[b] - x[a] ) + max( y[a] - y[b], y[b] - y[a] );
} 
 
inline int get_prev( int v )
{
	if ( pr[v] == v ) return v;
	pr[v] = get_prev( pr[v] );
	return pr[v];
} 
 
void dfs( int v, int prev )
{
	//cout<<v<<" "<<prev<<endl;
	tin[v] = ++timer;
	for ( int i = 0; i < graph[v].size(); i++ )
	{
		int id = graph[v][i];
		int next = v ^ edges[id].first ^ edges[id].second;
		if ( next == prev ) continue;
		f[0][next] = v;
		g[0][next] = max( x[v] - x[next], x[next] - x[v] ) + max( y[v] - y[next], y[next] - y[v] );
		dfs( next, v );
	}
	tout[v] = timer;
}
 
inline int is_parent( int parent, int child ) {
	return ( tin[parent] <= tin[child] && tin[child] <= tout[parent] );
}
 
inline int lca( int a, int b ) {
	if ( is_parent( a, b ) ) return a;
	if ( is_parent( b, a ) ) return b;
	for ( int i = logn - 1; i >= 0; i-- )
		if ( !is_parent( f[i][a], b ) )
			a = f[i][a];
	return f[0][a];
}
 
inline int fun( int a, int b ) {
	if ( a == b ) return 0;
	int result = 0;
	for ( int i = logn - 1; i >= 0; i-- )
		if ( !is_parent( f[i][b], a ) )
		{
			result = max( result, g[i][b] );
			b = f[i][b];
		}
	result = max( result, g[0][b] );
	return result;
}
 
inline int query( int a, int b )
{
	int c = lca( a, b );
	return max( fun( c, a ), fun( c, b ) );
}


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int q,sq,mk;
	cin>>n>>q>>sq>>mk;
	//cout<<n<<" "<<q<<" "<<sq<<" "<<mk<<endl;
	e=0;
	for(int i=0;i<n;i++){
		cin>>x[i]>>y[i];
		pr[i]=i;
	}
	for(int i=0;i<n;i++)p[i]=point(x[i],y[i],i);
	process(p);
	for(int i=0;i<n;i++)p[i]=point(-x[i],y[i],i);
	process(p);
	for(int i=0;i<n;i++)p[i]=point(x[i],-y[i],i);
	process(p);
	for(int i=0;i<n;i++)p[i]=point(-x[i],-y[i],i);
	process(p);
	for(int i=0;i<n;i++)p[i]=point(y[i],x[i],i);
	process(p);
	for(int i=0;i<n;i++)p[i]=point(-y[i],x[i],i);
	process(p);
	for(int i=0;i<n;i++)p[i]=point(y[i],-x[i],i);
	process(p);
	for(int i=0;i<n;i++)p[i]=point(-y[i],-x[i],i);
	process(p);
	sort(weight_id,weight_id+e);
	for(int i=0;i<e;i++){
		int a=edges[weight_id[i].second].first;
		int b=edges[weight_id[i].second].second;
		int pa=get_prev(a);
		int pb=get_prev(b);
		if(pa==pb)continue;
		pr[pa]=pb;
		graph[a].push_back( weight_id[i].second );
		graph[b].push_back( weight_id[i].second );    
	}
	f[0][0] = g[0][0] = 0; timer = 0;
	//cout<<"AAAAA"<<endl;
	dfs(0,-1 );
			//cout<<"AAAAA"<<endl;
	for ( int i = 1; i < logn; i++ ){
		for ( int j = 0; j < n; j++ )
		{
			f[i][j] = f[i - 1][ f[i - 1][j] ];
			g[i][j] = max( g[i - 1][j], g[i - 1][ f[i - 1][j] ] );
		}
	}
	long long as,bs,cs,at,bt,ct,ak,bk,ck;
	cin>>as>>bs>>cs>>at>>bt>>ct>>ak>>bk>>ck;
	pair<pii,int> p1;
	pair<pii,int> p2;
	pair<pii,int> p3;
	long long resp=0;
	long long num=2;
	for(int i=0;i<q;i++){
		if(i<sq){
			p2=p1;
			cin>>p1.f.f>>p1.f.s>>p1.s;
		}
		else{
			p3=p1;
			p1.f.f=1ll+((as*p1.f.f+bs*p2.f.f+cs)%(n));
			p1.f.s=1ll+((at*p1.f.s+bt*p2.f.s+ct)%(n));
			p1.s=(ak*p1.s+bk*p2.s+ck)%(mk);
			p2=p3;
		}
		int s=p1.f.f-1;
		int t=p1.f.s-1;
		int ans=query(s,t);
		ans=max(ans-1,0);
		//cout<<ans<<" "<<ki[i]<<endl;
		if(ans<=p1.s){
			resp+=num;
			resp%=mod;
		}
		num*=2ll;
		num%=mod;
		//cout<<s<<" "<<t<<" "<<query(s,t)<<endl;
	}
	cout<<resp<<endl;

	return 0;
}
























