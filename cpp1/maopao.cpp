#include <iostream>

using namespace std;

int main()
{
	const unsigned cnt = 8;
	int arr[cnt] = { 3,2,1,7,8,9,5,0 };
	unsigned times = 0;
    for(int i=1; i<cnt; ++i)
    {
        for(int j=0; j<cnt-i; ++j)
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
    }
	for (unsigned i = 0; i != cnt; ++i)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}
