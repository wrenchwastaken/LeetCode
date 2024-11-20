

class Solution {
public:
    bool isSame(unordered_map<char, int>& freq1,unordered_map<char, int>& freq2) {
        if (freq1.size() != freq2.size()) return false; // Fast check on size
        for (auto& p : freq1) {
            if (freq2.find(p.first) == freq2.end() || freq2.at(p.first) != p.second) {
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> freq1;
        for (char c : s1) {
            freq1[c]++;
        }

        int windowSize = s1.size();
        unordered_map<char, int> windowFreq;
        
        int left = 0;  // Left index of the sliding window
        for (int right = 0; right < s2.size(); ++right) {
            windowFreq[s2[right]]++;

            // When we have a valid window
            if (right - left + 1 == windowSize) {
                if (isSame(freq1, windowFreq)) {
                    return true;
                }
                // Remove one element from the left
                windowFreq[s2[left]]--;
                if (windowFreq[s2[left]] == 0) {
                    windowFreq.erase(s2[left]);
                }
                left++; // Slide the window
            }
        }

        return false;
    }
};
