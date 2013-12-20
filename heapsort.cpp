#include <iostream>
using namespace std;
//调用#include<algorithm>可直接使用swap函数！	

static void swap(int*a, int*b) //交换函数
 {
    int temp = 0;
    temp = *b;
    *b = *a;
    *a = temp;
 }
// a是待调整的堆数组，i是待调整的数组元素的位置，size是数组的长度
//本函数功能是：根据数组a构建大根堆
void HeapAdjust(int a[], int i, int size)
{
	int lchild = 2*i;//i的左孩子节点
	int rchild = 2*i + 1;//i的右孩子节点
	int max = i;//中间变量
	if(i<=size/2)//从最后一个非叶节点开始
	{
		if(lchild<=size && a[lchild]>a[max])
			max = lchild;
		if(rchild<=size && a[rchild]>a[max])
			max = rchild;
		if(max != i)
		{
			swap(a[i],a[max]);//父节点、左右孩子三者中最大者与父节点交换
			HeapAdjust(a,max,size);//避免调整以后以max为父节点的子树不是堆
		}
	}
    
}

void BuildHeap(int a[],int size)    //建立堆
{
    int i;
    for(i=size/2;i>=1;i--)    //非叶节点最大序号值为size/2 
    {
        HeapAdjust(a,i,size); 
    }    
} 

void HeapSort(int a[],int size)    //堆排序
{
    int i;
    BuildHeap(a,size);
    for(i=size;i>=1;i--)
    {
        swap(a[1],a[i]);           //交换堆顶和最后一个元素，即每次将剩余元素中的最大者放到最后面
        HeapAdjust(a,1,i-1);      //重新调整堆顶节点成为大顶堆，已经放到最后的元素不再参与调整
    }
} 

int main(int argc, char *argv[])
{
     // int a[]={4,15,8,5};
   	int size;
    while(cin>>size)
{
	 int a[size];
        int i;
        for(i=1;i<=size;i++)
            cin>>a[i];
        HeapSort(a,size);
        for(i=1;i<=size;i++)
            cout<<a[i]<< " ";//题目要求输出间隔空格！
		     cout<<endl;
    }
    return 0;
}
