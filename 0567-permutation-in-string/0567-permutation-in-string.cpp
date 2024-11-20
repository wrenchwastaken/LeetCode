class Solution {
public:
    bool isSame(int freq1[], int freq2[]){
        for(int i=0;i<26;i++){
            if(freq1[i] != freq2[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int freq1[26] = {0};
        for(int i=0;i<s1.size();i++){
            freq1[s1[i]-'a']++;
        }
        int windowSize = s1.size();
        for(int i=0;i<s2.size();i++){
            int winIdx = 0;
            int idx = i;
            int windowFreq[26] = {0};
            while(winIdx < windowSize && idx < s2.size()){
                windowFreq[s2[idx] - 'a']++;
                winIdx++;
                idx++;
            }
            if(isSame(freq1,windowFreq)){
                return true;
            }

        }
        return false;
    }
};