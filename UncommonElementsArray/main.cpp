#include <iostream>
#include <conio.h>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

int main()
{
    int16_t size1, size2;

    cout<<"\n Enter the size of array 1: ";
    cin>>size1;
    cout<<"\n Enter the size of array 2: ";
    cin>>size2;

    int32_t arr1[size1], arr2[size2];
    cout<<"\n Enter the array 1 elements:\n";
    for(int16_t i=0; i<size1; i++)
        cin>>arr1[i];
    cout<<"\n Enter the array 2 elements:\n";
    for(int16_t i=0; i<size2; i++)
        cin>>arr2[i];

    bitset<32768> checker1=0, checker2=0;
    for(int16_t i=0; i<size1; i++)
        checker1.set((arr1[i]>=0)?arr1[i]:32768+arr1[i]);

    for(int16_t i=0; i<size2; i++)
        checker2.set((arr2[i]>=0)?arr2[i]:32768+arr2[i]);

    vector<int32_t> uncommonelements;
    vector<int32_t>::iterator iue = uncommonelements.begin();
    for(int16_t j=1; j<16384; j++)
        if(checker1[32768-j] != checker2[32768-j])
            uncommonelements.push_back(-j);
    for(int16_t i = 0; i <= 16384; i++)
        if(checker1[i] != checker2[i])
            uncommonelements.push_back(i);

    cout<<"\n The uncommon elements are: ";
    iue = uncommonelements.begin();
    while(iue != uncommonelements.end())
        cout<<" "<<*iue++;

    getch();
    return 0;
}
