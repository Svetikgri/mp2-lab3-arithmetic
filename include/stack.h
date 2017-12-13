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
	 void Push(const  ValType& n);  //положить
	 ValType Pop();  //извлечь элемент
	 int View();  // просмотр
	 bool isfull();//проверка на полноту
	 bool isempty();// проверка на пустоту
	 int Get();//получить кол-во эл-тов
	 ValType Peek();  // ¬ернуть элемент с вершины стека без его удалени€
	 int GetTop();//получить top
	 void Clean();//очистка стека
	 bool operator==(const Stack &st) const;
	 Stack & operator=(const Stack &st);
};

template <class ValType>
Stack<ValType>::Stack(int s)//конструктор
	{
		if(s<0)
		throw "error";
		Size = s;
		pstack=new ValType[Size];
		top=-1;
	}

template <class ValType>
Stack<ValType>::~Stack()
	{
		delete [] pstack;
	}

template <class ValType>
Stack<ValType>::Stack(const Stack &st)//конструктор копировани€
{
	Size=st.Size;
	top=st.top;
	pstack=new ValType[Size];
	for (int i=0;i<top+1;i++)
	pstack[i]=st.pstack[i];
}

template <class ValType>
bool Stack<ValType>::isfull()// полон ли
{
	if (top==Size-1)
		return true;
	else 
		return false;
}

template <class ValType>
bool Stack<ValType>::isempty()// пусто ли
{
	if (top==-1)
		return true;
	else 
		return false;
}

template <class ValType>
 void Stack<ValType>::Push(const  ValType& n)//положить
 {
	 if (Size - top == 1)//(top>(Size-1))
	 {
		 ValType* temp;
		 temp=new ValType[Size * 2];
		 for (int i=0;i<top+1;i++)
			 temp[i]=pstack[i];
		 delete [] pstack;
		pstack=temp;
		
		pstack[top+1]=n;
		top++;
		Size=2*Size;
	 }
	 else
	 {
		pstack[top+1]=n;
		top++; 
	 }
 }
 template <class ValType>			                               // ¬ернуть элемент с вершины стека без его удалени€
ValType Stack<ValType>::Peek() 
{
	if (!isempty())
		return pstack[top];
	else
		throw 1;
}

 template <class ValType>
  ValType Stack<ValType>::Pop()  //извлечь элемент
  {
	  if (!isempty())
	  {
	  	  top=top-1;
		  return pstack[top + 1];
	  }
	  else throw "error";
  }

  template <class ValType>
  int Stack<ValType>::View() //просмотр
  {
	  if (!isempty())
	{
	  return pstack[top];
	  }
	  else throw "error";
  }

  template <class ValType>
   int Stack<ValType>::Get()//получить кол-во эл-тов
   {
	  return top+1;   
   }

   template <class ValType>
   int Stack<ValType>::GetTop()//получить top
   {
	  return top;   
   }

	template <class ValType>
	void Stack<ValType>::Clean()//очистить
	{
		top=-1;
	}
	
	template <class ValType>
	 bool Stack<ValType>::operator==(const Stack &v) const
	 {
		 if (this == &v)
		return true;
	if(( Size != v.Size)||(top != v.top))
		return false;
	for (int i=0;i<top+1;i++)
		if (pstack[i] != v.pstack[i])
			return false;
	return true;
	 }

	 template <class ValType>
	 Stack<ValType> & Stack<ValType>::operator=(const Stack &v)
	 {
		 if (this != &v)
	{
		if (Size != v.Size)
		{
			delete[] pstack;
			pstack=new ValType[v.Size];
		}
		Size=v.Size;
		top=v.top;
		for(int i=0;i<top+1;i++)
			pstack[i]=v.pstack[i];
		
	}
	return *this;
	 }
#endif