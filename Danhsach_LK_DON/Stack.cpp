
#include<iostream>
using namespace std;

/*
Nhap danh s�ch stack chua c�c so nguy�n, sau d� xuat ra m�n h�nh c�c gi� tri so nguy�n d�

*/

// khai b�o cau tr�c cua 1 c�i node trong stack
struct node
{
	int data; // stack dang chua c�c so nguy�n
	struct node *pNext; // con tro li�n ket giua c�c node voi nhau
};
typedef struct node NODE;

// khai b�o cau tr�c cua stack
struct stack
{
	NODE *pTop; // d�ng con tro dau de quan l� stack
};
typedef struct stack STACK;

// h�m khoi tao stack
void KhoiTaoStack(STACK &s)
{
	s.pTop = NULL;
}

// h�m khoi tao 1 c�i node
NODE *KhoiTaoNode(int x)
{
	NODE *p = new NODE();
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat !!!";
		return NULL;
	}
	p->data = x; // th�m gi� tri cua bien x v�o trong data cua c�i node
	p->pNext = NULL;
	return p;
}

// =============== KIEM TRA STACK C� RONG HAY KH�NG ===============
bool IsEmpty(STACK s)
{
	// neu danh s�ch rong
	if (s.pTop == NULL)
	{
		return true;
	}
	return false;// danh s�ch c� phan tu
}

// =============== TH�M 1 PHAN TU V�O �AU STACK- LIFO ===============
bool Push(STACK &s, NODE *p)
{
	if (p == NULL)
	{
		return false;
	}

	// neu danh s�ch rong
	if (IsEmpty(s) == true)
	{
		s.pTop = p; // node p ch�nh l� node dau stack
	}
	else // danh s�ch d� c� phan tu
	{
		p->pNext = s.pTop; // cho con tro cua node p tro den node dau danh s�ch <=> tro ki�n ket
		s.pTop = p; // cap nhat lai node dau
	}
	return true;
}

// =============== L?Y PH?N T? �?U STACK V� H?Y N� �I - LIFO ===============
bool Pop(STACK &s, int &x) // x ch�nh l� gi� tr? c?n l?y trong node
{
	// n?u danh s�ch r?ng
	if (IsEmpty(s) == true)
	{
		return false;
	}
	else
	{
		NODE *p = s.pTop; // node p ch�nh l� node th? m?ng d? t� n?a ch�ng ta x�a n� di
		x = p->data; // g�n gi� tr? c?a node d?u stack v�o bi?n x	
		s.pTop = s.pTop->pNext; // c?p nh?t node d?u stack l� node ti?p theo	
		delete p; // x�a node d?u stack v?a l?y 
		
	}
	return true;// l?y ph?n t? d?u stack th�nh c�ng
}


// =============== XEM TH�NG TIN C?A PH?N T? �?U STACK - KH�NG C� H?Y N� �I NH� ===============
bool Top(STACK &s, int &x) // x ch�nh l� gi� tr? c?n l?y ra d? xem
{
	if (IsEmpty(s) == true)
	{
		return false;
	}
	x = s.pTop->data; // l?y gi� tr? c?a ph?n t? d?u stack ra d? xem
	return true;
}

// h�m xu?t danh s�ch stack
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

// h�m nh?p danh s�ch c�c s? nguy�n trong stack
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

