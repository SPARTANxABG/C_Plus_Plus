
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//main function
int main(){

    //initialize and define vars
    int n,i;
    bool pass;
    double num = 1;
    string roman[7]={"I","IV","V","IX","X","XL","L"};

    //program input loop with sentinel
    while (num != 0){
        
        //roman numeral code switch
        pass = true;

        cout<<"\n--Type 0 to quit program--"<<"\nEnter a whole number between 1 and 50 to convert into roman numerals: ";
        cin>>num;

        //check for unwanted numbers
        if (((num < 1) && (num != 0) )||( num > 50)){
            cout<<"\nERROR: You did not enter a valid number. Try again.\n";
            pass = false;
        }
        else if (num == 0){
            pass = false;
        }
        //check for unwanted numbers
        else if ((int)(num*10)%10 > 0){
            cout<<"\nERROR: You did not enter a valid number. Try again.\n";
            pass = false;
        }

        //roman numeral code
        if (pass == true){
            cout<<"\n";

            //run math and if/else logic to divide input into roman numerals
            n = (int)num/10;

            if (n == 5){
                cout<<roman[6];
            }
            else if (n == 4){
                cout<<roman[5];
            }
            else if (n < 4){
                for (i=1;i<=n;i++){
                    cout<<roman[4];
                }
            }

            n = (int)num % 10;

            if (n == 9){
                cout<<roman[3];
            }
            else if (n >= 5){
                cout<<roman[2];
            }
            else if (n == 4){
                cout<<roman[1];
            }

            if (n>5 && n!=9){
                for (i=1;i<=n-5;i++){
                    cout<<roman[0];
                }
            }
            else if (n<4){
                for (i=1;i<=n;i++){
                    cout<<roman[0];
                }
            }
            cout<<"\n";
        }

    }
    
    //goodbye message
    if (num == 0){
        cout<<"\nThank you for using Roman Converter. Goodbye!\n\n";
    }

    return 0;
}