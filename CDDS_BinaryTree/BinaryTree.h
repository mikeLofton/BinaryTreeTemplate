#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#pragma once
template<typename T>
class TreeNode;

template<typename T>
class BinaryTree
{
public:

	BinaryTree() {};
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
	/// Calles the private draw function
	/// </summary>
	/// <param name="selected"></param>
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
	if (m_root == nullptr)
		return true;
	else
		return false;
}

template<typename T>
inline void BinaryTree<T>::insert(T value)
{
	bool inserted = false;
	TreeNode<T>* newNode = new TreeNode<T>(value);
	TreeNode<T>* currentNode = new TreeNode<T>();
	
	if (isEmpty())
	{
		m_root = newNode;
		inserted = true;
	}

	currentNode = m_root;

	while (!inserted)
	{
		if (newNode->getData() > currentNode->getData())
		{
			if (currentNode->hasRight())
			{
				currentNode = currentNode->getRight();
			}

			if (!currentNode->hasRight() && newNode->getData() > currentNode->getData())
			{
				currentNode->setRight(newNode);
				inserted = true;
			}
		}
		else if (newNode->getData() < currentNode->getData())
		{
			if (currentNode->hasLeft())
			{
				currentNode = currentNode->getLeft();
			}

			if (!currentNode->hasLeft() && newNode->getData() < currentNode->getData())
			{
				currentNode->setLeft(newNode);
				inserted = true;
			}	
		}
	}
}

template<typename T>
inline void BinaryTree<T>::remove(T value)
{
	TreeNode<T>* nodeToRemove = new TreeNode<T>();
	TreeNode<T>* parentNode = new TreeNode<T>();
	TreeNode<T>* currentNode = new TreeNode<T>();
	
	findNode(value, nodeToRemove, parentNode);

	//If node to remove is the root
	if (nodeToRemove == m_root && !nodeToRemove->hasLeft() && !nodeToRemove->hasRight())
	{
	 
		m_root = nullptr;
	}

		//For Deleting a leaf with no children
		if (!nodeToRemove->hasLeft() && !nodeToRemove->hasRight())
		{
			if (nodeToRemove == parentNode->getLeft())
			{
				parentNode->setLeft(nullptr);
			}

			if (nodeToRemove == parentNode->getRight())
			{
				parentNode->setRight(nullptr);
			}

			delete nodeToRemove;
		}

		//For Deleting a leaf that has a left child but no right child
		if (nodeToRemove->hasLeft() && !nodeToRemove->hasRight())
		{
			if (nodeToRemove == parentNode->getLeft() && nodeToRemove->hasLeft())
			{
				parentNode->setLeft(nodeToRemove->getLeft());
			}

			if (nodeToRemove == parentNode->getRight() && nodeToRemove->hasLeft())
			{
				parentNode->setRight(nodeToRemove->getLeft());
			}

			delete nodeToRemove;
		}

		//For Deleting a leaf that has a right child but no left child
		if (nodeToRemove->hasRight() && !nodeToRemove->hasLeft())
		{
			if (nodeToRemove == parentNode->getLeft() && nodeToRemove->hasRight())
			{
				parentNode->setLeft(nodeToRemove->getRight());
			}

			if (nodeToRemove == parentNode->getRight() && nodeToRemove->hasRight())
			{
				parentNode->setRight(nodeToRemove->getRight());
			}

			delete nodeToRemove;
		}

		//For Deleting a leaf with two children
		if (nodeToRemove->hasLeft() && nodeToRemove->hasRight())
		{
			currentNode = nodeToRemove->getRight();

			if (currentNode->hasLeft())
			{
				parentNode = currentNode;
				bool lowestFound = false;

				while (!lowestFound)
				{
					if (parentNode->getLeft()->hasLeft())
					{
						parentNode = parentNode->getLeft();
					}
					else 
					{
						currentNode = parentNode->getLeft();
						lowestFound = true;
					}
				}

				nodeToRemove->setData(currentNode->getData());
				parentNode->setLeft(currentNode->getRight());

				delete currentNode;
			}
			else
			{
				currentNode = nodeToRemove->getLeft();

				nodeToRemove->setData(currentNode->getData());

				if (currentNode->hasLeft())
				{
					nodeToRemove->setLeft(currentNode->getLeft());
				}
				else
				{
					nodeToRemove->setLeft(nullptr);
				}
				
				delete currentNode;
			}
		}
	
}

template<typename T>
inline TreeNode<T>* BinaryTree<T>::find(T value)
{
	TreeNode<T>* currentNode = new TreeNode<T>();
	currentNode = m_root;

	if (isEmpty())
	{
		return currentNode;
	}

	while (currentNode != nullptr)
	{
		if (value < currentNode->getData())
		{
			currentNode = currentNode->getLeft();
		}
		else if (value > currentNode->getData())
		{
			currentNode = currentNode->getRight();
		}
		else
		{
			return currentNode;
			break;
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
	TreeNode<T>* currentNode = new TreeNode<T>();
	currentNode = m_root;

	if (isEmpty())
		return false;

	while (currentNode != nullptr)
	{
		if (searchValue < currentNode->getData())
		{
			nodeParent = currentNode;
			currentNode = currentNode->getLeft();
		}
		else if (searchValue > currentNode->getData())
		{
			nodeParent = currentNode;
			currentNode = currentNode->getRight();
		}
		else if (searchValue == currentNode->getData())
		{
			nodeFound = currentNode;
			return true;
			break;
		}
		else
		{
			return false;
			break;
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
