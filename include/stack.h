// ���������� � ���������� ���������� �����
// ���� ������������ ��������: 
// - ������� ��������, 
// - ���������� ��������, 
// - �������� �������� �������� (��� ��������)
// - �������� �� �������, 
// - ��������� ���������� ��������� � �����
// - ������� �����
// ��� ������� � ������ ���� ������ �������������� ������
#ifndef _Stack_h_
#define _Stack_h_

#define Size 25

template <class ValType>
class Stack
{
protected:
  ValType *pstack;// ������ ��� �����
  int pos;//������ ���������� ��������
  
public:
	Stack()
	{
		pstack=new ValType[Size];
	}
	~Stack();
	 void Put(const  ValType n);  //��������
	 void Take(const  ValType n);  //������� �������
	 int Look(const  ValType n);  
	 int Check();
	 int Get();//�������� ���-�� ��-���
};