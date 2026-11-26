#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct{
    char hoten[30];
    int masv;
    float d1, d2, d3;
} Data;

typedef struct tagNode{
    Data infor;
    struct tagNode *link;
} Node;

typedef struct{
    Node *pHead;
    Node *pTail;
    int spt;
} LList;
/////////////////////////////////////
void initList(LList *L){
    L->pHead = NULL;
    L->pTail = NULL;
    L->spt = 0;
}
///////////////////////////////////
int emptyList(LList L)
{
    return (L.spt == 0);
}
//////////////////////////////////
Node *search(LList L, int ma){
	Node *pp = L.pHead;
	while (pp != NULL && pp->infor.masv!=ma)
	pp = pp->link;
	return pp;
}
//////////////////////////
void insert_Head(LList *L, Data x){
    Node *pp;
    pp = (Node*)malloc(sizeof(Node));
    pp->infor = x;
    pp->link = NULL;
    if (emptyList(*L))
    {
        L->pHead = pp;
        L->pTail = pp;
    }
    else
    {
        pp->link = L->pHead;
        L->pHead = pp;
    }
    L->spt++;
}
//////////////////////////////////////////////
void insert_Tail(LList *L, Data x){
    Node *pp;
    pp = (Node*)malloc(sizeof(Node));
    pp->infor = x;
    pp->link = NULL;
    if (emptyList(*L))
    {
        L->pHead = pp;
        L->pTail = pp;
    }
    else
    {
        L->pTail->link = pp;
        L->pTail = pp;
    }
    L->spt++;
}
///////////////////////////////////////////////////
void insert_After(LList *L, Data x, int masv){
    Node *p;
    Node *pp;
    p = L->pHead;
    while (p != NULL && p->infor.masv != masv)
    {
        p = p->link;
    }
    if (p == NULL)
    {
        printf("Khong tim thay sinh vien co ma %d\n", masv);
        return;
    }
    pp = (Node*)malloc(sizeof(Node));
    pp->infor = x;
    pp->link = NULL;
    pp->link = p->link;
    p->link = pp;
    if (p == L->pTail)
    {
        L->pTail = pp;
    }
    L->spt++;
}
/////////////////////////////////////////////////
void nhap(Data *x){
    printf("Nhap ma sv: ");
    scanf("%d", &(x->masv));
    if (x->masv > 0)
    {
        printf("Nhap ho ten: ");
        scanf(" %[^\n]", x->hoten);

        printf("Nhap diem mon 1: ");
        scanf("%f", &(x->d1));

        printf("Nhap diem mon 2: ");
        scanf("%f", &(x->d2));

        printf("Nhap diem mon 3: ");
        scanf("%f", &(x->d3));
    }
}
/////////////////////////////////////////////
void in(Data x){
    printf("Ten: %s, Ma: %d, Diem 1: %.2f, Diem 2: %.2f, Diem 3: %.2f\n",
           x.hoten, x.masv, x.d1, x.d2, x.d3);
}
//////////////////////////////////////////////
void processList(LList L){
    Node *pp = L.pHead;
    if (emptyList(L))
    {
        printf("Danh sach rong!\n");
        return;
    }

    printf("\n===== DANH SACH SINH VIEN =====\n");
    while (pp != NULL)
    {
        in(pp->infor);
        pp = pp->link;
    }
}
void duyetHocBong(LList L){
    Node *pp = L.pHead;
    while(pp != NULL)
    {
        float dtb = (pp->infor.d1 + pp->infor.d2 + pp->infor.d3) / 3;
        if(dtb >= 8.0)
        {
            in(pp->infor);
        }
        pp = pp->link;
    }
}
///////////////////////////////////
void delHead (LList *L){
	Node *pp;
	if(emptyList(*L)) return;
	else {
	     pp = L->pHead;
	     L->pHead = pp->link;
	     free(pp);
	     L->spt--;
	     if(L->pHead==NULL) L->pTail=NULL;
	}
}
//////////////////////////////////////
void delAfter (LList *L, Node *q) 
{
Node *pp;
if( NULL==q) return;
else {
	pp = q->link;
	if(q->link == L->pTail)
	L->pTail = q;
	q->link == pp->link;
	free(pp);
	L->spt--;
}
}
//////////////////////////////////
int main(){
    LList L;
    int kt = 0;
    int chon;
    Data x;
    initList(&L);
    do
    {
        printf(" CHUONG TRINH LAM VIEC VOI DSLK DON SV\n");
        printf("1: Them nut vao dau danh sach\n");
        printf("2: Them nut vao cuoi danh sach\n");
        printf("3: Them nut vao sau mot nut khac trong danh sach\n");
        printf("4: Xoa phan tu o dau danh sach\n");
        printf("5: Xoa phan tu o sau phan tu trong danh sach\n");
        printf("6: Duyet danh sach\n");
        printf("7: Duyet hoc bong\n");
        printf("0: Thoat\n");
        printf("Moi ban chon: ");
        scanf("%d", &chon);

        switch (chon)
        {
            case 1:
            {
                printf("Nhap thong tin SV can them\n");
                nhap(&x);
                if (x.masv > 0)
                {
                    insert_Head(&L, x);
                    printf("Da them sinh vien vao dau danh sach!\n");
                }
                break;
            }
            case 2:
            {
                printf("Nhap thong tin SV can them\n");
                nhap(&x);
                if (x.masv > 0)
                {
                    insert_Tail(&L, x);
                    printf("Da them sinh vien vao cuoi danh sach!\n");
                }
                break;
            }
            case 3:
            {
                int masv;
                printf("\n--- THEM SINH VIEN SAU MOT NODE ---\n");
                printf("Nhap ma sinh vien muon them sau: ");
                scanf("%d", &masv);
                printf("Nhap thong tin sinh vien moi:\n");
                nhap(&x);
                if (x.masv > 0)
                {
                    insert_After(&L, x, masv);
                }
                break;
            }
            case 4:
            {
                delHead(&L);
                break;	
			}
			case 5:
            {
                int masv;
                printf("Nhap ma SV phia truoc sinh vien can xoa\n ");
                scanf("%d", &masv);
                Node *q = search(L, masv);
                if (q != NULL)
                    delAfter (&L, q);
                else
                    printf("Khong tim thay sinh vien\n");
                break;
            }
            case 6:
            {
                processList(L);
                break;
            }
            case 7:
            {
            	duyetHocBong(L);
            	break;
			}
            case 0:
            {
                printf("Bye bye\n");
                kt = 1;
                break;
            }
            default:
            {
                printf("Lua chon khong hop le!\n");
                break;
            }
        }
    } 
	while (kt == 0);
    return 0;
}
