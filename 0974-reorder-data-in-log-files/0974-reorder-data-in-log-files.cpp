class Solution {
public:
    bool isLetter(string &s)
    {
        int i = 0;
        while(i<s.size() && s[i] != ' ')i++;

        i++;

        while(i<s.size() && s[i] != ' ')
        {
            if(!(s[i] >= '0' && s[i] <= '9'))
            {
                return true;
            }
            i++;
        }
        return false;
    }

    vector<string> reorderLogFiles(vector<string>& logs) 
    {
        vector<pair<string,string>>letters;
        vector<string>ans;
        for(auto &i : logs)
        {
            if(isLetter(i))
            {
                int findIndex = i.find(' ');
                letters.push_back({i.substr(findIndex+1),i.substr(0, findIndex)});
            }
            else ans.push_back(i);
        }
        
        reverse(ans.begin(),ans.end());
        sort(letters.begin(),letters.end());
        reverse(letters.begin(),letters.end());
        
        for(auto &i : letters)
        {
            ans.push_back(i.second +" "+ i.first);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};