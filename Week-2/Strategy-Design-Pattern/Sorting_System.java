interface SortStrategy {
    void sort(int[] array);
}

class QuickSort implements SortStrategy {
    @Override
    public void sort(int[] array) {
        System.out.println("Sorting using QuickSort");
        // Simplified for demo
    }
}

class MergeSort implements SortStrategy {
    @Override
    public void sort(int[] array) {
        System.out.println("Sorting using MergeSort");
        // Simplified for demo
    }
}

class SortingSystem {
    private SortStrategy sortStrategy;

    public SortingSystem(SortStrategy sortStrategy) {
        this.sortStrategy = sortStrategy;
    }

    public void sortData(int[] array) {
        sortStrategy.sort(array);
    }
}

public class Main {
    public static void main(String[] args) {
        int[] data = {5, 2, 8, 1, 9};
        SortingSystem quickSorter = new SortingSystem(new QuickSort());
        quickSorter.sortData(data);

        SortingSystem mergeSorter = new SortingSystem(new MergeSort());
        mergeSorter.sortData(data);
    }
}