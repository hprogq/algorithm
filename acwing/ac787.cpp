#include <iostream>
using namespace std;
const int N = 1e5 + 10;
// 归并排序需要以大内存换取更优的运行速度，申请数组大小不要超限，1e6在部分电脑上会超限。
// 否则可能会导致崩溃，表现为在调试时递归时向函数传递地址时导致SIGSEGV。

void merge_sort( int a[], int l, int r ) {
    // 边界条件，同快速排序
    if ( l == r )
        return;
    
    // 先递归处理完左右两侧，使得在后续操作进行之前，mid的左右两侧分别已经是有序的了。
    int mid = ( l + r ) >> 1;
    merge_sort( a, l, mid );
    merge_sort( a, mid + 1, r );
    
    // 合并部分，任务是将左右两侧两个有序的数组合并为一个。
    int i = l, j = mid + 1; // 左右两侧合并时，指示两侧下一个应合并数值的指针。
    // 合并需要一个临时数组k，用来临时存储合并后的结果，最后将其覆盖回原数组。
    int k[N], t = 0; // t是指向临时数组k下一个可存放位置的指针。
    while ( i <= mid && j <= r ) // 如果两侧都没合并完
        if ( a[i] < a[j] ) // 如果左边现在要合并的数比右边的数小（<=也可以的）
            k[ t ++ ] = a[ i ++ ]; // 就把左侧数组里下一个数添加到结果里
        else k[ t ++ ] = a[ j ++ ]; // 否则放右侧数组里的下一个数
    // 现在左侧或者右侧有一侧已经全部都合并完了（按要求合并到k数组中），可能还剩一侧。
    while ( i <= mid ) // 那一侧中剩下的数一定都比已经合并的数大，全部合并即可。
        k[ t ++ ] = a[ i ++ ];
    while ( j <= r ) // 同理，处理右侧或跳过。
        k[ t ++ ] = a[ j ++ ];
    for ( int i = l, j = 0; i <= r; i ++, j ++ ) // 将临时数组k的数据合并覆盖回原数组
        a[i] = k[j];
    return;
}

int main() {
    int n, a[N];
    scanf("%d", &n);
    for ( int i = 1; i <= n; i ++ )
        scanf("%d", &a[i]);
    merge_sort( a, 1, n );
    for ( int i = 1; i <= n; i ++ )
        printf("%d ", a[i]);
    return 0;
}