//all primes upto n

vector<int> sieveOfEratosthenes(int n){
    vector<bool> sieve(n+1,true);
    sieve[0]=sieve[1]=false;
    for(int i=2;i<n;i++){
        for(int j=2*i;j<=n;j+=i){
            if(j%i==0){
                sieve[j]=false;
            }
        }
    }
    vector<int> ans;
    for(int i=2;i<=n;i++){
        if(sieve[i]){
            ans.push_back(i);
        }
    }
    return ans;
}
