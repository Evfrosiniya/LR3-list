#include "LIST.h"
#include <iostream>


list::list()
{
	this->head = nullptr;
	this->len = 0;
}


list::~list()
{
	item* p = this->head;
	while (p != nullptr)
	{
		this->head = p->next;
		p->~item();
		p = this->head;
	}
}

/**
* @brief Добавление элемента
*
* @param k позиция элемента
* @param a значение элемента
*/

void list::add(size_t k, int a)
{
	if (this->len == 0)
	{
		item * p = new item(a, nullptr);
		this->head = p;
	}
	else
	{
		if (k == 1)
		{
			item * p = new item(a, this->head);
			this->head = p;
		}
		else
		{
			if (k > this->len)
			{
				item* p = this->head;
				for (unsigned int i = 1; i < this->len; i++)
				{
					p = p->next;
				}
				p->next = new item(a, nullptr);
			}
			else
			{
				item* p = this->head;
				for (unsigned int i = 1; i < k; i++)
				{
					p = p->next;
				}
				p->next = new item(a, p->next);
			}
		}
	}
	this->len++;
}

/**
* @brief Удаление элемента
*
* @param k позиция элемента
*/

void list::del(size_t k)
{
	item* p = this->head;

	if (k == 1)
	{
		this->head = p->next;
		p->~item();
	}
	else
	{
		for (unsigned int i = 2; i < k; i++)
		{
			if (p->next->next == nullptr) break;
			p = p->next;
		}
		item* t = p->next;
		p->next = t->next;
		t->~item();
	}
}

/**
* @brief Получение значения элемента
*
* @param k позиция элемента
*/

int list::get(size_t k)
{
	item* p = this->head;
	for (unsigned int i = 1; i < k; i++)
	{
		p = p->next;
	}
	return p->get();

}

/**
* @brief Печать списка
*/

void list::print()
{
	item* p = this->head;
	while (p != nullptr)
	{
		std::cout << p->get() << " ";
		p = p->next;
	}
}