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
	 int View(/*const  ValType n*/);  // ��������
	 bool isfull();//�������� �� �������
	 bool isempty();// �������� �� �������
	 int Get();//�������� ���-�� ��-���
	 void Clean();//������� �����
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
 void Stack<ValType>::Push(const  ValType n)//��������
 {
	 if (top<(Size-1))
	 {
		pstack[top+1]=n;
	 }
	 else

	
 }
 template <class ValType>
  ValType Stack<ValType>::Pop()  //������� �������
  {
	  return pstack[top];
	  top=top-1;
  }

#endif