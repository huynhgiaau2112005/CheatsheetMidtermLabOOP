#include "TableConverter.h"

UniversitiesToTableConverter::UniversitiesToTableConverter()
{
    this->_headers = {};
    this->_columnSizes = {};
}

UniversitiesToTableConverter::UniversitiesToTableConverter(const vector<string>& headers, const vector<int>& columnSizes)
{
    this->_headers = headers;
    this->_columnSizes = columnSizes;
}

void UniversitiesToTableConverter::setFixedColumnSizes(vector<University>& data)
{
    this->_columnSizes.clear();
    int maxLen[] = { 
        _headers[0].size(),
        _headers[1].size(),
        _headers[2].size()
    };
    
    int index = 0;
    for (University& element : data)
    {
        int indexLen = to_string(index).size();
        int nameLen = element.name().size();
        int tuitionAndFeesLen = PriceConverter::FloatToPrice(element.tuitionAndFees()).size();

        if (indexLen> maxLen[0])
            maxLen[0] = indexLen;
        if (nameLen > maxLen[1])
            maxLen[1] = nameLen;
        if (tuitionAndFeesLen > maxLen[2])
            maxLen[2] = tuitionAndFeesLen;
    }

    for (int i = 0; i < 3; i++)
    {
        _columnSizes.push_back(maxLen[i] + 1);
    }
}

string UniversitiesToTableConverter::convert(vector<University> universities)
{
    stringstream builder;
    int id = 0;

    // build headers
    for (int i = 0; i < _headers.size(); i++)
    {
        builder << "|" << left << setw(_columnSizes[i]) << _headers[i];
    }
    builder << "|\n";

    // draw the line seperating headers with data
    int rowLength = _columnSizes.size() + 1;
    for (const int& currentRowSize : _columnSizes)
    {
        rowLength += currentRowSize;
    }
    builder << setw(rowLength) << setfill('-') << "" << "\n";

    // draw data's row
    UniversitiesToRow rowConverter(_columnSizes);
    for (int i = 0; i < universities.size(); i++)
    {
        builder << rowConverter.convert(universities[i], i + 1) << "\n";
    }

    return builder.str();
}


UniversitiesToTableConverter::UniversitiesToRow::UniversitiesToRow()
{
    this->_columnSizes = {};
}

UniversitiesToTableConverter::UniversitiesToRow::UniversitiesToRow(const vector<int>& columnSizes)
{
    this->_columnSizes = columnSizes;
}

string UniversitiesToTableConverter::UniversitiesToRow::convert(University& university, const int& index)
{
    stringstream builder;
    builder << "|" << left << setw(_columnSizes[0]) << index 
        << "|" << left << setw(_columnSizes[1]) << university.name()
        << "|" << left << setw(_columnSizes[2]) << PriceConverter::FloatToPrice(university.tuitionAndFees());
    builder << "|";
    return builder.str();
}