class Solution {
public:
    bool isValid(string s) {
        vector<string> stack{"$"};
        unordered_map<string, string> hmap;
        hmap["("] = ")";
        hmap["{"] = "}";
        hmap["["] = "]";
        hmap[")"] = "x";
        hmap["]"] = "x";
        hmap["}"] = "x";

        for (auto x : s) {
            string l = stack.back();
            if (l == "$") {
                stack.push_back(string(1, x));
            } else {
                stack.pop_back();
                string h(1, x);
                auto itr = hmap.find(l);
                if (itr != hmap.end() && itr->second != h) {
                    stack.push_back(l);
                    stack.push_back(h);
                }
            }
        }
        return stack.size() == 1; 
    }
};
