class Heap{
  vector<int> v;
  bool minH;//to determine type of heap i.e. min-heap or max-heap
  bool compare(int a,int b){
    if(minH){
      return a<b;
    }
    return a>b;
  }
  void heapify(int i){
    int leftC=2*i,rightC=leftC+1,minI=i;
    if(leftC<v.size() && compare(v[leftC],v[i])){
      minI=leftC;
    }
    if(leftC<v.size() && compare(v[rightC],v[minI])){
      minI=rightC;
    }
    if(minI!=i){
      swap(v[i],v[minI]);
      heapify(minI);
    }
  }
  public:
    Heap(int s=10,bool type=true){
      v.reserve(s);
      v.push_back(-1);
      minH=type;
    }
    
    void push(int d){
      v.push_back(d);
      int id=v.size()-1,parent=id/2;
      while(id>1 && compare(v[id],v[parent])){
        swap(v[id],v[parent]);
        id=parent;
        parent/=2;
      }
    }
    int top(){
      return v[1];
    }
    int pop(){
      swap(v[1],v[v.size()-1]);
      int ans=v[v.size()-1];
      v.pop_back();
      heapify(1);
    }
    bool empty(){
      return v.size()==1;
    }
};

void createHeap(vector<int> a){
  for(int i=a.size()-1/2;i>=1;i--){
    heapify(a,i);
    //similar heapify function with vector passed as arguement
  }
}

void heapify1(vector<int> v,int i,int n){
  int leftC=2*i,rightC=leftC+1,minI=i;
  if(leftC<n && compare(v[leftC],v[i])){
    minI=leftC;
  }
  if(leftC<n && compare(v[rightC],v[minI])){
    minI=rightC;
  }
  if(minI!=i){
    swap(v[i],v[minI]);
    heapify1(minI);
  }
}

//in place heap sort
void heapSort(vector<int> a){
  createHeap(a);
  int n=a.size();
  while(n>1){
    swap(a[1],a[n-1]);
    n--;
    heapify1(a,1,n);
  }
}
