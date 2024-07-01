#include <iostream>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];  // Use pointers to TrieNode
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {  // Fixed the loop condition
            children[i] = NULL;  // Initialize children to NULL
        }
        isTerminal = false;
    }       
};


class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');  // Initialize root with null character
    }

    void insertUtil(TrieNode* root, string word) {
        // Base case: If word is empty, mark current node as terminal
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        // Assumption: Word will be in uppercase
        int index = word[0] - 'A'; // Calculate index for current character

        TrieNode* child;
        
        // Present
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            // Absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursively insert the rest of the word into the trie
        insertUtil(child, word.substr(1));
    }

    // Wrapper function to insert a word into the trie
    void insertWord(string word) {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word) {
        // Base case
        if (word.length() == 0) {
            return root->isTerminal;
        }

        int index = word[0] - 'A'; 

        TrieNode* child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            // Absent
            return false;
        }

        // Recursion
        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word) {
        return searchUtil(root, word);
    }
};

int main() {
    Trie* t = new Trie();

    t->insertWord("ARM");
    t->insertWord("DO");
    t->insertWord("TIME");

    cout << "Present or Not: " << t->searchWord("ARM") << endl;  // Corrected test word
    cout << "Present or Not: " << t->searchWord("TIM") << endl;

    delete t;  // Clean up memory
    return 0;
}
