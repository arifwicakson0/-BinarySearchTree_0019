#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
    string info;
    Node* leftchild;
    Node* rightchild;

    Node(string i, Node* l, Node* r)
    {
        info = i;
        leftchild = l;
        rightchild = r;
    }
};

class BinaryTree
{
public:
    Node* ROOT;
    BinaryTree()
    {
        ROOT = nullptr; // initially ROOT is null
    }

    void Insert(string element) // insert a node to the tree
    {
        Node* newNode = new Node(element, nullptr, nullptr); // allocate memory for the node
        newNode->info = element;                             // set the value of the node
        newNode->leftchild = nullptr;                        // set the left child to null
        newNode->rightchild = nullptr;                       // set the right child to null

        Node* parent = nullptr;
        Node* currentNode = nullptr;
        search(element, parent, currentNode); // locate the node which will be the parent of the new node

        if (parent == nullptr) // if the tree is empty
        {
            ROOT = newNode; // set the new node as the root
            return;
        }

        if (element < parent->info) // if the new node is less than the parent
        {
            parent->leftchild = newNode; // set the new node as the left child of the parent
        }
        else if (element > parent->info) // if the new node is greater than the parent
        {
            parent->rightchild = newNode; // set the new node as the right child of the parent
        }
    }

    void search(string element, Node*& parent, Node*& currentNode)
    {
        currentNode = ROOT;
        parent = nullptr;

        while ((currentNode != nullptr) && (currentNode->info != element)) // while the currentNode != NULL && currentNode->info != element
        {
            parent = currentNode;            // set the parent to the currentNode
            if (element < currentNode->info) // if the element is less than the currentNode
                currentNode = currentNode->leftchild; // set the currentNode to the left child
            else
                currentNode = currentNode->rightchild; // set the currentNode to the right child
        }
    }

    void inorder(Node* ptr) // function to perform inorder traversal
    {
        if (ROOT == nullptr)
        {
            cout << "Tree is empty" << endl;
            return;
        } if (ptr != nullptr)
        {
            inorder(ptr->leftchild);
            cout << ptr->info << " ";
            inorder(ptr->rightchild);
        }
    }

    void preorder(Node* ptr) // function to perform preorder traversal
    {
        if (ROOT == nullptr)
        {
            cout << "Tree is empty" << endl;
            return;
        }

        if (ptr != nullptr)
        {
            cout << ptr->info << " ";
            preorder(ptr->leftchild);
            preorder(ptr->rightchild);
        }
    }

    void postorder(Node* ptr) // function to perform postorder traversal
    {
        if (ROOT == nullptr) // if the tree is empty
        {
            cout << "Tree is empty" << endl;
            return;
        }
        // if the tree is not empty
        if (ptr != nullptr)
        {
            postorder(ptr->leftchild);
            postorder(ptr->rightchild);
            cout << ptr->info << " ";
        }
    }
};

int main()
{
    BinaryTree x;
    while (true)
    {
        cout << "\nMenu" << endl;
        cout << "1. implement insert operation" << endl;
        cout << "2. perform inorder traversal" << endl;
        cout << "3. perform preorder traversal" << endl;
        cout << "4. perform postorder traversal" << endl;
        cout << "5. exit" << endl;
        cout << "\nEnter your choice: ";

        char ch;
        cin >> ch;
        cout << endl;
        switch (ch)
        {
        case '1':
        {
            cout << "Enter a word: ";
            string word;
            cin >> word;
            x.Insert(word);
            break;
        }
        case '2':
        {
            x.inorder(x.ROOT);
            break;
        }
        case '3':
        {
            x.preorder(x.ROOT);
            break;
        }
        case '4':
        {
            x.postorder(x.ROOT);
            break;
        }
        case '5':
            return 0;
        default:
        {
            cout << "Invalid choice" << endl;
            break;
        }
        }
    }

}