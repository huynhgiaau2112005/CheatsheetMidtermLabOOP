#include "main.h"

int main()
{
    vector<string> headers = {"ID", "Name", "Tuition"};
    vector<int> columnSizes = {5, 10, 20};

    UniversitiesToTableConverter tableConverter(headers, columnSizes);
    //MockUniversityDataProvider mockDataProvider;
    //vector<University> data = mockDataProvider.getAllUniversities();
    vector<University> data = readFile("../UniversitiesRankings.csv");
    
    sort(data.begin(), data.end(), comparator);

    vector<University> outputData (data.begin(), data.begin() + 10);
    tableConverter.setFixedColumnSizes(outputData);

    cout << tableConverter.convert(outputData) << "\n\n";

    return 0;
}

bool comparator(University& a, University& b)
{
    if (a.tuitionAndFees() != b.tuitionAndFees())
    {
        return a.tuitionAndFees() > b.tuitionAndFees();
    }
    else return a.rank() > b.rank();
}