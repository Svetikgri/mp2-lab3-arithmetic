// объявление и реализация шаблонного стека
// стек поддерживает операции: 
// - вставка элемента, 
// - извлечение элемента, 
// - просмотр верхнего элемента (без удаления)
// - проверка на пустоту, 
// - получение количества элементов в стеке
// - очистка стека
// при вставке в полный стек должна перевыделяться память
#include <iostream>

using namespace std;

#ifndef _Stack_h_
#define _Stack_h_

//#define Size 25

template <class ValType>
class Stack
{
protected:
  ValType *pstack;// массив для стека
  int top;//индекс последнего занятого
  int Size;//размер стека

  
public:
	Stack(int Size=25);
	~Stack();
	Stack(const Stack &st);//конструктор копирования
	 void Push(const  ValType n);  //положить
	 ValType Pop();  //извлечь элемент
	 int View();  // просмотр
	 bool isfull();//проверка на полноту
	 bool isempty();// проверка на пустоту
	 int Get();//получить кол-во эл-тов
	 int GetTop();//получить top
	 void Clean();//очистка стека
	 bool operator==(const Stack &st) const;
	 Stack & operator=(const Stack &st);
};

template <class ValType>
Stack<ValType>::Stack(int Size)//конструктор
	{
		if(Size<0)
		throw "error";
		Size=Size;
		pstack=new ValType[Size];
		top=-1;
	}

template <class ValType>
Stack<ValType>::~Stack()
	{
		delete [] pstack;
	}

template <class ValType>
Stack<ValType>::Stack(const Stack &st)//конструктор копирования
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
	if (top==Size)//(Size-1))
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
 void Stack<ValType>::Push(const  ValType n)//положить
 {
	 if ((Size - top)==-1)//(top>(Size-1))
	 {
		 ValType* temp;
		 temp=new ValType[Size];
		 for (int i=0;i<top+1;i++)
			 temp[i]=pstack[i];
		 delete [] pstack;
		pstack=temp;
			/*new ValType[Size*2];
		for (int i=0;i<Size-1;i++)
			 pstack[i]=temp[i];*/
		
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

 template <class ValType>
  ValType Stack<ValType>::Pop()  //извлечь элемент
  {
	  if (!isempty())
	  {
	  return pstack[top];
	  top=top-1;
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
			pVector=new ValType[v.Size];
		}
		Size=v.Size;
		top=v.top;
		for(int i=0;i<top+1;i++)
			pstack[i]=v.pstack[i];
		
	}
	return *this;
	 }
#endif