#include <iostream>
#include <vector>
using namespace std;

//冒泡排序
void bubbleSort(vector<int>& arr)
{
    int n = arr.size();
    for(int i = 0; i < n - 1; ++i)
    {
        for(int j = 0; j < n - i - 1; ++j)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main()
{
    vector<int> origin;
    vector<int> mainBox;     
    vector<int> shulkerBox;  

    cout << "-1 end:" << endl;
    int x;
    while(cin >> x)
    {
        if(x == -1) break; //遇到-1停止接收数字
        origin.push_back(x);
    }

    if(origin.empty())
    {
        cout << "none!" << endl;
        return 0;
    }

    mainBox.push_back(origin[0]);
    for(size_t i = 1; i < origin.size(); i++)
    {
        int prev = origin[i-1];
        int cur  = origin[i];
        if(cur < prev)
        {
            shulkerBox.push_back(cur);
        }
        else
        {
            mainBox.push_back(cur);
        }
    }

    //各自冒泡排序
    bubbleSort(mainBox);
    bubbleSort(shulkerBox);

    //输出
    cout << "\n(mianbox):";
    for(auto num : mainBox)
        cout << num << " ";

    cout << "\n(shulkerBox):";
    for(auto num : shulkerBox)
        cout << num << " ";
    cout << endl;

    return 0;
}
