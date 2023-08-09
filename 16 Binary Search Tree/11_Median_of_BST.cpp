void inorder(struct Node *root,vector<float>& nums){
    if(root==NULL){
        return;
    }
    inorder(root->left,nums);
    nums.push_back(float(root->data));
    inorder(root->right,nums);
}
float findMedian(struct Node *root)
{
      //Code here
      vector<float> nums;
      inorder(root,nums);
      float ans;
      int n = nums.size();
      if(nums.size()%2==0){
          int index=n/2;
          ans = (nums[index] + nums[index-1])/2;
      }
      else{
          int index=(n/2);
          ans = nums[index];
      } 
      return ans;
}