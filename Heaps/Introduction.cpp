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
//Method 1
void createHeap(int a[],int n){
  //creating a max heap
  for(int i=0;i<n;i++){
    int l=2*i,r=l+1;
    if(a[l]>a[i]){
      
    }
    if(a[r]>a[i]){
    
    }
  }
}

//Method 2
void createHeap(int a[],int n){
  
}






