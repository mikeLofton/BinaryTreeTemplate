**Michael Lofton**

s218033 

Code Design and Data Structures

BinaryTreeTemplate

# I. Requirements
    
 1. **Description of Problem**

    **Name:** BinaryTreeTemplate

    **Problem Statement:** 

    Implement a Binary Search Tree. 

 2. **Input Information:**
    * Text Box - Allows you to input a number between 1 and 100.
    * Insert Button - Places a node with the current text box number into the Binary Tree.
    * Remove Button - Removes a node with the currenr text box number from the Binary Tree.
 3. **Output Information:**
    * Graphic display of the nodes and tree.
4. **User Interface Information:**
    * Text Box
    * Insert and Remove Buttons
    * The insered node, tree, and subtrees
    * The most recently added node will be green

# II. Design
 1. *System Architecture*

 2. *Object Information*
    * **File Name:** main.cpp
        * Name: main(int argc, char* argv[])
            * Description: Starts the game loop. 
            * Visibility: public
            * Type: int
    * **File Name:** TreeNode.h
        * **Class Name:** TreeNode (template: typename T)
        * Name: TreeNode()
            * Description: Base Constructor. Sets the left and right nodes to null pointer.
            * Visibility: public
        * Name: TreeNode(T value)
            * Description: Constructor that sets the tree node's value to the given value.
            * Visibility: public
        * Name: ~TreeNode()
            * Description: TreeNode's Destructor.
            * Visibility: public
        * Name: hasLeft()
            * Description: Returns whether or not a node has a left child.
            * Visibility: public
            * Type: bool
        * Name: hasRight()
            * Description: Returns whether or not a node has a right child.
            * Visibility: public
            * Type: bool
        * Name: getData()
            * Description: Returns the data a node contains.
            * Visibility: public
            * Type: T
        * Name: getLeft()
            * Description: Returns the child to the left of a node.
            * Visibility: public
            * Type: TreeNode(T)* 
        * Name: getRight()
            * Description: Returns the child to the right of a node.
            * Visibility: public
            * Type: TreeNode(T)*
        * Name: setData(T value)
            * Description: Sets a node's data to be the given value.
            * Visibility: public
            * Type: void
        * Name: setLeft(TreeNode(T)* node)
            * Description: Sets the left child of a node to be the given node.
            * Visibility: public
            * Type: void
        * Name: setRight(TreeNode(T)* node)
            * Description: Sets the right child of a node to be the given node.
            * Visibility: public
            * Type: void
        * Name: draw(int x, int y, bool selected = false)
            * Description: Draws the nodes to the screen.
            * Visibility: public
            * Type: void
        * Name: m_value(T)
            * Description: The value a node contains.
            * Visibility: private
        * Name: m_left(TreeNode(T)*)
            * Description: Pointer to a node's left child.
            * Visibility: private
        * Name: m_right(TreeNode(T)*)
            * Description: Pointer to a node's right child.
            * Visibility: private
    * **File Name:** BinaryTree.h
        * **Class Name:** TreeNode (template: typename T)
        * **Class Name:** BinaryTree (template: typename T)
        * Name: BinaryTree()
            * Description: BinaryTree Constructor. Sets the root to null pointer.
            * Visibility: public
        * Name: ~BinaryTree()
            * Description: BinaryTree Destructor.
            * Visibility: public
        * Name: isEmpty() const
            * Description: Returns whether or not there are any nodes in the tree.
            * Visibility: public
            * Type: bool
        * Name: insert(T value)
            * Description: Creates a new node that contains the given value and places it in the tree.
            * Visibility: public
            * Type: void
        * Name: remove(T value)
            * Description: Removes a node that contains the given value from the list.
            * Visibility: public
            * Type: void
        * Name: find(T value)
            * Description: Finds and returns a node with the given value in the tree.
            * Visibility: public
            * Type: TreeNode(T)*
        * Name: draw(TreeNode(T)* selected = nullptr)
            * Description: Calls the private draw function.
            * Visibility: public
            * Type: void
        * Name: findNode(T searchValue, TreeNode(T)*& nodeFound, TreeNode(T)\*& nodeParent)
            * Description: Finds a node that contains a given value. Grabs the found node's parent.
            * Visibility: private
            * Type: bool
        * Name: draw(TreeNode(T)* currentnode, int x, int y, int horizontalSpacing, TreeNode(T)* selected = nullptr)
            * Description: Draws the lines between the nodes.
            * Visibility: private
            * Type: void
        * Name: m_root(TreeNode(T)*)
            * Description: Pointer to the tree's root node.
            * Visibility: private