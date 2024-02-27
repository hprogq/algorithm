#include <iostream>
using namespace std;
const int N = 1e6 + 10;

void quick_sort( int a[], int l, int r ) {
    // 边界条件
    if ( l == r )  // 如果区间中只有一项，则没有必要排序。
        return;    // 写成 l >= r 也可以，但没必要。
    // 比如 [ 1 || 2 3 ] 选定key为1时，最后的递归会导致死循环。
    // 所以单项区间无需排序。（key定义可查看Hoare分区方式说明）
    
    // 分治部分，目的是使左侧的所有数都小于右侧。
    int i = l - 1, j = r + 1;  // 为下方++、--做准备
    int key = a[ ( l + r )  >> 1 ];  // 选定key。选两侧端点为key时，需要在最后指针重叠时与其交换。
    while ( i < j ) {  // 这个地方不能写<=是因为最后i和j可能相等。
        while ( a[ ++ i ] < key ); // 这两句话会至少移动i和j一次，因为原有的i和j必然已经交换过或者是初始情况。
        while ( a[ -- j ] > key );
        // 上面两行不是<=和>=是因为a[i]和a[j]可能是数组中的最大或最小值，这会导致无限循环。
        if ( i < j )
            swap( a[i], a[j] );
        // 最终i与j可能会相等(i=2, j=2)或者是越过并交错(i=5, j=4)，是因为上面的++和--至少执行一次。
    }
    
    // 递归部分，此时左侧所有数已经必然小于右侧，再继续分别排序左右两侧的数据即可。
    // if ( l < r ) {    // 所以if ( l >= r )那句也可以写在这里。
    quick_sort( a, l, j );
    quick_sort( a, j + 1, r );  // 如果上面写的是l到j，则这里不可以写i到r，因为i可能与l相同，则又重复执行l到r了。
    // }
    return;
}

int main() {
    int n, a[N];
    scanf("%d", &n);
    for ( int i = 0; i < n ; i ++ )
        scanf("%d", &a[i]);
    quick_sort( a, 0, n - 1 );
    for ( int i = 0; i < n ; i ++ )
        printf("%d ", a[i]);
    return 0;
}
