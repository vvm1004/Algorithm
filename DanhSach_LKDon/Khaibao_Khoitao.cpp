// Ki thuat th�m 1 node p v�o sau node q
#include<iostream>
using namespace std;
// Nhap danh s�ch ki�n ket don c�c so nguy�n

// ============ KHAI B�O C�U TR�C DANH S�CH LI�N KET �ON ============
struct node{
	int data; //du lieu cua mot node
	struct node *pNext; //con tro lien ket giua cac node voi nhau
};
typedef struct node NODE;

// khai b�o cau truc danh sach lien ket don

struct list{
	NODE *pHead;
	NODE *pTail;
};
typedef struct list LIST;

// ============ KHOI TAO CAU TR�C DANH S�CH LI�N KET �ON ===========
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
//// h�m th�m node p v�o dau danh s�ch
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
// h�m th�m node p v�o cuoi danh s�ch

void ThemVaoCuoi(LIST &l, NODE *p){
	//danh sach dang rong
	if(l.pHead==NULL){
		l.pHead= l.pTail = p;
	}
	else{
		 l.pTail->pNext = p; // cho con tro pTail lien ket  voi node p
		l.pTail = p;  //cap nhat lai l.pTail la p
	}
}

// xuat danh s�ch li�n k?t don
void XuatDanhSach(LIST l)
{
	for (NODE *k=l.pHead; k!=NULL; k=k->pNext)
	{
		cout<<k->data<<" ";
	}
}
int TimMax(LIST l){
	int max = l.pHead->data; // gia su NODE dau la NODE lon nhat
	//bat dau duyet tu NODE thu hai de kiem tra
	for(NODE *k =l.pHead->pNext; k!=NULL; k = k->pNext){
		if(max<k->data){
			max = k->data;
		}
	}
	return max;
}
int main(){
	LIST l;
	KhoiTaoDSLK(l); //khoi tao danh sach lien ket don
	int n;
	cout<<"\nNhap so luong node can them: ";
	cin>>n;
	for(int i=1; i<=n; i++){
		int x;
		cout<<"\nNhap gia tri so nguyen: ";
		cin>>x;
		NODE *p = KhoiTaoNode(x); //khoi tao 1 cai NODE so nguyen
//		ThemVaoDau(l,p); // them node p vao dau danh sach
		ThemVaoCuoi(l,p);
	}
	XuatDanhSach(l);
	cout<<"\n\nGia tri lon nhat: "<<TimMax(l);
}
