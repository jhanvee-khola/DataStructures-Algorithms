bool isMonotonic(vector<int>& nums) {
    bool b1=true,b2=true;
    for(int i=0;i<nums.size()-1;i++){
        if(nums[i]<=nums[i+1]){
            continue;
        }
        else{
            b1=false;
            break;
        }
    }
    for(int i=0;i<nums.size()-1;i++){
        if(nums[i]>=nums[i+1]){
            continue;
        }
        else{
            b2=false;
            break;
        }
    }
    return (b1 || b2);
}
