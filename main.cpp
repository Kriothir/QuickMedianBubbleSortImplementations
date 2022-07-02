#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
void randomArray(std::vector<int> &n, int size){
    std::random_device generate;
    std::mt19937 random_engine(generate());
    std::uniform_int_distribution<int> randomize(0, size);

    for (size_t i = 0; i < size; ++i)
    {
        n.push_back(randomize(generate));
    }
}

void increaseArray(std::vector<int> &n, int size){
    for(int i = 0; i <= size; i++){
        n.push_back(i);
    }
}
void decreaseArray(std::vector<int> &n, int size){
    for(int i = size; i >= 0; --i){
        n.push_back(i);
    }
}

bool CheckArray(std::vector<int> &n, int size){
    for(int i = 0; i < n.size()-1; i++)
        if(n[i+1] < n[i])
            return false;

    return true;
}

int Divide(std::vector<int> &n, int bottom, int top){
    int pivot = n[bottom];
    int left = bottom;
    int right = top;

    while(left <= right){
        while(n[left] <= pivot && left < top){
            left++;
        }
        while(n[right] >= pivot && right > bottom){
            right--;
        }
        if(left <= right && n[left] != n[right]){
            std::swap(n[left], n[right]);
        }
        else{
            std::swap(n[bottom], n[right]);
            return right;
        }
    }
    return right;
}

void QuickSort(std::vector<int> &n, int bottom, int top){
    // double x[10000];
    // x[0]=0;
    if(bottom < top){
        int j = Divide(n, bottom, top);
        QuickSort(n, bottom, j-1);
        QuickSort(n, j+1, top);
    }
}
int DivideMedian(std::vector<int> &n, int bottom, int top){
    int m = bottom + (top-bottom)/2;
    std::swap(n[bottom], n[m]);
    int pivot = n[bottom];
    int left = bottom;
    int right = top;

    while(left <= right){
        while(n[left] <= pivot && left < top){
            left++;
        }
        while(n[right] >= pivot && right > bottom){
            right--;
        }
        if( n[left] != n[right] && left <= right ){
            std::swap(n[left], n[right]);
        }
        else{
            std::swap(n[bottom], n[right]);
            return right;
        }
    }
    return right;
}

void QuickSortMedian(std::vector<int> &n, int bottom, int top){
    if(bottom < top){
        int j = DivideMedian(n, bottom, top);
        QuickSortMedian(n, bottom, j-1);
        QuickSortMedian(n, j+1, top);
    }
}

void BubbleSort(std::vector<int> &n){
    for(int i = 0; i < n.size();i++){
        for(int j = i+1; j < n.size(); j++){
            if(n[i] > n[j]){
                std::swap(n[i],n[j]);
            }
        }
    }
}

int main() {
    int input;
    bool check = true;
    int value;

    std::vector<int> apashe;
    while(check){
        std::cout << "1. Randomize array" << std::endl;
        std::cout << "2. Array by increase" << std::endl;
        std::cout << "3. Array by decrease" << std::endl;
        std::cout << "4. Display array" << std::endl;
        std::cout << "5. Check Sorted" << std::endl;
        std::cout << "6. Quick Sort" << std::endl;
        std::cout << "7. Median Sort" << std::endl;
        std::cout << "8. Bubble Sort" << std::endl;
        std::cout << "9. Izhod" << std::endl;
        std::cin >> value;

        if(value == 1){
            apashe.clear();
            std::cin >> input;
            randomArray(apashe, input);
        }
        else if(value == 2){
            apashe.clear();
            std::cin >> input;
            increaseArray(apashe, input);
        }
        else if(value == 3){
            apashe.clear();
            std::cin >> input;
            decreaseArray(apashe, input);
        }
        else if(value == 4) {
            for (int i = 0; i < apashe.size(); i++) {
                std::cout << apashe[i] << ", ";
            }
            std::cout << std::endl;
        }
        else if(value == 5){
            if(CheckArray(apashe, apashe.size())){
                std::cout << "Array is sorted" << std::endl;
            }
            else{
                std::cout << "Array is not sorted" << std::endl;
            }
        }
        else if(value == 6){
            auto start=std::chrono::steady_clock::now();
            QuickSort(apashe, 0, apashe.size() - 1);
            auto end=std::chrono::steady_clock::now();
            std::cout << "Cas trajanja: " <<
                      std::chrono::duration_cast<std::chrono::microseconds>
                              (end - start).count() <<
                      "microsecs."<<std::endl;

        }
        else if(value == 8){
            auto start=std::chrono::steady_clock::now();
            BubbleSort(apashe);
            auto end=std::chrono::steady_clock::now();
            std::cout << "Cas trajanja: " <<
                      std::chrono::duration_cast<std::chrono::microseconds>
                              (end - start).count() <<
                      "microsecs."<<std::endl;
        }
        else if(value == 7){
            auto start=std::chrono::steady_clock::now();
            QuickSortMedian(apashe, 0, apashe.size() - 1);
            auto end=std::chrono::steady_clock::now();
            std::cout << "Cas trajanja: " <<
                      std::chrono::duration_cast<std::chrono::microseconds>
                              (end - start).count() <<
                      "microsecs."<<std::endl;

        }

        else if (value == 9){
            check = false;
        }
    }
    return 0;
}
/*10000 elements
 * Random:
 *Quick sort: 2005 microsecs
 *Median sort:2183 microsecs
 *Bubble sort:849519 microsecs
 *Ascending:
 *Quick sort:162992 microsecs
 *Median sort:849 microsecs
 *Bubble sort:770921 microsecs
 *
 * 20000 elements
 * Random:
 *Quick sort:4351 microsecs
 *Median sort:4763 microsecs
 *Bubble sort:3081417 microsecs
 *Ascending:
 * Quick sort:643132 microsecs
 *Median sort:1614 microsecs
 *Bubble sort:1432023 microsecs
 *
 *30000 elements
 * Random:
 *Quick sort:6636 microsecs
 *Median sort:7342 microsecs
 *Bubble sort:6970965 microsecs
 *Ascending:
 * Quick sort:1480181 microsecs
 *Median sort:2274 microsecs
 *Bubble sort:3371210 microsecs
 *
 *40000 elements
  * Random:
 *Quick sort:9253 microsecs
 *Median sort:9855 microsecs
 *Bubble sort:12405489 microsecs
 *Ascending:
 * Quick sort:2620448 microsecs
 *Median sort:3000 microsecs
 *Bubble sort:5828986 microsecs
 *
 *50000 elements
 * Random:
 *Quick sort:12026 microsecs
 *Median sort:12594 microsecs
 *Bubble sort:19783676 microsecs
 *Ascending:
 * Quick sort: PROGRAM BREAKS
 *Median sort:4528 microsecs
 *Bubble sort:8696095 microsecs
 *
 * PROGRAM SE SESUJE OB SORITIRANJU NARAŠÈUJOÈEGA ZAPOREDJA PRI 1000000 ELEMENTOV
 * Kadar definiramo polje x[10000] in uredimo z quicksortom brez mediano 10000 narašèujoèih elementov, program crashne
 * Èe pa urejamo 10 elementov pa se algoritem normalno izvede
 */
