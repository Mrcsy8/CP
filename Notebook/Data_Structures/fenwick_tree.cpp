struct FT{
	ll ft[N+1]; // for more dimensions, make ft multi-dimensional
	void upd(int i0, ll v){ // add v to i0th element (0-based)
		// add extra fors for more dimensions
		for(int i=i0+1;i<=N;i+=i&-i)ft[i]+=v;
	}
	ll get(int i0){ // get sum of range [0,i0)
		ll r=0;
		// add extra fors for more dimensions
		for(int i=i0;i;i-=i&-i)r+=ft[i];
		return r;
	}
	ll get_sum(int i0, int i1){ // get sum of range [i0,i1) (0-based)
		return get(i1)-get(i0);
	}
};
