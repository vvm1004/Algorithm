#include<iostream>
using namespace std;


struct phanso
{
	int tuso;
	int mauso;
};
typedef struct phanso PHANSO;


void Nhap_Phan_So(PHANSO &ps)
{
	cout << "\nNhap tu so: ";
	cin >> ps.tuso;
	cout << "\nNhap mau so: ";
	cin >> ps.mauso;
}


void Xuat_Phan_So(PHANSO ps)
{
	cout << ps.tuso << "/" << ps.mauso;
}

struct node
{
	PHANSO data;
	node *pNext; 
};
typedef struct node NODE;

NODE *KhoiTaoNode(PHANSO ps)
{
	NODE *p = new NODE; 
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat !";
		return NULL;
	}
	p->data = ps;
	p->pNext = NULL; 
	return p;
}

void ThemDau(NODE *&pHead, NODE *p)
{
	if(pHead == NULL)
	{
		pHead = p;
	}
	else
	{
		p->pNext = pHead; 
		pHead = p; 
	}
}

void ThemCuoi(NODE *&pHead, NODE *p)
{
	if (pHead == NULL)
	{
		pHead = p;
	}
	else
	{
		for (NODE *k = pHead; ; k = k->pNext)
		{
			if (k->pNext == NULL)
			{
				k->pNext = p;
				break;
			}
		}
	}
}

void Xuat_Danh_Phan_So(NODE *pHead)
{
	for (NODE *k = pHead; k != NULL; k = k ->pNext)
	{
		Xuat_Phan_So(k->data);
		cout << endl;
	}
}

void XoaDau(NODE *&pHead)
{
	if (pHead == NULL)
	{
		return;
	}
	NODE *p = pHead;
	pHead = pHead->pNext;
	delete p; 
}

void XoaCuoi(NODE *&pHead)
{
	if (pHead == NULL)
	{
		return;
	}
	if (pHead->pNext == NULL)
	{
		NODE *p = pHead; 
		pHead = NULL;
		delete p; 
		return;
	}
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
void Them_Node_k_Sau_Node_q_Trong_Danh_Sach(NODE *&pHead, PHANSO x, NODE *q)
{
	
	for (NODE *l = pHead; l != NULL; l = l->pNext)
	{
		if (l->data.tuso == q->data.tuso && l->data.mauso == q->data.mauso)
		{
			NODE *k = KhoiTaoNode(x);
			k->pNext = l->pNext; // l->pNext chính là th?ng n?m sau node l
			l->pNext = k;
		}
	}
}

void Xoa_Node_Sau_Node_q_Trong_Danh_Sach(NODE *&pHead, NODE *q)
{

	for (NODE *l = pHead; l != NULL; l = l->pNext)
	{
		if (l->data.tuso == q->data.tuso && l->data.mauso == q->data.mauso && l->pNext != NULL)
		{
			NODE *tam = l->pNext; 
			l->pNext = l->pNext->pNext; 
			delete tam; 
		}
	}
}

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
