#pragma once

template <class T>
class ListItem
{
public:
	T key;
	ListItem* next;
};

template <class T>
class LinkedList
{
public:
	ListItem<T>* head;
	ListItem<T>* tail;

	void append(ListItem<T>* item)
	{
		tail->next = item;
		tail = item;
	}

	void append(T key)
	{
		ListItem<T>* item = new ListItem();
		item->key = key;

		this->append(item);
	}
};