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
	bool found = false;
	string identifier = "";
	if(myfile.fail())
	{
		cout << "Error: main() ; Failed to open file: " << endl;
		
	}
	else
    {
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
		Entry* nearest = starbucks ->getNearest(.5,.5);
		cout<<"Nearest location "<<nearest->identifier<<" "<<nearest->x<<" "<<nearest->y<<endl;
	}


	cout << "\nPress Any Key to Quit..."<< endl;
	_getch();
	return 0;



}