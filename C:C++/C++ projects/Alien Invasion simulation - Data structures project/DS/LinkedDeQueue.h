#pragma once
#include "DoubleLinkNode.h"


template <typename T>
class LinkedDeQueue
{
	private:
		DoubleLinkNode<T>* frontPtr;
		DoubleLinkNode<T>* backPtr;

	public:
		LinkedDeQueue();
		bool isEmpty() const;
		bool enqueue_front(const T& newEntry);
		bool dequeue_front(T& frntEntry);
		bool enqueue_rear(const T& newEntry);
		bool dequeue_rear(T& backEntry);
		bool peek_front(T& frntEntry)  const;
		bool peek_rear(T& backEntry) const;
		~LinkedDeQueue();

		//copy constructor
		LinkedDeQueue(const LinkedDeQueue<T>& LQ);

};


template <typename T>
LinkedDeQueue<T>::LinkedDeQueue()
{
	backPtr = nullptr;
	frontPtr = nullptr;

}

template <typename T>
bool LinkedDeQueue<T>::isEmpty() const
{
	return (frontPtr == nullptr) && (frontPtr == backPtr) ;
}

template <typename T>
bool LinkedDeQueue<T>::enqueue_front(const T& newEntry)
{
	DoubleLinkNode<T>* newNodePtr = new DoubleLinkNode<T>(newEntry);
	// Insert the new node
	if (isEmpty())	//special case if this is the first node to insert
	{
		frontPtr = newNodePtr;
		backPtr = newNodePtr;
	}
	else
	{
		newNodePtr->setNext(frontPtr);
		frontPtr->setPrev(newNodePtr);
		frontPtr = newNodePtr;
	}
	return true;
} 

template <typename T> 
bool LinkedDeQueue<T> ::dequeue_front(T& frntEntry)
{
	if (isEmpty())
		return false;

	DoubleLinkNode<T>* nodetoDeletePtr = frontPtr;
	frntEntry = frontPtr->getItem();
	frontPtr = frontPtr->getNext();

	if (nodetoDeletePtr == backPtr)	 // Special case: last node in the queue
	{
		backPtr = nullptr;
		frontPtr = nullptr;
	}
	else
	{
		frontPtr->setPrev(nullptr);
	}
	delete nodetoDeletePtr;

	return true;
}

template <typename T> 
bool LinkedDeQueue<T> ::enqueue_rear(const T& newEntry)
{
	DoubleLinkNode<T>* newNodePtr = new DoubleLinkNode<T>(newEntry);

	if (isEmpty()) //special case if this is the first node to insert 
	{
		frontPtr = newNodePtr;
		backPtr = newNodePtr;
	}
	else
	{
		newNodePtr->setPrev(backPtr);
		backPtr->setNext(newNodePtr);
		backPtr = newNodePtr;
	}

	return true;
}

template <typename T>
bool LinkedDeQueue<T> :: dequeue_rear(T& newEntry)
{
	if (isEmpty())
		return false;

	DoubleLinkNode<T>* nodetoDeletePtr = backPtr;

	newEntry = backPtr->getItem();
	backPtr = backPtr->getPrev();

	if (nodetoDeletePtr == frontPtr) //special case: last node in the queue
	{
		frontPtr = nullptr;
		backPtr = nullptr;
	}
	else
	{
		backPtr->setNext(nullptr);
	}

	delete nodetoDeletePtr;

	return true;
}

template <typename T> 
bool LinkedDeQueue<T> :: peek_front(T& frntEntry)  const
{
	if (isEmpty())
		return false;

	frntEntry = frontPtr->getItem();
	return true;
}

template <typename T>
bool LinkedDeQueue<T> ::peek_rear(T& backEntry) const
{
	if (isEmpty())
		return false;

	backEntry = backPtr->getItem();
	return true;
}

template <typename T>
LinkedDeQueue<T>:: ~LinkedDeQueue()
{
	T temp;
	while (dequeue_front(temp));
}

//copy constructor
template <typename T>
LinkedDeQueue<T>::LinkedDeQueue(const LinkedDeQueue<T>& LQ)
{
	frontPtr = nullptr;
	backPtr = nullptr;

	DoubleLinkNode<T>* NodePtr = LQ.frontPtr;

	while (NodePtr)
	{
		enqueue_front(NodePtr->getItem());
		NodePtr = NodePtr->getNext();
	}
}