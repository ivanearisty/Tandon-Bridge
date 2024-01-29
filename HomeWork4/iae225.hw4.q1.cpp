# include <iostream>

using namespace std;

int withWhile();
int withFor();

int main(){
    while(true){
        int choice;
        cout << "Would you like to test for or while loop functionality? 1=for, anythingElse=while" << endl;
        cin >> choice;
        if(choice == 1){
            withFor();
        }else{
            withWhile();
        }
    }

    return 0;
}

int withWhile(){
    int firstN;
    cout << "(While) Please enter a positive integer: ";
    cin >> firstN;
    int i = 1;
    while(i <= firstN){
        cout << i * 2 << endl;
        i++;
    }
    return 0;
}

int withFor(){
    int firstN;
    cout << "(For) Please enter a positive integer: ";
    cin >> firstN;
    for(int i = 1 ; i <= firstN ; i++){
        cout << i * 2 << endl;
    }
    return 0;
}