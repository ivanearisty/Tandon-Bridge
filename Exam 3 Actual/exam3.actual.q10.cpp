#include <iostream>
#include <vector>

using namespace std;

class Electronic{
	public:
		virtual void showImage(int integer) const = 0;

};

class Television : public Electronic{

	public:
		void showImage(int integer) const override {
			cout << integer << " Television" << endl;
		}
};

class Computer : public Electronic{

	public:
		void showImage(int integer) const override {
			cout << integer << " Computer" << endl;
		}
};

int main(){

	vector<Electronic*> electronics;

	Computer *aComputer = new Computer();
	Television *aTelevision= new Television();
	Television *aNotherTelevision= new Television();

	electronics.push_back(aComputer);
	electronics.push_back(aTelevision);
	electronics.push_back(aNotherTelevision);

	int anInt = 0;

	for(const auto& elec : electronics){
		elec->showImage(anInt++);
	}

	return 0;
}