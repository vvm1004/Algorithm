
#include<iostream>
using namespace std;
//int n = 0; // cach 2
// Nhap danh sách kiên ket don các so nguyên

// ============ KHAI BÁO CÂU TRÚC DANH SÁCH LIÊN KET ÐON ============
struct node{
	int data; //du lieu cua mot node
	struct node *pNext; //con tro lien ket giua cac node voi nhau
};
typedef struct node NODE;

// khai báo cau truc danh sach lien ket don

struct list{
	NODE *pHead;
	NODE *pTail;
};
typedef struct list LIST;

// ============ KHOI TAO CAU TRÚC DANH SÁCH LIÊN KET ÐON ===========
void KhoiTaoDSLK(LIST &l){
	// cho 2 node dau va cuoi tro den vung nho rong
	l.pHead = NULL;
	l.pTail = NULL;
}
//ham khoi tao 1 cai node
NODE *KhoiTaoNode(int x){
	
	NODE *p = new NODE;
	if(p==NULL){
		cout<<"\nKhong du bo nho de cap phat !";
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}
//// hàm thêm node p vào dau danh sách
void ThemVaoDau(LIST &l, NODE *p){
	//danh sach dang rong
	if(l.pHead==NULL){
		l.pHead= l.pTail = p;
	}
	else{
		p->pNext = l.pHead; //dung con tro cua node p lien ket voi l.pHead
		l.pHead = p;  //cap nhat lai l.pHead la p
	}
}
// hàm thêm node p vào cuoi danh sách


void ThemVaoCuoi(LIST &l, NODE *p)
{
	// danh sách dang rong
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p; // cap nhat lai l.pTail là p
	}
}

// xuat danh sách liên ket don
void XuatDanhSach(LIST l)
{
	for (NODE *k=l.pHead; k!=NULL; k=k->pNext)
	{
		cout<<k->data<<" ";
	}
}
// Thêm node p vào sau node q(nam trong danh sách liên ket don)
void ThemNode_p_VaoSauNode_q(LIST &l, NODE *p){
	int x;
	cout<<"\nNhap gia tri node q: ";
	cin>>x;
	NODE *q = KhoiTaoNode(x);
	
	//Neu danh sach chi co 1 phan tu va phan tu do cung chinh la node q ==> bai toan tro thanh ky thuat them vao cuoi danh sach
	if(q->data == l.pHead->data && l.pHead->pNext == NULL  ){
		ThemVaoCuoi(l,p);
	}else{
			//duyet tu dau den cuoi de tim node q
		for(NODE *k = l.pHead; k!=NULL; k = k->pNext){
		//Neu node q co ton tai
			if(q->data == k->data){
				NODE *h = KhoiTaoNode(p->data); //khoi tao node h moi de them vao sau node q
				NODE *g = k->pNext; //cho node g tro den node nam sau node q
				h->pNext = g; //Buoc 1 : Tao moi lien ket tu node h den node g <=> cung chinh la tao moi lien ket tu node h den node nam sau node 
				k->pNext = h;// Buoc 2: Tao moi lien ket tu node q den node h <=> cung chinh la node k den node h
			}
		}
	}

}
// Thêm node p vào truoc node q(nam trong danh sách liên ket don)
void ThemNode_p_VaoTruocNode_q(LIST &l, NODE *p){
	int x;
	cout<<"\nNhap gia tri node q: ";
	cin>>x;
	NODE *q = KhoiTaoNode(x); // khoi tao 1 node q
	//neu danh sach chi ton tai duy nhat 1 node va node nay cung chinh la node q luon - thi van de tro ve bai toan them node p vao dau danh sach
	if (q->data == l.pHead->data && l.pHead->pNext == NULL)
	{
		ThemVaoDau(l, p); // thêm node p vào d?u danh sách
	}
	else{
		
//		// ============ CÁCH 1: TRONG DANH SÁCH CHi TON TAI 1 NODE Q ============
//		NODE *g = new NODE; //node g chinh la node giu lien ket voi cai node nam truoc node q trong danh sach
//		//duyet tu dau danh sach den cuoi de tim node q
//		for(NODE *k = l.pHead; k!=NULL; k=k->pNext){
//					//	// phát hien node q có ton tai trong danh sách thì bat dau thêm node p vào truoc node q
//				if(q->data==k->data){
//					p->pNext = k; //Buoc 1: cho node p tro(liên ket) den node k <=> cung chính là cho node p tro den node q
//					g->pNext = p; // Buoc 2: cho node g tro den node p 
//				}
//				g = k;// giu liên ket voi cái node nam truoc node q trong danh sách
//
//		}
		// ============ CÁCH 2: TRONG DANH SÁCH TON TAI TU 2 NODE Q TRO LÊN ============
		NODE *g = new NODE; //node g chinh la node giu lien ket voi cai node nam truoc node q trong danh sach
		//duyet tu dau danh sach den cuoi de tim node q
		for(NODE *k = l.pHead; k!=NULL; k=k->pNext){
					//	// phát hien node q có ton tai trong danh sách thì bat dau thêm node p vào truoc node q
				if(q->data==k->data){
					NODE *h = KhoiTaoNode(p->data); // moi lan phát hien 1 node q thì ta khoi tao 1 node p moi <=> khoi tao node h
					h->pNext = k; //Buoc 1: cho node p tro(liên ket) den node k <=> cung chính là cho node p tro den node q
					g->pNext = h; // Buoc 2: cho node g tro den node p 
				}
				g = k;// giu liên ket voi cái node nam truoc node q trong danh sách

		}
	}
	
}
// CÁCH 1: 
 //hàm thêm 1 node p vào vi trí bat kì vt trong danh sách l
void ThemNode_p_VaoViTriBatKi(LIST &l, NODE *p, int vt, int n){
	//danh sach dang rong
	if(l.pHead==NULL || vt ==1){
		// thêm node p vào dau danh sách l
		ThemVaoDau(l, p);
	}
	else if(vt == n+1){
		// thêm node p vào cu?i danh sách l
		ThemVaoCuoi(l, p); 
	}
	else{
		int dem = 0; //xac dinh vt can them
		NODE *g = new NODE; //node g chinh la node giu lien ket voi cai node nam truoc node q trong danh sach
		//duyet tu dau danh sach den cuoi de tim node q
		for(NODE *k = l.pHead; k!=NULL; k=k->pNext){
			dem ++;
					//	// phát hien node q có ton tai trong danh sách thì bat dau thêm node p vào truoc node q
				if(dem==vt){
					NODE *h = KhoiTaoNode(p->data); // moi lan phát hien 1 node q thì ta khoi tao 1 node p moi <=> khoi tao node h
					h->pNext = k; //Buoc 1: cho node p tro(liên ket) den node k <=> cung chính là cho node p tro den node q
					g->pNext = h; // Buoc 2: cho node g tro den node p 
				}
				g = k;// giu liên ket voi cái node nam truoc node q trong danh sách

		}
	}
}

// CÁCH 2: dùng bien toàn cuc cho bien n
// hàm thêm 1 node p vào vi tri bat kì vt trong danh sách l
//void ThemNode_p_VaoViTriBatKi(LIST &l, NODE *p, int vt)
//{
//
//	// danh sách dang rong
//	if (l.pHead == NULL || vt == 1)
//	{
//		// thêm node p vào d?u danh sách l
//		ThemVaoDau(l, p);
//	}
//	else if (vt == n + 1)
//	{
//		// thêm node p vào cu?i danh sách l
//		ThemVaoCuoi(l, p);
//	}
//	else // vt nam trong doan [2, n]
//	{
//		int dem = 0; 
//	
//		NODE *g = new NODE;
//		
//		for (NODE *k = l.pHead; k != NULL; k = k->pNext)
//		{
//			dem++;
//			// tìm vi trí vt can thêm
//			if (dem == vt)
//			{
//				NODE *h = KhoiTaoNode(p->data); 
//
//				h->pNext = k; 
//				g->pNext = h; 
//				break;
//			}
//			g = k; 
//		}
//	}
//}
void XoaDau(LIST &l){
	//neu danh sach dang rong
	if(l.pHead==NULL){
		return;
	}
	NODE *p = l.pHead;// node p là node se xóa
	l.pHead = l.pHead->pNext;
	delete p;
}
// xóa cuoi

void XoaCuoi(LIST &l){
	//neu danh sach dang rong
	if(l.pHead==NULL){
		return;
	}
	//truong hop danh sach co phan tu
	if(l.pHead->pNext==NULL){
		XoaDau(l);
		return;
	}
	//duyet tu dau danh sach den thang ke cuoi
	for(NODE *k = l.pHead; k!=NULL; k = k->pNext){
		//phat hien thang ke cuoi
		if(k->pNext == l.pTail){
			delete l.pTail;
			k->pNext = NULL;
			l.pTail = k;
		}
	}
	
}
// hàm xóa 1 node nam sau node q trong danh sách
void XoaSauNode_q(LIST &l, NODE *q)
{
	// duyet danh sách tu dau den cuoi d? tìm node q
	for (NODE *k = l.pHead; k != NULL; k = k->pNext)
	{
		// phát hien node q
		if (k->data == q->data)
		{
			NODE *g = k->pNext; // node g chính là node n?m sau node k(nam sau node q) <=> node mà ta se xóa
			k->pNext = g->pNext; // cap nhat moi liên ket giua node k(node q) voi node sau node g 
			delete g; // xóa node nam sau node q			
		}
	}
}
// hàm xóa 1 cái node có khóa k bat kì
void XoaNodeCoKhoaBatKy(LIST &l, int x)
{
	// neu danh sách rong thì không làm gì het
	if (l.pHead == NULL)
	{
		return;
	}
	// neu node can xóa nam dau danh sách
	if (l.pHead->data == x)
	{
		XoaDau(l);
		return;
	}
	// neu node can xóa nam  cuoi danh sách
	if (l.pTail->data == x)
	{
		XoaCuoi(l);
		return;
	}

	NODE *g = new NODE; // node g là node tro den node nam truoc node can xóa: x
	// duyet danh sách liên ket don de tìm
	for (NODE *k = l.pHead; k != NULL; k = k->pNext)
	{
	
		if (k->data == x)
		{
			g->pNext = k->pNext; // cap nhat moi liên ket giua node k voi node sau node h
			delete k; // xóa node n?m sau node k	
			return;
		}
		g = k; // cho node g tr? d?n node k
	}

}
// hàm giai phóng vùng nho cho danh sách liên ket don
void Giai_Phong_Danh_Sach(LIST &l)
{
	
	//for (NODE *k = l.pHead; k != NULL; k = k->pNext)
	//{
	//	delete k; // giai phóng tung cái node trong danh sách
	//}

	NODE *k = NULL;
	while(l.pHead!=NULL){
		k = l.pHead;
		l.pHead = l.pHead->pNext;
		delete k;
	}
}
// menu
void Menu(LIST &l)
{
	int luachon;
	while (69)
	{
		system("cls");
		cout << "\n\n\t\t========== Menu ==========";
		cout << "\n\t1. Them node vao danh sach";
		cout << "\n\t2. Xuat danh sach lien ket don";
		cout << "\n\t3. Them node p vao sau node q trong danh sach";
		cout << "\n\t4. Them node p vao truoc node q trong danh sach";
		cout << "\n\t5. Them node p vao vi tri bat ki trong danh sach";
		cout << "\n\t6. Xoa dau";
		cout << "\n\t7. Xoa cuoi";
		cout << "\n\t8. Xoa node sau node q";
		cout << "\n\t9. Xoa node co khoa k bat ky";
		cout << "\n\t0. Thoat";
		cout << "\n\n\t\t========== End ===========";

		cout << "\nNhap lua chon: ";
		cin >> luachon;

		if (luachon < 0 || luachon > 9)
		{
			cout << "\nLua chon khong hop le. Xin kiem tra lai !";
			system("pause"); // dung màn hình
		}
		else if (luachon == 1)
		{
//			n++; // cách 2
			int x;
			cout << "\nNhap gia tri so nguyen: ";
			cin >> x;
			NODE *p = KhoiTaoNode(x); // khoi tao 1 cái node
			ThemVaoCuoi(l, p); // thêm node vào cu?i danh sách
		}
		else if (luachon == 2)
		{
			XuatDanhSach(l);
			system("pause");
		}
		else if (luachon == 3)
		{
			int x;
			cout << "\nNhap gia tri node p can them vao sau: ";
			cin >> x;
			NODE *p = KhoiTaoNode(x);
			ThemNode_p_VaoSauNode_q(l, p); // thêm node p vào sau node q trong danh sách l
		}
		else if (luachon == 4)
		{
			int x;
			cout << "\nNhap gia tri node p can them vao truoc: ";
			cin >> x;
			NODE *p = KhoiTaoNode(x);
			ThemNode_p_VaoTruocNode_q(l, p); // thêm node p vào tru?c node q trong danh sách l
		}
		else if (luachon == 5)
		{
			//// cách 1: 
			int n = 0;
			// vòng lap lay so luong node trong danh sách
			for (NODE *k = l.pHead; k != NULL; k = k->pNext)
			{
				n++;
			}

			// khoi tao giá tri cho node p
			int x;
			cout << "\nNhap gia tri node p: ";
			cin >> x;
			NODE *p = KhoiTaoNode(x);

			// nhap vi trí can thêm cho node p ==> can kiem tra dieu ki?en
			int vt;
			do
			{
				cout << "\nNhap vi tri can them node p: ";
				cin >> vt;
				if (vt < 1 || vt > n + 1)
				{
					cout << "\nVi tri can them phai nam trong doan[1; " << n + 1 << "]";
					system("pause");
				}
			} while (vt < 1 || vt > n + 1);

			 ThemNode_p_VaoViTriBatKi(l, p, vt, n); //CÁCH 1
//			ThemNode_p_VaoViTriBatKi(l, p, vt); // CÁCH 2
			n++;
		}
		else if (luachon == 6)
		{
			XoaDau(l);

		}
		else if (luachon == 7)
		{
			XoaCuoi(l);

		}
		else if (luachon == 8)
		{
			int x;
			cout << "\nNhap node q: ";
			cin >> x;
			NODE *q = KhoiTaoNode(x);
			XoaSauNode_q(l, q);
		}
		else if (luachon == 9)
		{
			int x;
			cout << "\nNhap node can xoa: ";
			cin >> x;
			XoaNodeCoKhoaBatKy(l, x);
		}
		else
		{
			break; // thoát khoi vòng l?p hi?n t?i
		}
	}
}
int main()
{
	LIST l;
	KhoiTaoDSLK(l); // luôn luôn goi hàm khoi tao danh sách liên ket don truoc khi thao tác voi danh sách
	Menu(l);
	
	Giai_Phong_Danh_Sach(l);

	cout << "\n\n\t\t DANH SACH LIEN KET DON \n";
	XuatDanhSach(l);

	system("pause");
	return 0;
}
