#include<iostream>
#include<math.h>
using namespace std;
int main(){
	bool ch = false;
	int n;
	cin>>n;
	int st[n][5];
	for(int i=0;i<n;i++){
		cin>>st[i][0]>>st[i][1]>>st[i][2];
		st[i][3] = 0;
		st[i][4] = 0;
		st[i][0] = st[i][0]/(st[i][1]*st[i][2]);
	}
	float P;
	cin>>P;
	float w = P*1000;
	float max = 0.0;
	int in = 0;
	for(int i=0;i<n;i++){
		if(w<=0){
			break;
		}
		for(int j=0;j<n;j++){
			if(st[j][0] > max && st[j][0] != -1){
				max = st[j][0];
				in = j;
			}
		}
		st[in][0] = -1;
		max = 0;
		float y = w/(st[in][2]);
		if(y>=st[in][0] && w-(st[in][1]*st[in][2])>=0){
			y = st[in][1];
			st[in][3] = y;
			st[in][4] = 0;
			w = w - (st[in][1]*st[in][2]);
		}else{
			int t = y;
			st[in][3] = t;
			float u = ((y-t)*st[in][2]);
			if(u>0 && u<1){
				u = ceil((y-t)*st[in][2]);
				st[in][4] = u;
			}else{
				st[in][4] = u;
			}
			w -= (t*st[in][2])+(st[in][2]*st[in][4]);
		}
	}
	for(int i=0;i<n;i++){
		cout<<st[i][3]<<" "<<st[i][4]<<endl;
	}
	return 0;
}//2 10000 200 5 5000 100 10 1.255
//3 10000 200 5 5000 100 10 7000 100 7 1.951
//3 10000 200 5 10000 100 10 7000 100 7 1.951
