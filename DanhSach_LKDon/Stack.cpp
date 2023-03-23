
#include<iostream>
using namespace std;


struct node
{
	int data; 
	struct node *pNext; 
};
typedef struct node NODE;


struct stack
{
	NODE *pTop;
};
typedef struct stack STACK;


void KhoiTaoStack(STACK &s)
{
	s.pTop = NULL;
}


NODE *KhoiTaoNode(int x)
{
	NODE *p = new NODE();
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat !!!";
		return NULL;
	}
	p->data = x; 
	p->pNext = NULL;
	return p;
}


bool IsEmpty(STACK s)
{

	if (s.pTop == NULL)
	{
		return true;
	}
	return false;
}


bool Push(STACK &s, NODE *p)
{
	if (p == NULL)
	{
		return false;
	}

	if (IsEmpty(s) == true)
	{
		s.pTop = p;
	}
	else 
	{
		p->pNext = s.pTop; 
		s.pTop = p; 
	}
	return true;
}


bool Pop(STACK &s, int &x) 
{

	if (IsEmpty(s) == true)
	{
		return false;
	}
	else
	{
		NODE *p = s.pTop; 
		x = p->data; 
		s.pTop = s.pTop->pNext; 	
		delete p; 
		
	}
	return true;
}


bool Top(STACK &s, int &x)
{
	if (IsEmpty(s) == true)
	{
		return false;
	}
	x = s.pTop->data;
	return true;
}


void XuatStack(STACK s)
{
	while (IsEmpty(s) == false)
	{
		int x;
		Pop(s, x);
		cout << x << " ";
	}

	if (IsEmpty(s) == true)
	{
		cout << "\nDANH SACH DANG RONG KIA";
	}
	else
	{
		cout << "\nDANH SACH DANG TON TAI PHAN TU";
	}
}


void NhapStack(STACK &s)
{
	int luachon;
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t ============== Menu ==============";
		cout << "\n\t1. Them phan tu vao stack - Push";
		cout << "\n\t2. Xuat danh sach stack ra man hinh - Pop";
		cout << "\n\t3. Xem thong tin phan tu dau stack - Top";
		cout << "\n\t0. Ket thuc";
		cout << "\n\n\t\t ============== End ==============";

		cout << "\nNhap lua chon: ";
		cin >> luachon;
		if (luachon == 1)
		{
			int x;
			cout << "\nNhap phan tu can them: ";
			cin >> x;
			NODE *p = KhoiTaoNode(x);
			Push(s, p);
		}
		else if (luachon == 2)
		{
			XuatStack(s);
			system("pause");
		}
		else if (luachon == 3)
		{
			int x;
			Top(s, x);
			cout << "\nPhan tu dau stack la: " << x;
			system("pause");
		}
		else
		{
			break;
		}
	}
}

int main()
{
	STACK s;
	KhoiTaoStack(s);

	NhapStack(s);

	system("pause");
	return 0;
}

