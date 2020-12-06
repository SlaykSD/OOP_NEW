#pragma once
#include <iostream>
#include<stdexcept>

namespace best_list {


	template <class T>
	struct Node {
		//class data
		T val_;
		Node* next;
		Node* prev;
		// metods
		Node() :next(nullptr), prev(nullptr) {}
		Node(T val) :Node() {
			val_ = val;
		}
		~Node() = default;
	};


	template <class T>
	class List
	{
	public:
		typedef Node<T> Node;
		class IterList;
		friend class IterList;
	private:
		friend class Node;
		Node* head;
		Node* last;

		int sz;
	public:
		class IterList
		{
			friend class List<T>;
		private:
			Node* curr;

		public:
			IterList() : curr() {}
			IterList(const List<T>& list) :curr(list.head) { }
			IterList& operator++() { curr = curr->next; return *this; }
			IterList& operator++(int) { List<T>::IterList res(*this); curr = curr->next; return res; }
			IterList& operator--() { curr = curr->prev; return *this; }
			IterList& operator--(int) { List<T>::IterList res(*this); curr = curr->prev; return res; }
			bool operator==(const IterList& it) { return curr == it.curr; }
			bool operator!=(const IterList& it) { return curr != it.curr; }
			T& operator*() { return curr->val_; }
			T* operator->() { return &curr->val_; }
			~IterList() = default;
		};

		int size()const { return sz; }
		int empty()const { return sz == 0; }

		List() :head(nullptr), last(nullptr), sz(0) {}
		List(T val) : List()
		{

			head = new Node(val);
			last = head;
			sz++;
		}
		List(List<T>& list)
		{
			head = new Node(list.head->val_);
			IterList it =list.begin();
			sz++;
			Node* tmp = head;
			Node* prev =  nullptr;
			++it;
			for (it; it != list.end(); ++it)
			{
				if (prev)
					tmp->prev = prev;
				Node* curr = new Node(*it);
				tmp->next = curr;
				prev = tmp;
				tmp = tmp->next;
				sz++;
			}
			last = tmp;
			last->prev = prev;
		}

		List<T>& operator = (List<T>& a) {
			if (&a != this) {
				this->clear();
				head = new Node(a.head->val_);
				auto it = a.begin();
				sz++;
				++it;
				Node* tmp = head;
				Node* prev = nullptr;
				for (it; it != a.end(); ++it)
				{
					if (prev)
						tmp->prev = prev;
					Node* curr = new Node(*it);
					tmp->next = curr;
					prev = tmp;
					tmp = tmp->next;
					sz++;
				}
				last = tmp;
				last->prev = prev;
			}
			return *this;
		}
		List<T>& operator = (List<T>&& a) {
			if (&a != this) {
				this->clear();
				sz = a.sz;
				head = a.head;
				last = a.last;
				a.head = nullptr;
				a.last = nullptr;
			}
			return*this;
		}
		List<T>& push_back(const T& fresh)
		{
			Node* tmp = new Node(fresh);
			tmp->prev = last;
			if (head != nullptr)
			{
				last->next = tmp;
				last = tmp;
				sz++;
			}
			else
			{
				last = tmp;
				head = tmp;
				sz++;
			}
			return *this;
		}
		const T& pop_back()
		{
			if (!this->empty())
			{
				T res = last->val_;
				Node* tmp = last;
				last = last->prev;
				delete tmp;
				sz--;
				if (last == nullptr)
				{
					head = nullptr;
					return res;
				}
				last->next = nullptr;
				return res;
			}
			else
				throw std::out_of_range("list is empty");
		}
		List<T>& erase(IterList it)
		{
			if (sz == 0)
				throw std::out_of_range("list is empty");
			sz--;
			if (sz == 0)
			{
				delete head;
				last = nullptr;
				head = nullptr;
				return *this;
			}
			Node* left = it.curr->prev;
			Node* right = it.curr->next;
			if (!(left && right))
			{
				//handle of end
				if (!left)
				{
					auto tmp = head;
					head = head->next;
					head->prev = nullptr;
					//++it;
					delete tmp;
				}
				else
				{
					auto tmp = last;
					last = last->prev;
					last->next = nullptr;
					//--it;
					delete tmp;
				}
			}
			else
			{
				//default
				left->next = right;
				right->prev = left;
			//	++it;
				delete it.curr;
			}
			return *this;
		}

		IterList end()
		{
			IterList  it;
			if (head != nullptr)
			{
				it.curr = last->next;
			}
			return it;
		}
		IterList begin()
		{
			return IterList(*this);
		}

		void clear()
		{

			List<T>::IterList it = this->begin();
			while (it != this->end())
			{
				auto prevIt = it;
				it++;
				erase(prevIt);
			}
			sz = 0;
		}
		~List()
		{
			while (head != nullptr)
			{
				auto tmp = head;
				head = head->next;
				delete tmp;
			}
			sz = 0;
		}
	};


	/*template <class T>
	class IterList
	{
		friend class List<T>;
		typedef Node<T> Node;
	private:
		Node* first;
		Node* curr;
	public:
		IterList() :first(), curr() {}
		IterList(List<T> list) :first(list.head), curr(first) { }
		IterList<T>& operator++() { curr = curr->next; return *this; }
		IterList<T>& operator++(int) { IterList<T> res(this); curr = curr->next; return res; }
		bool operator==(const IterList& it) { return curr == it.curr; }
		bool operator!=(const IterList& it) { return curr != it.curr; }
		T& operator*() { return curr->val_; }
		T* operator->() { return &curr->val_; }
		~IterList() = default;
	};*/


	//List(T* pVal)//Copy list pVal - begin
	//{
	//	try {
	//		int i = _msize(pVal) / _msize(T);
	//		if (i > 1)
	//		{
	//			head = new Node(*pVal);
	//			sz++;
	//			Node* tmp = head;
	//			for (int  j = 1; j < i; j++)
	//			{
	//				Node* curr = new Node(pVal[j]);
	//				tmp->next = curr;
	//				tmp = tmp->next;
	//				sz++;

	//			}
	//		}
	//		else
	//		{
	//			head = new Node(*pVal);
	//			sz++;
	//		}
	//	}
	//	catch(...){
	//		std::cout << " nullptr" << std::endl;
	//	}
	//}


	//List(List<T>& list):sz(list.sz)
	//{
	//	head = new Node(list.pop_back());
	//	auto it = list.begin();
	//	sz++;
	//	Node* tmp = head;
	//	for (it; it!= list.end(); ++it)
	//	{
	//		Node* curr = new Node(*it);
	//		tmp->next = curr;
	//		tmp = tmp->next;
	//		sz++;
	//	}
	//}
}