// Implementation of Breath First Search ( BFS ) using Queue Data Structure
#include <iostream>
#include <queue>
using namespace std;
class Node            // Node class for creating attributes of Tree Nodes
{
    public:           // Data members
    int data;
    Node* left;
    Node* right;
    Node* root;
    Node(int val)            // Parametrized Constructors
    {
        data = val; left = NULL;
        right = NULL; root = NULL;
    }
};
class BinaryTree            // Binart Tree class for Implementation of Binary Trees
{
    public:
    Node* InsertNodeInTree(Node* root, int val)    // Inserting Nodes in Tree
    {
        if(root == NULL)    // If the current Node is empty
            return new Node(val);      // Insert the node with specified value
        if(val <= root -> data)    // If given value is less than the parent Node, add in Left Subtree
            root -> left = InsertNodeInTree(root -> left, val);
        if(val > root -> data)     // If given value is more than the parent Node, add in Right Subtree
            root -> right = InsertNodeInTree(root -> right, val);
        return root;
    }
    public:
    void PrintTree(Node* root)   // Printing Tree by Pre-Order Traversal
    {
        if(root == NULL)    // If current Node is empty, backtrack
            return;
        PrintTree(root -> left);    // Printing left Subtree
        cout << "Node : " << endl;
        if(root -> left != NULL)     // If Left is not empty
            cout << "\t" << root -> data << " ---> " << root -> left -> data << "\t Left ( Occupied )" << endl;
        else                         // Otherwise
            cout << "\t" << root -> data << "\t\t Left ( Empty ) " << endl;
        if(root -> right != NULL)     // If Right is not empty
            cout << "\t" << root -> data << " ---> " << root -> right -> data << "\t Right ( Occupied )" << endl;
        else                         // Otherwise
            cout << "\t" << root -> data << "\t\t Right ( Empty )" << endl;
        PrintTree(root -> right);         // Printing Right Subtree
    }
    void BreadthFirstSearch(Node* root, int val)  // Breadth First Search Algorithm using Queues
    {   // Time Complexity is O(n) time as all Tree Nodes will be Traversed in worst case
        queue<Node*> Queue;   // Queue creation
        Queue.push(root);           // Enqueuing root node in the Queue
        while(!Queue.empty())   // While Queue is not empty
        {
            int size = Queue.size();         // Iterating till the Size of the Queue ( every Level )
            for(int i = 0; i < size; i++)
            {
                Node* front = Queue.front();    // Storing Front Node pointer reference
                if(front -> data == val)            // If value is matched
                {
                    cout << front -> data << " --> Found " << endl;
                    cout << "Search is Successfull !!" << endl;
                    Queue.pop();
                    return;       // Control moves out of the Function
                }
                else
                {
                    cout << front -> data << " --> ";
                    Queue.pop();            // Dequeue the front Node
                }
                if(front -> left)              // If Left Node exists, Enqueue it
                    Queue.push(front -> left);
                if(front -> right)             // If Right Node exists, Enqueue it
                    Queue.push(front -> right);
            }
        }     // If entire Tree is iterated
        cout << "Not Found" << endl;
        cout << "Search is Unsuccessful !!" << endl;
    }
};
int main()
{
    Node* root = NULL;      // Root Node initialised
    BinaryTree binarytree;          // Object creation for Binary Tree class
    int s, x;
    cout << "Enter Root Node for the Binary Tree : ";
    cin >> x;
    root = binarytree.InsertNodeInTree(root, x);   // Inserting Root Node
    cout << "Enter the number of Nodes to add to the Binary Tree : ";
    cin >> s;
    for(int k = 0; k < s ; k++)
    {
        cout << "Enter Node value : ";   // Appending Tree
        cin >> x;
        root = binarytree.InsertNodeInTree(root, x);
    }
    binarytree.PrintTree(root);   // Showing the Tree
    cout << "Enter Node value to be Searched : ";
    cin >> x;
    cout << "The Path taken by Breadth First Search ( BFS ) is : " << endl;
    binarytree.BreadthFirstSearch(root, x);   // Implementation of Breadth First Search
    return 0;   // End of the Program
}