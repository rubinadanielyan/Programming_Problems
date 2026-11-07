
#include <iostream>
using namespace std;

template <typename T>
class BST
{
private:
    struct Node
    {
        T value;
        Node* left;
        Node* right;

        Node(T val)
        {
            value = val;
            left = nullptr;
            right = nullptr;
        }
    };

    Node* root;

    Node* add(Node* node, T value)
    {
        if (node == nullptr)
            return new Node(value);

        if (value < node->value)
            node->left = add(node->left, value);
        else if (value > node->value)
            node->right = add(node->right, value);

        return node;
    }

    T findMax(Node* node) const
    {
        while (node->right != nullptr)
            node = node->right;

        return node->value;
    }

    Node* erase(Node* node, T value)
    {
        if (node == nullptr)
            return nullptr;

        if (value < node->value)
        {
            node->left = erase(node->left, value);
        }
        else if (value > node->value)
        {
            node->right = erase(node->right, value);
        }
        else
        {
            if (node->left == nullptr)
            {
                Node* temp = node->right;
                delete node;
                return temp;
            }

            if (node->right == nullptr)
            {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            T maxValue = findMax(node->left);
            node->value = maxValue;
            node->left = erase(node->left, maxValue);
        }

        return node;
    }

    void show(Node* node) const
    {
        if (node == nullptr)
            return;

        show(node->left);
        cout << node->value << " ";
        show(node->right);
    }

    void clear(Node* node)
    {
        if (node == nullptr)
            return;

        clear(node->left);
        clear(node->right);
        delete node;
    }

public:
    BST()
    {
        root = nullptr;
    }

    ~BST()
    {
        clear(root);
    }

    void insert(T value)
    {
        root = add(root, value);
    }

    void remove(T value)
    {
        root = erase(root, value);
    }

    void print() const
    {
        cout << "BST elements: ";
        show(root);
        cout << endl;
    }
};

int main()
{
    BST<int> tree;

    tree.insert(15);
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(12);
    tree.insert(17);
    tree.insert(25);

    tree.remove(12);

    tree.print();

    return 0;
}
