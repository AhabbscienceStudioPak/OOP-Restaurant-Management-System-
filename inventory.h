#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <bits/stdc++.h>

#ifndef INVENTORY_H
#define INVENTORY_H

using namespace std;

class Inventory{
	protected:
		fstream fin1;
		string line;
	public:
		Inventory(){
            // Open an existing record
            fin1.open("inventory.csv", ios::in);
		}
		virtual void displayInventory() = 0;
		~Inventory(){
            // Close an existing record
            fin1.close();
		}		
};

class DisplayInventory : public Inventory{
	public:
		void displayInventory() override {
	    	vector<string> row;
            string line, word;
            cout << "\t ****************************** \t\n" 
	        << "\t   Inventory \t\n"  
	        << "\t ****************************** \t\n";
	        
	        while(!fin1.eof()){
	        	row.clear();
                 
                getline(fin1, line);
                
                // used for breaking words
                stringstream s(line);
                while (getline(s, word, ',')) {
                    // add all the column data
                    // of a row to a vector
                    row.push_back(word);
                }
                cout << row[0] << ". " << row[1] << ": " << row[2] << row[3] << endl;
	       }
	    }
};

class UpdateInventory{
	public:
	UpdateInventory(){

	}
	~UpdateInventory(){
		
	}
    void update_Inventory(int sfood){
    fstream fin1, fout1;
    // Open an existing record
    fin1.open("inventory.csv", ios::in);
    // Create a new file to store updated data
    fout1.open("inventorynew.csv", ios::out);
    int found = 0, i = 0;
	float used=0.0;
    char sub;
    int index, new_marks;
    string line, word, party;
    vector<string> row;
  
    // Traverse the file
    while (!fin1.eof()) {
  
        row.clear();
        //row1.clear();
  
        getline(fin1, line);
        stringstream s(line);
        
        //getline(fin, line1);
        //stringstream s1(line1);
  
        while (getline(s, word, ',')) {
            row.push_back(word);
        }

        int row_size = row.size();

        if (sfood == 1){
        	found = 1;
        	if(stoi(row[0]) == 1){
                stringstream convert;
  
                // sending a number as a stream into output string and adding new votes
                used = stof(row[2]) - 0.5;
                convert << used;
  
                // the str() converts number into string
                row[2] = convert.str();
            }else if(stoi(row[0]) == 5){
                stringstream convert;
  
                // sending a number as a stream into output string and adding new votes
                used = stof(row[2]) - 0.1;
                convert << used; 
				
				// the str() converts number into string
                row[2] = convert.str();           	
			}else if(stoi(row[0]) == 3){
                stringstream convert;
  
                // sending a number as a stream into output string and adding new votes
                used = stof(row[2]) - 1.0;
                convert << used;
				
                // the str() converts number into string
                row[2] = convert.str();				
			}
  
            if (!fin1.eof()) {
                for (i = 0; i < row_size - 1; i++) {
  
                    // write the updated data
                    // into a new file 'inventorynew.csv'
                    // using fout
                    fout1 << row[i] << ",";
                }
  
                fout1 << row[row_size - 1] << endl;
            }
        }
        else if (sfood == 2){
        	found = 1;
        	if(stoi(row[0]) == 2){
                stringstream convert;
  
                // sending a number as a stream into output string and adding new votes
                used = stof(row[2]) - 0.08;
                convert << used;
  
                // the str() converts number into string
                row[2] = convert.str();
            }else if(stoi(row[0]) == 3){
                stringstream convert;
  
                // sending a number as a stream into output string and adding new votes
                used = stof(row[2]) - 0.5;
                convert << used;   
				
                // the str() converts number into string
                row[2] = convert.str();				         	
			}else if(stoi(row[0]) == 7){
                stringstream convert;
  
                // sending a number as a stream into output string and adding new votes
                used = stof(row[2]) - 2.0;
                convert << used;
				
                // the str() converts number into string
                row[2] = convert.str();								
			}
            if (!fin1.eof()) {
                for (i = 0; i < row_size - 1; i++) {
  
                    // write the updated data
                    // into a new file 'inventorynew.csv'
                    // using fout
                    fout1 << row[i] << ",";
                }
  
                fout1 << row[row_size - 1] << endl;
            }			
	    }
        else if (sfood == 3 || sfood == 4 || sfood == 5){
        	found = 1;
        	if(stoi(row[0]) == 2){
                stringstream convert;
  
                // sending a number as a stream into output string and adding new votes
                used = stof(row[2]) - 0.5;
                convert << used;
  
                // the str() converts number into string
                row[2] = convert.str();
            }else if(stoi(row[0]) == 4){
                stringstream convert;
  
                // sending a number as a stream into output string and adding new votes
                used = stof(row[2]) - 1.0;
                convert << used;    
				
                // the str() converts number into string
                row[2] = convert.str();				        	
			}else if(stoi(row[0]) == 5){
                stringstream convert;
  
                // sending a number as a stream into output string and adding new votes
                used = stof(row[2]) - 0.2;
                convert << used;
				
                // the str() converts number into string
                row[2] = convert.str();								
			}else if(stoi(row[0]) == 6){
                stringstream convert;
  
                // sending a number as a stream into output string and adding new votes
                used = stof(row[2]) - 1.0;
                convert << used;
				
                // the str() converts number into string
                row[2] = convert.str();								
			}
            if (!fin1.eof()) {
                for (i = 0; i < row_size - 1; i++) {
  
                    // write the updated data
                    // into a new file 'inventorynew.csv'
                    // using fout
                    fout1 << row[i] << ",";
                }
  
                fout1 << row[row_size - 1] << endl;
            }
        }
        else {
            if (!fin1.eof()) {
                for (i = 0; i < row_size - 1; i++) {
  
                    // writing other existing records
                    // into the new file using fout.
                    fout1 << row[i] << ",";
                }
  
                // the last column data ends with a '\n'
                fout1 << row[row_size - 1] << endl;
            }
        }
        if (fin1.eof())
            break;
    }
    
    //Exception Handling
    try{
    	if (found == 0){
    		throw found;
		}
	}
    catch (int found) {
       cerr << "record not found\n";
    }
  
    fin1.close();
    fout1.close();
  
    // removing the existing file
    remove("inventory.csv");
    // renaming the updated file with the existing file name
    rename("inventorynew.csv", "inventory.csv");
    }	
};

#endif
