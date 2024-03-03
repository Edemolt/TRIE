#include <iostream>
#include <string>
using namespace std;

class TRIE {
public:
    struct Node {
        Node* arr[26] = {};
        int flag = 0;

        int contains_char(char ch) {
            return arr[ch - 'a'] != NULL;
        }

        void put(Node* new_node, char ch) {
            arr[ch - 'a'] = new_node;
        }

        Node* get_next(char ch) {
            return arr[ch - 'a'];
        }

        void set_flag() {
            flag = 1;
        }

        int is_flag_set() {
            return flag;
        }
    };

    Node* root = new Node();

    void insert(string word) {
        Node* temp = root;

        for (char i : word) {
            if (!(temp->contains_char(i))) {
                Node* new_node = new Node();
                temp->put(new_node, i);
            }
            temp = temp->get_next(i);
        }

        temp->set_flag();
    }

    int search(string word) {
        Node* temp = root;

        for (char i : word) {
            if (!temp->contains_char(i)) return 0;
            temp = temp->get_next(i);
        }
        return temp->is_flag_set();
    }

    int starts_with(string word) {
        Node* temp = root;
        for (char i : word) {
            if (!temp->contains_char(i)) return 0;
            temp = temp->get_next(i);
        }
        return 1;
    }
};