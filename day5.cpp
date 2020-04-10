// Link to problem - https://www.linkedin.com/posts/women-who-code-delhi_hi-everyone-here-is-the-question-for-day-activity-6653901869225738240-Jgff

void recursivelySolve(vector<int> &orig,int st,int en,vector<int> &ans){
      if(st == en){
          return;
      }

      int n = en-st+1;
      int lSt = st, lEn = st+(n-1)/2, rSt = lEn+1, rEn = en;
      vector<int> nums(orig.begin(),orig.end()); // very important to make another copy here! 
      recursivelySolve(nums,lSt,lEn,ans);
      recursivelySolve(nums,rSt,rEn,ans);

      sort(nums.begin()+rSt, nums.begin()+rEn+1); // can be done using pointers too instead of sorting
      for(int i=lSt;i<=lEn;i++)
          ans[i] += lower_bound(nums.begin()+rSt, nums.begin()+rEn+1, nums[i]) - (nums.begin()+rSt);

  }

  vector<int> countSmaller(vector<int>& nums) {
      // Approach 1 - O(n^2)
      // Approach 2 - Divide and Conquer (better)
      int n = nums.size();
      if(n == 0) return vector<int>();
      vector<int> ans(n,0);
      recursivelySolve(nums,0,n-1,ans);
      return ans;
  }
