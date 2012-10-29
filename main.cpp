#include "Starbucks.h"
#include "mogulsdStarbucks.h"
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>


using namespace std;

int main(){
	ifstream myfile;
	Entry* starbucksLocations;
	starbucksLocations = new Entry[7700];
	myfile.open("Starbucks_2006.csv");
	int i = 0;
	double userX;
	double userY;
	bool found = false;
	string identifier = "";
	if(myfile.fail())
	{
		cout << "Error: main() ; Failed to open file: " << endl;
		
	}
	else
    {
		cout<<"Please enter an X coordinate (0<X<1) and hit enter" << endl;
		cin>>userX;
		cout<<"Please enter an Y coordinate (0<Y<1) and hit enter" << endl;
		cin>>userY;
		while(!myfile.eof()){
			//tried to eliminate duplicates
			/*getline(myfile, starbucksLocations[i].identifier,',');
			identifier = starbucksLocations[i].identifier;

			for(int j=0;j<i;j++){
				if(starbucksLocations[j].identifier==identifier){
					found = true;
				}
			}
			if(!found){*/
				getline(myfile, starbucksLocations[i].identifier,',');
				myfile>>starbucksLocations[i].x;
				myfile.get();
				myfile>>starbucksLocations[i].y;
				myfile.get();
				i++;
			//}
		}
		myfile.close();
		mogulsdStarbucks* starbucks = new mogulsdStarbucks();
		starbucks ->build(starbucksLocations,7655);
		Entry* nearest = starbucks ->getNearest(userX,userY);
		cout<<"Nearest location "<<nearest->identifier<<" "<<nearest->x<<" "<<nearest->y<<endl;
	}


	cout << "\nPress Any Key to Quit..."<< endl;
	_getch();
	return 0;



}