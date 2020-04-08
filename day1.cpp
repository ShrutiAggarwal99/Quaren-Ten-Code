// Link to problem : https://www.linkedin.com/posts/women-who-code-delhi_hi-everyone-here-is-the-question-for-day-activity-6652452326193881088-Wl7Z

int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size(), minDiff = INT_MAX, ans = 0;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++){
            int st = i+1, en = n-1;
            while(st<en){
                int curSum = nums[i] + nums[st] +nums[en];
                int curDiff = abs(curSum-target);
                if(minDiff > curDiff){
                    minDiff = curDiff;
                    ans = curSum;
                }
                if(curSum<target) st++;
                else if(curSum>target) en--;
                else return target;
            }
        }
        return ans;
    }
