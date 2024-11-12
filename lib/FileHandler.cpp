#include "FileHandler.h"

void reformatDataLine(string& line)
{
    for (int i = 0; i < line.size() - 1; )
    {
        if (line[i] == '"')
        {
            line.erase(i, 1);
            if (line[i] == '"')
            {
                i++;
                continue;
            }
            else if (line[i] == ',')
            {
                line[i] = '\n';
            }
            else if (line[i - 1] == ',')
            {
                line[i - 1] = '\n';
            }
        }
        else
        {
            i++;
        }
    }
    line.back() = '\n';
}

void reformatDataLine2(string& line)
{
    int open = false;
    for (int i = 0; i < line.size(); i++)
    {
        if (open == false)
        {
            if (line[i] == ',')
                line[i] = '\n';
            else if (line[i] == '\"')
            {
                line.erase(i, 1);
                open = true;
            }
        }
        else
        {
            if (line[i] == '\"')
            {
                line.erase(i, 1);
                if (i < line.size())
                {
                    if (line[i] == '\"')
                        continue;
                    else if (line[i] == ',')
                    {
                        line[i] = '\n';
                        open = false;
                    }
                }
            }
        }
    }
}

vector<University> readFile(const string& fileName)
{
    ifstream fileStream(fileName.c_str());
    if (!fileStream.is_open())
    {
        cout << "Can not open file \'" << fileName << "\'\n"; 
        return {};
    }
    
    vector<University> data;
    string ignoredBuffer;
    string line;
    string tmp_Name;
    string tmp_Location;
    string tmp_Rank;
    string tmp_Description;
    string tmp_TuitionAndFees;
    string tmp_InState;
    string tmp_UndergradEnrollment;

    getline(fileStream, ignoredBuffer);

    while (!fileStream.eof())
    {
        getline(fileStream, line);
        reformatDataLine2(line);

        stringstream lineStream (line);

        getline(lineStream, tmp_Name);
        getline(lineStream, tmp_Location);
        getline(lineStream, tmp_Rank);
        getline(lineStream, tmp_Description);
        getline(lineStream, tmp_TuitionAndFees);
        getline(lineStream, tmp_InState);
        getline(lineStream, tmp_UndergradEnrollment);

        /*cout << tmp_Name << "\n";
        cout << tmp_Location << "\n";
        cout << tmp_Rank << "\n";
        cout << tmp_Description << "\n";
        cout << tmp_TuitionAndFees << "\n";
        cout << tmp_InState << "\n";
        cout << tmp_UndergradEnrollment << "\n";
        cout << "----------------------------------------------------\n";*/


        data.push_back(
            University(
                tmp_Name, tmp_Location, stoi(tmp_Rank), tmp_Description,
                PriceConverter::PriceToFloat(tmp_TuitionAndFees), PriceConverter::PriceToFloat(tmp_InState), PriceConverter::PriceToFloat(tmp_UndergradEnrollment)
            )
        );
    }
    return data;
}