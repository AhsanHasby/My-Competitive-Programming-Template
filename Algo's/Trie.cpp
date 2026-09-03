#include<bits/stdc++.h>
using namespace std;

class TrieNode {
public:

    TrieNode* children[26];
    bool isLeaf;
    TrieNode() {
        isLeaf = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }

    void insert(TrieNode* root, const string& key) {
        // Initialize the curr pointer with the root node
        TrieNode* curr = root;

        for (char c : key) {
            if (curr->children[c - 'a'] == nullptr) {
                // If node for current character does not exist then make a new node
                TrieNode* newNode = new TrieNode();
            
                // Keep the reference for the newly created node
                curr->children[c - 'a'] = newNode;
            }
            // Move the curr pointer to the newly created node
            curr = curr->children[c - 'a'];
        }
        // Mark the end of the word
        curr->isLeaf = true;
    }

    // Method to search a key in the Trie
    bool search(TrieNode* root, const string& key) {
    
        // Initialize the curr pointer with the root node
        TrieNode* curr = root;

        // Iterate across the length of the string
        for (char c : key) {
        
            // Check if the node exists for the current character in the Trie
            if (curr->children[c - 'a'] == nullptr) 
                return false;
            
            // Move the curr pointer to the already existing node for the current character
            curr = curr->children[c - 'a'];
        }

        // Return true if the word exists and is marked as ending
        return curr->isLeaf;
    }
};