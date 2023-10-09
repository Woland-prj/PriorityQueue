#include <iostream>
#include "PriorityQueue.h"
#define ArrLen 3

void pushTest(CPriorityQueue &Qe, PrQeData testArr[]) {
    for (size_t i = 0; i < ArrLen; i++)
        Qe.push(testArr[i]);
    while (!Qe.isEmpty()) {
        PrQeData data = Qe.pop();
        std::cout << data.data << ' ' << data.priority << std::endl;
    }
    std::cout << std::endl;
}

void changeTest(CPriorityQueue& Qe, PrQeData testArr[], int ind, int priority) {
    for (size_t i = 0; i < ArrLen; i++)
        Qe.push(testArr[i]);
    Qe.changePriority(testArr[ind], priority);
    while (!Qe.isEmpty()) {
        PrQeData data = Qe.pop();
        std::cout << data.data << ' ' << data.priority << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    PrQeData testArr1[] = { { 7, 1 }, { 4, 2 }, { 8, 3 } };
    PrQeData testArr2[] = { { 4, 2 }, { 7, 1 }, { 8, 3 } };
    PrQeData testArr3[] = { { 4, 2 }, { 8, 5 }, { 7, 6 } };
    CPriorityQueue Qe;
    while (!Qe.isEmpty()) {
        PrQeData data = Qe.pop();
        std::cout << data.data << ' ' << data.priority << std::endl;
    }
    pushTest(Qe, testArr1);
    pushTest(Qe, testArr2);
    pushTest(Qe, testArr3);
    changeTest(Qe, testArr3, 2, 1);
    changeTest(Qe, testArr3, 2, 4);
    changeTest(Qe, testArr3, 0, 7);
}