#include <iostream>
#include <queue>
#include <stack>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

class BinaryTree
{
public:
    Node *Insertion()
    {
        int data;
        Node *newNode = new Node;

        cout << "Enter data or type -1 for no insert : ";
        cin >> data;

        if (data == -1)
            return 0;

        newNode->data = data;
        cout << "Enter Left Child : " << data << endl;
        newNode->left = Insertion();

        cout << "Enter Right Child : " << data << endl;
        newNode->right = Insertion();
        return newNode;
    }
    bool isSearch(Node *root, int key)
    {
        if (root == nullptr)
            return false;

        if (!root)
            return false;

        else
        {

            queue<Node *> q;
            q.push(root);

            while (!q.empty())
            {
                Node *temp = q.front();
                q.pop();

                if (temp->data == key)
                    return true;

                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
        }
        return false;
    }
    int findMax(Node *root)
    {
        if (root == nullptr)
            return 0;
        queue<Node *> q;
        Node *temp = nullptr;
        q.push(root);

        int maxi = root->data;

        while (!q.empty())
        {
            temp = q.front();
            q.pop();

            if (maxi < temp->data)
                maxi = temp->data;

            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }
        return maxi;
    }
    int findHight(Node *root)
    {
        int x, y;
        if (root != nullptr)
        {
            x = findHight(root->left);
            y = findHight(root->right);

            return (x > y) ? x + 1 : y + 1;
        }
        return 0;
    }
    int findDeepest(Node *root)
    {
        if (root == nullptr)
            return 0;

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            root = q.front();
            q.pop();

            if (root->left)
                q.push(root->left);
            if (root->right)
                q.push(root->right);
        }
        return root->data;
    }
    void mirrorTree(Node *root)
    {
        if (root != nullptr)
        {
            mirrorTree(root->left);
            mirrorTree(root->right);

            Node *temp = root->left;
            root->left = root->right;
            root->right = temp;
        }
        return;
    }

    int diameter(Node* root){
        if(root == nullptr)
            return 0;
        
        int d1 = findHight(root -> left) + findHight(root -> right) + 1;
        int d2 = diameter(root -> left);
        int d3 = diameter(root -> right);

        return max(max(d1,d2),d3);
    }
};

class Traversal
{
public:
    void preOrder(Node *root)
    {
        if (root == nullptr)
            return;

        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
    void inOrder(Node *root)
    {
        if (root == nullptr)
            return;

        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
    void postOrder(Node *root)
    {
        if (root == nullptr)
            return;

        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
    void levelOrder(Node *root)
    {
        if (root == nullptr)
            return;

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *temp = q.front();
            cout << temp->data << " ";
            q.pop();

            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
    void reverseLevelOrder(Node *root)
    {
        if (root == nullptr)
            return;

        queue<Node *> q;
        stack<int> st;
        q.push(root);

        while (!q.empty())
        {
            Node *temp = q.front();
            st.push(temp->data);
            q.pop();

            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }

        while (!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }
    }
};

class Views
{
    int maxLeft = 0;
    int maxRight = 0;

    public:
        void leftView(Node* root,int level){
            if(root == nullptr)
                return;
            
            if(level >= maxLeft){
                cout << root -> data << " ";
                maxLeft++; 
            }

            leftView(root -> left,level + 1);
            leftView(root -> right,level + 1);
        }
    
        void rightView(Node* root,int level){
            if(root == nullptr)
                return;
            
            if(level >= maxRight){
                cout << root -> data << " ";
                maxRight++;
            }
            rightView(root -> right,level + 1);
            rightView(root -> left,level + 1);
        }

        vector<int> topView(Node* root){
            vector<int> ans;

            if(root == nullptr)
                return ans;
            
            map<int,int> mp;
            queue<pair<Node*,int>>q;
            q.push({root,0});

            while(!q.empty()){
                auto temp = q.front();
                q.pop();

                auto first = temp.first;
                int ht = temp.second;

                if(mp.find(ht) == mp.end())
                    mp[ht] = first -> data;
                
                if(first -> left)
                    q.push({first -> left,ht - 1});
                
                if(first -> right)
                    q.push({first -> right, ht + 1});
            }

            for(auto i : mp)
                ans.push_back(i.second);
            
            return ans;
        }

        vector<int> bottomView(Node* root){
            vector<int> ans;

            if(root == nullptr)
                return ans;
            
            map<int,int> mp;
            queue<pair<Node*,int>>q;
            q.push({root,0});

            while(!q.empty()){
                auto temp = q.front();
                q.pop();

                auto first = temp.first;
                int ht = temp.second;

                mp[ht] = first -> data;
                
                if(first -> left)
                    q.push({first -> left,ht - 1});
                
                if(first -> right)
                    q.push({first -> right, ht + 1});
            }

            for(auto i : mp)
                ans.push_back(i.second);
            
            return ans;
        }
};

int main()
{
    BinaryTree Tree;
    Traversal Display;
    Node *root = nullptr;
    root = Tree.Insertion();
    Display.inOrder(root);

    cout << Tree.diameter(root);
    return 0;
}

/*
2 7 2 -1 -1 6 -1 -1 5 -1 9 -1 -1
*/