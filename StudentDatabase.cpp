#include<bits/stdc++.h>

using namespace std;

void checkRecord(string inp_string, string checkData, int checkByWhat) {
    

    string studName, studSurname, temp = "";
    int studAge = 0, studId = 0, counter = 0, i = 0;
    string check_delimiter;

    vector<string> vec;

    while(i <= inp_string.length()-1) {

        check_delimiter = inp_string[i];

        if(check_delimiter == ";") {
            vec.push_back(temp);
            temp = "";
        }
        else {
            temp += check_delimiter;
        }

        i++;
    }

    if (checkByWhat == 1) {    
        if(vec.at(1) == checkData) 
            cout<<"  Found -> "<<vec.at(0)<<" "<<vec.at(1)<<" "<<vec.at(2)<<" "<<vec.at(3)<<endl;
    }
    else if (checkByWhat == 2) {
        if(vec.at(2) == checkData) 
            cout<<"  Found -> "<<vec.at(0)<<" "<<vec.at(1)<<" "<<vec.at(2)<<" "<<vec.at(3)<<endl;
    }
    else if (checkByWhat == 3) {
        if(vec.at(0) == checkData) 
            cout<<"  Found -> "<<vec.at(0)<<" "<<vec.at(1)<<" "<<vec.at(2)<<" "<<vec.at(3)<<endl;
    }
    else if (checkByWhat == 4) {
        if(vec.at(3) == checkData) 
            cout<<"  Found -> "<<vec.at(0)<<" "<<vec.at(1)<<" "<<vec.at(2)<<" "<<vec.at(3)<<endl;
    }
    else
        cout<<"\nData not   Found"<<endl;
    
}

void searchStudentRecord() {

    string inp_string, checkData;

    ifstream ReadFile("data.txt", ios :: in);

    cout<<"\n  1. Search by Name"<<endl;
    cout<<"  2. Search by Surname"<<endl;
    cout<<"  3. Search by Id"<<endl;
    cout<<"  4. Search by Age"<<endl;

    int choice;

    cout<<"\n  Enter your choice -> ";
    cin>>choice;

    switch(choice) {

        case 1:
            cout<<"\n  Enter the Name of the student -> ";
            cin>>checkData;
            cout<<endl;

            while(getline(ReadFile, inp_string))
                    checkRecord(inp_string, checkData, 1);
                    

            break;

        case 2:
            
            cout<<"\n  Enter the Surname of the student -> ";
            cin>>checkData;
            cout<<endl;

            while(getline(ReadFile, inp_string))
                    checkRecord(inp_string, checkData, 2);
                    

            break;

        case 3:
            cout<<"\n  Enter the Id of the student -> ";
            cin>>checkData;
            cout<<endl;

            while(getline(ReadFile, inp_string)) 
                    checkRecord(inp_string, checkData, 3);
                    

            break;

        case 4:
            cout<<"\n  Enter the Age of the student -> ";
            cin>>checkData;
            cout<<endl;

            while(getline(ReadFile, inp_string))
                    checkRecord(inp_string, checkData, 4);
                    
        
        default:
            break;
    }

    ReadFile.close();

}

void addStudentRecord() {

    ofstream WriteFile("data.txt", ios :: app);

    string studName, studSurname;
    int studAge, studId;

    cout<<"\nEnter Student's name -> ";
    cin>>studName;

    cout<<"Enter "<<studName<<"'s surname -> ";
    cin>>studSurname;
    
    cout<<"Enter "<<studName<<"'s age -> ";
    cin>>studAge;

    cout<<"Enter "<<studName<<"'s roll no -> ";
    cin>>studId;

    WriteFile << studId << ";" << studName << ";" << studSurname << ";" << studAge << ";" <<endl;

    cout<<"\nRecord successfully stored into database"<<endl;

    WriteFile.close();

}

void deleteStudentRecord() {

    

}

void eraseDatabase() {

    ofstream WriteFile("data.txt", ios :: trunc);
    
    cout<<"\nDatabase erased successfully"<<endl;

    WriteFile.close();

}


int main() {

    bool program_running = true;

    while(program_running) {

        system("cls");

        ofstream MyWriteFile;
        MyWriteFile.open("data.txt", ios :: app);
        
        ifstream MyReadFile;
        MyReadFile.open("data.txt", ios :: in);

        cout<<"1. Search Student's information"<<endl;
        cout<<"2. Add new student record"<<endl;
        cout<<"3. Delete a student record"<<endl;
        cout<<"4. Erase the entire database"<<endl;
        cout<<"0. Exit"<<endl;
        
        int choice;
        cout<<"\nEnter your choice -> ";
        cin>>choice;

        switch (choice)
        {
        case 0:
            return 0;
            break;

        case 1:
            searchStudentRecord();
            break;

        case 2:
            addStudentRecord();
            break;

        case 3:
            deleteStudentRecord();
            break;

        case 4:
            eraseDatabase();
            break;
        
        default:
            break;
        }

        string choice_string;
        
        cout<<"\nDo you want to continue? Enter yes or no -> ";
        cin>>choice_string;

        if(choice_string == "y" || choice_string == "yes" || choice_string == "Yes" || choice_string == "YES")
            program_running = true;
        else
            program_running = false;
        
    }

    return 0;
}
