#include <stdio.h>

int solve(int* a, int s) {
    if (s <= 0) return 0;
    return *a + solve(a + 1, s - 1);
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int sum = 0;
    
    // Method 1: 
    for(int i = 0; i < 5; i ++)
        sum += *(arr + i);
    
    // Method 2: 
    int* end = arr + 5;
    for(int* i = arr; i < end; i ++)
        sum += *i;
    
    // Method 3:
    sum = solve(arr, 5);
    
    printf("%d\n", sum);
    return 0;
}
