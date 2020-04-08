vector<int> solve(ListNode *head){
	ListNode *cur = head;
	int n = 0;
	while(cur != NULL){
		cur = cur->next;
		n++;
	}
	stack<pair<int,int> > st;
	vector<int> ans(n,0);
	cur = head;
	int idx = 0;
	while(cur != NULL){
		while(!st.empty() && cur->val > st.top().first){
			ans[st.top().second] = cur->val;
			st.pop();
		}
		st.push(make_pair(cur->val,idx));
        cur = cur->next;
		idx++;
	}
    return ans;
}
