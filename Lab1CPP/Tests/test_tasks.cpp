#include "lab1.h"
#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <algorithm>


bool check_result(int test_num, Array *arr, FILE *input)
{
    auto res = test_num == 1 ? task1(arr) : task2(arr);
    size_t size1;
    if (fscanf(input, "%lu", &size1) < 0)
    {
        return false;
    }
    if (res.size() != size1)
    {
        printf("TASK %d result.size()!=expected.size() (%lu!=%lu)\n", test_num, res.size(), size1);
        return false;
    }
    for (size_t i = 0; i < size1; i++)
    {
        int num = 0;
        if (fscanf(input, "%d", &num) < 0)
        {
            return false;
        }
        if(res[i]!=num){
             printf("TASK %d result != expected, index = %lu (%d!=%d)\n", test_num,i,res[i],num);
            return false;
        }
    }
    return true;
}
int main(int argc, char **argv)
{
    FILE *input;
    if (argc <= 1)
    {
        input = fopen("/Users/user/Projects/Algorithms/Lab1CPP/input_test_tasks.txt", "r");
    }
    else
    {
        input = fopen(argv[1], "r");
    }
    Array *arr = array_create_and_read(input);//считываем вводный массив
    auto result = task1(arr);//получаем ответ из таски
    Array* expected = array_create_and_read(input);//считываем ожидаемый ответ
    if(result.size()!=expected->size()){//сравниваем размеры
        printf("TASK 1 FAILED: result.size()!=expected.size()\n");
    }else{
        for(size_t i=0;i<result.size();i++){
            auto result_el = result.at(i);
            auto expected_el = expected->get(i);
            if(result_el!=expected_el){
                printf("TASK 1 FAILED: result[%lu]!=expected[%lu]\n",i,i);
            }
        }
    }
    //не забыть удалить arr и expected
    
    for (int i = 1; i <= 2; i++)
    {
        if (!check_result(i, arr, input))
        {
            printf("TASK %d test failed\n", i);
        }
        else
        {
            printf("TASK %d test success\n", i);
        }
    }
    delete arr;
}