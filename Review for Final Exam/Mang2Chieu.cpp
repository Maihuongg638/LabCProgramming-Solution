#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define MAX 10

void NhapKichThuoc(int *a, char *s)
{
    do
    {
        printf("\nNhap so luong %s : ", s);
        scanf("%d", a);
        if(*a < 0 || *a > MAX)
            printf("\nSo luong pt %s k hop le. Xin kiem tra nhap lai!!!", s);
    } while (*a < 0 || *a > MAX);
}
void NhapMang(int a[][MAX], int row, int col )
{
    for(int i = 0; i < row; ++i)
    {
        for(int j = 0; j < col; ++j)
        {
            printf("\nNhap a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

void RanDomMang(int a[][MAX], int row, int col, int lowerbound, int upperbound )
{
    srand(time(0)); // reset lại time mỗi lần chạy random
    for(int i = 0; i < row; ++i)
    {
        for(int j = 0; j < col; ++j)
        {
            a[i][j] = lowerbound + rand() % (upperbound - lowerbound + 1);
        }
    }
}
void XuatMang(int a[][MAX], int row, int col)
{
    printf("\nMang la : \n");
    for(int i = 0; i < row; ++i)
    {
        for(int j = 0; j < col; ++j)
        {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
}
void HoanViDong(int a[][MAX], int idxRow1, int idxRow2, int col)
{
    for(int i = 0; i < col; ++i)
    {
        int temp = a[idxRow1][i];
        a[idxRow1][i] = a[idxRow2][i];
        a[idxRow2][i] = temp;
    }
}

void HoanViCot(int a[][MAX], int idxCol1, int idxCol2, int row)
{
    for(int i = 0; i < row; ++i)
    {
        int temp = a[i][idxCol1];
        a[i][idxCol1] = a[i][idxCol2];
        a[i][idxCol2] = temp;
    }
}

void Xoa1Dong(int a[][MAX], int idxXoa, int *row, int col)
{
    for(int i = idxXoa + 1; i < *row; ++i)
    {
        HoanViDong(a, i - 1, i, col);
    }
    (*row)--;
}

void Xoa1Cot(int a[][MAX], int idxXoa, int row, int *col)
{
    for(int i = idxXoa + 1; i < *col; ++i)
    {
        HoanViCot(a, i - 1, i, row);
    }
    (*col)--;
}

// void BienDoi(int *a)
// {
//     (*a)--;
//     printf("\n\t %d \n", *a);
// }
void BienDoi(int &a) // truyền tham chiếu
{
    a--;
    printf("\n\t %d \n", a);
}

void ThemMotDong(int a[][MAX], int idxThem, int &row, int col)
{
    int b[col];
    printf("\nNhap vao nhung pt can them : ");
    for(int i = 0; i < col; ++i)
    {
        printf("\nNhap a[%d] = ", i);
        scanf("%d", &b[i]);
    }
    // Them mang b vo dong cuoi cua mang a
    for(int i = 0; i < col; ++i)
    {
        a[row][i] = b[i];
    }

    //  Hoan vi dong do len vi tri can them
    for(int i = row; i >  idxThem; --i)
    {
        HoanViDong(a, i, i - 1, col);
    }
    row++;
}

void ThemMotCot(int a[][MAX], int idxThem, int row, int &col)
{
    int b[row];
    printf("\nNhap vao nhung pt can them : ");
    for(int i = 0; i < row; ++i)
    {
        printf("\nNhap a[%d] = ", i);
        scanf("%d", &b[i]);
    }
    // Them mang b vo cot cuoi cua mang a
    for(int i = 0; i < row; ++i)
    {
        a[i][col] = b[i];
    }

    //  Hoan vi dong do len vi tri can them
    for(int i = col; i >  idxThem; --i)
    {
        HoanViCot(a, i, i - 1, row);
    }
    col++;
}


int main()
{
    // int a = 5;
    // printf("%d", a);
    // BienDoi(a);
    // printf("%d", a);
    
    int a[MAX][MAX]; // tối đa 10 dòng và 10 cột
    int row, col; // số lượng phần tử thật trên mảng 2 chiều mà ng dùng sử dụng

    NhapKichThuoc(&row, (char *)" dong ");
    NhapKichThuoc(&col, (char *)" cot ");

    // NhapMang(a, row, col);
    RanDomMang(a, row, col, 10, 30);
    XuatMang(a, row, col);

    // HoanViCot(a, 0, 1,row);
    // Xoa1Dong(a, 0, &row, col);
    // Xoa1Cot(a, 1, row, &col);
    // ThemMotDong(a, 1, row, col);
    ThemMotCot(a, 3, row, col);
    XuatMang(a, row, col);

    
    
    return 0;
}