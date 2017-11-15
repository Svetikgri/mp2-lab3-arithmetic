// ���������� � ���������� ���������� �����
// ���� ������������ ��������: 
// - ������� ��������, 
// - ���������� ��������, 
// - �������� �������� �������� (��� ��������)
// - �������� �� �������, 
// - ��������� ���������� ��������� � �����
// - ������� �����
// ��� ������� � ������ ���� ������ �������������� ������
#include <iostream>

using namespace std;

#ifndef _Stack_h_
#define _Stack_h_

//#define Size 25

template <class ValType>
class Stack
{
protected:
  ValType *pstack;// ������ ��� �����
  int top;//������ ���������� ��������
  int Size;//������ �����

  
public:
	Stack(int Size=25);
	~Stack();
	Stack(const Stack &st);//����������� �����������
	 void Push(const  ValType n);  //��������
	 ValType Pop();  //������� �������
	 int View();  // ��������
	 bool isfull();//�������� �� �������
	 bool isempty();// �������� �� �������
	 int Get();//�������� ���-�� ��-���
	 int GetTop();//�������� top
	 void Clean();//������� �����
	 bool operator==(const Stack &st) const;
	 Stack & operator=(const Stack &st);
};

template <class ValType>
Stack<ValType>::Stack(int Size)//�����������
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
Stack<ValType>::Stack(const Stack &st)//����������� �����������
{
	Size=st.Size;
	top=st.top;
	pstack=new ValType[Size];
	for (int i=0;i<top+1;i++)
	pstack[i]=st.pstack[i];
}

template <class ValType>
bool Stack<ValType>::isfull()// ����� ��
{
	if (top==Size)//(Size-1))
		return true;
	else 
		return false;
}

template <class ValType>
bool Stack<ValType>::isempty()// ����� ��
{
	if (top==-1)
		return true;
	else 
		return false;
}

template <class ValType>
 void Stack<ValType>::Push(const  ValType n)//��������
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
  ValType Stack<ValType>::Pop()  //������� �������
  {
	  if (!isempty())
	  {
	  return pstack[top];
	  top=top-1;
	  }
	  else throw "error";
  }

  template <class ValType>
  int Stack<ValType>::View() //��������
  {
	  if (!isempty())
	{
	  return pstack[top];
	  }
	  else throw "error";
  }

  template <class ValType>
   int Stack<ValType>::Get()//�������� ���-�� ��-���
   {
	  return top+1;   
   }

   template <class ValType>
   int Stack<ValType>::GetTop()//�������� top
   {
	  return top;   
   }

	template <class ValType>
	void Stack<ValType>::Clean()//��������
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