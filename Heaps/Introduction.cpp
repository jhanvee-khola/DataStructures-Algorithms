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

//Create a heap from an array(in place)
//Method 1 - O(nlogn) time
void createHeap(vector<int> a){
  //creating a max heap
  for(int i=2;i<a.size();i++){
    int idx=i,parent=i/2;
    while(idx>1 && a[idx]>a[parent]){
      swap(a[idx],a[parent]);
      idx=parent;
      parent/=2;
    }
  }
}

//Method 2 - O(n) time
void createHeap(vector<int> a){
  for(int i=a.size()-1/2;i>=1;i--){
    heapify(a,i);
    //similar heapify function with vector passed as arguement
  }
}
