#include<iostream>
using namespace std;

/*
Nh?p danh s�ch queue ch?a c�c s? nguy�n, sau d� xu?t ra m�n h�nh c�c gi� tr? s? nguy�n d�

*/

// khai b�o c?u tr�c c?a 1 c�i node trong queue
struct node
{
	int data; // queue dang ch?a c�c s? nguy�n
	struct node *pNext; // con tr? li�n k?t gi?a c�c node v?i nhau
};
typedef struct node NODE;

// khai b�o c?u tr�c c?a queue
struct queue
{
	NODE *pHead; //  con tr? d?u
	NODE *pTail; // con tr? cu?i 
};
typedef struct queue QUEUE;

// h�m kh?i t?o queue
void KhoiTaoQueue(QUEUE &q)
{
	q.pHead = NULL;
	q.pTail = NULL;
}

// h�m kh?i t?o 1 c�i node
NODE *KhoiTaoNode(int x)
{
	NODE *p = new NODE();
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat !!!";
		return NULL;
	}
	p->data = x; // th�m gi� tr? c?a bi?n x v�o trong data c?a c�i node
	p->pNext = NULL;
	return p;
}

// =============== KI?M TRA QUEUE C� R?NG HAY KH�NG ===============
bool IsEmpty(QUEUE q)
{
	// n?u danh s�ch r?ng
	if (q.pHead == NULL)
	{
		return true;
	}
	return false;// danh s�ch c� ph?n t?
}

// =============== TH�M 1 PH?N T? V�O CU?I QUEUE- FIFO ===============
bool Push(QUEUE &q, NODE *p)
{
	if (p == NULL)
	{
		return false;
	}

	// n?u danh s�ch r?ng
	if (IsEmpty(q) == true)
	{
		q.pHead = q.pTail = p; // node p ch�nh l� node d?u v� node cu?i
	}
	else // danh s�ch d� c� ph?n t?
	{
		q.pTail->pNext = p; // li�n k?t con tr? cu?i c?a danh s�ch v?i ph?n t? p c?n th�m v�o
		q.pTail = p; // c?p nh?t l?i con tr? cu?i l� node p
	}
	return true;
}

// =============== L?Y PH?N T? �?U QUEUE V� H?Y N� �I - FIFO ===============
bool Pop(QUEUE &q, int &x) // x ch�nh l� gi� tr? c?n l?y trong node
{
	// n?u danh s�ch r?ng
	if (IsEmpty(q) == true)
	{
		return false;
	}
	else
	{
		NODE *p = q.pHead; // node p ch�nh l� node th? m?ng d? t� n?a ch�ng ta x�a n� di
		x = p->data; // g�n gi� tr? c?a node d?u stack v�o bi?n x	
		q.pHead = q.pHead->pNext; // c?p nh?t node d?u queue l� node ti?p theo	
		delete p; // x�a node d?u queue v?a l?y 

	}
	return true;// l?y ph?n t? d?u queue th�nh c�ng
}


// =============== XEM TH�NG TIN C?A PH?N T? �?U QUEUE - KH�NG C� H?Y N� �I NH� ===============
bool Top(QUEUE &q, int &x) // x ch�nh l� gi� tr? c?n l?y ra d? xem
{
	if (IsEmpty(q) == true)
	{
		return false;
	}
	x = q.pHead->data; // l?y gi� tr? c?a ph?n t? d?u queue ra d? xem
	return true;
}

// h�m xu?t danh s�ch queue
void XuatQueue(QUEUE q)
{
	while (IsEmpty(q) == false)
	{
		int x;
		Pop(q, x);
		cout << x << " ";
	}

	if (IsEmpty(q) == true)
	{
		cout << "\nDANH SACH DANG RONG KIA";
	}
	else
	{
		cout << "\nDANH SACH DANG TON TAI PHAN TU";
	}
}

// h�m nh?p danh s�ch c�c s? nguy�n trong queue
void NhapQueue(QUEUE &q)
{
	int luachon;
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t ============== Menu ==============";
		cout << "\n\t1. Them phan tu vao queue - Push";
		cout << "\n\t2. Xuat danh sach queue ra man hinh - Pop";
		cout << "\n\t3. Xem thong tin phan tu dau queue - Top";
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
			Push(q, p);
		}
		else if (luachon == 2)
		{
			XuatQueue(q);
			system("pause");
		}
		else if (luachon == 3)
		{
			int x;
			Top(q, x);
			cout << "\nPhan tu dau queue la: " << x;
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
	QUEUE q;
	KhoiTaoQueue(q);

	NhapQueue(q);

	system("pause");
	return 0;
}
