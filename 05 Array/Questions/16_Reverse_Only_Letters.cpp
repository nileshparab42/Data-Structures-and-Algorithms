class Solution {
public:
    string reverseOnlyLetters(string s) {
        int l=0;
        int h=s.length();
        while(l<h){
            if( isalpha(s[l]) && isalpha(s[h])){
                swap(s[l],s[h]);
                l++;
                h--;
            } 
            if(!isalpha(s[l])){
                l++;
            }
            if(!isalpha(s[h])){
                h--;
            }
        }
        return s;
    }
};