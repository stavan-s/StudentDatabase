#include<bits/stdc++.h>

int c = 0;
bool exists = false;
bool doNotDelete = false;
bool isPasswordChanged = false;

using namespace std;

string encryptPassword(string pass) {

    string encryptedString = "";

    int i = 0;

    for(char c : pass) {

        if(i >= 0 && i <= 2) {
            encryptedString += c - 3;
            i++;
        }
        else if(i >= 3 && i <= 6) {
            encryptedString += c + 6;
            i++;
        }
        else if(i == 7 || i == 8) {
            encryptedString += c - 12;
            i++;
        }
        else if(i % 2 == 0) {
            encryptedString += c + 2;
            i++;
        }
        else {
            encryptedString += c - 5;
            i++;
        }
        
    }

    return encryptedString;
    
}

string decryptPassword(string pass) {

    string decryptedString = "";

    int i = 0;

    for(char c : pass) {

        if(i >= 0 && i <= 2) {
            decryptedString += c + 3;
            i++;
        }
        else if(i >= 3 && i <= 6) {
            decryptedString += c - 6;
            i++;
        }
        else if(i == 7 || i == 8) {
            decryptedString += c + 12;
            i++;
        }
        else if(i % 2 == 0) {
            decryptedString += c - 2;
            i++;
        }
        else {
            decryptedString += c + 5;
            i++;
        }
        
    }

    return decryptedString;
    
}

bool fileExists(const string& name) {
    ifstream theFile(name.c_str());
    return theFile.good();
}

bool isPasswordValid(string pass) {

    int alphabetCount = 0, digitCount = 0, specialCharacterCount = 0;

    if(pass.length() < 10) {
        cout<<pass.length()<<endl;
        return false;
    }
    else {
        for(char c : pass) {
        
            if(c >= 65 && c <= 90 || c >= 97 && c <= 122) {
                alphabetCount++;
            }
            else if(c >= 48 && c <= 57){
                digitCount++;
            }
            else {
                specialCharacterCount++;
            }
        }

        if(alphabetCount >= 5 && digitCount >= 3 && specialCharacterCount >= 2 )
            return true;
        else 
            return false;
        
    }
    
}

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
    }
    
    WriteFile.close();

}

int returnIdFromLine(string line) {

    string temp = "";
    char delimiter = ';';

    int i = 0;

    while(line[i] != delimiter) {
        
        temp += line[i];
        i++;
    }

    return stoi(temp);

}

void deleteStudentRecord() {

    cout<<"\nEnter the student's Id -> ";
    int Id;
    cin>>Id;

    if(!IdExists(Id)) {
        cout<<endl<<Id<<" does not exist in the whole database"<<endl;
        doNotDelete = true;
        return;
    }

    ifstream OriginalFile("data.txt", ios :: in);
    ofstream TempFile("temp.txt", ios :: out);

    string lineFromFile;

    while(getline(OriginalFile, lineFromFile)) {

        if(returnIdFromLine(lineFromFile) != Id) {

            TempFile << lineFromFile << endl;    
        }   
    }

    TempFile.close();
    OriginalFile.close();

    cout<<"\nRecord erased Successfully!!"<<endl;

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

void updateAdminPassword() {

    ofstream passWriteFile("shadow.txt", ios :: app);
    ifstream passReadFile("shadow.txt", ios :: in);

    system("cls");

    string enteredOldPassword, enteredNewPassword, adminPassword, reEnterNewPassword;
    getline(passReadFile, adminPassword);

    cout<<"Enter admin password to continue -> ";
    cin>>enteredOldPassword;

    jump_here_for_updation_of_password:

    system("cls");

    if(decryptPassword(adminPassword) == enteredOldPassword) {

        cout<<"Please set a password that contains the following:"<<endl;
        cout<<"-> at least 5 alphabets,"<<endl;
        cout<<"-> at least 3 digits,"<<endl;
        cout<<"-> at least 2 special characters."<<endl;

        cout<<"\nEnter new admin password -> ";
        cin>>enteredNewPassword;

        if(isPasswordValid(enteredNewPassword)) {

            cout<<"\nRetype the new admin password -> ";
            cin>>reEnterNewPassword;

            if(reEnterNewPassword == enteredNewPassword) {

                ofstream tempFile("temp.txt", ios :: out);
                
                tempFile << encryptPassword(reEnterNewPassword);
                cout<<"\nAdmin password successfully changed!!"<<endl;
                isPasswordChanged = true;

                tempFile.close();
                
            }
            else {
                cout<<"\nIncorrect Password!!"<<endl;
            }
            
        }
        else {
            system("cls");
            cout<<"Try again..."<<endl;
            goto jump_here_for_updation_of_password;
        }

    }
    else {
        cout<<"\nIncorrect Password!!"<<endl;  
    }

    passReadFile.close();
    passWriteFile.close();
    
}


int main() {

    bool program_running = true, pass_valid = false;

    string admin_password;

    int pass_tries = 1;

    system("cls");

    if(!fileExists("data.txt")) {
        ofstream pass_file("shadow.txt", ios :: out);

        alpha:
        
        cout<<"Please set a password that contains the following:"<<endl;
        cout<<"-> at least 5 alphabets,"<<endl;
        cout<<"-> at least 3 digits,"<<endl;
        cout<<"-> at least 2 special characters."<<endl;
        cout<<"\nEnter the password -> ";
        
        getline(cin, admin_password);

        if(isPasswordValid(admin_password)) {
            string password = encryptPassword(admin_password);

            pass_file << password;

            cout<<"\nPassword Updated Successfully!!\n"<<endl;

            pass_valid = true;

            system("pause");
        }
        else {
            system("cls");
            cout<<"Try again...\n\n";
            goto alpha;
        }
    }
    else {
        string encryptedPassword, enteredPassword;
        ifstream pass_file("shadow.txt", ios :: in);
        getline(pass_file, encryptedPassword);

        system("cls");

        jump_for_pass:

        cout<<"Enter admin password to access the database -> ";
        cin>>enteredPassword;

        if(enteredPassword == decryptPassword(encryptedPassword)) {

            pass_valid = true;
        }
        else {
            system("cls");
            
            if(pass_tries < 3) {
                pass_tries++;
            }
            else if(pass_tries == 3){
                cout<<"Out of chances..."<<endl<<endl;
                system("pause");
                return 0;
            }
            
            cout<<"Try again..."<<endl;
            cout<<3-pass_tries+1<<" Chance left..."<<endl<<endl;
            goto jump_for_pass;
        }
    }

    if(pass_valid) {

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
                cout<<"6. Update admin password"<<endl;
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
                    if(!doNotDelete) {
                        MyReadFile.close();
                        MyWriteFile.close();
                        remove("data.txt");
                        rename("temp.txt", "data.txt");
                    }
                    doNotDelete = false;
                    break;

                case 4:
                    eraseDatabase();
                    break;

                case 5:
                    printEntireDatabase();
                    break;

                case 6:
                    updateAdminPassword();

                    if(isPasswordChanged) {
                        remove("shadow.txt");
                        rename("temp.txt", "shadow.txt");
                        isPasswordChanged = false;
                    }
                    
                    break;
                
                default:
                    cout<<"\nEnter appropriate choice"<<endl;
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
        }
    return 0;
}
