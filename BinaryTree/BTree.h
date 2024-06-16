#pragma once

template<typename K_t, typename T>
class BinaryTree
{
public:
	template<typename K_t, typename T>
	struct Node
	{
		K_t Key;
		T Val;
		Node<K_t, T>* Left_child;
		Node<K_t, T>* Right_child;

		Node(K_t Usr_key = K_t(), T Usr_val = T(), Node<K_t, T>* Usr_left_child = nullptr, Node<K_t, T>* Usr_right_child = nullptr)
		{
			Key = Usr_key;
			Val = Usr_val;
			Left_child = Usr_left_child;
			Right_child = Usr_right_child;
		}

		~Node()
		{

		}
	};

	Node<K_t, T>* Root = nullptr;
	int Size = 0;

public:

	void push_in_tree(K_t Usr_key, T Usr_val);
	int size_of_tree();
	T operator[](const K_t Usr_key);
	void delete_node(K_t Usr_key);
};

template<typename K_t, typename T>
void BinaryTree<K_t, T>::push_in_tree(K_t Usr_key, T Usr_val)
{
	if (this->Root == nullptr)
	{
		this->Root = new Node<K_t, T>(Usr_key, Usr_val);
	}
	else
	{
		Node<K_t, T>* Current_node = this->Root;
		while (Current_node != nullptr)
		{
			if (Usr_key <= Current_node->Key)
			{
				if (Current_node->Left_child == nullptr)
				{
					Current_node->Left_child = new Node<K_t, T>(Usr_key, Usr_val);
					break;
				}
				else
				{
					Current_node = Current_node->Left_child;
				}
			}
			else
			{
				if (Current_node->Right_child == nullptr)
				{
					Current_node->Right_child = new Node<K_t, T>(Usr_key, Usr_val);
					break;
				}
				else
				{
					Current_node = Current_node->Right_child;
				}
			}
		}
	}
	this->Size++;
}

template<typename K_t, typename T>
int BinaryTree<K_t, T>::size_of_tree()
{
	return this->Size;
}

template<typename K_t, typename T>
T BinaryTree<K_t, T>::operator[](const K_t Usr_key)
{
	Node<K_t, T>* Current_node = this->Root;

	while (Current_node != nullptr)
	{
		if (Usr_key == Current_node->Key)
		{
			return Current_node->Val;
		}
		else if (Usr_key <= Current_node->Key)
		{
			Current_node = Current_node->Left_child;
		}
		else
		{
			Current_node = Current_node->Right_child;
		}
	}
	return T();
}

template<typename K_t, typename T>
void BinaryTree<K_t, T>::delete_node(K_t Usr_key)
{
	Node<K_t, T>* Current_node = this->Root;

	while (Current_node != nullptr)
	{
		if (Usr_key <= Current_node->Key)
		{
			if (Current_node->Left_child->Key == Usr_key)
			{
				Node<K_t, T>* To_save = Current_node->Left_child->Right_child;
				Node<K_t, T>* To_delete = Current_node->Left_child;
				Current_node->Left_child = To_save;
				delete To_delete;
				this->Size--;
				return;
			}
			Current_node = Current_node->Left_child;
		}
		else
		{
			if (Current_node->Right_child->Key == Usr_key)
			{
				Node<K_t, T>* To_save = Current_node->Right_child->Right_child;
				Node<K_t, T>* To_delete = Current_node->Right_child;
				Current_node->Right_child = To_save;
				delete To_delete;
				this->Size--;
				return;
			}
			Current_node = Current_node->Right_child;
		}
	}
}