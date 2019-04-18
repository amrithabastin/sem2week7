#include <iostream>
using namespace std;

class Node
{
	public:
	int data;
	// Children and parent
	Node *left;
	Node *right;
	Node *parent;

	Node(int value)
	{
		data = value;
		left = NULL;
		right = NULL;
		parent = NULL;
	}
};

class BST
{
	public:
	Node *root;

	BST(){ 
	 root = NULL;
	 }
	//functions of bst
	void insert(int value)
	{ insertHelper(root, value);}

	void insertHelper(Node *curr, int value)
	{	//base case
		if (root == NULL)
		{
			root = new Node(value);
		}
		// Else compare the curr data with value
		else if (value < curr->data)
		{
			// else move left and call insertH
			if (curr->left == NULL)
			{
				curr->left = new Node(value);
				curr->left->parent=curr;
			}
			else
				insertHelper(curr->left, value);
		}
		else
		{
			// Else move right and call insertH
			if (curr->right == NULL)
			{
				curr->right = new Node(value);
				curr->right->parent=curr;
			}
			else
				insertHelper(curr->right, value);
		}
  	}
	//to find min

	Node* find_min(Node * curr)
	{
		if(root==NULL)
		{
			return NULL;
		}
		if(curr->left!=NULL)
		{
			return find_min(curr->left);
		}
		else
		{
			return curr;
		}
	}
	//counting
	int count(Node* curr)
	{
		return counthelper(curr,0);
	}

	int counthelper(Node* curr, int c)
	{
		int a=0,b=0;
		c++;
		if(curr->left!=NULL)
		{
			a=counthelper(curr->left,0);
		}
		if(curr->right!=NULL)
		{
			b=counthelper(curr->right,0);
		}
			return c+a+b;
	}

  	void display()
	{
		displayHelper(root);
		cout<<endl;
	}

  	void displayHelper(Node *curr)
	{
		// Base condition
		if (curr == NULL)
			return;
		// Display left.
		displayHelper(curr->left);
		// Display current
		cout << curr->data << ",";
		// Display right
		displayHelper(curr->right);
	}

	void displayFancy()
	{
		displayFancyHelper(root,0);
	}

	void displayFancyHelper(Node * cur,int s)
	{
		//when at the end of a trail return
		if(cur==NULL)
		{return;}
		//go left and increase the number of spaces
		displayFancyHelper(cur->left,s+1);
		//print the spaces
		for(int i=0;i<4*s;i++){cout<<" ";}
		//print the data
		cout<<cur->data<<endl;
		//go right and increase the number of spaces
		displayFancyHelper(cur->right,s+1);
  	}

	Node* search(Node * cur,int value)
	{
		if(cur==NULL)
		{return NULL;}
		if(cur->data==value)
		{return cur;}
		if(cur->data<value)
		{return search(cur->right,value);}
		else
		{return search(cur->left,value);}
	}

	void binary_delete(Node * cur)
	{
		Node* temp=cur;
		if(cur->right!=NULL)
		{
			temp=temp->right;
			while(temp->left!=NULL)
			{
				temp=temp->left;
			}
			cur->data=temp->data;
			if(temp->right!=NULL)
			{binary_delete(temp);}
			else
			{
				temp->parent->right=NULL;
				delete temp;
			}
}
		else
		{
			temp=temp->left;
			while(temp->right!=NULL)
			{
				temp=temp->right;
			}
			cur->data=temp->data;
			if(temp->left!=NULL)
			{binary_delete(temp);}
			else
			{
				temp->parent->left=NULL;
				delete temp;
			}
		}
	}
};

int main()
{
	BST lol;
	lol.insert(14);
	lol.insert(8);
	lol.insert(2);
	lol.insert(3);
	lol.insert(21);
	lol.insert(78);
	lol.insert(5);
	lol.insert(67);
	lol.insert(6);
	lol.display();
	lol.displayFancy();
	if(lol.search(lol.root,2)==NULL)
	{
		cout<<"Not Found"<<endl;
	}
	else
	{
		cout<<"Found"<<endl;
	}
	cout<<lol.count(lol.root)<<endl;
	lol.binary_delete(lol.root);
	lol.displayFancy();
}

   


