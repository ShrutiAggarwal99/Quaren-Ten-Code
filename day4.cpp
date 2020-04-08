// Link to problem : https://www.linkedin.com/posts/women-who-code-delhi_hi-everyone-here-is-the-question-for-day-activity-6653539501115305984-AhsH

#include <bits/stdc++.h>
using namespace std;

vector<int> getHousesRange(vector<int> height){
	int n = height.size();
	vector<int> range(n,1);
	
	stack<pair<int,int> > st;
	
	for(int i=0;i<n;i++){
		while(!st.empty() && st.top().first < height[i])
			st.pop();
		range[i] = i - (st.empty() ? -1 : st.top().second);
		st.push(make_pair(height[i],i));
	}
	return range;
}

int main() {
	int n;
	cin>>n;
	vector<int> height(n,0);
	for(int i=0;i<n;i++)
		cin>>height[i];
	
	vector<int> range = getHousesRange(height);
	for(int i=0;i<n;i++)
		cout<<range[i]<<" ";
	return 0;
}
