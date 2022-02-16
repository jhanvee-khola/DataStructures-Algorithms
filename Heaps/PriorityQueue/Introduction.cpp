#include<iostream>
#include<queue>
#include<string>
using namespace std;

class Person{
  public:
    int age;
    string name;

    Person(int a,string n){
      age=a;
      name=n;
    }
};

class ComparePerson{
  public:
  //comparator to allot priority to elements
    bool operator()(Person a,Person b){
      return a.age<b.age;
    }
};

int main(){
  int n;
  cin>>n;
  //stl implementation 
  priority_queue<int> pq; //based on max-heap
  priority_queue<int,vector<int>,greater<int>> mpq; //based on min-heap
  //push
  for(int i=0;i<n;i++){
    int m;
    cin>>m;
    pq.push(m);//O(logn) time
  }
  
  //pop
  while(!pq.empty()){
    cout<<pq.top();
    pq.pop();
  }
  
  //customised prority queue using functors
  prority_queue<Person,vector<Person>,PersonCompare> p;
  for(int i=0;i<n;i++){
    string n;
    int a;
    cin>>n>>a;
    Person t(a,n);
    p.push(t);
  }
  
  //getting top k priority elements
  int k;
  cin>>k;
  for(int i=0;i<k;i++){
    Person t=p.top();
    cout<<t.name<<" "<<t.age<<endl;
    p.pop();
  }
  return 0;
}

















