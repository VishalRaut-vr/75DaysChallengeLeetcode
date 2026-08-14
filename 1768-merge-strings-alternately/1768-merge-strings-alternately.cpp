class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();

        string res;
        int i = 0, j = 0;

        while(i < n1 && j < n2){
            res.push_back(word1[i]);
            res.push_back(word2[j]);
            i++;
            j++;
        }

        while(i < n1){
            res.push_back(word1[i++]);
        }
        while(j < n2){
            res.push_back(word2[j++]);
        }
        return res;
    }
};