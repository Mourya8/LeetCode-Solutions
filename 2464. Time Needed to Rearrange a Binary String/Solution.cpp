class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int need = 0;
        int zero = 0;
        for(char c : s){
            if(c == '0') zero++;
            else if(zero > 0){
                need = max(need + 1, zero);
            }
        }
        return need;
    }
};