#include <stdio.h>
int main() {
    char grade;
    scanf("%c", &grade);
    switch (grade) {
        case 'A':
            printf("90-100\n");
            break;
        case 'B':
            printf("80-89\n");
            break;
        case 'C':
            printf("70-79\n");
            break;
        case 'D':
            printf("60-69\n");
            break;
        case 'E':
            printf("Under 60\n");
            break;
    }
    return 0;
}
