// объ€вление и реализаци€ шаблонного стека
// стек поддерживает операции: 
// - вставка элемента, 
// - извлечение элемента, 
// - просмотр верхнего элемента (без удалени€)
// - проверка на пустоту, 
// - получение количества элементов в стеке
// - очистка стека
// при вставке в полный стек должна перевыдел€тьс€ пам€ть
#ifndef _Stack_h_
#define _Stack_h_

#define Size 25

template <class ValType>
class Stack
{
protected:
  ValType *pstack;// массив дл€ стека
  int pos;//индекс последнего зан€того
  
public:
	Stack()
	{
		pstack=new ValType[Size];
	}
	~Stack();
	 void Put(const  ValType n);  //положить
	 void Take(const  ValType n);  //извлечь элемент
	 int Look(const  ValType n);  
	 int Check();
	 int Get();//получить кол-во эл-тов
};