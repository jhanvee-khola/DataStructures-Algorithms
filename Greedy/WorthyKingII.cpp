#define ll long long int

ll worthy(int n,vector<ll> nTroops){
  sort(nTroops.begin(),nTroops.end());
  ll total=nTroops[0];
  ll x=2;
  for(int i=1;i<n;i++){
    total+=nTroops[i]/x;
    if(nTroops[i]%x){
      total++;
    }
    x++;
  }
  return total;
}
