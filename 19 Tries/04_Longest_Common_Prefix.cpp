class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    TrieNode(char data){
        this->data=data;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }
};

class Solution {
public:
    void insertWord(TrieNode* root,string word){
        cout<<word<<"\n";
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }
        char ch=word[0];
        int index = ch - 'a';
        cout<<index<<"\n";
        TrieNode* child=NULL;
        if(root->children[index]==NULL){
            child = new TrieNode(ch);
            root->children[index]=child;
        }
        else{
            child=root->children[index];
        }
        return insertWord(child,word.substr(1));
    }

    string longestCommonPrefix(vector<string>& strs) {
        // Trie Solution
        string ans="";

        TrieNode* root = new TrieNode('-');
        for(int i=0;i<strs.size();i++){
            if(strs[i].size()==0){
                return ans;
            }
            insertWord(root,strs[i]);
        }

        while(root!=NULL){
            int count=0;
            TrieNode* next=NULL;


            for(int i=0;i<26;i++){
                if(root->children[i]!=NULL){
                    count++;
                    next=root->children[i];
                }
            }

            if(count==1){
                if(next->isTerminal==true){
                    ans+=next->data;
                    root=NULL;
                }
                else{
                    ans+=next->data;
                    root=next;
                }
            }
            if(count==0 || count>1){
                root=NULL;
            }

        }

        return ans;

        // Brute Force Solution
        // string ans="";
        // int i=0;
        // while(strs[0].size()!=0 && i<strs[0].size()){
        //     char ch=strs[0][i];
        //     for(int j=1;j<strs.size();j++){
        //         if(strs[j][i]!=ch || i>strs[j].size()){
        //             return ans;
        //         }
        //     }
        //     ans=ans+ch;
        //     i++;
        // }
        // return ans;
    }
};