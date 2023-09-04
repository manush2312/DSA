#include<iostream>
using namespace std;


class TrieNode {
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch){  // Constructor
            this->data = ch;
            for(int i=0 ; i<26; i++){  // during start all the child nodes must be NULL..
                children[i] = NULL;
            }
            isTerminal = false;
        }
};


class Trie{

    TrieNode* root;  // creation of root node..

    void insertUtil(TrieNode* root, string word){
        
        //base case..
        if(word.length() == 0){
            root->isTerminal = true; // setting the last node as terminal..
        }

        // we are assuming that all characters in word string are in CAPS..
        int index = word[0] - 'A';  // getting the index of the character..

        TrieNode* child;

        // checking whether the that index is present or not.. 
        //Present part..
        if(root->children[index] != NULL){
            child = root->children[index];
        }else{
            // absent part..
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call..
        insertUtil(child, word.substr(1));
        
        
    }

    void insertWord(string word){
        insertUtil(root, word);  // just calling the function..
    }


};


int main(){


    return 0;
}