#include <iostream>

// Struktur Node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class SolutionAI {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p || !q) return p == q;
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main() {
    SolutionAI sol;

    // --- CONTOH 1: Pohon Identik [1,2,3] ---
    TreeNode* p1 = new TreeNode(1);
    p1->left = new TreeNode(2);
    p1->right = new TreeNode(3);

    TreeNode* q1 = new TreeNode(1);
    q1->left = new TreeNode(2);
    q1->right = new TreeNode(3);

    // --- CONTOH 2: Pohon Berbeda [1,2] vs [1,null,2] ---
    TreeNode* p2 = new TreeNode(1);
    p2->left = new TreeNode(2);

    TreeNode* q2 = new TreeNode(1);
    q2->right = new TreeNode(2);

    // Eksekusi dan Cetak Hasil
    std::cout << "Hasil Contoh 1: " << (sol.isSameTree(p1, q1) ? "true" : "false") << std::endl;
    std::cout << "Hasil Contoh 2: " << (sol.isSameTree(p2, q2) ? "true" : "false") << std::endl;

    return 0;
}