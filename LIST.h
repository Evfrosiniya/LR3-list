/** @class list
@brief Класс, реализующий список

Содержит методы добавления элемента в определённое место списка, удаления определённого элемента, получения значения определённого элемента и вывода списка на экран
*/

#pragma once
class list
{
private:
	
	class item
	{
	private:
		int info;
	public:
		item* next;
		item(int info_, item* next_)
		{
			this->info = info_;
			this->next = next_;
		}
		~item()
		{
		}
		int get()
		{
			return this->info;
		}
	};
	unsigned int len;
	item* head;
public:
	list();
	~list();
	void add(size_t k, int a);
	void del(size_t k);
	int get(size_t k);
	void print();
};