#include<iostream>
using namespace std;

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

void insertWord(TrieNode* root,string word){
    if(word.length()==0){
        root->isTerminal=true;
        return;
    }
    char ch=word[0];
    int index = ch - 'A';
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

bool searchWord(TrieNode* root,string word){
    if(word.length()==0){
        return root->isTerminal;
    }
    char ch=word[0];
    int index = ch - 'A';
    TrieNode* child=NULL;
    if(root->children[index]==NULL){
        return false;
    }
    else{
        child=root->children[index];
    }
    return searchWord(child,word.substr(1));
}

void deleteWord(TrieNode* root,string word){
    if(word.length()==0){
        root->isTerminal=false;
        return;
    }
    char ch=word[0];
    int index = ch - 'A';
    TrieNode* child=NULL;
    if(root->children[index]==NULL){
        cout<<"Word is not present\n";
        return;
    }
    else{
        child=root->children[index];
    }
    deleteWord(child,word.substr(1));
}

int main(){
    TrieNode* root = new TrieNode('-');
    insertWord(root,"NILESH");
    insertWord(root,"ASKAAN");
    insertWord(root,"RIYA");
    insertWord(root,"NITESH");
    cout<<searchWord(root,"NITESH");
    deleteWord(root,"NITESH");
    cout<<searchWord(root,"NITESH");
    return 0;
}