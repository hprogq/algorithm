#include <stdio.h>
#define MAXN 10
int main() {
    int stack[MAXN], tt = 0, cmd;
    for ( ; ; ) {
        printf("Please choose action(1: Push 2: Pop  0: Exit):");
        scanf("%d", &cmd);
        switch ( cmd ) {
            case 0:
                printf("Exiting the System\n");
                return 0;
            case 1:
                if ( tt >= MAXN ) {
                    printf("Unsuccessful push operation: Stack is full\n");
                    break;
                }
                printf("Enter an integer to push: ");
                scanf("%d", &stack[ tt++ ]);
                break;
            case 2:
                if ( !tt ) {
                    printf("Unsuccessful pop operation: Stack is empty\n");
                    break;
                }
                printf("Popped: %d\n", stack[ --tt ]);
                break;
            default:
                continue;
        }
        printf("----------------------\n| Stack:");
        for ( int i = 0; i < tt; i++ )
            printf(" %d", stack[i]);
        printf("\n----------------------\n");
    }
    return 0;
}
