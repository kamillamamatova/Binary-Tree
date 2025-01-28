// Binary Trees

// Searching for a node in a Binary Search Tree (BST)

int find (struct tree_node * current_ptr, int val){
    // Check if there are nodes in the tree.
    if (current_ptr != NULL){
        // Found the value at the root.
        if (current_ptr->data == val){
            return 1;
        }
        if (val < current_ptr->data){
            return find(current_ptr->left, val);
        }
        // Or search to the right.
        else{
            return find (current_ptr->right, val);
        }
    }
    else{
        return 0;
    }
}

// Searching for a node in an arbitrary tree.

int Find(struct tree_node *current_ptr, int val){
    if(current_ptr != NULL){
        if (current_ptr->data == val){
            return 1;
        }
        return (Find(current_ptr->left, val) || Find(current_ptr->right, val))
    }
    else{
        return 0;
    }
}

// Summing the values of nodes in a tree.

int add(struct tree_node *current_ptr){
    if(current_ptr != NULL){
        // Recursively add all the nodes in a tree.
        return current_ptr->data + add(current_ptr->left) + add(current_ptr->right);
    }
    else{
        return 0;
    }
}

// Print Even Nodes: Write a function that prints out all even nodes in a binary search tree

int printEven(struct tree_node *current_ptr){
    if(current_ptr != NULL){
        if(current_ptr->data % 2 == 0){
            printf("%d ", current_ptr->data);
        }
        // Recursively check left and right sides of the tree.
        printEven(current_ptr->left);
        printEven(current_ptr->right);
    }
}

// This is basically a traversal. 
// Except we added a condition (IF) statement before the print statement.

// Print Odd Nodes (in ascending order)
// Write a function that prints out all odd nodes, in a binary search tree, in ascending order

int printOddAsc(struct tree_node * current_ptr){
    if(current_ptr != NULL){
        printOddAsc(current_ptr->left);
        if(current_ptr->data % 2 == 1){
            printf("%d ", current_ptr->data);
        }
        printOddAsc(current_ptr->right);
    }
}

// The question requested ascending order
// This requires in order traversal. So we simply change the order of the statement.

// Computer Height
// Write a recursive function to compute the height of a tree.
// Defined as the length of the longest path from the root to a leaf node.
// For the purpose of this program: 
// a tree with only 1 node has height 1 and an empty tree has a height 0

struct tree_node{
    int data;
    struct tree_node* left;
    struct tree_node* right;
}

int height(sturct tree_node * root){
    int leftHeight, rightHeight;

    if(root == NULL){
        return 0;
    }

    leftHeight = height(root->left);
    rightHeight = height(root->right);

    if(leftHeight > rightHeight){
        return leftHeight + 1;
    }

    return rightHeight + 1;
}

/* Find Largest: 
    - Write a recursive function that returns a pointer to the node containing 
    the largest element in a BST.
        - This is a BST, which mean it has an ordering property.
        - The largest node is located either the root or the greatest node in 
        the right subtree. */

struct tree_node{
    int data;
    struct tree_node* left;
    struct tree_node* right; 
}

struct node * largest(struct tree_node *B){
    // If B is NULL, there is no node
    if(B == NULL){
        return NULL;
    }
    // If B's right is NULL, that means B is the largest
    else if(B->right == NULL){
        return B;
    }

    // So if B's right was NOT equal to NULL,
    // There is a right subtree of B.
    // Which means that the largest value is in this subtree. 
    // So recursively call B's right.
    else{
        return largest(B->right);
    }
}

// Number of Single Children
/* In a binary tree, each node can have zero, one, or two children.
Write a recursive function that returns the number of nodes with a single child. */

struct tree_node{
    int data;
    struct tree_node * left;
    struct tree_node * right;
}

int one(struct tree_node *p){
    if(p != NULL){
        if (p->left == NULL){
            if(p->right != NULL){
                return 1 + one(p->right);
            }
        }
        else if(p->right == NULL){
            if(p->left != NULL){
                return 1 + one(p->left);
            }
        }
        else{
            return one(p->left) + one(p->right);
        }
    }
}
