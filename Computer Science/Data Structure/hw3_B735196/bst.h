#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>
#include <queue>

using namespace std;
template <class K, class E> class BST; //���漱��

template <class K, class E>
class TreeNode {
	friend class BST<K, E>;
	TreeNode(K ky, E el, TreeNode<K, E>* left = 0, TreeNode<K, E>* right = 0)
		: key(ky), element(el), leftChild(left), rightChild(right)
	{ }

private:
	TreeNode<K, E>* leftChild;
	K key;
	E element;
	TreeNode<K, E>* rightChild;
};

template <class K, class E>
class BST {
public:
	BST() //BST�� ������
	{
		root = 0;
	} // empty BST

	void Insert(K& newkey, E& el)
	{
		Insert(root, newkey, el);
	}

	void Preorder()
	{
		Preorder(root);
	}

	void Inorder()
	{
		Inorder(root);
	}

	void Postorder()
	{
		Postorder(root);
	}

	void Levelorder();

	bool Find(const K&, E&);

	void Delete(K& oldkey)
	{
		Delete(root, oldkey);
	}

private:
	void Visit(TreeNode<K, E>*);
	void Insert(TreeNode<K, E>*&, K&, E&);
	void Preorder(TreeNode<K, E>*);
	void Inorder(TreeNode<K, E>*);
	void Postorder(TreeNode<K, E>*);
	void Delete(TreeNode<K, E>*&, K&);
	TreeNode<K, E>* root;
};


template <class K, class E>
void BST<K, E>::Visit(TreeNode<K, E>* ptr)
{
	cout << ptr->key << ":" << ptr->element << " ";
}
template <class K, class E>
void BST<K, E>::Insert(TreeNode<K, E>*& ptr, K& newkey, E& el) { //Insert�� 	helper�Լ�
	if (ptr == 0)
		ptr = new TreeNode<K, E>(newkey, el);

	else if (newkey < ptr->key)
		Insert(ptr->leftChild, newkey, el);

	else if (newkey > ptr->key)
		Insert(ptr->rightChild, newkey, el);

	else ptr->element = el; // Update element
}

template <class K, class E>
void BST<K, E>::Preorder(TreeNode<K, E>* currentNode) { //Preorder��helper�Լ�
	if (currentNode) {
		Visit(currentNode);
		Preorder(currentNode->leftChild);
		Preorder(currentNode->rightChild);
	}
}

//..... Inorder, Postorder��helper�Լ��������Ͻÿ�. //..... Levelorder(����p266 �����ϵ�STL ť���̿�)�������Ͻÿ�. 
template <class K, class E>
void BST<K, E>::Inorder(TreeNode<K, E>* currentNode) { //Inorder��helper�Լ�
	if (currentNode) {

		Inorder(currentNode->leftChild);
		Visit(currentNode);
		Inorder(currentNode->rightChild);
	}
}

template <class K, class E>
void BST<K, E>::Postorder(TreeNode<K, E>* currentNode) { //Postorder��helper�Լ�
	if (currentNode) {

		Postorder(currentNode->leftChild);
		Postorder(currentNode->rightChild);
		Visit(currentNode);
	}
}

template <class K, class E>
void BST<K, E>::Levelorder()
{
	queue<TreeNode<K, E>*> q;
	TreeNode<K, E>* currentNode = root;

	while (currentNode)
	{
		Visit(currentNode);
		if (currentNode->leftChild)
			q.push(currentNode->leftChild);
		if (currentNode->rightChild)
			q.push(currentNode->rightChild);
		if (q.empty())
			return;
		currentNode = q.front();
		q.pop();
	}
}

template <class K, class E>
bool BST<K, E>::Find(const K& k, E& e)
{
	TreeNode<K, E>* ptr = root;
	// root���� �����ؼ� �ݺ��ؼ� k�� ���� key�� ���� �ִ� ��带 ã�� 
	// ã�� ����� element�� e�� �����Ͽ� ��ȯ�Ѵ�. 
	// k�� ���� �ִ� e�� ã������ true, �� ã������ false�� ��ȯ�Ѵ�.

	
	while (ptr)
	{
		if (k < ptr->key)
		{
			ptr = ptr->leftChild;

		}

		else if (k > ptr->key)
		{
			ptr = ptr->rightChild;
		}

		else
		{
			e = ptr->element;
			return true;
		}
		
	}
	return false;

}
	

template <class K, class E>
void BST<K, E>::Delete(TreeNode<K, E>*& ptr, K& oldkey)
{
	// ptr�� ��Ʈ�� �ϴ� Ʈ������ oldkey�� Ű�� �ϴ� ��带 ����ÿ�.
	TreeNode<K, E>* tmpptr=NULL; 
	TreeNode<K, E>* tmpparentptr=NULL;

	if (ptr == 0) return; // �׷� ��尡 �����Ƿ�, �׳� return

	if (oldkey < ptr->key) //left subtree���� oldkey�� ã�� ����ÿ�
		Delete(ptr->leftChild, oldkey);

	else if (oldkey > ptr->key) // right subtree���� ����ÿ�
		// �ڵ��Ͻÿ�
		Delete(ptr->rightChild, oldkey);

	else // oldkey�� �����ִ� ������ ptr��带 ã�� ���: 
		 // Children �� ������ ��带 ã�� �����带 ��ü�Ѵ�.

		if (!ptr->leftChild && !ptr->rightChild) // Children�� ���ٸ�
		{
			delete ptr; 
			ptr = 0; 
			return;
		}

		else if (ptr->leftChild && !ptr->rightChild) //�������� ��尡 ���� Child�� ���� �ִ� ���
			// ��child�� ptr�� ����Ű���ϰ� ���� ptr�� ����Ű�� ��� ����
		{
			tmpptr = ptr; 
			ptr = ptr->leftChild; 
			delete tmpptr; 
			return;
		}

		else if (ptr->rightChild && !ptr->leftChild) //�������� ��尡 ������ Child�� �ִٸ�
		{
			//���� �����ϰ� �ڵ�
			tmpptr = ptr;
			ptr = ptr->rightChild;
			delete tmpptr;
			return;
		}

		else { //���� �� ������ child��� �ִ� ���:
			   //��Ʈ�� rc�� ����Ʈ������ ������ ���� ��塯ã��

			TreeNode<K, E>* rc = ptr->rightChild; // rc�� ��Ʈ�� subtree

			if (!rc->leftChild) // rc�� ����Child�� ������ rc�� �� ���!
			// { rc����� key/element/rightChild ������ ptr���� �ű��
			//   rc��� ����(�� delete rc);}
			{
				
				ptr->key = rc->key;
				ptr->rightChild = rc->rightChild;
				ptr->element = rc->element;
				delete rc;
				return;
			}

			else // rc�� ����Child�� �ִ� ���, rc�� ����Child�� ����Child
			// { ������ ���� Child�� ������ �i�ư�,���� ���� Ű ���� ���
			//  �� ã�´�. �� ����� key/element��  ptr���� �ű��, 
			//  �� ����� rightChild�� �� ����� parent�� leftChild�� ����
			//  �� ���� �� ��带 ����; }  
			{

				while (rc->leftChild!=0)
				{
					tmpparentptr = rc;
					rc = rc->leftChild;
				}

				ptr->key = rc->key;
				ptr->element = rc->element;
				tmpparentptr->leftChild = rc->rightChild;
				delete rc;
				return;

			}
		}
}

#endif 



