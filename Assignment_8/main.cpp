#include <iostream>

using namespace std;

/*struct TreeNode
{
char key;
TreeNode *left;
TreeNode *right;
TreeNode *parent;
};*/

struct TreeNode
{
    int key;
    TreeNode *leftChild;
    TreeNode *rightChild;
    TreeNode *parent;
};

struct Node{
char key;
Node *next;
};
Node *head = NULL;

/**void addToList(TreeNode *node){
    if (head == NULL)
    {
        head->key = node->key;
        //head->next = NULL;
    }
    else
    {
        Node *current = head;
        Node *dummy = new Node;
        if(node->key > current->key)
        {
            while(current != NULL)
            {
                if(current->key < node->key)
                {
                    dummy->key = node->key;
                    dummy->next = current->next;
                    current->next = dummy;
                    return;
                }
                else
                {
                    current = current->next;
                }
            }
        }
        else
        {
            dummy->key = node->key;
            dummy->next = current;
            head = dummy;
        }
    }
}

void searchTree(TreeNode * node, char m, char n){
    if(node->left!=NULL)
        searchTree(node->left, m , n);
    if(node->key <= n && node->key >= m){
        //addToList(node);

        Node *newNode = new Node;
        newNode->key = node->key;
        newNode->next = NULL;
        if (head == NULL)
        {
            head->key = node->key;
            head->next = NULL;
        }
        Node *current = head;
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
    if(node->right!=NULL)
        searchTree(node->right, m, n);
}

void printList(){
    Node *current = head;
    while(current != NULL){
        cout<<current->key<<" "<<endl;
        current=current->next;
    }
}

void RangeSearch(TreeNode *node, char m, char n){
    //TreeNode *walker = node;
    searchTree(node, m, n);
    printList();
}*/

/*void searchTree(TreeNode * node, char m, char n){
    if(node->left!=NULL)
        searchTree(node->left, m , n);
    char letter = node->key;
    if(letter <= n && letter >= m){
        //cout<<"hello"<<endl;
        //addToList(node);
         Node *newNode = new Node;
        newNode->key = node->key;
        newNode->next = NULL;
        Node *tmp = new Node;
        if (head == NULL)
        {
            tmp->key = node->key;
            tmp->next = NULL;
            head = tmp;
        }
        else{
            Node *current = head;
            while(current->next != NULL)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }
    if(node->right!=NULL)
        searchTree(node->right, m, n);
}

void printList(){
    Node *current = head;
    while(current != NULL){
        cout<<current->key<<" "<<endl;
        current=current->next;
    }
}

void RangeSearch(TreeNode *node, char m, char n){
    searchTree(node, m, n);
    //printList();
}
/**l//////////////////////////////////////////////////////////////*/



/**#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

int maxDepth(struct node* node)
{
   if (node==NULL)
       return 0;
   else
   {
       int lDepth = maxDepth(node->left);
       int rDepth = maxDepth(node->right);

       cout<<"Left height "<<lDepth<<" Right Height "<<rDepth<<endl;
       if (lDepth > rDepth)
           return(lDepth+1);
       else return(rDepth+1);
   }
}*/
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////

/**TreeNode* leftRotate(TreeNode *x, TreeNode *root){
    TreeNode *y = new TreeNode;
    TreeNode *nullNode = new TreeNode;
    //cout<<"rotating left"<<endl;
    y = x->rightChild;
    x->rightChild = y->leftChild;
    if( y->leftChild != nullNode)
        y->leftChild->parent = x;
    y->parent = x->parent;
    if(x->parent == nullNode->parent)
        root = y;
    else if( x == x->parent->leftChild)
            x->parent->leftChild = y;
    else
            x->parent->rightChild = y;
    y->leftChild = x;
    x->parent = y;

    return root;
}

TreeNode* rightRotate(TreeNode *y, TreeNode *root){
    TreeNode *x = new TreeNode;
    TreeNode *nullNode = new TreeNode;
    //cout<<"rotating right"<<endl;
    x = y->leftChild;
    y->leftChild = x->rightChild;
    if( x->rightChild != nullNode)
        x->rightChild->parent = y;
    x->parent = y->parent;
    if(y->parent == nullNode->parent){
        root = x;
    }
    else if (y == (y->parent->leftChild))
        y->parent->leftChild = x;
    else
        y->parent->rightChild = x;
    x->rightChild = y;
    y->parent = x;

    return root;
}

int MaxHeight(TreeNode* node)
{
    if (node==NULL)
       return 0;
    else
    {
        int leftHeight = MaxHeight(node->leftChild);
        int rightHeight = MaxHeight(node->rightChild);

        if (leftHeight > rightHeight)
            return(leftHeight+1);
        else
            return(rightHeight+1);

    }
}

int MaxHeightDifference(TreeNode *root)
{
    TreeNode *left = root->leftChild;
    TreeNode *right = root->rightChild;

    int leftHeight = MaxHeight(left)+1;
    int rightHeight = MaxHeight(right)+1;
    int difference;

    if(leftHeight > rightHeight)
        difference = (leftHeight-rightHeight);
    else
        difference = (rightHeight-leftHeight);

    return difference;
}

TreeNode* higherTree(TreeNode *target, TreeNode *root)
{
    TreeNode *left = target->leftChild;
    TreeNode *right = target->rightChild;
    bool rotated = false;

    int leftHeight = MaxHeight(left)+1;
    int rightHeight = MaxHeight(right)+1;
    int difference;

    if(leftHeight > rightHeight){
        difference = (leftHeight-rightHeight);
        if(difference > 1){
            root = rightRotate(target, root);
            rotated = true;
        }
    }
    else{
        difference = (rightHeight-leftHeight);
        if(difference > 1){
            root = leftRotate(target, root);
            rotated = true;
        }
    }
    return root;
}

TreeNode* traverse(TreeNode * node, TreeNode * root){

    if(node->leftChild!= NULL)
        traverse(node->leftChild, root);

    if(node->rightChild!= NULL)
        traverse(node->rightChild, root);

    root = higherTree(node, root);
    /*if(higherTree(node, root) == true){
        cout<<"is true "<<endl;
        return;
    }
    return root;
}

TreeNode* CheckHeightAndRotate(TreeNode *root)
{
    TreeNode *walker = root;
    while(MaxHeightDifference(root) > 1){
        root = traverse(walker, root);
        //cout<<"Loop"<<endl;
    }
    return root;
}*/
/////////////////////////////////////////////////////////////
TreeNode* leftRotate(TreeNode *x, TreeNode *root){
    TreeNode *y = new TreeNode;
    TreeNode *nullNode = new TreeNode;
    //cout<<"rotating left"<<endl;
    y = x->rightChild;
    x->rightChild = y->leftChild;
    if( y->leftChild != nullNode)
        y->leftChild->parent = x;
    y->parent = x->parent;
    if(x->parent == nullNode->parent)
        root = y;
    else if( x == x->parent->leftChild)
            x->parent->leftChild = y;
    else
            x->parent->rightChild = y;
    y->leftChild = x;
    x->parent = y;

    return root;
}

TreeNode* rightRotate(TreeNode *y, TreeNode *root){
    TreeNode *x = new TreeNode;
    TreeNode *nullNode = new TreeNode;
    //cout<<"rotating right"<<endl;
    x = y->leftChild;
    y->leftChild = x->rightChild;
    if( x->rightChild != nullNode)
        x->rightChild->parent = y;
    x->parent = y->parent;
    if(y->parent == nullNode->parent){
        root = x;
    }
    else if (y == (y->parent->leftChild))
        y->parent->leftChild = x;
    else
        y->parent->rightChild = x;
    x->rightChild = y;
    y->parent = x;

    return root;
}

int MaxHeight(TreeNode* node)
{
    if (node==NULL)
       return 0;
    else
    {
        int leftHeight = MaxHeight(node->leftChild);
        int rightHeight = MaxHeight(node->rightChild);

        if (leftHeight > rightHeight)
            return(leftHeight+1);
        else
            return(rightHeight+1);

    }
}

int MaxHeightDifference(TreeNode *root)
{
    TreeNode *left = root->leftChild;
    TreeNode *right = root->rightChild;

    int leftHeight = MaxHeight(left)+1;
    int rightHeight = MaxHeight(right)+1;
    int difference;

    if(leftHeight > rightHeight)
        difference = (leftHeight-rightHeight);
    else
        difference = (rightHeight-leftHeight);

    return difference;
}

TreeNode* higherTree(TreeNode *target, TreeNode *root)
{
    TreeNode *left = target->leftChild;
    TreeNode *right = target->rightChild;
    bool rotated = false;

    int leftHeight = MaxHeight(left)+1;
    int rightHeight = MaxHeight(right)+1;
    int difference;

    if(leftHeight > rightHeight){
        difference = (leftHeight-rightHeight);
        if(difference > 1){
            root = rightRotate(target, root);
            rotated = true;
        }
    }
    else{
        difference = (rightHeight-leftHeight);
        if(difference > 1){
            root = leftRotate(target, root);
            rotated = true;
        }
    }
    return root;
}

TreeNode* traverse(TreeNode * node, TreeNode * root){
    root = higherTree(node, root);

    if(node->leftChild!= NULL)
        traverse(node->leftChild, root);
    if(node->rightChild!= NULL)
        traverse(node->rightChild, root);
    return root;
}

TreeNode* CheckHeightAndRotate(TreeNode *root)
{
    while(MaxHeightDifference(root) > 1){
        root = traverse(root, root);
    }
    return root;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
/*struct node* newNode(int data)
{
    struct node* node = new node;//(struct node*)
                                //malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}
*/
int main()
{
    /*struct node *root = newNode(1);

    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->right = newNode(6);
    root->left->right->right->left = newNode(5);

    printf("Hight of tree is %d", maxDepth(root));

    getchar();*/
    return 0;
}

/**
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}*/
