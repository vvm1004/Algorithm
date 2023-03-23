#include<iostream>
using namespace std;

/*
Nh?p danh sách queue ch?a các s? nguyên, sau dó xu?t ra màn hình các giá tr? s? nguyên dó

*/

// khai báo c?u trúc c?a 1 cái node trong queue
struct node
{
	int data; // queue dang ch?a các s? nguyên
	struct node *pNext; // con tr? liên k?t gi?a các node v?i nhau
};
typedef struct node NODE;

// khai báo c?u trúc c?a queue
struct queue
{
	NODE *pHead; //  con tr? d?u
	NODE *pTail; // con tr? cu?i 
};
typedef struct queue QUEUE;

// hàm kh?i t?o queue
void KhoiTaoQueue(QUEUE &q)
{
	q.pHead = NULL;
	q.pTail = NULL;
}

// hàm kh?i t?o 1 cái node
NODE *KhoiTaoNode(int x)
{
	NODE *p = new NODE();
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat !!!";
		return NULL;
	}
	p->data = x; // thêm giá tr? c?a bi?n x vào trong data c?a cái node
	p->pNext = NULL;
	return p;
}

// =============== KI?M TRA QUEUE CÓ R?NG HAY KHÔNG ===============
bool IsEmpty(QUEUE q)
{
	// n?u danh sách r?ng
	if (q.pHead == NULL)
	{
		return true;
	}
	return false;// danh sách có ph?n t?
}

// =============== THÊM 1 PH?N T? VÀO CU?I QUEUE- FIFO ===============
bool Push(QUEUE &q, NODE *p)
{
	if (p == NULL)
	{
		return false;
	}

	// n?u danh sách r?ng
	if (IsEmpty(q) == true)
	{
		q.pHead = q.pTail = p; // node p chính là node d?u và node cu?i
	}
	else // danh sách dã có ph?n t?
	{
		q.pTail->pNext = p; // liên k?t con tr? cu?i c?a danh sách v?i ph?n t? p c?n thêm vào
		q.pTail = p; // c?p nh?t l?i con tr? cu?i là node p
	}
	return true;
}

// =============== L?Y PH?N T? Ð?U QUEUE VÀ H?Y NÓ ÐI - FIFO ===============
bool Pop(QUEUE &q, int &x) // x chính là giá tr? c?n l?y trong node
{
	// n?u danh sách r?ng
	if (IsEmpty(q) == true)
	{
		return false;
	}
	else
	{
		NODE *p = q.pHead; // node p chính là node th? m?ng d? tí n?a chúng ta xóa nó di
		x = p->data; // gán giá tr? c?a node d?u stack vào bi?n x	
		q.pHead = q.pHead->pNext; // c?p nh?t node d?u queue là node ti?p theo	
		delete p; // xóa node d?u queue v?a l?y 

	}
	return true;// l?y ph?n t? d?u queue thành công
}


// =============== XEM THÔNG TIN C?A PH?N T? Ð?U QUEUE - KHÔNG CÓ H?Y NÓ ÐI NHÉ ===============
bool Top(QUEUE &q, int &x) // x chính là giá tr? c?n l?y ra d? xem
{
	if (IsEmpty(q) == true)
	{
		return false;
	}
	x = q.pHead->data; // l?y giá tr? c?a ph?n t? d?u queue ra d? xem
	return true;
}

// hàm xu?t danh sách queue
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

// hàm nh?p danh sách các s? nguyên trong queue
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
