//Find N distinct numbers whose Bitwise XOR is equal to K
#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,x;
	    cin>>n>>x;
	    if(n==1){
	        cout<<x<<endl;
	        continue;
	    }
	    else if(n==2){
	        cout<<x<<" "<<0<<endl;
	        continue;
	    }
	    else{
	        int temp=0,p=n-1,q=n-2;
	        for(int i=1;i<=n-3;i++){
	            cout<<i<<" ";
	            temp=temp^i;
	        }
	        if(temp==x){
	            int c=p^q;
	            cout<<p<<" "<<q<<" "<<c;
	        }
	        else{
	            int c=temp^x^p;
	            cout<<0<<" "<<p<<" "<<c;
	        }
	        cout<<endl;
	    }
	}
	return 0;
}
