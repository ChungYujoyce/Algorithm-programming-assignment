#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
     char* pathName = "C:\\Users\\USER\\Desktop\\algo\\testcase_hw2\\testcase6-2.txt"; // 你要建立檔案的路徑
     ofstream fout(pathName);
     unsigned seed;

     if (fout) { // 如果建立成功
    seed = (unsigned)time(NULL); // 取得時間序列
    srand(seed); // 以時間序列當亂數種子
      for (int i = 0; i < 1000000; i++)
      {

    fout << rand() << endl; // 使用與cout同樣的方式進行寫入


      }

    fout.close();  // 執行完操作後關閉檔案控制代碼
     }
    return 0;
}
