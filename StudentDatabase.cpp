#include<bits/stdc++.h>

int c = 0;
bool exists = false;

using namespace std;

char to_lowercase(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + 32;
    }
    return c;
}

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

    studName = vec.at(1);
    studSurname = vec.at(2);
    studId = stoi(vec.at(0));
    studAge = stoi(vec.at(3));


    if (checkByWhat == 1) {    
        if(vec.at(1) == checkData) { 

            studName[0] = toupper(studName[0]);
            studSurname[0] = toupper(studSurname[0]);
            
            c++;
            cout<<"  Found "<<c<<" -> "<<studId<<" "<<studName<<" "<<studSurname<<" "<<studAge<<endl;
            
        }
    }
    else if (checkByWhat == 2) {
        if(vec.at(2) == checkData) { 

            studName[0] = toupper(studName[0]);
            studSurname[0] = toupper(studSurname[0]);
            
            c++;
            cout<<"  Found "<<c<<" -> "<<studId<<" "<<studName<<" "<<studSurname<<" "<<studAge<<endl;
            
        }
    }
    else if (checkByWhat == 3) {
        if(vec.at(0) == checkData) { 
            c++;
            cout<<"  Found "<<c<<" -> "<<studId<<" "<<studName<<" "<<studSurname<<" "<<studAge<<endl;
            
        }
    }
    else if (checkByWhat == 4) {
        if(vec.at(3) == checkData) {
            c++;
            cout<<"  Found "<<c<<" -> "<<studId<<" "<<studName<<" "<<studSurname<<" "<<studAge<<endl;
            
        }
    }
}

void searchStudentRecord() {

    string inp_string, checkData;

    ifstream ReadFile("data.txt", ios :: in);

    cout<<"\n  1. Search by Id"<<endl;
    cout<<"  2. Search by Name"<<endl;
    cout<<"  3. Search by Surname"<<endl;
    cout<<"  4. Search by Age"<<endl;

    int choice;

    cout<<"\n  Enter your choice -> ";
    cin>>choice;

    switch(choice) {

        case 1:

            cout<<"\n  Enter the Id of the student -> ";
            cin>>checkData;
            cout<<endl;

            while(getline(ReadFile, inp_string)) { 
                    checkRecord(inp_string, checkData, 3);
            }
            
            break;

        case 2:
            
            cout<<"\n  Enter the Name of the student -> ";
            cin>>checkData;
            cout<<endl;

            for(char &c : checkData) {
                c = to_lowercase(c);
            }

            while(getline(ReadFile, inp_string)) {

                    for(char &c : inp_string) {
                        c = to_lowercase(c);
                    }
                    
                    checkRecord(inp_string, checkData, 1);
            }

            break;

        case 3:
            
            cout<<"\n  Enter the Surname of the student -> ";
            cin>>checkData;
            cout<<endl;

            for(char &c : checkData) {
                c = to_lowercase(c);
            }

            while(getline(ReadFile, inp_string)) {

                    for(char &c : inp_string) {
                        c = to_lowercase(c);
                    }
                    
                    checkRecord(inp_string, checkData, 2);
            }      

            break;

        case 4:
            cout<<"\n  Enter the Age of the student -> ";
            cin>>checkData;
            cout<<endl;

            while(getline(ReadFile, inp_string)) {
                    checkRecord(inp_string, checkData, 4);
            }

            break;
                    
        
        default:
            break;
    }

    if(c == 0)
        cout<<"  Data not found"<<endl;
    c = 0;

    ReadFile.close();

}

bool IdExists(int Id) {
    
    ifstream ReadFile("data.txt", ios :: in);

    string inp_string, checkDelimiter = ";", tempString = "";

    while(getline(ReadFile, inp_string)) {

        tempString = "";

        for(char c : inp_string) {
            
            if (c == ';') break;
            else tempString += c;
            
        }
        
        if(tempString.length() != 0) {
            if(stoi(tempString) == Id) {
                ReadFile.close();
                return true;
            }
        }
    }
    
    ReadFile.close();
    return false;

}

void addStudentRecord() {

    ofstream WriteFile("data.txt", ios :: app);

    string studName, studSurname;
    int studAge, studId;

    jumpHere:

    cout<<"\nEnter Student's Id -> ";
    cin>>studId;

    if(!IdExists(studId)) {

        cout<<"Enter Student's name -> ";
        cin>>studName;
        
        cout<<"Enter "<<studName<<"'s surname -> ";
        cin>>studSurname;

        cout<<"Enter "<<studName<<"'s age -> ";
        cin>>studAge;

        WriteFile << studId << ";" << studName << ";" << studSurname << ";" << studAge << ";" <<endl;

        cout<<"\nRecord stored into database successfully!!"<<endl;

        exists = false;

        WriteFile.close();

    }
    else {

        cout<<"Id -> "<<studId<<" already exixts in the database. Please enter another one"<<endl;
        goto jumpHere;

        WriteFile.close();

    }

}

void deleteStudentRecord() {

    

}

void eraseDatabase() {

    string choice;

    cout<<"\nAre you sure you want to Erase the entire database??"<<endl;
    cout<<"\nEnter yes or no -> ";
    cin>>choice;

    if(choice == "y" || choice == "yes" || choice == "Yes" || choice == "YES") {

        ofstream WriteFile("data.txt", ios :: trunc);

        cout<<"\nDatabase erased successfully!!"<<endl;

        WriteFile.close();
    }

}

void printRecord(string inp_string) {

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

    studName = vec.at(1);
    studSurname = vec.at(2);
    studId = stoi(vec.at(0));
    studAge = stoi(vec.at(3));

    cout<<studId<<" "<<studName<<" "<<studSurname<<" "<<studAge<<endl<<endl;
    
}

void printEntireDatabase() {

    ifstream ReadFile("data.txt", ios :: in);

    string printString;

    system("cls");

    cout<<"Printing the entire database....\n\n"<<endl;


    while(getline(ReadFile, printString)) {
    
        printRecord(printString);
        
    }

    ReadFile.close();
    
}


int main() {

    bool program_running = true;

    while(program_running) {

        system("cls");

        ofstream MyWriteFile;
        MyWriteFile.open("data.txt", ios :: app);
        
        ifstream MyReadFile;
        MyReadFile.open("data.txt", ios :: in);

        cout<<"1. Search student's information"<<endl;
        cout<<"2. Add new student record"<<endl;
        cout<<"3. Delete a student record"<<endl;
        cout<<"4. Erase the entire database"<<endl;
        cout<<"5. Print whole database"<<endl;
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
            c = 0;
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

        case 5:
            printEntireDatabase();
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
