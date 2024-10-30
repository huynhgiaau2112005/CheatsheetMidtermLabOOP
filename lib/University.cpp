#include "University.h"


University::University()
{
    this->_name = "";
    this->_location = "";
    this->_rank = 0;
    this->_description = "";
    this->_tuitionAndFees = 0;
    this->_inState = 0;
    this->_undergradEnrollment = 0;
}

University::University(const string& name, const string& location, const int& rank, const string& description, 
    const float& tuitionAndFees, const float& inState, const float& undergradEnrollment)
{
    this->_name = name;
    this->_location = location;
    this->_rank = rank;
    this->_description = description;
    this->_tuitionAndFees = tuitionAndFees;
    this->_inState = inState;
    this->_undergradEnrollment = undergradEnrollment;
}

string University::name()
{
    return this->_name;
}

string University::location()
{
    return this->_location;
}

int University::rank()
{
    return this->_rank;
}

string University::description()
{
    return this->_description;
}

float University::tuitionAndFees()
{
    return this->_tuitionAndFees;
}

float University::inState()
{
    return this->_inState;
}

float University::undergradEnrollment()
{
    return this->_undergradEnrollment;
}

vector<University> MockUniversityDataProvider::getAllUniversities()
{
    return {
        University("HCMUS", "227 Nguyen Van Cu", 1, "The best school", 32.500, 0, 53.235),
        University("UIT", "Hang Thuyen street", 2, "University Of Science", 42.853, 0, 65.563),
        University("BKU", "268 Ly Thuong Kiet", 3, "Bach Khoa University", 63.485, 0, 43.632),
        University("UEH", "A lot", 4, "University of Economics HCM City", 82.623, 5.321, 42.325),
        University("FTU-HCMC", "Ho Chi Minh City", 5, "Foreign Trade University", 100.523, 5.865, 63.253)
    };
}

float PriceConverter::PriceToFloat(string price)
{
    if (price == "")
    {
        return 0;
    }

    while (!isdigit(price[0]))
    {
        price.erase(0, 1);
    }

    for (char& c : price)
    {
        if (c == ',')
        {
            c = '.';
            break;
        }
    }

    return stof(price);
}

string PriceConverter::FloatToPrice(float price)
{
    stringstream ssPrice;
    ssPrice << fixed << setprecision(3) << price;

    string priceInString = "$ " + ssPrice.str();
    for (char& c : priceInString)
    {
        if (c == ',')
        {
            c = '.';
            break;
        }
    }

    return priceInString;
}