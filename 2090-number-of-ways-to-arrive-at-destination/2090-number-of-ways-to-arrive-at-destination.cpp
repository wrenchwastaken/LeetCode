class Solution {
public:
#define P pair<long long,int>
    int countPaths(int n, vector<vector<int>>& roads) {
        //define mod
        int mod = 1e9 + 7;
        vector<vector<pair<int,int>>> adj(n);
        //make adjacency list
        for(auto it : roads){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            //assign both ways
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        vector<long long> minTime(n, LLONG_MAX);
        vector<int> ways(n,0);
        minTime[0] = 0;
        ways[0] = 1;
        //take a priority queue for dijkstra
        priority_queue<P,vector<P>,greater<P>> pq;
        //{0th node, time}
        pq.push({0,0});
        //iterate until pq is empty
        while(!pq.empty()){
            //take all variables
            auto it = pq.top();
            long long time = it.first;
            int node = it.second;
            pq.pop();
            //go to neighbour nodes
            for(auto iter : adj[node]){
                int adjN = iter.first;
                int travel = iter.second;
                //check for dijkstra
                if(time + travel < minTime[adjN]){
                    //update time, ways and pq
                    minTime[adjN] = time + travel;
                    ways[adjN] = ways[node];
                    pq.push({minTime[adjN],adjN});
                }
                //if equal
                else if(minTime[adjN] == time + travel){
                    ways[adjN] = (ways[node] + ways[adjN]) % mod;
                }
            }
        }
        //return ways for destination
        return ways[n-1] % mod;
    }
};