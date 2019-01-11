/************************************************************************
* Class: avl tree
*
* Purpose: holds a node which is a struct and contains all the various
*	functions to insert to, delete from and display an avl tree
*
* Manager functions:	
* 	avltree();
*	~avltree();
*	avltree(const avltree<T> &);
*	avltree<T> & operator=(const avltree<T> &);
*
* Methods:		
*	void setroot(AVLNode<T> * avl);
*	void display(AVLNode<T> * root);
*	AVLNode<T> * deldata(AVLNode<T> * root, T data, bool * h);
*	AVLNode<T> * insert(T data, bool * h);
*
*	static AVLNode<T> * del(AVLNode<T> * node, AVLNode<T> * root, bool * h);
*	static AVLNode<T> * balright(AVLNode<T> * root, bool * h);
*	static AVLNode<T> * balleft(AVLNode<T> * root, bool * h);
*	static AVLNode<T> * buildtree(AVLNode<T> * root, T data, bool * h);
*	static void deltree(AVLNode<T> * root);
*************************************************************************/


#include <iostream>
using std::cout;

template<typename T>
struct AVLNode
{
	T data;
	int balfact;
	AVLNode * left;
	AVLNode * right;
};

 template<typename T>
class avltree
{
public:
	avltree();
	~avltree();
	avltree(const avltree<T> &);
	avltree<T> & operator=(const avltree<T> &);

	void setroot(AVLNode<T> * avl);
	void display(AVLNode<T> * root);
	AVLNode<T> * deldata(AVLNode<T> * root, T data, bool * h);
	AVLNode<T> * insert(T data, bool * h);
	avltree<T> * equal(AVLNode<T> & rhs, avltree<T> & copy);

	static AVLNode<T> * del(AVLNode<T> * node, AVLNode<T> * root, bool * h);
	static AVLNode<T> * balright(AVLNode<T> * root, bool * h);
	static AVLNode<T> * balleft(AVLNode<T> * root, bool * h);
	static AVLNode<T> * buildtree(AVLNode<T> * root, T data, bool * h);
	static void deltree(AVLNode<T> * root);
private:
	AVLNode<T> * m_root;
};
/**********************************************************************	
* Purpose: ctor
*
* Entry: 
*
* Exit: sets root to nullptr
*
************************************************************************/

template<typename T>
avltree<T>::avltree()
{
	m_root = nullptr;
}
/**********************************************************************	
* Purpose: inserts data into the tree
* Entry: passed the data and a bool for height
*
* Exit: calls build tree and returns the root
*
************************************************************************/

template<typename T>
AVLNode<T> * avltree<T>::insert(T data, bool * h)
{
	m_root = buildtree(m_root, data, h);
	return m_root;
}
/**********************************************************************	
* Purpose: this inserts a node
*
* Entry: passed a node, the data and a bool for height
*
* Exit: returns the new tree
*
************************************************************************/

template<typename T>
AVLNode<T> * avltree<T>::buildtree(AVLNode<T> * root, T data, bool * h)
{
	AVLNode<T> * node1, * node2;
 
	if (root == nullptr)
	{
		root = new AVLNode<T>;
		root->data = data;
		root->left = nullptr;
		root->right = nullptr;
		root->balfact = 0;
		*h = true;
		return root;
	}
	if (data < root->data)
	{
		root->left = buildtree (root -> left, data, h);
 
		// If left subtree is higher
		if (*h)
		{
			switch (root -> balfact)
			{
				case 1 :
					node1 = root->left;
					if (node1->balfact == 1)
					{
						cout << "\nRight rotation, RR.";
						root->left = node1->right;
						node1->right = root;
						root->balfact = 0;
						root = node1;
					}
					else
					{
						cout << "\nDouble rotation, RL, left then right.";
						node2 = node1->right;
						node1->right = node2->left;
						node2->left = node1;
						root->left = node2->right;
						node2->right = root;
						if (node2->balfact == 1 )
							root->balfact = -1;
						else
							root->balfact = 0;
						if (node2->balfact == -1)
							node1->balfact = 1;
						else
							node1->balfact = 0;
						root = node2;
					}
					root->balfact = 0;
					*h = false;
					break;
 
				case 0:
					root->balfact = 1;
					break;
				case -1:
					root->balfact = 0;
					*h = false;
			}
		}
	}
 
	if (data > root->data)
	{
		root->right = buildtree (root->right, data, h);
 
		if ( *h )
		{
			switch (root->balfact)
			{
				case 1 :
					root->balfact = 0;
					*h = false;
					break;
				case 0 :
					root->balfact = -1;
					break;
				case -1 :
					node1 = root->right;
					if (node1->balfact == -1)
					{
						cout << "\nLeft rotation, LL.";
						root->right = node1->left;
						node1->left = root;
						root->balfact = 0;
						root = node1;
					}
					else
					{
						cout << "\nDouble rotation, LR right then left.";
						node2 = node1->left;
						node1->left = node2->right;
						node2->right = node1;
						root->right = node2->left;
						node2->left = root;
						if (node2->balfact == -1)
							root->balfact = 1;
						else
							root->balfact = 0;
						if ( node2->balfact == 1)
							node1->balfact = -1;
						else
							node1->balfact = 0;
						root = node2;
					}
					root->balfact = 0;
					*h = false;
			}
		}
	}
	return root;
}
/**********************************************************************	
* Purpose: displays the tree
*
* Entry: passed the root
*
* Exit: ~in order traversal~
*
************************************************************************/

template<typename T>
void avltree<T>::display(AVLNode<T> * root)
{
	if ( root != nullptr )
	{
		display (root->left);
		cout << root->data << " ";
		display (root->right);
	}
}
/**********************************************************************	
* Purpose: deletes a node
*
* Entry: passed the root, data to be deleted, and bool for height
*
* Exit: deletes the node and returns the new tree
*
************************************************************************/

template<typename T>
AVLNode<T> * avltree<T>::deldata(AVLNode<T> * root, T data, bool * h)
{
	AVLNode<T> * node;
	if (root->data == 13)
		cout << root->data;
	if (root == nullptr)
	{
		cout << "\nNo such data.";
		return root;
	}
	else
	{
		if (data < root->data)
		{
			root->left = deldata (root->left, data, h);
			if (*h)
				root = balright (root, h);
		}
		else
		{
			if (data > root->data)
			{
				root->right = deldata (root->right, data, h);
				if ( *h )
					root = balleft ( root, h );
			}
			else
			{
				node = root;
				if (node->right == nullptr)
				{
					root = node->left;
					*h = true;
					delete node;
				}
				else
				{
					if (node->left == nullptr)
					{
						root = node->right;
						*h = true;
						delete node;
					}
					else
					{
						node->right = del(node->right, node, h);
						if (*h)
							root = balleft(root, h);
					}
				}
			}
		}
	}
	return root;
}
/**********************************************************************	
* Purpose: does the actual deleting
*
* Entry: passed the successor and the node to be deleted
*
* Exit: deletes the node and returns the new tree
*
************************************************************************/

template<typename T>
AVLNode<T> * avltree<T>::del(AVLNode<T> * succ, AVLNode<T> * node, bool * h)
{
	AVLNode<T> * temp = succ;
 
	if (succ->left != nullptr)
	{
		succ->left = del(succ->left, node, h);
		if (*h)
			succ = balright(succ, h);
	}
	else
	{
		temp = succ;
		node->data = succ->data;
		succ = succ->right;
		delete temp;
		*h = true;
	}
	return succ;
}
/**********************************************************************	
* Purpose: this balances the right child of a tree
*
* Entry: passed the root
*
* Exit: balances the tree and returns the new one
************************************************************************/

template<typename T>
AVLNode<T> * avltree<T>::balright(AVLNode<T> * root, bool * h)
{
	AVLNode<T> * temp1, * temp2;
	switch (root->balfact)
	{
		case 1:
			root->balfact = 0;
			break;
		case 0:
			root->balfact = -1;
			*h = false;
			break;
		case -1:
			temp1 = root->right;
			if(temp1->balfact <= 0)
			{
				cout << "\nLeft rotation.";
				root->right = temp1->left;
				temp1->left = root;
				if(temp1->balfact == 0)
				{
					root->balfact = -1;
					temp1->balfact = 1;
					*h = false;
				}
				else
				{
					root->balfact = temp1->balfact = 0;
				}
				root = temp1;
			}
			else
			{
				cout << "\nDouble rotation, right then left.";
				temp2 = temp1->left;
				temp1->left = temp2->right;
				temp2->right = temp1;
				root->right = temp2->left;
				temp2->left = root;
				if(temp2->balfact == -1)
					root->balfact = 1;
				else
					root->balfact = 0;
				if(temp2->balfact == 1)
					temp1->balfact = -1;
				else
					temp1->balfact = 0;
				root = temp2;
				temp2->balfact = 0;
			}
	}
	return root;
}
/**********************************************************************	
* Purpose: this balances the left child of a tree
*
* Entry: passed the root
*
* Exit: balances the tree and returns the new one
************************************************************************/

template<typename T>
AVLNode<T> * avltree<T>::balleft(AVLNode<T> * root, bool * h)
{
	AVLNode<T> * temp1, * temp2;
	switch(root->balfact)
	{
		case -1:
			root->balfact = 0;
			break;
 
		case 0:
			root->balfact = 1;
			*h = false;
			break;
 
		case 1 :
			temp1 = root->left;
			if(temp1->balfact >= 0)
			{
				cout << "\nRight rotation.";
				root->left = temp1->right;
				temp1->right = root;
 
				if(temp1->balfact == 0)
				{
					root->balfact = 1;
					temp1->balfact = -1;
					*h = false;
				}
				else
				{
					root->balfact = temp1->balfact = 0;
				}
				root = temp1;
			}
			else
			{
				cout << "\nDouble rotation, left then right.";
				temp2 = temp1->right;
				temp1->right = temp2->left;
				temp2->left = temp1;
				root->left = temp2->right;
				temp2->right = root;
				if (temp2->balfact == 1)
					root->balfact = -1;
				else
					root->balfact = 0;
				if (temp2->balfact == -1)
					temp1->balfact = 1;
				else
					temp1->balfact = 0;
				root = temp2;
				temp2->balfact = 0;
			}
	}
	return root;
}
/**********************************************************************	
* Purpose: sets the main root to the passed in node
*
* Entry: passed the root 
*
* Exit: sets main root to the parameter
*
************************************************************************/

template<typename T>
void avltree<T>::setroot(AVLNode<T> * avl)
{
	m_root = avl;
}
/**********************************************************************	
* Purpose: dtor
*
* Entry:
*
* Exit: calls delete tree and passes the root
*
************************************************************************/

template<typename T>
avltree<T>::~avltree()
{
	deltree(m_root);
}
 /**********************************************************************	
* Purpose: deletes all nodes
*
* Entry: passed the root
*
* Exit: recusively deletes all nodes
*
************************************************************************/

template<typename T>
void avltree<T>::deltree(AVLNode<T> * root)
{
	if (root != nullptr)
	{
		deltree(root->left);
		deltree(root->right);
	}
	delete root;
}
/**********************************************************************	
* Purpose: copy ctor
*
* Entry:  passed a const avl tree by ref
*
* Exit: uses the op =
*
************************************************************************/

template<typename T>
avltree<T>::avltree(const avltree<T> & that)
{
	*this = that;
}
