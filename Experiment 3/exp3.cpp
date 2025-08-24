class Solution {
  public:
    vector<vector<int>> countFreq(vector<int>& arr) {
        // code here
        unordered_map<int,int>map;
        
        for(int i=0; i<arr.size(); i++){
            if(map.find(arr[i])==map.end()){
                map[arr[i]]=1;
            }
            else{
                map[arr[i]]++;
            }
        }
        
        vector<vector<int>>ans;
        
        for(auto x : map){
            ans.push_back({x.first, x.second});
        }
        
        return ans;
        
    }
};