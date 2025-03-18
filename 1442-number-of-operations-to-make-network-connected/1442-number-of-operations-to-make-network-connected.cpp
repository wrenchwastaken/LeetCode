class UnionFind{
    vector<int> parent, rank;
    public:
    UnionFind(int n){
        parent.resize(n);
        rank.resize(n);
        for(int i=0; i<n; ++i){
            parent.at(i) = i;
            rank.at(i) = 1;
        }
    }
    
    int findParent(int x){
        if(parent.at(x) == x){
            return x;
        }
        parent.at(x) = findParent(parent.at(x));
        return parent.at(x);
    }
    
    void makeUnion(int x, int y){
        int xP = findParent(x);
        int yP = findParent(y);
        
        if(rank.at(xP) == rank.at(yP)){
            parent.at(yP) = xP;
            rank.at(xP)++;
        }else if( rank.at(xP) < rank.at(yP) ){
            parent.at(xP) = yP;
        }else {
            parent.at(yP) = xP;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        UnionFind obj(n);
        int totalComponents = n;
        int redundantEdges = 0;
        for(auto &edge : connections){
            int u = edge.at(0), v = edge.at(1);
            int xP = obj.findParent(u);
            int yP = obj.findParent(v);
            
            if(xP == yP){
                redundantEdges++;
            }else{
                totalComponents--;
                obj.makeUnion(u, v);
            }
        }
        
        if(totalComponents == 1){
            return 0;
        }
        if(redundantEdges < totalComponents-1){
            return -1;
        }
        
        return totalComponents-1;
    }
};