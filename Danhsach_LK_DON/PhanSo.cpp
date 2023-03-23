#include<iostream>
using namespace std;

// Nh?p danh sách liên k?t don các phân s?
// khai báo c?u trúc 1 cái phân
struct phanso
{
	int tuso;
	int mauso;
};
typedef struct phanso PHANSO;


// nh?p phân s?
void Nhap_Phan_So(PHANSO &ps)
{
	cout << "\nNhap tu so: ";
	cin >> ps.tuso;
	cout << "\nNhap mau so: ";
	cin >> ps.mauso;
}

// hàm xu?t phân s?
void Xuat_Phan_So(PHANSO ps)
{
	cout << ps.tuso << "/" << ps.mauso;
}

// khai báo c?u trúc 1 cái node
struct node
{
	PHANSO data; // thành ph?n d? li?u c?a 1 cái node
	node *pNext; // con tr? dùng d? gi? d?a ch? c?a cái node mà nó mu?n liên k?t d?n
};
typedef struct node NODE;

// hàm kh?i t?o 1 cái node 
NODE *KhoiTaoNode(PHANSO ps)
{
	NODE *p = new NODE; // Kh?i t?o vùng nh? cho cái node chu?n b? thêm vào danh sách
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat !";
		return NULL;
	}
	p->data = ps; // truy?n giá tr? ps vào cho cái data c?a cái node p
	p->pNext = NULL; // chua liên k?t d?n th?ng nào h?t
	return p;
}

// hàm thêm 1 cái node p vào d?u danh sách
void ThemDau(NODE *&pHead, NODE *p)
{
	// n?u danh sách r?ng
	if(pHead == NULL)
	{
		pHead = p;
	}
	else
	{
		p->pNext = pHead; // cho node p c?nh thêm k?t n?i d?n th?ng d?u danh sách
		pHead = p; // c?p nh?t l?i node d?u chính là node v?a thêm vào
	}
}

// hàm thêm 1 cái node p cu?i danh sách
void ThemCuoi(NODE *&pHead, NODE *p)
{
	// n?u danh sách r?ng
	if (pHead == NULL)
	{
		pHead = p;
	}
	else
	{
		for (NODE *k = pHead; ; k = k->pNext)
		{
			// n?u cái th?ng dang xét mà cái pNext bên trong nó dang liên k?t d?n NULL ==> k chính là node cu?i danh sách
			if (k->pNext == NULL)
			{
				k->pNext = p;
				break;
			}
		}
	}
}

// hàm xu?t danh sách các phân s?
void Xuat_Danh_Phan_So(NODE *pHead)
{
	for (NODE *k = pHead; k != NULL; k = k ->pNext)
	{
		Xuat_Phan_So(k->data);
		cout << endl;
	}
}

// hàm xóa node d?u danh sách
void XoaDau(NODE *&pHead)
{
	// danh sách dang r?ng
	if (pHead == NULL)
	{
		return;
	}
	NODE *p = pHead; // node p là node th? m?ng gi? th?ng d?u danh sách thông qua vi?c tr? d?n th?ng pHead
	pHead = pHead->pNext;
	delete p; // xóa di th?ng p cung chính là xóa di th?ng d?u danh sách
}

// hàm xóa node cu?i danh sách
void XoaCuoi(NODE *&pHead)
{
	// danh sách dang r?ng
	if (pHead == NULL)
	{
		return;
	}
	// n?u danh sách t?n t?i 1 cá node
	if (pHead->pNext == NULL)
	{
		NODE *p = pHead; // node p là node th? m?ng gi? th?ng d?u danh sách thông qua vi?c tr? d?n th?ng pHead
		pHead = NULL;
		delete p; // xóa di th?ng p cung chính là xóa di th?ng d?u danh sách
		return;
	}
	// di ki?m cái NODE cu?i
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
// hàm thêm 1 NODE k vào sau NODE q trong dannh sách - NODE q ph?i t?n t?i thì m?i thêm
void Them_Node_k_Sau_Node_q_Trong_Danh_Sach(NODE *&pHead, PHANSO x, NODE *q)
{
	
	// duy?t danh sách d? ki?m tra xem có t?n t?i node q hay không
	for (NODE *l = pHead; l != NULL; l = l->pNext)
	{
		if (l->data.tuso == q->data.tuso && l->data.mauso == q->data.mauso)
		{
			NODE *k = KhoiTaoNode(x);
			// BU?C 1: l?y node k liên k?t d?n node n?m sau node l
			k->pNext = l->pNext; // l->pNext chính là th?ng n?m sau node l
			// BU?C 2: l?y th?ng l k?t n?i v?i node k c?n thêm vào sau node l
			l->pNext = k;
		}
	}
}

// hàm xóa 1 NODE k sau NODE q trong dannh sách - NODE q ph?i t?n t?i thì m?i xóa sau
void Xoa_Node_Sau_Node_q_Trong_Danh_Sach(NODE *&pHead, NODE *q)
{

	// duy?t danh sách d? ki?m tra xem có t?n t?i node q hay không
	for (NODE *l = pHead; l != NULL; l = l->pNext)
	{
		if (l->data.tuso == q->data.tuso && l->data.mauso == q->data.mauso && l->pNext != NULL)
		{
			NODE *tam = l->pNext; // Bu?c 1: nh? th?ng tam gi? dùm d?a ch? c?a th?ng n?m sau node l
			l->pNext = l->pNext->pNext; // Bu?c 2: cho node l liên k?t d?n node n?m sau node c?n xóa
			delete tam; // Bu?c 3: xóa di th?ng tam <=> xóa di th?ng n?m sau node l
		}
	}
}

// thi?t k? menu thao tác trên danh sách liên k?t don
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
