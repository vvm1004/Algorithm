
#include<iostream>
using namespace std;

/*
Nhap danh sách stack chua các so nguyên, sau dó xuat ra màn hình các giá tri so nguyên dó

*/

// khai báo cau trúc cua 1 cái node trong stack
struct node
{
	int data; // stack dang chua các so nguyên
	struct node *pNext; // con tro liên ket giua các node voi nhau
};
typedef struct node NODE;

// khai báo cau trúc cua stack
struct stack
{
	NODE *pTop; // dùng con tro dau de quan lí stack
};
typedef struct stack STACK;

// hàm khoi tao stack
void KhoiTaoStack(STACK &s)
{
	s.pTop = NULL;
}

// hàm khoi tao 1 cái node
NODE *KhoiTaoNode(int x)
{
	NODE *p = new NODE();
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat !!!";
		return NULL;
	}
	p->data = x; // thêm giá tri cua bien x vào trong data cua cái node
	p->pNext = NULL;
	return p;
}

// =============== KIEM TRA STACK CÓ RONG HAY KHÔNG ===============
bool IsEmpty(STACK s)
{
	// neu danh sách rong
	if (s.pTop == NULL)
	{
		return true;
	}
	return false;// danh sách có phan tu
}

// =============== THÊM 1 PHAN TU VÀO ÐAU STACK- LIFO ===============
bool Push(STACK &s, NODE *p)
{
	if (p == NULL)
	{
		return false;
	}

	// neu danh sách rong
	if (IsEmpty(s) == true)
	{
		s.pTop = p; // node p chính là node dau stack
	}
	else // danh sách dã có phan tu
	{
		p->pNext = s.pTop; // cho con tro cua node p tro den node dau danh sách <=> tro kiên ket
		s.pTop = p; // cap nhat lai node dau
	}
	return true;
}

// =============== L?Y PH?N T? Ð?U STACK VÀ H?Y NÓ ÐI - LIFO ===============
bool Pop(STACK &s, int &x) // x chính là giá tr? c?n l?y trong node
{
	// n?u danh sách r?ng
	if (IsEmpty(s) == true)
	{
		return false;
	}
	else
	{
		NODE *p = s.pTop; // node p chính là node th? m?ng d? tí n?a chúng ta xóa nó di
		x = p->data; // gán giá tr? c?a node d?u stack vào bi?n x	
		s.pTop = s.pTop->pNext; // c?p nh?t node d?u stack là node ti?p theo	
		delete p; // xóa node d?u stack v?a l?y 
		
	}
	return true;// l?y ph?n t? d?u stack thành công
}


// =============== XEM THÔNG TIN C?A PH?N T? Ð?U STACK - KHÔNG CÓ H?Y NÓ ÐI NHÉ ===============
bool Top(STACK &s, int &x) // x chính là giá tr? c?n l?y ra d? xem
{
	if (IsEmpty(s) == true)
	{
		return false;
	}
	x = s.pTop->data; // l?y giá tr? c?a ph?n t? d?u stack ra d? xem
	return true;
}

// hàm xu?t danh sách stack
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

// hàm nh?p danh sách các s? nguyên trong stack
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

