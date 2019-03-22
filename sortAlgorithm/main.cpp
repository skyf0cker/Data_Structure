#include "SortModule.h"

using namespace std;

std::vector<int> SortAlgorithm::data;

int main(int argc, char** argv) {
    SortAlgorithm *s = new SortAlgorithm(20);
    SortAlgorithm *s2 = new SortAlgorithm(20);
    SortAlgorithm *s3 = new SortAlgorithm(20);
    

    double BSTime = s->GetTime(&SortAlgorithm::BubbleSort);
    double ISTime = s2->GetTime(&SortAlgorithm::InsertSort);
    double QSTime = s3->GetTime(&SortAlgorithm::QuickSort);
    cout<<"Time of BS: "<<BSTime<<endl;
    cout<<"Time of IS: "<<ISTime<<endl;
    cout<<"Time of QS: "<<QSTime<<endl;
}