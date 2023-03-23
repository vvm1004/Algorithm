#include<iostream>
using namespace std;

// Nh?p danh s�ch li�n k?t don c�c ph�n s?
// khai b�o c?u tr�c 1 c�i ph�n
struct phanso
{
	int tuso;
	int mauso;
};
typedef struct phanso PHANSO;


// nh?p ph�n s?
void Nhap_Phan_So(PHANSO &ps)
{
	cout << "\nNhap tu so: ";
	cin >> ps.tuso;
	cout << "\nNhap mau so: ";
	cin >> ps.mauso;
}

// h�m xu?t ph�n s?
void Xuat_Phan_So(PHANSO ps)
{
	cout << ps.tuso << "/" << ps.mauso;
}

// khai b�o c?u tr�c 1 c�i node
struct node
{
	PHANSO data; // th�nh ph?n d? li?u c?a 1 c�i node
	node *pNext; // con tr? d�ng d? gi? d?a ch? c?a c�i node m� n� mu?n li�n k?t d?n
};
typedef struct node NODE;

// h�m kh?i t?o 1 c�i node 
NODE *KhoiTaoNode(PHANSO ps)
{
	NODE *p = new NODE; // Kh?i t?o v�ng nh? cho c�i node chu?n b? th�m v�o danh s�ch
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat !";
		return NULL;
	}
	p->data = ps; // truy?n gi� tr? ps v�o cho c�i data c?a c�i node p
	p->pNext = NULL; // chua li�n k?t d?n th?ng n�o h?t
	return p;
}

// h�m th�m 1 c�i node p v�o d?u danh s�ch
void ThemDau(NODE *&pHead, NODE *p)
{
	// n?u danh s�ch r?ng
	if(pHead == NULL)
	{
		pHead = p;
	}
	else
	{
		p->pNext = pHead; // cho node p c?nh th�m k?t n?i d?n th?ng d?u danh s�ch
		pHead = p; // c?p nh?t l?i node d?u ch�nh l� node v?a th�m v�o
	}
}

// h�m th�m 1 c�i node p cu?i danh s�ch
void ThemCuoi(NODE *&pHead, NODE *p)
{
	// n?u danh s�ch r?ng
	if (pHead == NULL)
	{
		pHead = p;
	}
	else
	{
		for (NODE *k = pHead; ; k = k->pNext)
		{
			// n?u c�i th?ng dang x�t m� c�i pNext b�n trong n� dang li�n k?t d?n NULL ==> k ch�nh l� node cu?i danh s�ch
			if (k->pNext == NULL)
			{
				k->pNext = p;
				break;
			}
		}
	}
}

// h�m xu?t danh s�ch c�c ph�n s?
void Xuat_Danh_Phan_So(NODE *pHead)
{
	for (NODE *k = pHead; k != NULL; k = k ->pNext)
	{
		Xuat_Phan_So(k->data);
		cout << endl;
	}
}

// h�m x�a node d?u danh s�ch
void XoaDau(NODE *&pHead)
{
	// danh s�ch dang r?ng
	if (pHead == NULL)
	{
		return;
	}
	NODE *p = pHead; // node p l� node th? m?ng gi? th?ng d?u danh s�ch th�ng qua vi?c tr? d?n th?ng pHead
	pHead = pHead->pNext;
	delete p; // x�a di th?ng p cung ch�nh l� x�a di th?ng d?u danh s�ch
}

// h�m x�a node cu?i danh s�ch
void XoaCuoi(NODE *&pHead)
{
	// danh s�ch dang r?ng
	if (pHead == NULL)
	{
		return;
	}
	// n?u danh s�ch t?n t?i 1 c� node
	if (pHead->pNext == NULL)
	{
		NODE *p = pHead; // node p l� node th? m?ng gi? th?ng d?u danh s�ch th�ng qua vi?c tr? d?n th?ng pHead
		pHead = NULL;
		delete p; // x�a di th?ng p cung ch�nh l� x�a di th?ng d?u danh s�ch
		return;
	}
	// di ki?m c�i NODE cu?i
	for (NODE *k = pHead; ;k = k->pNext)
	{
		if (k->pNext->pNext == NULL)
		{
			delete k->pNext;
			k->pNext = NULL;
			break;
		}
	}
}
// h�m th�m 1 NODE k v�o sau NODE q trong dannh s�ch - NODE q ph?i t?n t?i th� m?i th�m
void Them_Node_k_Sau_Node_q_Trong_Danh_Sach(NODE *&pHead, PHANSO x, NODE *q)
{
	
	// duy?t danh s�ch d? ki?m tra xem c� t?n t?i node q hay kh�ng
	for (NODE *l = pHead; l != NULL; l = l->pNext)
	{
		if (l->data.tuso == q->data.tuso && l->data.mauso == q->data.mauso)
		{
			NODE *k = KhoiTaoNode(x);
			// BU?C 1: l?y node k li�n k?t d?n node n?m sau node l
			k->pNext = l->pNext; // l->pNext ch�nh l� th?ng n?m sau node l
			// BU?C 2: l?y th?ng l k?t n?i v?i node k c?n th�m v�o sau node l
			l->pNext = k;
		}
	}
}

// h�m x�a 1 NODE k sau NODE q trong dannh s�ch - NODE q ph?i t?n t?i th� m?i x�a sau
void Xoa_Node_Sau_Node_q_Trong_Danh_Sach(NODE *&pHead, NODE *q)
{

	// duy?t danh s�ch d? ki?m tra xem c� t?n t?i node q hay kh�ng
	for (NODE *l = pHead; l != NULL; l = l->pNext)
	{
		if (l->data.tuso == q->data.tuso && l->data.mauso == q->data.mauso && l->pNext != NULL)
		{
			NODE *tam = l->pNext; // Bu?c 1: nh? th?ng tam gi? d�m d?a ch? c?a th?ng n?m sau node l
			l->pNext = l->pNext->pNext; // Bu?c 2: cho node l li�n k?t d?n node n?m sau node c?n x�a
			delete tam; // Bu?c 3: x�a di th?ng tam <=> x�a di th?ng n?m sau node l
		}
	}
}

// thi?t k? menu thao t�c tr�n danh s�ch li�n k?t don
void Menu(NODE *&pHead)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t ======== QUAN LY DANH SACH PHAN SO ========\n";
		cout << "\n1. Nhap phan so";
		cout << "\n2. Xuat danh sach phan so";
		cout << "\n3. Xoa dau danh sach";
		cout << "\n4. Xoa cuoi danh sach";
		cout << "\n5. Them NODE k sau NODE q trong danh sach";
		cout << "\n6. Xoa 1 cai NODE sau NODE q trong danh sach";
		cout << "\n0. Ket thuc";
		cout << "\n\n\t\t =================== END  ==================\n";

		int luachon;
		cout << "\nNhap lua chon: ";
		cin >> luachon;

		if (luachon == 1)
		{
			PHANSO ps;
			cout << "\n\n\t\t NHAP PHAN SO\n";
			Nhap_Phan_So(ps);

			NODE *p = KhoiTaoNode(ps);
			//ThemDau(pHead, p);
			ThemCuoi(pHead, p);
		}
		else if (luachon == 2)
		{
			cout << "\n\n\t\t DANH SACH PHAN SO\n";
			Xuat_Danh_Phan_So(pHead);
			system("pause");
		}
		else if (luachon == 3)
		{
			XoaDau(pHead);
		}
		else if (luachon == 4)
		{
			XoaCuoi(pHead);
		}
		else if (luachon == 5)
		{
			PHANSO x;
			cout << "\nNhap gia tri phan so cho NODE K can them: ";
			Nhap_Phan_So(x);
			PHANSO y;
			cout << "\nNhap gia tri phan so cho NODE q can kiem tra: ";
			Nhap_Phan_So(y);
			NODE *q = KhoiTaoNode(y);
			Them_Node_k_Sau_Node_q_Trong_Danh_Sach(pHead, x, q);
		}
		else if (luachon == 6)
		{
			PHANSO y;
			cout << "\nNhap gia tri phan so cho NODE q can kiem tra: ";
			Nhap_Phan_So(y);
			NODE *q = KhoiTaoNode(y);
			Xoa_Node_Sau_Node_q_Trong_Danh_Sach(pHead, q);
		}
		else
		{
			break;
		}

	}
}

int main()
{
	NODE *pHead = NULL;
	Menu(pHead);
	system("pause");
	return 0;
}
