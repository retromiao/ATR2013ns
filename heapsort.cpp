#include <iostream>
using namespace std;
//����#include<algorithm>��ֱ��ʹ��swap������	

static void swap(int*a, int*b) //��������
 {
    int temp = 0;
    temp = *b;
    *b = *a;
    *a = temp;
 }
// a�Ǵ������Ķ����飬i�Ǵ�����������Ԫ�ص�λ�ã�size������ĳ���
//�����������ǣ���������a���������
void HeapAdjust(int a[], int i, int size)
{
	int lchild = 2*i;//i�����ӽڵ�
	int rchild = 2*i + 1;//i���Һ��ӽڵ�
	int max = i;//�м����
	if(i<=size/2)//�����һ����Ҷ�ڵ㿪ʼ
	{
		if(lchild<=size && a[lchild]>a[max])
			max = lchild;
		if(rchild<=size && a[rchild]>a[max])
			max = rchild;
		if(max != i)
		{
			swap(a[i],a[max]);//���ڵ㡢���Һ���������������븸�ڵ㽻��
			HeapAdjust(a,max,size);//��������Ժ���maxΪ���ڵ���������Ƕ�
		}
	}
    
}

void BuildHeap(int a[],int size)    //������
{
    int i;
    for(i=size/2;i>=1;i--)    //��Ҷ�ڵ�������ֵΪsize/2 
    {
        HeapAdjust(a,i,size); 
    }    
} 

void HeapSort(int a[],int size)    //������
{
    int i;
    BuildHeap(a,size);
    for(i=size;i>=1;i--)
    {
        swap(a[1],a[i]);           //�����Ѷ������һ��Ԫ�أ���ÿ�ν�ʣ��Ԫ���е�����߷ŵ������
        HeapAdjust(a,1,i-1);      //���µ����Ѷ��ڵ��Ϊ�󶥶ѣ��Ѿ��ŵ�����Ԫ�ز��ٲ������
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
            cout<<a[i]<< " ";//��ĿҪ���������ո�
		     cout<<endl;
    }
    return 0;
}
