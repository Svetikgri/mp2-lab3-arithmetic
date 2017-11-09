// объ€вление и реализаци€ шаблонного стека
// стек поддерживает операции: 
// - вставка элемента, 
// - извлечение элемента, 
// - просмотр верхнего элемента (без удалени€)
// - проверка на пустоту, 
// - получение количества элементов в стеке
// - очистка стека
// при вставке в полный стек должна перевыдел€тьс€ пам€ть
#include <iostream>

using namespace std;

#ifndef _Stack_h_
#define _Stack_h_

//#define Size 25

template <class ValType>
class Stack
{
protected:
  ValType *pstack;// массив дл€ стека
  int top;//индекс последнего зан€того
  int Size;//размер стека

  
public:
	Stack(int Size=25);
	~Stack();
	Stack(const Stack &st);//конструктор копировани€
	 void Push(const  ValType n);  //положить
	 ValType Pop();  //извлечь элемент
	 int View(/*const  ValType n*/);  // просмотр
	 bool isfull();//проверка на полноту
	 bool isempty();// проверка на пустоту
	 int Get();//получить кол-во эл-тов
	 void Clean();//очистка стека
};
template <class ValType>
Stack<ValType>::Stack(int Size)
	{
		pstack=new ValType[Size];
		top=-1;
	}

template <class ValType>
Stack<ValType>::~Stack()
	{
		delete [] pstack;
	}
template <class ValType>
Stack<ValType>::Stack(const Stack &st)
{
	Size=st.Size;
	top=st.top;
	pstack=new ValType[Size];
	for (int i=0;i<top;i++)
	pstack[i]=st.pstack[i];
}
template <class ValType>
bool Stack<ValType>::isfull()
{
	if (top==(Size-1))
		return true;
	else 
		return false;
}

template <class ValType>
bool Stack<ValType>::isempty()
{
	if (top==-1)
		return true;
	else 
		return false;
}
template <class ValType>
 void Stack<ValType>::Push(const  ValType n)//положить
 {
	 if (top<(Size-1))
	 {
		pstack[top+1]=n;
	 }
	 else

	
 }
 template <class ValType>
  ValType Stack<ValType>::Pop()  //извлечь элемент
  {
	  return pstack[top];
	  top=top-1;
  }

#endif