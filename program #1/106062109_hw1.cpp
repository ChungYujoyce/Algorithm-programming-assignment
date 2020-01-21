#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void combine(int array1[5], int array2[5], int length, int result[5]){ // return mixed object array
    for(int l=0; l<length;l++){
        result[l] = (array1[l] > array2[l]) ? array1[l] : array2[l];
    }
}
int sum(int array1[5], int length){
    int s=0;
    for(int l=0; l<length;l++){
        s += array1[l];
    }
    return s;
}
int countMaxEnergy(int elements[10000][5],int object, int element, int num){
    int biggest=0;
    if(num >= element || object==num){
        for(int i=0; i< element; i++){
            int tmp=0;
            for(int j=0; j< object; j++){
                tmp = (tmp > elements[j][i]) ? tmp : elements[j][i];
            }
            biggest +=tmp;
        }
    }else{ // K = 2 || 3 || 4
        // delete some not qualify object bit array
        int visited[object] ={0};
        int new_elements[object][element]={0};
        unordered_set<int> best;
        int test_num=1;
        int test=pow(2,element);
        int bit_array[element]={0};
        for(int i=1; i<test; i++){ // run 1~element create bit_array
            int best_index=0; // store this iteration best object's index
            int tmp_sum=0; // this iteration's sum
            int best_sum=0; // store current best sum
            for(int j=0; j<object;j++){
                tmp_sum=0; // stupid!!!
                int m = test_num;
                for(int k=0; k<element;k++){
                    if(m&1){
                        tmp_sum+= elements[j][k];
                    }
                    if(m>0) m>>=1;
                }
                if(best_sum < tmp_sum){
                    best_index = j;
                    best_sum = tmp_sum;
                }
            }
            test_num++;
            best.insert(best_index); // place here , every iteration gain one key
        }
        // assign new objects
        int k=0; // new_elements's own index
        int rows=0;
        for (auto idx: best){
            for(int j=0;j<element;j++){
                new_elements[k][j] = elements[idx][j];
            }
            k++; rows++;
            //cout << idx<<"w ";

        }
        // for loop search right object permutation
        // fewer rows
        int max_object=0;
        if(num==2){
            for(int i=0; i<rows-1; i++){
                for(int j=i+1; j<rows; j++){
                    int result[element]={0};
                    combine(new_elements[i], new_elements[j], element ,result);
                    int tmp_sum = sum(result,element);
                    max_object = (tmp_sum > max_object) ? tmp_sum : max_object;
                }
            }
            biggest = max_object;
        }else if(num==3){ // k==3
            int result[element]={0};
            int result2[element]={0};
            for(int i=0; i<rows-2; i++){
                for(int j=i+1; j<rows-1; j++){
                    combine(new_elements[i], new_elements[j], element ,result);
                    for(int k=i+2; k<rows; k++){
                       combine(result, new_elements[k], element ,result2);
                       int tmp_sum=sum(result2,element);
                       max_object = (tmp_sum > max_object) ? tmp_sum : max_object;
                    }
                }
            }
            biggest = max_object;
        }else{ //k==4
            int result[element]={0};
            int result2[element]={0};
            int result3[element]={0};
            for(int i=0; i<rows-3; i++){
                for(int j=i+1; j<rows-2; j++){
                    combine(new_elements[i], new_elements[j], element ,result);
                    for(int k=i+2; k<rows-1; k++){
                        combine(result, new_elements[k], element ,result2);
                        for(int l=i+3; l<rows; l++){
                            combine(result2, new_elements[l], element ,result3);
                            int tmp_sum=sum(result3,element);
                            max_object = (tmp_sum > max_object) ? tmp_sum : max_object;
                        }
                    }
                }
            }
            biggest = max_object;
        }
    }
    return biggest;
}
int main()
{
    int testcase=0;
    int num=0;
    int object=0;
    int element=0;

    cin >> testcase;

    for(int t=0; t<testcase; t++){
        cin >> object >> num >> element;

        int elements[10000][5];

        for(int i=0; i<object;i++){
            for(int j=0; j<element; j++){
                cin >> elements[i][j];
            }
        }
        int ans = countMaxEnergy(elements, object, element, num);
        cout << ans << endl;
    }

    return 0;
}
