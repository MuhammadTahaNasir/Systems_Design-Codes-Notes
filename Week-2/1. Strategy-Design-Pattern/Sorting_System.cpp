#include <iostream>
#include <vector>

using namespace std;

// Abstract base class
class SortStrategy
{
public:
    virtual void sort(int *array, int size) = 0;
    virtual ~SortStrategy() {} // Virtual destructor for proper cleanup
};

// Concrete strategy: QuickSort
class QuickSort : public SortStrategy
{
public:
    void sort(int *array, int size) override
    {
        cout << "Sorting using QuickSort" << endl;
        // Simplified for demo
    }
};

// Concrete strategy: MergeSort
class MergeSort : public SortStrategy
{
public:
    void sort(int *array, int size) override
    {
        cout << "Sorting using MergeSort" << endl;
        // Simplified for demo
    }
};

// Context class that uses the strategy
class SortingSystem
{
private:
    SortStrategy *sortStrategy;

public:
    SortingSystem(SortStrategy *strategy) : sortStrategy(strategy) {}

    void sortData(int *array, int size)
    {
        sortStrategy->sort(array, size);
    }

    ~SortingSystem()
    {
        delete sortStrategy; // Clean up the strategy object
    }
};

int main()
{
    int data[] = {5, 2, 8, 1, 9};
    int size = sizeof(data) / sizeof(data[0]);

    SortingSystem *quickSorter = new SortingSystem(new QuickSort());
    quickSorter->sortData(data, size);

    SortingSystem *mergeSorter = new SortingSystem(new MergeSort());
    mergeSorter->sortData(data, size);

    delete quickSorter;
    delete mergeSorter;
    return 0;
}