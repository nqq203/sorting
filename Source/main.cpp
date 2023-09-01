#include "support.h"
#include "sortAlgorithms.h"
#include "DataGenerator.h"

using namespace std;

//MAIN SORT FUNCTION CALL
void sortRunTime(string typesort, int* a, int n, double& time)
{
    clock_t start, end;
    if (typesort == "insertion-sort")
    {
        start = clock();
        insertionSortRunTime(a, n);
        end = clock();
    }
    else if (typesort == "counting-sort")
    {
        start = clock();
        countingSortRunTime(a, n);
        end = clock();
    }
    else if (typesort == "flash-sort")
    {
        start = clock();
        flashSortRunTime(a, n);
        end = clock();
    }
    else if (typesort == "selection-sort")
    {
        start = clock();
        selectionSortRunTime(a, n);
        end = clock();
    }
    else if (typesort == "bubble-sort")
    {
        start = clock();
        bubbleSortRunTime(a, n);
        end = clock();
    }
    else if (typesort == "shaker-sort")
    {
        start = clock();
        shakerSortRunTime(a, n);
        end = clock();
    }
    else if (typesort == "shell-sort")
    {
        start = clock();
        shellSortRunTime(a, n);
        end = clock();
    }
    else if (typesort == "heap-sort")
    {
        start = clock();
        heapSortRunTime(a, n);
        end = clock();
    }
    else if (typesort == "merge-sort")
    {
        start = clock();
        mergeSortRunTime(a, 0, n);
        end = clock();
    }
    else if (typesort == "quick-sort")
    {
        start = clock();
        quickSortRunTime(a, 0, n);
        end = clock();
    }
    else if (typesort == "radix-sort")
    {
        start = clock();
        radixSort_RunTime(a, n);
        end = clock();
    }
    else
        return;
    time = 1000.0 * (double (end) - double (start)) / CLOCKS_PER_SEC;
}
void sortComparison(string typesort, int* a, int n, unsigned long long& count)
{
    count = 0; // reset
    if (typesort == "insertion-sort")
    {
        insertionSortCount(a, n, count);
    }
    else if (typesort == "counting-sort")
    {
        countingSortCount(a, n, count);
    }
    else if (typesort == "flash-sort")
    {
        flashSortCount(a, n, count);
    }
    else if (typesort == "selection-sort")
    {
        selectionSortCount(a, n, count);
    }
    else if (typesort == "bubble-sort")
    {
        bubbleSortCount(a, n, count);
    }
    else if (typesort == "shaker-sort")
    {
        shakerSortCount(a, n, count);
    }
    else if (typesort == "shell-sort")
    {
        shellSortCount(a, n, count);
    }
    else if (typesort == "heap-sort")
    {
        heapSortCount(a, n, count);
    }
    else if (typesort == "merge-sort")
    {
        mergeSort_Comparison(a, 0, n, count);
    }
    else if (typesort == "quick-sort")
    {
        quickSortCount(a, 0, n, count);
    }
    else if (typesort == "radix-sort")
    {
        radixSort_Comparison(a, n, count);
    }
    else
        return;
}

//SOME INPUT & OUTPUT SETUPS
void outputPara(string outputpara, double time, unsigned long long count)
{
    if (outputpara == "-time")
        cout << "Running Time: " << time << endl;
    else if (outputpara == "-comp")
        cout << "Comparisons: " << count << endl;
    else if (outputpara == "-both")
    {
        cout << "Running Time: " << time << endl;
        cout << "Comparisons: " << count << endl;
    }
}
void inputOrder(string inputorder, int &dataType)
{
    if(inputorder=="-rand")
        dataType=0;
    else if (inputorder== "-nsorted")
        dataType=1;
    else if (inputorder=="-sorted")
        dataType=2;
    else if (inputorder=="-rev")
        dataType=3;

}

//COMMANDS
void commandline1(string typesort, string inputfile, string outputpara, int n, int* arr, unsigned long long& count, double& time)
{
    int* b = dynamicArray(n+1);
    copyarray(arr, b, n);
    sortRunTime(typesort, arr, n, time);
    sortComparison(typesort, b, n, count);
    cout << "ALGORITHM MODE\n";
    cout << "Algorithm: " << sortName(typesort) << '\n';
    cout << "Input file: " << inputfile << '\n';
    cout << "Input size: " << n << '\n';
    cout << "-------------------------\n";
    outputPara(outputpara, time, count);
    delete[] b;
}
void commandline2(string typesort, string inputsize, string inputorder, int n, int* a, double& time, unsigned long long& count, string outputpara)
{
    int* b = dynamicArray(n+1);
    copyarray(a, b, n);
    sortRunTime(typesort, a, n, time);
    sortComparison(typesort, b, n, count);
    cout << "ALGORITHM MODE" << endl;
    cout << "Input size: " << inputsize << endl;
    cout << "Input order: " << inputorder << endl;
    cout << "-------------------------------" << endl;
    outputPara(outputpara, time, count);
    delete[] b;
}
void commandline3(string typesort, string inputsize, int n, int* a, double& time, unsigned long long& count, string outputpara)
{
    cout << "ALGORITHM MODE" << endl;
    cout << "Algorithm: " << sortName(typesort) << endl;
    cout << "Input size: " << inputsize << endl;
    cout << endl;

    for (int i = 0; i < 4; i++)
    {
        string line;
        GenerateData(a, n, i);

        int* b = dynamicArray(n+1);
        copyarray(a, b, n);

        if (i == 0)
        {
            writingFileCommand3("input_1.txt", a, n);
            line = "Randomize";
        }
        else if (i == 1)
        {
            writingFileCommand3("input_3.txt", a, n);
            line = "Sorted";
        }
        else if (i == 2)
        {
            writingFileCommand3("input_4.txt", a, n);
            line = "Reversed";
        }
        else
        {
            line = "Nearly Sorted";
            writingFileCommand3("input_2.txt", a, n);
        }
        cout << "Input order: " << line << endl;
        cout << "-----------------------------" << endl;
        sortRunTime(typesort, a, n, time);
        sortComparison(typesort, b, n, count);
        outputPara(outputpara, time, count);
        cout << endl;
        delete[] b;
    }
}
void commandline4(string algo1, string algo2, string giveninput, int n, int* a, double& time1, double& time2, unsigned long long& count1, unsigned long long& count2)
{
    int* b = dynamicArray(n+1);
    int* c = dynamicArray(n+1);
    int* d = dynamicArray(n+1);
    copyarray(a, b, n);
    copyarray(a, c, n);
    copyarray(a, d, n);
    sortRunTime(algo1, a, n, time1);
    sortRunTime(algo2, b, n, time2);
    sortComparison(algo1, c, n, count1);
    sortComparison(algo2, d, n, count2);
    cout << "COMPARE MODE" << endl;
    cout << "Algorithm: " << algo1 << " | " << algo2 << endl;
    cout << "Input file " << giveninput << endl;
    cout << "Input size " << n << endl;
    cout << "---------------------------------" << endl;
    cout << "Running time: " << time1 << " | " << time2 << endl;
    cout << "Comparisons: " << count1 << " | " << count2 << endl;
    delete[] b;
    delete[] c;
    delete[] d;
}
void commandline5(string algo1, string algo2, string inputsize, string inputorder, int& n, int* a, double& time1, double& time2, unsigned long long& count1, unsigned long long& count2)
{
    int* b = dynamicArray(n+1);
    int* c = dynamicArray(n+1);
    int* d = dynamicArray(n+1);
    sortRunTime(algo1, a, n, time1);
    sortRunTime(algo2, b, n, time2);
    sortComparison(algo1, c, n, count1);
    sortComparison(algo2, d, n, count2);
    cout << "COMPARE MODE" << endl;
    cout << "Algorithm: " << algo1 << " | " << algo2 << endl;
    cout << "Input size " << n << endl;
    cout << "Input order " << inputorder << endl;
    cout << "---------------------------------" << endl;
    cout << "Running time: " << time1 << " | " << time2 << endl;
    cout << "Comparisons: " << count1 << " | " << count2 << endl;
    delete[] b;
    delete[] c;
    delete[] d;
}

int main(int argc, char* argv[])
{
    string inputsize, inputorder;
    int n, dataType;
    string typesort;
    string outputpara;
    string inputgiven;

    if (strcmp(argv[1], "-a") == 0)
    {
        double time = 0;
        unsigned long long count = 0;
        if (strcmp(argv[3], "input.txt") == 0)
        {
            typesort = argv[2];
            inputgiven = argv[3];
            outputpara = argv[4];
            readInputsize(n, inputgiven);
            int* a = dynamicArray(n+1);

            readFile(a, n, inputgiven);
            commandline1(typesort, inputgiven, outputpara, n, a, count, time);
        }
        else if (strcmp(argv[4], "-time") == 0 || strcmp(argv[4], "-comp") == 0 || strcmp(argv[4], "-both") == 0)
        {
            inputsize = argv[3];
            outputpara = argv[4];
            typesort = argv[2];
            n = stoi(inputsize);
            int* a = dynamicArray(n+1);
            commandline3(typesort, inputsize, n, a, time, count, outputpara);
        }
        else
        {
            inputsize = argv[3];
            inputorder = argv[4];
            typesort = argv[2];
            outputpara = argv[5];
            n = stoi(inputsize);
            inputOrder(inputorder, dataType);
            int* a = dynamicArray(n+1);
            GenerateData(a, n, dataType);
            writinginputFile(a, n);
            commandline2(typesort, inputsize, inputorder, n, a, time, count, outputpara);
            writingFile(a, n);
        }
    }
    else if (strcmp(argv[1], "-c") == 0)
    {
        double time1 = 0, time2 = 0;
        unsigned long long count1 = 0, count2 = 0;
        string algo1;
        string algo2;
        algo1 = argv[2];
        algo2 = argv[3];
        if (argc == 5)
        {
            inputgiven = argv[4];
            readInputsize(n, inputgiven);
            int* a = dynamicArray(n+1);
            readFile(a, n, inputgiven);
            commandline4(algo1, algo2, inputgiven, n, a, time1, time2, count1, count2);

        }
        else
        {
            inputsize = argv[4];
            inputorder = argv[5];
            n = stoi(inputsize);
            inputOrder(inputorder, dataType);
            int* a = dynamicArray(n+1);
            GenerateData(a, n, dataType);
            writinginputFile(a, n);
            commandline5(algo1, algo2, inputsize, inputorder, n, a, time1, time2, count1, count2);
            writingFile(a, n);
        }
    }

    return 0;
}
