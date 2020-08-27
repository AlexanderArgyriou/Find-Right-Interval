class Solution 
{
    public:
        vector<int> findRightInterval(vector<vector<int>> &in) 
        {  
            vector<int> ans( in.size() );
            vector<int> pos( in.size() );
            set<int> start;
        
        for(int i = 0; i < in.size(); ++i)
        {
            start.insert(in[i][0]); // set of start values of intervals
            pos[i] = in[i][0];  // original positions of start values
        }
        
        // for every end value
        for(int i = 0; i < in.size(); ++i)
        {
            //(?exist) find the closest bigger start value for the current end value
            auto it1 = start.upper_bound(in[i][1]); 
            // (?exist) find the same start value with the current end value 
            auto it2 = start.find(in[i][1]);  
            
            if(it2 != start.end())
            { // if the same value exist take position from original positions array
                ans[i] = ( find(pos.begin(), pos.end(), *it2) - pos.begin() );
            }
            else if(it1 != start.end()) 
            {  // if closest greater value exist take pos from original pos array
                ans[i] = ( find(pos.begin(), pos.end(), *it1) - pos.begin() );
            }
            else
            {  // if same or greater value does not exist , answer with -1
                ans[i] = -1;
            }
        }
        return ans;
    }
};
