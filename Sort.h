#pragma once

#include <vector>

template<typename T>
void mergeSort(std::vector<T>& vec);

template<typename T>
void bubbleSort(std::vector<T>& vec);

template<typename T>
void selectionSort(std::vector<T>& vec);

template<typename T>
void shellSort(std::vector<T>& vec);

template<typename T>
void shakerSort(std::vector<T>& vec);

template<typename T>
void insertionSort(std::vector<T>& vec);

template<typename T>
inline void mergeSort(std::vector<T>& vec)
{
    int mid = vec.size() / 2;
    if (vec.size() % 2 == 1)
        mid++;
    int h = 1;
    int* c = (int*)malloc(vec.size() * sizeof(int));
    int step;
    while (h < vec.size())
    {
        step = h;
        int i = 0;   
        int j = mid;
        int k = 0;   
        while (step <= mid)
        {
            while ((i < step) && (j < vec.size()) && (j < (mid + step)))
            { 
                if (vec[i] < vec[j])
                {
                    c[k] = vec[i];
                    i++; k++;
                }
                else {
                    c[k] = vec[j];
                    j++; k++;
                }
            }
            while (i < step)
            { 
                c[k] = vec[i];
                i++; k++;
            }
            while ((j < (mid + step)) && (j < vec.size()))
            {  
                c[k] = vec[j];
                j++; k++;
            }
            step = step + h;
        }
        h = h * 2;
        for (i = 0; i < vec.size(); i++)
            vec[i] = c[i];
    }
}

template<typename T>
inline void bubbleSort(std::vector<T>& vec)
{
    for (int i = 0; i < vec.size(); i++) {
        bool flag = true;
        for (int j = 0; j < vec.size() - (i + 1); j++) {
            if (vec.at(j) > vec.at(j + 1)) {
                flag = false;
                std::swap(vec.at(j), vec.at(j + 1));
            }
        }
        if (flag) {
            break;
        }
    }
}

template<typename T>
inline void selectionSort(std::vector<T>& vec)
{
    int i, j, min_idx;
    for (i = 0; i < vec.size() - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < vec.size(); j++)
            if (vec.at(j) < vec.at(min_idx))
                min_idx = j;
        if (min_idx != i)
            std::swap(vec.at(min_idx), vec.at(i));
    }
}

template<typename T>
inline void shellSort(std::vector<T>& vec)
{
    for (int gap = vec.size() / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < vec.size(); i += 1)
        {
            int temp = vec.at(i);
            int j;
            for (j = i; j >= gap && vec.at(j - gap) > temp; j -= gap)
                vec.at(j) = vec.at(j - gap);
            vec.at(j) = temp;
        }
    }
}

template<typename T>
inline void shakerSort(std::vector<T>& vec)
{
    bool swapped = true;
    int start = 0;
    int end = vec.size() - 1;

    while (swapped) {
        swapped = false;
        for (int i = start; i < end; ++i) {
            if (vec.at(i) > vec.at(i + 1)) {
                std::swap(vec.at(i), vec.at(i + 1));
                swapped = true;
            }
        }
        if (!swapped)
            break;
        swapped = false;
        --end;
        for (int i = end - 1; i >= start; --i) {
            if (vec.at(i) > vec.at(i + 1)) {
                std::swap(vec.at(i), vec.at(i + 1));
                swapped = true;
            }
        }
        ++start;
    }
}

template<typename T>
inline void insertionSort(std::vector<T>& vec)
{
    int i, key, j;
    for (i = 1; i < vec.size(); i++)
    {
        key = vec.at(i);
        j = i - 1;
        while (j >= 0 && vec.at(j) > key)
        {
            vec.at(j + 1) = vec.at(j);
            j = j - 1;
        }
        vec.at(j + 1) = key;
    }
}
