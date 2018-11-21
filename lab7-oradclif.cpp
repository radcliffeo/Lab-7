//
// Created by owen on 11/19/18.
//

#include <iostream>
#include "Lab7-oradclif.h"
#include "unixTimer.h"
#include "ContainerPrinting.h"
#include "RandomUtilities.h"

using namespace std;

// post: a vector of listSize random doubles from
//         the range minNum to maxNum has been returned.
vector<int>
getNums(size_t listSize, int minNum, int maxNum)
{
    vector<int> theList;
    for (size_t i = 0; i < listSize; ++i)
    {
        theList.push_back(randReal(minNum, maxNum));
    }

    return theList;
}

int
main() {
    Sort sort;
    vector<int> v1 = getNums(10,1,500);
    vector<int> *v1pointer = &v1;
    cout << v1 << endl;
    //sort.bubble(v1pointer);
    sort.merge(v1);
    cout << v1;
}

/*
void Sort::bubble(list<int> *list) {}

void Sort::insertion(list<int> *list) {}

void Sort::merge(list<int> *list) {}

void Sort::quicksort(list<int> *list) {}

void Sort::selection(list<int> *list) {}
 */