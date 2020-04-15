#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>


struct TreeNode {
    //char value;
    int number;
    std::unordered_map<char, TreeNode*> children;
    TreeNode(char value, int number) : number(number) {};
};

class SecretCode {
public:
    SecretCode(std::string& s) {
        ProcessingText(s);
    };
    int FindFirstWord(std::string& key) {
        TreeNode* cur = text_[key[0] - 'a'];
        for (int i = 1; i < key.length(); ++i) {
            if (cur == NULL) {
                return -1;
            }
            cur = text_[key[i - 1] - 'a']->children[key[i]];
        }
        return cur->number - key.length() + 1;
    };
private:
    void ProcessingText(std::string& str) {
        text_.assign(26, NULL);
        std::vector<TreeNode*> last_nodes(4, NULL);
        std::vector<TreeNode*> new_nodes(4, NULL);
        int current_word = 1;
        int i = 0;
        while (i < str.length()) {
            while (!isalpha(str[i])) {
                ++i;
            }
            i = AddNewWord(str, i, last_nodes, new_nodes, current_word);
            ++current_word;
            swap(new_nodes, last_nodes);
            new_nodes.assign(4, NULL);
        }
    };
    int AddNewWord(std::string& str, int i, std::vector<TreeNode*>& last_nodes, std::vector<TreeNode*>& new_nodes, int count) {
        if (text_[str[i] - 'a'] == NULL) {
            text_[str[i] - 'a'] = new TreeNode(str[i] - 'a', count);
        }
        new_nodes[0] = text_[str[i] - 'a'];
        for (int j = 1; j < 5; ++j) {
            ++i;
            if (i >= str.length() || !isalpha(str[i])) {
                return i;
            }
            if (last_nodes[j - 1] != NULL) {
                if (last_nodes[j - 1]->children[str[i]] == NULL) {
                    last_nodes[j - 1]->children[str[i]] = new TreeNode(str[i], count);
                }
                new_nodes[j] = last_nodes[j - 1]->children[str[i]];
            }
        }
        while (isalpha(str[i])) {
            ++i;
        }
        return i;
    }

    std::vector<TreeNode*> text_;
};




int main() {
    std::string a;
    getline(std::cin, a);
    SecretCode sc(a);
    std::string key;
    getline(std::cin, key);
    std::cout << sc.FindFirstWord(key);
    return 0;
}
