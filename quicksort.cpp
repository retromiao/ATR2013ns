#include <iostream>
using namespace std;

int Partition(int a[],int low,int high)//�Ƚ������¼�ݴ���a[0]λ���ϣ�//���������ֻ��a[low]��a[high]�ĵ����ƶ�
{
a[0] = a[low];//���ӱ�ĵ�һ����¼�������¼���ݴ���a[0]λ���ϣ�
int prvotkey = a[low];//�����¼
while (low < high)
{
     while (low<high && a[high]>=prvotkey) //�ѱ������¼С�ļ�¼�Ƶ��Ͷ�
     --high;
     a[low] = a[high];
     while (low<high && a[low]<=prvotkey) //�ѱ������¼��ļ�¼�Ƶ��߶�
     ++low;
     a[high] = a[low];
}

a[low] = a[0];//�����¼��λ
return low;//��������λ��
}//Partition

void Qsort(int a[],int low,int high)
{
int prvotloc;
if(low < high)
{
     prvotloc = Partition(a,low,high);    //����һ������Ľ����Ϊ����
     Qsort(a,low,prvotloc-1); //���ӱ�ݹ����������low ��prvotloc-1
     Qsort(a,prvotloc+1,high); //���ӱ�ݹ����������prvotloc+1��high

}
}//Qsort

void Quicksort(int a[],int size)
{
Qsort(a,1,size); //��һ����Ϊ���ᣬ�ӵ�һ���ŵ���size��
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
            cout<<a[i]<< " ";//��ĿҪ���������ո�
		     cout<<endl;
    }
    return 0;
}
