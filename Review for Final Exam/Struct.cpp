#include<stdio.h>
struct PhanSo
{
    int TuSo, MauSo;
};
typedef struct PhanSo PHANSO;

void NhapPhanSo(PHANSO *ps){
    printf("\nNhap tu so : ");
    scanf("%d", &(ps->TuSo));
    NhapMau:
        printf("\nNhap mau so : ");
        scanf("%d", &(ps->MauSo));
        if(ps->MauSo == 0)
        {
            printf("\nMau so phai khac 0. Xin kiem tra va nhap lai!!!");
            goto NhapMau;
        }
}
void XuatPhanSo(PHANSO ps)
{+
    printf("\nPhan so la : %d/ %d", ps.TuSo, ps.MauSo);
}

int UCLN(int a, int b)
{
    int max = a > b ? a : b;
    int min = a < b ? a : b;
    if(max % min == 0)
        return min;
    for(int i = min - 1; i >= 2; --i)
    {
        if(max % i == 0 && min % i == 0)
            return i;
    }
    return 1;
}
PHANSO Cong2PS(PHANSO a, PHANSO b)
{
    PHANSO kq;
    kq.MauSo =  a.MauSo * b.MauSo / UCLN(a.MauSo, b.MauSo);
    int temp = kq.MauSo /a.MauSo;
    kq.TuSo = temp * a.TuSo;
    temp = kq.MauSo /b.MauSo;
    kq.TuSo += temp * b.TuSo;

    return kq;
}
int main()
{
    PHANSO ps1, ps2;
    NhapPhanSo(&ps1);
    XuatPhanSo(ps1);
    NhapPhanSo(&ps2);
    XuatPhanSo(ps2);
    XuatPhanSo(Cong2PS(ps1, ps2));
    
    return 0;
}