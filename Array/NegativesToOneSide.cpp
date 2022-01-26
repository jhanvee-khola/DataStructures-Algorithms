//Use of extra space is not allowed
void negativesSide(int *a,int n){
  int i=0,j=0;
  while(i<n){
    if(a[i]<0){
      if (i != j){
        swap(arr[i], arr[j]);
      }
      j++;
    }
    i++;
  }
}

//Two-Pointer
void negativesSide(int *a,int n){
  int left=0,right=n-1;
  while (left<=right){
    if(a[left]<0 && a[right]<0){
      left++;
    }
    else if (a[left]>0 && a[right]<0){
      int temp=a[left];
      a[left]=a[right];
      a[right]=temp;
      left++;
      right--;
    }
    else if (arr[left]>0 && arr[right] >0){
      right--;
    }
    else{
      left++;
      right--;
    }
  }
}

//If order is to be maintained i.e Relative Order has to be preserved








