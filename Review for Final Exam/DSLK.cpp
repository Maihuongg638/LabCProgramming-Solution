#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//  1: Khai báo danh sách cấu trúc dữ liệu  liên kết các số nguyên
struct Node
{
    int data;
    struct Node *pNext;
};
typedef struct Node NODE;
//  Tạo ra danh sách đầu cuối
struct List
{
    NODE *pHead, *pTail;
};
typedef struct List LIST;
//  b2: Khởi tạo:
void Init(LIST &l)
{
    l.pHead = l.pTail = NULL;
}
// tạo ra một node vào trong danh sách liên kết
NODE* GetNode(int data)
{
    NODE *p = (NODE *)malloc(sizeof(NODE));
    if(p == NULL)
    {
        printf("\nKHong du vung nho de khoi tao Node \n");
        getch();
        return NULL;
    }
    p ->data = data;
    p ->pNext = NULL;
    return p;
}

void AddHead(LIST &l, NODE *p)
{
    if(l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }
    p->pNext = l.pHead;
    l.pHead = p;
}
void AddTail(LIST &l, NODE *p)
{
    if(l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }
    l.pTail ->pNext = p;
    l.pTail = p;
    p->pNext = NULL;
}
void Input(LIST &l)
{
    int n; 
    printf("\nNhap so luong phan tu : ");
    scanf("%d", &n);
    Init(l);
    for(int i = 1; i <= n; i++)
    {
        int data;
        printf("\nNhap du lieu thu %d = ", i);
        scanf("%d", &data);
        NODE *p = GetNode(data);
        AddTail(l, p);
    }
}
void Output(LIST l)
{
    printf("\nDanh sach la : ");
    for(NODE *p = l.pHead; p; p = p ->pNext)
    {
        printf("%4d", p ->data);
    }

    /*
    for(int i = 0; i < n; ++i)
    {
        printf("%4d", a[i]);
    }
    */
}
void GiaiPhong(LIST &l)
{
    NODE *p;
    if(l.pHead != NULL)
    {
        p= l.pHead;
        l.pHead = l.pHead ->pNext;
        delete p;
    }
}
int TimMax(LIST &l)
{
    int max = l.pHead ->data;
    for(NODE *p = l.pHead ->pNext; p; p =  p->pNext)
    {
        if(p ->data > max)
        {
            max = p ->data;
        }
    }
    return max;
}
void HoanVi(int &a, int &b)
{
    int Temp = a; 
    a = b;
    b = Temp;
}
void SapXepTangGiam(LIST &l, char phanloai)
{
    for(NODE *p = l.pHead; p != l.pTail; p= p ->pNext)
    {
        for(NODE *k = p ->pNext; k; k =  k ->pNext )
        {
            if(phanloai == 'T' || phanloai == 't')
            {
                if( p ->data > k ->data)
                {
                    HoanVi(p->data, k ->data);
                }
            }
            else if(phanloai == 'G' || phanloai == 'g')
            {
                if( p ->data < k ->data)
                {
                    HoanVi(p->data, k ->data);
                }
            }
        }
    }
}
// Thêm x  vào sau q;
void ThemNodeVaoSau1PT(LIST &l, NODE *q, NODE *x)
{
    for(NODE *p = l.pHead; p; p = p ->pNext)
    {
        if(p ->data == q ->data)
        {
            NODE *g = p ->pNext;
            x ->pNext = g;
            p ->pNext = x;
            return;
        }
    }
}
void ThemNodeVaoSauData(LIST &l, int data, NODE *p)
{
    for(NODE *k = l.pHead; k != l.pTail; k = k ->pNext)
    {
        if(k ->data == data)
        {
            NODE *NodeSau = k ->pNext;
            p ->pNext = NodeSau;
            k ->pNext = p;
            return ;
        }
    }
    if(l.pTail->data == data)
    {
        NODE *g = GetNode(data);
        AddTail(l, g);
        return;
    }
}
void ThemNodeVaoTruocData(LIST &l, int data, NODE *p)
{
    if(l.pHead->data == data)
    {
        NODE *g = GetNode(data);
        AddHead(l, g);
        return;
    }
    NODE *NodeTruoc;
    for(NODE *k = l.pHead; k; k = k ->pNext)
    {
        if(k ->data == data)
        {
            p ->pNext = k;
            NodeTruoc ->pNext = p;
            return;
        }
        NodeTruoc = k;
    }
}

void XoaDau(LIST &l)
{
    NODE *p = l.pHead;
    l.pHead = p ->pNext;
    delete p;
}
void XoaCuoi(LIST &l)
{
    NODE *NodeTruoc;
   for(NODE *p = l.pHead; p; p = p ->pNext)
    {
        if(p == l.pTail)
        {
            NodeTruoc ->pNext = NULL;
            l.pTail  = NodeTruoc;
            delete p;
            return;
        }
        NodeTruoc = p;
    }
}
void XoaNodeX(LIST &l, NODE *x)
{
    NODE *Truoc;
    for(NODE *p = l.pHead; p; p = p ->pNext)
    {
        if(p == x)
        {
            Truoc -> pNext = x;
            x -> pNext = p ->pNext;
            free(p);
            return;
        }
        Truoc = p;
    }
}
int main()
{
    LIST l;
    Input(l);
    Output(l);
    // printf("\nMAX = %d", TimMax(l));
    // // SapXepTangGiam(l, 't');
    // // Output(l);
    // // SapXepTangGiam(l, 'g');
    // NODE *q = GetNode(3);
    // NODE *x = GetNode(69);
    // // ThemNodeVaoSau1PT(l, q, x);
    // // XoaDau(l);
    // // XoaCuoi(l);
    // // AddTail(l, x);
    // // ThemNodeVaoSauData(l, 69, x);
    // ThemNodeVaoTruocData(l, 69, q);
    // Output(l);
    GiaiPhong(l);


    getch();
    return 0;
}