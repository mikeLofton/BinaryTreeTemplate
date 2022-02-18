#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#pragma once
template<typename T>
class TreeNode;

template<typename T>
class BinaryTree
{
public:

	/// <summary>
	/// Constructor
	/// </summary>
	BinaryTree() { m_root = nullptr; }

	///Destructor
	~BinaryTree() {};

	/// <summary>
	/// Returns whether or not there are any nodes in the list
	/// </summary>
	bool isEmpty() const;

	/// <summary>
	/// Creates a new node that stores the given value and places it into the tree
	/// </summary>
	/// <param name="value">The new value to add to the tree</param>
	void insert(T value);

	/// <summary>
	/// Finds the node with the given value and removes it from the tree
	/// </summary>
	/// <param name="value">The value of the node to search for in the tree</param>
	void remove(T value);

	/// <summary>
	/// Finds and returns a node with the given value in the tree
	/// </summary>
	/// <param name="value">The value of the node to search for</param>
	TreeNode<T>* find(T value);

	/// <summary>
	/// Calls the private draw function
	/// </summary>
	void draw(TreeNode<T>* selected = nullptr);

private:
	/// <summary>
	/// Finds the node that matches the value in the list
	/// </summary>
	/// <param name="searchValue">The value of the node to search for</param>
	/// <param name="nodeFound">A pointer that will store the address of the node that was found</param>
	/// <param name="nodeParent">A pointer that will store the address of the parent of the node that was found</param>
	/// <returns>Whether or not a node matching the value could be found</returns>
	bool findNode(T searchValue, TreeNode<T>*& nodeFound, TreeNode<T>*& nodeParent);

	void draw(TreeNode<T>* currentnode, int x, int y, int horizontalSpacing, TreeNode<T>* selected = nullptr);

	TreeNode<T>* m_root = nullptr;
};

#endif

template<typename T>
inline bool BinaryTree<T>::isEmpty() const
{
	if (m_root == nullptr) //if the root equals null pointer
		return true;	//Return true
	else
		return false;
}

template<typename T>
inline void BinaryTree<T>::insert(T value)
{
	bool inserted = false;
	TreeNode<T>* newNode = new TreeNode<T>(value); //The node you're inserting
	TreeNode<T>* currentNode = new TreeNode<T>(); //The current node you're checking
	TreeNode<T>* nodeToFind = new TreeNode<T>(); //The node you want to find
	TreeNode<T>* parentNode = new TreeNode<T>(); //The parent of the node to find
	
	if (isEmpty()) //If the tree is empty
	{
		m_root = newNode; //Set root to newNode
		inserted = true; //Set inserted to true
	}

	currentNode = m_root; //Set currentNode to root

	findNode(value, nodeToFind, parentNode); //Looks for a node with the given value

	while (!inserted)
	{
		//If the newNode's data equal the data of a node thats already in the tree
		if (newNode->getData() == nodeToFind->getData())
		{
			break; //Break out the loop
		}
		//If the new node's data is greater than the current node's data
		else if (newNode->getData() > currentNode->getData())
		{
			if (currentNode->hasRight()) //If the current node has a right node
			{
				currentNode = currentNode->getRight(); //Set current node to its right
			}
			//If current node does not have a right
			if (!currentNode->hasRight() && newNode->getData() > currentNode->getData())
			{
				currentNode->setRight(newNode); //Set newNode to be current node's right
				inserted = true;
			}
		}
		//If the node's data is less than the current node's data
		else if (newNode->getData() < currentNode->getData())
		{
			if (currentNode->hasLeft()) //If the current node has a left
			{
				currentNode = currentNode->getLeft(); //Set current node to its left
			}
			//If the current node does not have a left 
			if (!currentNode->hasLeft() && newNode->getData() < currentNode->getData())
			{
				currentNode->setLeft(newNode); //Set new node to be current node's left
				inserted = true;
			}	
		}
	}
}

template<typename T>
inline void BinaryTree<T>::remove(T value)
{
	TreeNode<T>* nodeToRemove = new TreeNode<T>(); //The node you're trying to remove
	TreeNode<T>* parentNode = new TreeNode<T>(); //The nodeToRemove's parent
	TreeNode<T>* currentNode = new TreeNode<T>(); //Node to keep track of the current node
	
	findNode(value, nodeToRemove, parentNode); //Finds the node you're trying to remove and its parent

		//For Deleting a leaf with no children
		if (!nodeToRemove->hasLeft() && !nodeToRemove->hasRight()) //If nTR doesn't have a left and doesn't have a right
		{
			if (nodeToRemove == parentNode->getLeft()) //If nTR equals the parent node's left
			{
				parentNode->setLeft(nullptr); //Set parent node's left to null
			}

			if (nodeToRemove == parentNode->getRight()) //If nTR equals parent node's right
			{
				parentNode->setRight(nullptr); //Set parent node's right to null
			}

			delete nodeToRemove; //Delete the node 

			//If you removed the root set the root to null pointer
			if (nodeToRemove == m_root)
				m_root = nullptr;
		}

		//For Deleting a leaf that has a left child but no right child
		else if (nodeToRemove->hasLeft() && !nodeToRemove->hasRight()) //If nTR has a left but doesn't have a right
		{
			if (nodeToRemove == parentNode->getLeft() && nodeToRemove->hasLeft()) //If nTR equals the parent's left and nTR has a left
			{
				parentNode->setLeft(nodeToRemove->getLeft()); //Set the parent's left to be nTR's left
			}

			if (nodeToRemove == parentNode->getRight() && nodeToRemove->hasLeft()) //If nTR equals the parent's right and nTR has a right
			{
				parentNode->setRight(nodeToRemove->getLeft()); //Set the parent's right to nTR's left
			}

			//If you're removing the root set the root to be its left
			if (nodeToRemove == m_root)
			{
				m_root = nodeToRemove->getLeft();
			}

			delete nodeToRemove; //Delete the node
		}

		//For Deleting a leaf that has a right child but no left child
		else if (nodeToRemove->hasRight() && !nodeToRemove->hasLeft()) //If nTR has a right and doesn't have a left
		{
			if (nodeToRemove == parentNode->getLeft() && nodeToRemove->hasRight()) //If nTR equals the parent node's left and nTR has a right
			{
				parentNode->setLeft(nodeToRemove->getRight()); //Set the parent node's left to nTR's right
			}

			if (nodeToRemove == parentNode->getRight() && nodeToRemove->hasRight()) //If nTR equals the parent node's right and nTR has a right
			{
				parentNode->setRight(nodeToRemove->getRight()); //Set the parent node's right to nTR's right
			}

			//If you're removing the root set the root to be its right
			if (nodeToRemove == m_root)
			{
				m_root = nodeToRemove->getRight();
			}

			delete nodeToRemove; //Delete the node
		}

		//For Deleting a leaf with two children
		else if (nodeToRemove->hasLeft() && nodeToRemove->hasRight() && !isEmpty()) //If nTR has a left and a right
		{
			currentNode = nodeToRemove->getRight(); //Set currentNode to nTR's right

			if (currentNode->hasLeft()) //If the current node has a left
			{
				parentNode = currentNode; //Set parent node to current node
				bool lowestFound = false; //lowest found equals false

				while (!lowestFound) //While the lowest is not found
				{
					if (parentNode->getLeft()->hasLeft()) //If the parent node's left has a left
					{
						parentNode = parentNode->getLeft(); //Set parent node to equal its left
					}
					else 
					{
						currentNode = parentNode->getLeft(); //Set current node to the parent's left
						lowestFound = true; //lowest found equals true
					}
				}

				nodeToRemove->setData(currentNode->getData()); //Set nTR's data to current node's data
				parentNode->setLeft(currentNode->getRight()); //Set parent node's left to current node's right

				delete currentNode; //Delete current node
			}
			else
			{
				currentNode = nodeToRemove->getLeft(); //Set current node to equal nTR's left

				nodeToRemove->setData(currentNode->getData()); //Set nTR's data to current node's data

				if (currentNode->hasLeft()) //If the current node has a left
				{
					nodeToRemove->setLeft(currentNode->getLeft()); //Set nTR's left to current node's left
				}
				else
				{
					nodeToRemove->setLeft(nullptr); //Set nTR's left to null
				}
				
				delete currentNode; //Delete the current node
			}
		}
	
}

template<typename T>
inline TreeNode<T>* BinaryTree<T>::find(T value)
{
	TreeNode<T>* currentNode = new TreeNode<T>(); //Create a node that tracks the current node
	currentNode = m_root; //Set current node to the root

	//If the tree is empty return the current node
	if (isEmpty())
	{
		return currentNode;
	}

	while (currentNode != nullptr) //While the current node doesn't equal null
	{
		if (value < currentNode->getData()) //If the value is less than the current node's data
		{
			currentNode = currentNode->getLeft(); //Set current node to current's left
		}
		else if (value > currentNode->getData()) //If value is greater than the current node's data
		{
			currentNode = currentNode->getRight(); //Set current node to current's right
		}
		else
		{
			return currentNode; //Return current node
			break; //Break out the loop
		}
	}
	
}

template<typename T>
inline void BinaryTree<T>::draw(TreeNode<T>* selected)
{
	draw(m_root, 400, 40, 400, selected);
}

template<typename T>
inline bool BinaryTree<T>::findNode(T searchValue, TreeNode<T>*& nodeFound, TreeNode<T>*& nodeParent)
{
	TreeNode<T>* currentNode = new TreeNode<T>(); //Create a node that tracks the current node
	currentNode = m_root; //Set the current node to root

	//If the tree is empty return false
	if (isEmpty()) 
		return false;

	while (currentNode != nullptr) //While the current node is not null
	{
		if (searchValue < currentNode->getData()) //If the value is less than the current node's data
		{
			nodeParent = currentNode; //Set node parent to current node
			currentNode = currentNode->getLeft(); //Current node equals its left
		}
		else if (searchValue > currentNode->getData()) //If the value is greater than the current node's data
		{
			nodeParent = currentNode; //Set node parent to current node
			currentNode = currentNode->getRight(); //Current node equals its right
		}
		else if (searchValue == currentNode->getData()) //If the value equal the current node's data
		{
			nodeFound = currentNode; //Node found equals current node
			return true; //Return true
			break; //Break out the loop
		}
		else
		{
			return false; //Return false
			break; //Break out the loop
		}
	}
}

template<typename T>
inline void BinaryTree<T>::draw(TreeNode<T>* currentNode, int x, int y, int horizontalSpacing, TreeNode<T>* selected)
{
	//Decrease the horizontal space as the node
	horizontalSpacing /= 2;

	//Checks if the current node is null
	if (currentNode)
	{
		//Draws the left child if this node has one
		if (currentNode->hasLeft())
		{
			//Draws a line between the left child and the current one
			DrawLine(x, y, x - horizontalSpacing, y + 80, RED);
			//Draws the left child
			draw(currentNode->getLeft(), x - horizontalSpacing, y + 80, horizontalSpacing, selected);
		}

		//Draws the right child if this node has one
		if (currentNode->hasRight())
		{
			//Draws a line between this child and the current node
			DrawLine(x, y, x + horizontalSpacing, y + 80, RED);
			//Draws the right child
			draw(currentNode->getRight(), x + horizontalSpacing, y + 80, horizontalSpacing, selected);
		}
		//Draws the current node
		currentNode->draw(x, y, (selected == currentNode));
	}
}
