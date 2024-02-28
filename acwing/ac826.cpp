#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int main() {
    int v; // 询问数量
    int val[N], nxt[N] = { 1 }; // val存储每个编号对应的值，nxt存储链表中每个编号对应值的下一个值的编号
    int idx = 1, head = -1; // idx为指向链表下一个空闲可存下标的指针，head为指向链表头的指针，初始值为-1代表链表为空。
    scanf("%d", &v);
    while ( v -- ) {
        char op[3];
        scanf("%s", op); // 使用字符数组和%s读入，可以自动忽略空格
        if ( *op == 'H' ) { // *op指向op[0]
            nxt[idx] = head; // 首先将链表头部元素后移，与当前新的链表头相连
            scanf("%d", &val[idx]); // 然后读入新链表头的值
            head = idx ++; // 更新链表头指针
        } else if ( *op == 'D' ) {
            int k;
            scanf("%d", &k);
            if ( !k ) // 如果k为0，则链表头变化
                head = nxt[head]; // 此时需要更新链表头指针
            nxt[k] = nxt[nxt[k]]; // 将第k个元素与其下一个相连的元素分离，再与更后面的那个相连。
        } else if ( *op == 'I' ) {
            int k, x;
            scanf("%d%d", &k, &x);
            nxt[idx] = nxt[k]; // 将x与k的后方元素相连
            nxt[k] = idx; // 将k与x相连
            val[ idx ++ ] = x; // 将x的值写入，移动指针
        }
    }
    for ( int i = head; ~i; i = nxt[i] ) // 从表头开始，到-1停止
        printf("%d ", val[i]);
    return 0;
}
