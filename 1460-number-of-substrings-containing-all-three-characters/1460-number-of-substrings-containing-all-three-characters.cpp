class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0;
        int n = s.size();
        //hasharray for tracking
        int lastSeen[3] = {-1,-1,-1};
        for(int i=0;i<n;i++){
            //setting lastSeen idx
            lastSeen[s[i] - 'a'] = i;
            //updating count to min window + all possible before it
            count += 1 + min({lastSeen[0],lastSeen[1],lastSeen[2]});
        }
        return count;
    }
};