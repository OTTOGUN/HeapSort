#include <stdio.h>
#define size 10

void Swap(int* num,int i,int j){
    int temp;
    temp = num[i];
    num[i] = num[j];
    num[j] = temp;
}

//最大堆调整
void Heapify(int* num,int len,int k)
{
    if (k < len)
    {
        int root = k;           //根结点
        int lchild = 2 * k + 1; //左孩子结点
        int rchild = 2 * k + 2; //右孩子结点
        //查找左右孩子结点中的最大结点
        if ( lchild < len && num[root] < num[lchild])
        {
            root = lchild;
        }
        if ( rchild < len && num[root] < num[rchild])
        {
            root = rchild;
        }

        //交换最大结点到根节点
        if ( root != k )
        {
            Swap(num,root,k);
            //每次交换都可能影响到对应孩子结点字数的顺序
            //需要对交换后的孩子结点子树进行最大堆调整
            Heapify(num,len,root);
        }
    }
}

//创建最大堆
void CreateHeap(int* num,int len)
{
    int i;
    //最后一个结点下标
    int last = len - 1;
    //最后一个节点的父结点下标
    int parent = (last - 1) / 2;
    //从最后一个节点的父节点到根节点，一次进行最大堆调整
    for (i = parent;i >= 0;i--)
    {
        Heapify(num,len,i);
    }
}

//堆排序
void HeapSort(int* num,int len)
{
    //创建最大堆并进行最大堆调整
    CreateHeap(num,len);
    printf("最大堆调整!\n");
    int i;
    //一次取出根结点(最大值)
    for(int i = len - 1;i >= 0;i--)
    {
        //将最大堆的根节点(最大值)换到最后一个结点
        Swap(num,i,0);
        //交换二叉树的根节点发生改变，所以还需要对根结点做最大调整
        //而此时根结点小于所有父节点，因而在调整时只需考虑最大孩子的分支即可
        Heapify(num,i,0);
    }
}

int main(){
    int i;
    int num[size] = {8,4,3,1,6,9,5,7,2,0};
    HeapSort(num,size);

    for(i = 0;i < size;i++){
        printf("%d",num[i]);
    }
    printf("\n");
    return 0;
}
