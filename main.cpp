#include<bits/stdc++.h>
using namespace std;

class sgtree{
public:
	vector<int> seg;
	sgtree(int n){
		seg.resize(4*n+1);
	}
	void build(int ind,int lo,int hi,vector<int>&arr){
		if(lo==hi){
			seg[ind]=arr[lo];
			return;
		}
		int mid=(lo+hi)/2;
		build(2*ind+1,lo,mid,arr);
		build(2*ind+2,mid+1,hi,arr);
		seg[ind]=seg[2*ind+1]+seg[2*ind+2];
	}
	void update(int segind,int val,int ind,int lo,int hi){
		if(lo==hi){
			seg[segind]=val;
			return;
		}
		int mid=(lo+hi)/2;
		if(ind <= mid){
			update(2*segind+1,val,ind,lo,mid);
		}
		else update(2*segind+2,val,ind,mid+1,hi);
		seg[segind]=seg[2*segind+1]+seg[2*segind+2];
	}

	int getSum(int ind,int left,int right,int lo,int hi){
		// cout<<"HI"<<endl;
		if(left>hi || right<lo) return 0;
		// cout<<"hi"<<endl;
		int mid=(lo+hi)/2;
		if(lo==hi) return seg[ind];
		// if(left>=lo &&/ right<=hi) return seg[ind];
		if(hi<=mid) return getSum(2*ind+1,left,right,lo,mid);
		if(lo>=mid+1) return getSum(2*ind+2,left,right,mid+1,hi);
		// cout<<"hi"<<endl;
		return getSum(2*ind+1,left,right,lo,mid)+
		getSum(2*ind+2,left,right,mid+1,hi);
	}
};

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(auto &it : arr) cin>>it;
	sgtree sg(n);
	sg.build(0,0,n-1,arr);
	int q;
	cin>>q;
	// cout<<sg.seg[0]<<endl;
	while(q--){
		
	}
	return 0;
}

