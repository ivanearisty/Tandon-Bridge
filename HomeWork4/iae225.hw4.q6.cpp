# include <iostream>

using namespace std;

int main (){
    int n;
    cout << "Input a number: ";
    cin >> n;

    for(int i = 1 ; i <= n ; i++){

        int temp = i;
        int oddCount = 0;
        int evenCount = 0;

        while(temp != 0){
            int digit = temp % 10;
            temp /= 10;

            if(digit % 2 == 0){
                evenCount++;
            }else{
                oddCount++;
            }
        }

        if(evenCount > oddCount) cout << i << endl;

    }

    return 0;
}