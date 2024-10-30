#pragma once

#include "University.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class UniversitiesToTableConverter
{
private:
    vector<string> _headers;
    vector<int> _columnSizes;
public:
    UniversitiesToTableConverter();
    UniversitiesToTableConverter(const vector<string>& headers, const vector<int>& columnSizes);
    void setFixedColumnSizes(vector<University>& data);
    string convert(vector<University> universities);
private:
    class UniversitiesToRow
    {
    private:
        vector<int> _columnSizes;
    public:
        UniversitiesToRow();
        UniversitiesToRow(const vector<int>& columnSizes);
        string convert(University& university, const int& index);
    };
};