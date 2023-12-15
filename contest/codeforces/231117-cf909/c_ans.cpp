#include<iostream>
#include<vector>
using namespace std;
 
void solve(){
	int n;
	cin>>n;
	vector<int>A(n);
	for(auto &x:A)cin>>x;
	int sum=A[0];
	int ans=A[0];
	for(int i=1;i<n;++i){
		if(sum<0||(A[i]+A[i-1])%2==0)sum=0;
		sum+=A[i];
		ans=max(ans,sum);
	}
	cout<<ans<<"\n";
}
int main(){
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
	cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	cin>>T;
	while(T--)solve();
}