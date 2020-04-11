// Link to the problem - https://www.linkedin.com/posts/women-who-code-delhi_hi-everyone-here-is-the-question-for-day-activity-6654264286782820352-rlg0

bool TheFloorIsLava(vector<int>& furnitures) {
        int n = furnitures.size();
        set<pair<int,int>> included;
        vector<pair<int,int>> p;
        if(!binary_search(furnitures.begin(),furnitures.end(),1))
            return 0;
        p.emplace_back(1,1);
        included.insert(make_pair(1,1));
        while(p.size()){
            pair<int,int> u = p[0];
            p.erase(p.begin());
            int k = u.first;
            int a = u.second;
            if(a == furnitures[n-1])
                return true;
            if(k-1 > 0 && binary_search(furnitures.begin(),furnitures.end(),a+k-1)){
                if(!included.count(make_pair(k-1,a+k-1))){
                    included.insert(make_pair(k-1,a+k-1));
                    p.emplace_back(k-1,a+k-1);
                }
            }
            if(binary_search(furnitures.begin(),furnitures.end(),a+k)){
                if(!included.count(make_pair(k,a+k))){
                    included.insert(make_pair(k,a+k));
                    p.emplace_back(k,a+k);
                }
            }
            if(binary_search(furnitures.begin(),furnitures.end(),a+k+1)){
                if(!included.count(make_pair(k+1,a+k+1))){
                    included.insert(make_pair(k+1,a+k+1));
                    p.emplace_back(k+1,a+k+1);
                }
            }

        }
        return false;
    }
