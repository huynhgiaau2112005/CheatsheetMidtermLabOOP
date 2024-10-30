#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class University
{
private:
    string _name;
    string _location;
    int _rank;
    string _description;
    float _tuitionAndFees;
    float _inState;
    float _undergradEnrollment;
public:
    University();
    University(const string& name, const string& location, const int& rank, const string& description,
    const float& tuitionAndFees, const float& inState, const float& undergradEnrollment);
public:
    string name();
    string location();
    int rank();
    string description();
    float tuitionAndFees();
    float inState();
    float undergradEnrollment();
};

class MockUniversityDataProvider
{
public:
    vector<University> getAllUniversities();
};

class PriceConverter
{
public:
    static float PriceToFloat(string price);
    static string FloatToPrice(float price);
};