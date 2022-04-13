#include <stdio.h>
extern void print_progression(int num);

int main(){
    int num;

    printf("Progression: (2-1)+(4-2)+(2*n-n)\n");
    printf("Enter a number: ");
    if (scanf("%d", &num) <= 0)
    {
        printf("Input error\n");
    }else if (num < 0)
    {
        printf("Number should be positive\n"); 
    }else if (num == 0)
    {
        printf("Sum: 0\n"); 
    }else
    {
        print_progression(num);
    }

    return 0;
}
