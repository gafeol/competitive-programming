struct seg{
	int x[2], y[2];
	int ind;

	seg(){}

	seg(int x1, int y1, int xx, int yy, int i){
		if(x1 > xx){
			swap(x1, xx);
			swap(y1, yy);
		}
		x[0] = x1;
		x[1] = xx;
		y[0] = y1;
		y[1] = yy;
		ind = i;
	}
} s[MAXN];

struct cmp{
	bool operator() (const int& ui, const int& oi) {
		if(ui == -1) return true;
		if(oi == -1) return false;
		seg u = s[ui];
		seg o = s[oi];
		double yy;
		for(int a=0;a<2;a++){
			if(u.x[a] >= o.x[0] && o.x[1] >= u.x[a]){
				yy = (double)((o.y[1] - o.y[0])/((double)(o.x[1] - o.x[0])))*(double)(u.x[a] - o.x[0]); 
				yy = o.y[0] + yy; 
				return ((double)u.y[a] < yy); 
			}
		}

		for(int a=0;a<2;a++){
			if(o.x[a] >= u.x[0] && u.x[1] >= o.x[a]){
				yy = (double)((u.y[1] - u.y[0])/((double)(u.x[1] - u.x[0])))*(double)(o.x[a] - u.x[0]); 
				yy = u.y[0] + yy;
				return (yy < (double)o.y[a]); 
			}
		}
		debug("	return false\n");
		return (u.ind < o.ind);
	}
};

multiset<int, cmp> q;

