#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
     char* pathName = "C:\\Users\\USER\\Desktop\\algo\\testcase_hw2\\testcase6-2.txt"; // �A�n�إ��ɮת����|
     ofstream fout(pathName);
     unsigned seed;

     if (fout) { // �p�G�إߦ��\
    seed = (unsigned)time(NULL); // ���o�ɶ��ǦC
    srand(seed); // �H�ɶ��ǦC��üƺؤl
      for (int i = 0; i < 1000000; i++)
      {

    fout << rand() << endl; // �ϥλPcout�P�˪��覡�i��g�J


      }

    fout.close();  // ���槹�ާ@�������ɮױ���N�X
     }
    return 0;
}
