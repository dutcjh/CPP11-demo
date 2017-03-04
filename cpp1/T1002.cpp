#include<iostream>
#include<cstring>
#include<cstdlib>
#include<string>
#define N 100010

using namespace std;

const char change[30]="22233344455566677778889999";   //����ĸ�����ֵ�ת��
char map[N][20];
int n;

int cmp(const void* a,const void* b)
{
    return strcmp((char*)a,(char*)b);
}

int main()
{
    cin >> n;
    for (int i=0;i<n;i++)
    {
        string s;
        cin >> s;
        int pos=0;
        for (int j=0;j<s.length();j++)
        {
            if (pos==3)    //ע��˴���3����Ϊ�ӵ�0λ��ʼ��
                map[i][pos++]='-';
            if (s[j]>='A'&&s[j]<'Z' && s[j]!='Q')
                map[i][pos++]=change[s[j]-'A'];
                else if (isdigit(s[j]))
                    map[i][pos++]=s[j];
        }
        map[i][8]='\0';     //�ַ���ĩβҪ��'\0'
    }
    qsort(map,n,sizeof(map[0]),cmp);    //�ֵ�����������
    int flag=0;
    for (int i=0;i<n;i++)
    {
        int num=0;
        for (;strcmp(map[i],map[i+1])==0 && i<n;i++,num++);
        if (num)
        {
            cout << map[i] << " " << num+1 << endl;
            flag=1;
        }
    }
    if (!flag)
        cout << "No duplicates." << endl;
    return 0;
}
