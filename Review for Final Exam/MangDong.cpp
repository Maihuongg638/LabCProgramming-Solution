#include<stdio.h>
#include<stdlib.h>
void NhapMang(int *a, int n)
{
    for(int i = 0; i < n; ++i)
    {
        printf("\nNhap a[%d] = ", i);
        scanf("%d", i + a);
    }
}
void XuatMang(int *a, int n)
{
    printf("\nMang la: ");
    for(int i = 0; i < n; ++i)
    {
        printf("%4d", *(i + a));
    }
}
int main()
{
    int n = 6;
    int *a = (int *)malloc(sizeof(int) * n);
    // int *a = (int *)calloc(n, sizeof(int));
    n = 5;
    a = (int *)realloc(a, sizeof(int) * n);
    // NhapMang(a, n);
    XuatMang(a, n);

    free(a);
    
    return 0;
}