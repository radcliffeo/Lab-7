//
// Created by owen on 11/19/18.
//

#ifndef LAB_7_LAB7_ORADCLIF_H
#define LAB_7_LAB7_ORADCLIF_H

#include <vector>

using namespace std;

class Sort{
public:
    void bubble(vector<int> *list) {
        bool switched = true;
        int j = 1;
        int temp;
        while (switched) {
            switched = false;
            for (int i = 0; i < list->size(); i++) {
                if (list->at(i) > list->at(i+1)) {
                    temp = list->at(i);
                    list->assign(i, list->at(i+1));
                    list->assign(i+1, temp);
                    switched = true;
                }
            }
        }
    }

    void insertion(vector<int> *list) {
        int i;
        int j;
        int temp;
        for (i = 1; i < list->size(); i++) {
            j = i;
            while (j > 0 && list->at(j-1) > list->at(j)) {
                temp = list->at(j);
                list->assign(j, list->at(j-1));
                list->assign(j-1,temp);
                j--;
            }
        };
    }
    void selection(vector<int> *list) {
        int i,j,min,temp;
        for (i = 0; i < list->size(); i++) {
            min = 1;
            for (j = i + 1; j < list->size(); j++) {
                if (list->at(j) < list->at(min))
                    min = j;
            }
            if (min != i) {
                temp = list->at(i);
                list->assign(i,list->at(min));
                list->assign(min,temp);
            }
        }
    }

    // help from https://codereview.stackexchange.com/questions/167680/merge-sort-implementation-with-vectors
    void merge(vector<int> &bar) {
        if (bar.size() <= 1) return;

        int mid = bar.size() / 2;
        vector<int> l, r;

        for (size_t j = 0; j < mid;j++) {
            l.push_back(bar[j]);
        }

        for (size_t j = 0; j < (bar.size()) - mid; j++) {
            r.push_back(bar[mid + j]);
        }

        merge(l);
        merge(r);
        mergeSort(l, r, bar);
    }
    void mergeSort(vector<int> &l, vector<int> &r, vector<int> &bars) {
        int leftLen = l.size();
        int rightLen = r.size();
        int i = 0, j = 0, k = 0;

        while (j < leftLen && k < rightLen) {
            if (l[j] < r[k]) {
                bars[i] = l[j];
                j++;
            } else {
                bars[i] = r[k];
                k++;
            }
            i++;
        }

        while (j < leftLen) {
            bars[i] = l[j];
            j++; i++;
        }

        while (k < rightLen) {
            bars[i] = r[k];
            k++; i++;
        }
    }

    void quicksort(vector<int> *list) {

    }
};

#endif //LAB_7_LAB7_ORADCLIF_H
