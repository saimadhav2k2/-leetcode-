class Solution {
public:
    void helper(stack<int> &s,vector<vector<int>> &adj,vector<bool> &vis,vector<bool> &dfsvis,int i,int &flag){
        vis[i]=true;
        dfsvis[i]=true;
        
        for(auto &n:adj[i]){
            if(!vis[n]){
                helper(s,adj,vis,dfsvis,n,flag);
            }else if(dfsvis[n]){
                flag=0;return;
            }
        }
        dfsvis[i]=false;
        s.push(i);
    }
    vector<int> findOrder(int nc, vector<vector<int>>& pq) {
        vector<vector<int>> adj(nc);
        vector<bool> vis(nc,false);
        vector<bool> dfsvis(nc,false);
        
        vector<int> ans;
        stack<int> s;
        
        for(int i=0;i<pq.size();i++){
            adj[pq[i][1]].push_back(pq[i][0]);
        }
        
        int flag;
        for(int i=0;i<nc;i++){
            flag=1;
            if(!vis[i]){
                helper(s,adj,vis,dfsvis,i,flag);
            }
            if(flag==0)return ans;
        }
        
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        
        return ans;
    }
};