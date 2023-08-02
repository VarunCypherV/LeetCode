//HASHMAP , RUN TIME 16MS
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<string , int> hashmap1;
        for(char ch : s ){
            string ch21(1, ch);
            hashmap1[ch21]++;
        }
        for(char ch2:t){
            string ch22(1, ch2);
            if(hashmap1[ch22]){
                hashmap1[ch22]--;
            }     
            else{
                return false;
            }
        }
        for(char ch3 : s ){
            string ch23(1, ch3);
            if(hashmap1[ch23]!=0){
                return false;
        } 
        }
        return true;
    }
};
