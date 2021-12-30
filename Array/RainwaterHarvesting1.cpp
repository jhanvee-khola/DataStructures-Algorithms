//Method-1
int maxWater(int arr[],int n){
// To store the maximum water that can be stored 
int res=0; 
// For every element of the array 
for (int i=1;i<n-1;i++) { 
    // Find the maximum element on its left 
    int left=arr[i]; 
    for (int j=0;j<i;j++) 
       left=max(left, arr[j]); 
    // Find the maximum element on its right    
    int right=arr[i]; 
    for (int j=i+1; j<n; j++) 
       right=max(right,arr[j]);  
    // Update the maximum water     
   res=res+(min(left,right)-arr[i]);    
} 
return res;  
}

//Method-2 -> O(n) time
//Pre-processing to find the maximum on the left and right for each element of the array beforehand 
int main(){
    int a[1000000], l[1000000], r[1000000];
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    l[0]=a[0];
    r[n-1]=a[n-1];
    int leftmax=0,rightmax=0;
    for (int i=1;i<n;i++){
        l[i]=max(l[i-1],a[i]);
    }
    for (int i=n-2;i>=0;i--){
        r[i]=max(r[i+1],a[i]);
    }
    int water=0;
    for (int i=0;i<n;i++){
        water+=(min(l[i],r[i])-a[i]);
    }
    cout << water;
}
    
//Method-3 ->Two-Pointer Approach
int maxWater_optimized(int arr[], int n){
    int water=0; // To store the final ans

    int left_max=0;  // Which stores the current max height of the left side
    int right_max=0; // Which stores the current max height of the right side

    int lo=0;     // Counter to traverse from the left_side
    int hi=n-1; // Counter to traverse from the right_side
    while (lo<=hi){
        if(arr[lo]<arr[hi]){
            if(arr[lo]>left_max){
                left_max=arr[lo]; // Updating left_max
            }
            else{
                water+=left_max-arr[lo]; // Calculating the ans
            }
            lo++;
        }
        else{
            if(arr[hi]>right_max){
                right_max=arr[hi]; // Updating right_max
            }
            else{
                water+=right_max-arr[hi]; // Calculating the ans
            }
            hi--;
        }
    }
    return water;
}
