class Solution {
public:


    bool topo_sort(int curr,vector<vector<int>> &adj,vector<int> &visited,vector<int> &path_visited,stack<int> &s){

        visited[curr]=1;
        path_visited[curr]=1;

        for(auto x:adj[curr]){

            if(visited[x] && path_visited[x]) return false;
            
            if(visited[x]==0){
                if(!topo_sort(x,adj,visited,path_visited,s)) return false;
            }
        }
        path_visited[curr]=0;
        s.push(curr);
        return true;


    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        

        vector<vector<int>> adj(numCourses);
      
        for(auto x:prerequisites){
            adj[x[1]].push_back(x[0]);
            
        }
        vector<int> visited(numCourses,0);
        vector<int> path_visited(numCourses,0);
        stack<int> s;
        for(int i=0;i<numCourses;i++){
            if(visited[i]==0){
                if(!topo_sort(i,adj,visited,path_visited,s)) return {};
            }
        }
        vector<int> res;

        while(!s.empty()){
            int ele=s.top();
            s.pop();
            res.push_back(ele);
        }
        return res;
    


    }
};