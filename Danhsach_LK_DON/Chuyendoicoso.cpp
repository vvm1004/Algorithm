#include<iostream>
using namespace std;

/*
�?i 1 s? nguy�n sang co s? 2 8 16

*/

// khai b�o 1 c�i node
struct node
{
	int data;
	struct node *pNext;
};
typedef struct node NODE;
// khai b�o c?u tr�c c?a 1 c�i stack
struct stack
{
	NODE *pTop; // con tr? qu?n l� d?u stack
};
typedef struct stack STACK;

// h�m kh?i t?o stack
void KhoiTaoStack(STACK &s)
{
	s.pTop = NULL;
}

// h�m kh?i t?o 1 c�i node
NODE *KhoiTaoNode(int x)
{
	NODE *p = new NODE();
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat !";
		return NULL;
	}
	p->data = x; // dua d? li?u c?a bi?n x v�o trong c�i data c?a node p
	p->pNext = NULL;
	return p;
}

/* ================= KI?M TRA STACK R?NG =================*/ 
bool IsEmpty(STACK s)
{
	// n?u stack r?ng
	if (s.pTop == NULL)
	{
		return false;
	}
	return true;
}

/* ================= TH�M PH?N T? V�O �?U STACK =================*/
bool Push(STACK &s, NODE *p)
{
	// node p dang r?ng
	if (p == NULL)
	{
		return false;
	}

	// n?u danh s�ch r?ng
	if (IsEmpty(s) == false)
	{
		s.pTop = p;// node p cung ch�nh l� node pTop <=>ch�nh l� node d?u stack
	}
	else
	{
		p->pNext = s.pTop; // B1: cho con tr? c?a node p tr? d?n node pTop
		s.pTop = p;// c?p nh?t l?i node d?u ch�nh l� node p
	}
	return true;// th�m th�nh c�ng
}

/* ================= L?Y PH?N T? �?U DANH S�CH V� H?Y N� �I ================= */
bool Pop(STACK &s, int &x) // x ch�nh l� gi� tr? c?n l?y ra
{
	// n?u danh s�ch r?ng
	if (IsEmpty(s) == false)
	{
		return false; // l?y th?t b?i <=> danh s�ch dang r?ng
	}
	NODE *p = s.pTop; // g�n node d?u danh s�ch v�o node p <=> node p ch�nh l� node m� t� n?a ta s? x�a n�
	s.pTop = s.pTop->pNext; // c?p nh?t l?i node d?u 
	x = p->data; // l?y gi� tr? c?a node d?u ra g�n v�o bi?n x
	return true; // l?y ph?n t? th�nh c�ng
}

/* ================= XEM TH�NG TIN C?A NODE �?U DANH S�CH ================= */
bool Top(STACK s, int &x) // x ch�nh l� gi� tr? c?n xem
{
	// n?u danh s�ch r?ng

	if (IsEmpty(s) == false)
	{
		return false;
	}
	x = s.pTop->data;
	return true;
}

// H�M �?I CO S? 10 SANG CO S? 2 8 16
void Chuyen_So_So(STACK &s, int cosocandoi, int hethapphan)
{
	while (hethapphan != 0)
	{
		int x = hethapphan % cosocandoi;
		NODE *p = KhoiTaoNode(x); // th�m x v�o node p
		Push(s, p); // th�m node p v�o stack
		hethapphan /= cosocandoi;
	}
}

// xu?t danh s�ch stack
void XuatStack(STACK &s)
{
	while (IsEmpty(s) == true)
	{
		int x;
		Pop(s, x);
		if (x < 10)
		{
			cout << x;
		}
		else
		{
			if (x == 10)
			{
				cout << "A";
			}
			else if (x == 11)
			{
				cout << "B";
			}
			else if (x == 12)
			{
				cout << "C";
			}
			else if (x == 13)
			{
				cout << "D";
			}
			else if (x == 14)
			{
				cout << "E";
			}
			else if (x == 15)
			{
				cout << "F";
			}
			
		}
	}
}



int main()
{
	STACK s;
	KhoiTaoStack(s);
	
	int hethapphan;
	cout << "\nNhap gia tri he thap phan(10) can chuyen: ";
	cin >> hethapphan;
	int cosocandoi;
	cout << "\nNhap co so can chuyen(2, 8, 16:  ";
	cin >> cosocandoi;

	Chuyen_So_So(s, cosocandoi, hethapphan);
	cout << "\nKET QUA\n";
	XuatStack(s);
	cout << endl;

	system("pause");
	return 0;
}
