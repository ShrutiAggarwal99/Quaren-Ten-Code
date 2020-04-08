// Link to problem : https://www.linkedin.com/posts/women-who-code-delhi_hi-everyone-here-is-the-question-for-day-activity-6653185173842161664-BtX0

int bonusPoints(vector<int> rankings){
	int n = rankings.size();
	vector<int> fromLeft(n,1);
	vector<int> fromRight(n,1);
 
	for(int i=1;i<n;i++){
		if(rankings[i]>rankings[i-1])
			fromLeft[i] = fromLeft[i-1]+1;
	}
 
	int ans = 0;
	for(int i=n-2;i>=0;i--){
		if(rankings[i]>rankings[i+1])
			fromRight[i] = fromRight[i+1]+1;
		ans += max(fromLeft[i],fromRight[i]);
	}
	ans += max(fromLeft[n-1],fromRight[n-1]);
	return ans;
}
