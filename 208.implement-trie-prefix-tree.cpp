/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */
#include <cstdio>
#include <string>
using namespace std;

// @lc code=start
class Trie {
    class Node {
    public:
        Node* map[130];
        bool is_terminal;
        char val;
        Node(char chr='\0') {
            for (int i=0; i<130; i++) {
                map[i] = nullptr;
            }
            is_terminal = true;
            val = chr;
        }
    };
    Node root;
public:
    Trie() {
        root = Node();
    }
    
    void insert(string word) {
        root.is_terminal = false;
        Node* current_node = &root;
        for (char &chr: word) {
            if (current_node->map[chr]==nullptr) {
                Node* new_node = new Node(chr);
                current_node->map[chr] = new_node;
            }
            current_node = current_node->map[chr];
            current_node->is_terminal = false; // Unset it to false for all the following characters
            printf("");
        }
        if (current_node->map['\0']==nullptr) {
            current_node->map['\0'] = new Node('\0');
        }
        printf("");
    }
    
    bool search(string word) {
        Node* current_node = &root;
        for (char& chr: word) {
            if (current_node->map[chr]==nullptr) {
                return false;
            } else {
                current_node = current_node->map[chr];
            }
        }
        if (current_node->map['\0']==nullptr) {
            return false;
        }
        return true;
    }
    
    bool startsWith(string prefix) {
        Node* current_node = &root;
        for (char& chr: prefix) {
            if (current_node->map[chr]==nullptr) {
                return false;
            } else {
                current_node = current_node->map[chr];
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

int main() {
    Trie trie;
    trie.insert("apple");
    printf("%d\n", trie.search("apple"));
    printf("%d\n", trie.search("app"));
    return 0;
}
