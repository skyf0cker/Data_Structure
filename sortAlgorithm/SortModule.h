#include <iostream>
#include <vector>
#include <random>
#include <functional>
#include <ctime>

class SortAlgorithm{
    public:
        SortAlgorithm(int _size);
        static std::vector<int> BubbleSort();
        static std::vector<int> InsertSort();
        static std::vector<int> QuickSort();
        static std::vector<int> QuickSortPart(std::vector<int>);
        static std::vector<int> MergeInsert();
        static double GetTime(std::vector<int> (*func)());
        static std::vector<int> data;
};

SortAlgorithm::SortAlgorithm(int _size) {
    srand(time(0));
    std::vector<int> vec({});
    for (int i = 0; i < _size; i++) {
        vec.push_back(rand());
    }
    data = vec;
}

std::vector<int> SortAlgorithm::BubbleSort() {
    int _size = data.size();
    for (int loop = 0;loop < _size; loop++) {
        for (int comPos = 0;comPos < _size - loop; comPos++) {
            if (data[comPos] > data[comPos + 1]) {
                int temp = 0;
                temp = data[comPos];
                data[comPos] = data[comPos+1];                
                data[comPos+1] = temp;
            }
        }        
    }
    return data;
}

std::vector<int> SortAlgorithm::InsertSort() {
    int max_bound = data.size();
    for (int bound = 1; bound < max_bound; bound++) {
        for (int comPos = bound;comPos > 0; comPos--) {
            if (data[comPos] < data[comPos-1]) {
                int temp = 0;
                temp = data[comPos];
                data[comPos] = data[comPos-1];
                data[comPos-1] = temp;
            } else {
                break;
            }
        }
    }
    return data;
}

std::vector<int> SortAlgorithm::QuickSortPart(std::vector<int> data) {
    int sential = 0;
    int standard = data.size()-1;
    // for (int i:data) {
    //     std::cout<<i<<",";
    // }
    // std::cout<<std::endl;
    // std::cout<<"standard value:"<<data[standard]<<std::endl;
    if (data.size() >= 2) {
        while(sential != standard){
            // std::cout<<"sential index: "<<sential<<std::endl;
            // std::cout<<"standard index: "<<standard<<std::endl;
            // std::cout<<"test value:"<<sential - standard<<std::endl;
            // std::cout<<"test value: "<<data[sential] - data[standard]<<std::endl;
            // std::cout<<"sential value: "<<data[sential]<<std::endl;
            // std::cout<<"stanndard value:"<<data[standard]<<std::endl;
            // std::cout<<"judge value: "<<(data[sential]-data[standard])*(sential-standard)<<std::endl;
            if (((data[sential]-data[standard])/10000)*(sential-standard) < 0) {
                int temp = 0;
                temp = data[sential];
                data[sential] = data[standard];
                data[standard] = temp;
                temp = sential;
                sential = standard;
                standard = temp;
                // std::cout<<data[sential]<<" > "<<data[standard]<<". so change the pos!"<<std::endl;
                // std::cout<<"sential index:"<<sential<<", standard index:"<<standard<<std::endl;
                // std::cout<<"sential value:"<<data[sential]/10000<<", standard value:"<<data[standard]/10000<<std::endl;
                // for (int i:data) {
                //     std::cout<<i<<",";
                // }
                // std::cout<<std::endl;
            }
            if (standard > sential) {
                // std::cout<<"sential add 1"<<std::endl;
                sential++;
            } else {
                // std::cout<<"sential reduce 1"<<std::endl;
                sential--;
            }
        }
        std::vector<int> vecLeft;
        std::vector<int> vecRight;

        vecLeft.insert(vecLeft.end(), data.begin(), data.begin()+standard);
        vecRight.insert(vecRight.end(), data.begin()+standard, data.end());

        vecLeft = QuickSortPart(vecLeft);
        vecRight = QuickSortPart(vecRight);

        vecLeft.insert(vecLeft.end(), vecRight.begin(), vecRight.end());
        return vecLeft;
    } else {
        return data;
    }
    
}

std::vector<int> SortAlgorithm::QuickSort() {
    std::vector<int> result =  QuickSortPart(data);
    return result;
}

double SortAlgorithm::GetTime(std::vector<int> (*func)()) {
    clock_t start = clock();
    func();
    clock_t finish = clock();
    return (finish-start)/(double)CLOCKS_PER_SEC;
}



