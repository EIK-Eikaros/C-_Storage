#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<int> v,r;
	int n,k;
	cin>>n>>k;
	int a[1001];
	int b[n][1001];
	for(int i=0;i<1001;i++)
		a[i] = 0;
	int ra,rb;
	for(int i=0;i<n;i++){
		cin>>ra;
		for(int j=0;j<ra;j++){
			cin>>rb;
			b[i][rb] = 1;
			a[rb]++;
		}
	}
	for(int i=2;i<1001;i++){
		if(a[i]>=k && a[i]!=0){
			v.push_back(i);
		}
	}
	for(int i=0;i<n;i++){
		int g =0;
		for(int j=0;j<v.size();j++){
			if(b[i][v[j]] == 1){
				g++;
			}
		}
		r.push_back(g);
	}
	cout<<v.size()<<endl;
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}cout<<endl;
	for(int i=0;i<r.size();i++){
		cout<<r[i]<<" ";
	}
}//5 3 5 12 387 15 162 5 6 14 162 92 387 7 748 4 14 5 12 387 6 17 952 12 92 398 849 5 14 5 92 12 387

