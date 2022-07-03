
//-----------------------------------------------------------
#define ll long long int

ll worthy(int n,vector<ll> nTroops){
  sort(nTroops.begin(),nTroops.end());
  vector<bool> attack(n,false);
  int total=0;
  for(int i=1;i<=n;i++){
    bool b=false;
    for(int j=0;j<n;j++){
      if(!attack[j] && nTroops[j]%i==0){
        total+=nTroops[j]/i;
        b=true;
        attack[j]=true;
        break;
      }
    }
    if(!b){
      for(int j=0;j<n;j++){
        if(!attack[j]){
          total+=nTroops[j]/i+1;
          attack[j]=true;
          break;
        }
      }
    }
  }
  return total;
}

//---------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------

