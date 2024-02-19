#include<iostream>
#include<fstream> // for working with the files
#include<sstream>
#include<string>

using namespace std;

int main(){
    int a , i = 0 ;
    string text , old , password1 , password2 , pass, name , password0 , age , user , word , word1;

    string creds[2] , cp[2];

    cout << "       Security System" << endl;
    cout << " ________________________________" << endl ;
    cout << "|           1. Register          |"<< endl;
    cout << "|           2. Login             |"<< endl;
    cout << "|           3. Change Password   |"<< endl;
    cout << "|           4. End Program       |"<< endl;
    cout << "|________________________________|" <<endl<<endl;

    do{
        cout << endl << endl;
        cout <<"Enter Your Choice:- ";
        cin >> a;
        switch(a){
            case 1:{
                cout << " _____________________________" << endl << endl;
                cout << "|-----------Register----------|"<< endl;
                cout << "|_____________________________|" << endl << endl;
                cout << "Please enter your Username:- ";
                cin >> name;
                cout << "Please enter the Password:- ";
                cin >> password0;
                cout << "Please enter your Age:- ";
                cin >> age;

                ofstream of1;
                of1.open("file.txt");
                if(of1.is_open()){
                    of1 << name << "\n";
                    of1 << password0;
                    cout << "Registration Successsfull" << endl;
                }
                break;
            }
            case 2:{
                i = 0;
                cout << " _____________________________" << endl << endl;
                cout << "|------------Login------------|"<< endl;
                cout << "|_____________________________|" << endl << endl;

                ifstream of2;

                of2.open("file.txt");
                cout << "Please enter the Username:- ";
                cin >> user;
                cout << "Please enter the Password:- ";
                cin >> pass;
                
                if(of2.is_open()){
                    while(!of2.eof()){
                        while(getline(of2 , text)){
                            istringstream iss(text);

                            iss >> word;
                            creds[i] = word;
                            i++;
                        }
                        if(user == creds[0] && pass == creds[1]){
                            cout <<"-----Login successful-----";
                            cout << endl << endl;
                            cout <<"Details: "<<endl;
                            cout << "Username: "+ name << endl;
                            cout << "Password: "+ pass << endl;
                            cout << "Age: "+ age << endl;
                        }

                        else{
                            cout << endl<<endl;
                            cout<<"InCorrect Credentials"<<endl;
                            cout<<"|      1. Press 2 to Login              |"<<endl;
                            cout<<"|      1. Press 3 to Change Pasword     |"<<endl;

                            break;
                        }
                    }
                }
                break;
            }

            case 3:{
                i = 0;

                cout << " _____________________________" << endl << endl;
                cout << "|--------Change Password------|"<< endl;
                cout << "|_____________________________|" << endl << endl;
                ifstream of0 ;
                of0.open("file.txt");

                cout<<"Enter the old Password:- ";
                cin >> old;
                if(of0.is_open()){
                    while(!of0.eof()){
                        while(getline(of0 , text)){
                            istringstream iss(text);
                            iss >> word1;
                            cp[i] = word1;
                            i++;
                        }

                        if(old == cp[1]){
                            of0.close();
                            ofstream of1;
                            if(of1.is_open()){
                                cout << "Enter your new Password:- ";
                                cin >> password1;
                                cout << "Enter your Password again:- ";
                                cin >> password2;

                                if(password1 == password2){
                                    of1 << cp[0] << "\n";
                                    of1 << password1;
                                    cout << "Password changed successfully"<<endl;
                                }
                                else{
                                    of1<<cp[0]<<"\n";
                                    of1<<old;
                                    cout<<"Password do not match" << endl;
                                }
                            }
                        }
                        else{
                            cout<<"Please enter a Valid Password" << endl;
                            break;
                        }
                    }
                }
                break;
            }
            case 4: {
                cout << "---------------------Thank You--------------------";
                break;
            }
            default:
                cout << "Enter a Valid Choice";
        }
    }while(a!=4);
    return 0;
}