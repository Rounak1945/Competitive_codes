#include<bits/stdc++.h>
using namespace std;

class Node {
    Node *links[26];
    bool flag = false;

    public:
    bool containsKey(char c) {
        return (links[c - 'a'] != NULL);
    }
    void createRef(char c, Node* node) {
        links[c - 'a'] = node;
    }
    Node* move(char c) {
        return links[c - 'a'];
    }
    void setEnd() {
        flag = true;
    }
    bool isEnd() {
        return flag;
    }
};

class Trie {
    Node* root;

    public:
    // Initializing Data structure (constructor)
    Trie() {
        root = new Node();
    }

    // Insert a word into the trie {O(word.length)}
    void insert(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i ++) {
            if(!node -> containsKey(word[i])) {
                node -> createRef(word[i], new Node());
            }
            // move to the reference trie
            node = node -> move(word[i]);
        }
        node -> setEnd();
    }

    // Check the word is in the trie or not {O(word.length)}
    bool search(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i ++) {
            if(!node -> containsKey(word[i])) return false;
            node = node -> move(word[i]);
        }
        return node -> isEnd();
    }

    // Check if there is any word in the trie which starts with the given word {O(word.length)}
    bool startsWith(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i ++) {
            if(!node -> containsKey(word[i])) return false;
            node = node -> move(word[i]);
        }
        return true;
    }
};


int main() {

}
