#include<stdio.h>

int main()
{
    // int x = 5;
    // const int *const Ptr = &x; // chỉ có thể thay đổi giá trị của x, ta khổng thể dùng *Ptr để thay đổi giá trị x
    // // Vì Ptr là một con trỏ hằng
    // x++; 
    // printf("\nGia Tri cua a = %d", x);
    // printf("\nGia tri ma con tro p dang nam giu la : *p = %d", *Ptr);
    int a = 5;
    int *p = &a; // con trỏ p
    *p = a; // gán địa chỉ của  cho p;
    printf("\nGia Tri cua a = %d", a);
    printf("\nGia tri ma con tro p dang nam giu la : *p = %d", *p);
    printf("\ndia chi cua a la: &a = %p", &a);
    printf("\ndia chi cua bien ma p dang nam giu la: p = %p", p);
    printf("\ndia chi thuc su p = %p", &p);

    // *p =  7; // tăng giá trị mà p giữ lên 1 đơn vị
    *p++;
    printf("\nGia Tri cua a = %d", a);
    printf("\nGia tri ma con tro p dang nam giu la : *p = %d", *p);

    a++;
    printf("\nGia Tri cua a = %d", a);
    printf("\nGia tri ma con tro p dang nam giu la : *p = %d\n", *p);

    int b[] = {1, 2, 3, 4, 5,6};
    int n = sizeof(b) / sizeof(int);
    for(int i = 0; i < n; ++i)
    {
        printf("%4d", *(i + b));
    }
}