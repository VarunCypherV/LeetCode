//code solution
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for(auto x: strs){
            string word = x;
            sort(word.begin(), word.end());
            mp[word].push_back(x);
        }
        
        vector<vector<string>> ans;
        for(auto x: mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};


//Mycode 110/119 test cases
class Solution {
public:

    bool static vectorz(const vector<string>& a, const  vector<string>& b) {
        return a == b;
    }
    bool static vectorz2(const string a, const  string b) {
        return a == b;
    }

    bool isAnagram(string s, string t) {
        if(s.length()==t.length() && s.length()==0){
            return true;
        }
        if (s.length() != t.length()) {
            return false;
        }
        unordered_map<char, int> hashmap1;
        for (char ch : s) {
            hashmap1[ch]++;
        }
        for (char ch : t) {
            if (hashmap1[ch] == 0) {
                return false;
            }
            hashmap1[ch]--;
        }
        for (auto x : hashmap1) {
            if (x.second != 0) {
                return false;
            }
        }

        return true;
    }
 
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector <string> result;
        vector<vector<string>> rf;
        unordered_set<string> hset;
        int flag=0;
        int countx=0;
        for(string s : strs){
            result.push_back(s);
            int strs_count=count(strs.begin(),strs.end(),s)-1;
            for(string t : strs){ 
                if (s!=t && isAnagram(s,t)){
                    result.push_back(t);
                    countx=1;
                }
                else if(s==t && isAnagram(s,t) &&strs_count!=0 ){
                    result.push_back(t);
                    countx=1;
                    strs_count--;
                    flag=1;
                }
            }
            sort(result.begin(),result.end());
            if(flag==0){
                auto it2 = unique(result.begin(), result.end());
                result.erase(it2, result.end());
            }
            
            rf.push_back(result); //sorting inside [, , ,]
            //then u sort it according to [[],[],[]]
            sort(rf.begin(),rf.end());
            auto it = unique(rf.begin(), rf.end(), vectorz);
            rf.erase(it, rf.end());
            result.clear();
            countx=0;
        }
        return rf;
    }

};
