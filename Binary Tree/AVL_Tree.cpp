#include<iostream>
using namespace std;

struct node
{
    int data;
    node *left, *right;
    int height;
}*root;

class avl_tree{
    public:
    avl_tree() {
    root = NULL;
    }
    int height(node *t){
        int h = 0;
        if (t != NULL)
        {
            int l_height = height(t->left);
            int r_height = height(t->right);
            int max_height = max(l_height, r_height);
            h = max_height + 1;
        }
    }

    int difference(node *t){
        int l_height = height(t->left);
        int r_height = height(t->right);

        int diff = l_height - r_height;
        return diff;
    }

    node* rr_rotat(node *parent) {
        node *t;
        t = parent->right;
        parent->right = t->left;
        t->left = parent;
        cout<<"Right-Right Rotation";
        return t;
    }

   node* ll_rotat(node *parent) {
        node *t;
        t = parent->left;
        parent->left = t->right;
        t->right = parent;
        cout<<"Left-Left Rotation";
        return t;
    }

   node* lr_rotat(node *parent) {
        node *t;
        t = parent->left;
        parent->left = rr_rotat(t);
        cout<<"Left-Right Rotation";
        return ll_rotat(parent);
    }

    node* rl_rotat(node *parent) {
        node *t;
        t = parent->right;
        parent->right = ll_rotat(t);
        cout<<"Right-Left Rotation";
        return rr_rotat(parent);
    }

    node* balance(node *t){
        int bal_factor = difference(t);
        if (bal_factor > 1) {
            if (difference(t->left) > 0)
                t = ll_rotat(t);
            else
                t = lr_rotat(t);
        } else if (bal_factor < -1) {
            if (difference(t->right) > 0)
                t = rl_rotat(t);
            else
                t = rr_rotat(t);
        }
        return t;
    }

    node* insert(node *root, int data){
        if (root == NULL) {
        root = new node;
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        return root;
    } else if (data< root->data) {
        root->left = insert(root->left, data);
        root = balance(root);
    } else if (data >= root->data) {
        root->right = insert(root->right, data);
        root = balance(root);
    } return root;
    }

    void show(node* p, int l){
        int i;
        if (p != NULL) {
            show(p->right, l+ 1);
            cout<<" ";
            if (p == root)
                cout << "Root -> ";
            for (i = 0; i < l&& p != root; i++)
                cout << " ";
                cout << p->data;
                show(p->left, l + 1);
        }
    }

    void inorder(node *t) {
    if (t == NULL)
        return;
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }

    void preorder(node *t){
    if (t == NULL)
      return;
      cout << t->data << " ";
      preorder(t->left);
      preorder(t->right);
    }

    void postorder(node *t) {
    if (t == NULL)
        return;
        postorder(t ->left);
        postorder(t ->right);
        cout << t->data << " ";
    }
};

int main()
{
    int c, i;
    avl_tree avl;
    root = avl.insert(root, 5);
    root = avl.insert(root, 6);
    root = avl.insert(root, 8);
    avl.show(root, 1);

}
