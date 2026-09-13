class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for(const auto& str : strs){
            encoded += to_string(str.size()) + "#" + str;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string>decoded;

        int i = 0;
        while( i < s.size()){
            int j = i;

            // find the delimiter
            while(s[j] != '#'){
                j++;
            }

            // extract the length numnber
            int length = stoi(s.substr(i, j-i));

            // extract the actual string using the length
            string str = s.substr(j+1, length);
            decoded.push_back(str);

            // move the pointer to start for next
             i = j + 1 + length;
        }

        return decoded;

        //time complexity : o(n)
        //space complexity : O(n)
    }
};
