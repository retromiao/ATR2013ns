#include <iostream>
using namespace std;

int Partition(int a[],int low,int high)//先将枢轴记录暂存在a[0]位置上，//排序过程中只作a[low]或a[high]的单向移动
{
a[0] = a[low];//用子表的第一个记录作枢轴记录（暂存在a[0]位置上）
int prvotkey = a[low];//枢轴记录
while (low < high)
{
     while (low<high && a[high]>=prvotkey) //把比枢轴记录小的记录移到低端
     --high;
     a[low] = a[high];
     while (low<high && a[low]<=prvotkey) //把比枢轴记录大的记录移到高端
     ++low;
     a[high] = a[low];
}

a[low] = a[0];//枢轴记录到位
return low;//返回枢轴位置
}//Partition

void Qsort(int a[],int low,int high)
{
int prvotloc;
if(low < high)
{
     prvotloc = Partition(a,low,high);    //将第一次排序的结果作为枢轴
     Qsort(a,low,prvotloc-1); //低子表递归调用排序由low 到prvotloc-1
     Qsort(a,prvotloc+1,high); //高子表递归调用排序由prvotloc+1到high

}
}//Qsort

void Quicksort(int a[],int size)
{
Qsort(a,1,size); //第一个作为枢轴，从第一个排到第size个
}//Quicksort

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
        Quicksort(a,size);
        for(i=1;i<=size;i++)
            cout<<a[i]<< " ";//题目要求输出间隔空格！
		     cout<<endl;
    }
    return 0;
}
