#pragma once

template<typename T>
class TreeNode
{
public:

	/// <summary>
	/// Base Constructor
	/// </summary>
	TreeNode();

	/// <summary>
	/// Sets the tree node's value to the given value
	/// </summary>
	/// <param name="value">The given value</param>
	TreeNode(T value);

	///Destructor
	~TreeNode() {};

	/// <summary>
	/// Returns whether or not this node has a left child
	/// </summary>
	bool hasLeft();

	/// <summary>
	/// Returns whether or not this node has a right child
	/// </summary>
	bool hasRight();

	/// <summary>
	/// Returns the data this node contains 
	/// </summary>
	T getData() { return m_value; }

	/// <summary>
	/// Gets the child to the left of this node
	/// </summary>
	TreeNode<T>* getLeft() { return m_left; }

	/// <summary>
	/// Gets the child to the right of this node
	/// </summary>
	TreeNode<T>* getRight() { return m_right; }

	/// <summary>
	/// Sets the value of the data this node is storing to be the given value
	/// </summary>
	/// <param name="value">The value to change the data to</param>
	void setData(T value) { m_value = value; }

	/// <summary>
	/// Sets the left child of this node to be the given node
	/// </summary>
	/// <param name="node">The node to set as this nodes new child</param>
	void setLeft(TreeNode<T>* node);

	/// <summary>
	/// Sets the left child of this node to be the given node
	/// </summary>
	/// <param name="node">The node to set as this nodes new child</param>
	void setRight(TreeNode<T>* node);

	void draw(int x, int y, bool selected = false);

private:
	T m_value;

	TreeNode<T>* m_left;
	TreeNode<T>* m_right;
};

template<typename T>
inline void TreeNode<T>::setLeft(TreeNode<T>* node)
{
	m_left = node;
}

template<typename T>
inline void TreeNode<T>::setRight(TreeNode<T>* node)
{
	m_right = node;
}

template<typename T>
inline void TreeNode<T>::draw(int x, int y, bool selected)
{
	//Creates an array to store the string representation of the value
	static char buffer[10];

	//Converts the value to a string and stores it in the array
	sprintf(buffer, "%d", m_value);

	//Draws the circle to represent the node
	DrawCircle(x, y, 30, YELLOW);

	//If the node is the current selected node change its color
	if (selected)
		DrawCircle(x, y, 28, GREEN);
	else
		DrawCircle(x, y, 28, BLACK);

	//Draw the value of the node inside its circle
	DrawText(buffer, x - 12, y - 12, 12, WHITE);
}

template<typename T>
inline TreeNode<T>::TreeNode()
{
	m_left = nullptr;
	m_right = nullptr;
}

template<typename T>
inline TreeNode<T>::TreeNode(T value)
{
	m_value = value;
}

template<typename T>
inline bool TreeNode<T>::hasLeft()
{
	if (getLeft() != nullptr) //If left does not equal null
		return true;	//Return true
	else
		return false;
}

template<typename T>
inline bool TreeNode<T>::hasRight()
{
	if (getRight() != nullptr) //If right does not equal null
		return true;	//Return true
	else
		return false;
}
