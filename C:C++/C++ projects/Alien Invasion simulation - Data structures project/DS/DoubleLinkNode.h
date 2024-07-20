#pragma once

template<typename T> 
class DoubleLinkNode
{
	private:
		T item; //data item
		DoubleLinkNode<T>* next; //pointer to the next node
		DoubleLinkNode<T>* prev; //pointer to the previous node

	public:
		DoubleLinkNode();
		DoubleLinkNode(const T& r_Item);
		DoubleLinkNode(const T& r_Item, DoubleLinkNode<T>* nextNodePtr, DoubleLinkNode<T>* prevNodePtr);
		void setItem(const T& r_Item);
		void setNext(DoubleLinkNode<T>* nextNodePtr);
		void setPrev(DoubleLinkNode<T>* prevNodePtr);
		T getItem() const;
		DoubleLinkNode<T>* getPrev() const;
		DoubleLinkNode<T>* getNext() const;
};

template <typename T>
DoubleLinkNode<T>::DoubleLinkNode()
{
	next = nullptr;
	prev = nullptr;
}

template <typename T>
DoubleLinkNode<T>::DoubleLinkNode(const T& r_item)
{
	setItem(r_item);
	next = nullptr;
	prev = nullptr;
}

template <typename T>
DoubleLinkNode<T>::DoubleLinkNode(const T& r_item, DoubleLinkNode<T>* nextNodePtr, DoubleLinkNode<T>* prevNodePtr)
{
	setItem(r_item);
	setNext(nextNodePtr);
	setPrev(prevNodePtr);
}

template <typename T>
void DoubleLinkNode<T>::setItem(const T& r_item)
{
	item = r_item;
}

template <typename T>
void DoubleLinkNode<T>::setNext(DoubleLinkNode<T>* nextNodePtr)
{
	next = nextNodePtr;
}

template <typename T>
void DoubleLinkNode<T>::setPrev(DoubleLinkNode<T>* prevNodePtr)
{
	prev = prevNodePtr;
}

template <typename T>
T DoubleLinkNode<T>::getItem() const
{
	return item;
}

template <typename T>
DoubleLinkNode<T>*  DoubleLinkNode<T>::getNext() const
{
	return next;
}

template <typename T>
DoubleLinkNode<T>* DoubleLinkNode<T>::getPrev() const
{
	return prev;
}