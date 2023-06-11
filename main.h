#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <bits/stdc++.h>
#include "inventory.h"


using namespace std;

class Restaurant{
	private:
		string name;
	public:
		Restaurant(string x){
			name = x;
		}
		void setName(string y){
			name = y;
		}
		string getName() const{
		    return name;
		}
		void disInfo() const{
		    cout << "\t ****************************** \t\n" 
	        << "\t\t" << name << " \t\n"  
	        << "\t ****************************** \t\n";
		}
}; 

class Menu{	
    private:
    	fstream fin, fout;
		string food[100];
	    int fprice[100];
	    int fnum[100];
	public:
	    friend class UpdateInventory; //gives class UpdateInventory access to private members of Menu class
	    UpdateInventory i1; //UpdateInventory class object to update inventory in MenuSelect function
		Menu(){
		    fin.open("menu.csv", ios::in);
		    fout.open("bill.txt",ios::out | ios::app);
		}
		
	    void displayMenu(){
	    	vector<string> row;
            string line, word;
            int i = 0;
            cout << "\t ****************************** \t\n" 
	        << "\t   Menu Items \t\n"  
	        << "\t ****************************** \t\n";
	        while(!fin.eof()){
	        	row.clear();
  
                // read an entire row and
                // store it in a string variable 'line'
                getline(fin, line);
  
                // used for breaking words
                stringstream s(line);
                while (getline(s, word, ',')) {
                    // add all the column data
                    // of a row to a vector
                    row.push_back(word);
                }
                cout << "\t " << row[0] << ". " << row[1] << "\t" << " ...PKR" << row[2] << endl;
                
                //storing file data in arrays for use within class
                food[i] = row[1];
	            fprice[i] = stoi(row[2]);
	            fnum[i] = stoi(row[0]);
	            i++;
	       }
	       cout << endl;
	    }
	    void menuSelect(){
	    	int selectitems, rollfood, bill = 0;
	    	cout << "\nEnter the no. of items that you would love to select: ";
	    	cin >> selectitems;
            string line, word;
            int sfood[selectitems];
            //unique food id is typed while updating the inventory in the loop section
	    	for(int i = 0; i < selectitems; i++){
	    		cout << "Enter item no.: ";
	    	    cin >> sfood[i]; 
				i1.update_Inventory(sfood[i]);                 
			}
			
			
			cout<<"\n\t------------------------ Bill Details ---------------------\n\n";
	        fout <<"\n\t------------------------ Bill Details ---------------------\n\n";

	        //cout<<"\t---------------------- Taxt total is 400.99 $ ------------------\n\n";
	        //outfile<<"\t---------------------- Taxt total is 400.99 $ ------------------\n\n";

	        cout<<"\t-------------------------- Selected Items -----------------------\n\n";
	        fout <<"\t-------------------------- Selected Items -----------------------\n\n";
	        
	        for(int i = 0; i < selectitems; i++){
	        	cout << endl;
	        	cout << "\t\t\t" << i + 1 << ": " << food[sfood[i] - 1] << "\t\t"<< fprice[sfood[i] - 1] <<"PKR."<<endl;
	        	fout << "\t\t\t" << i + 1 << ": " << food[sfood[i] - 1] << "\t\t"<< fprice[sfood[i] - 1] <<"PKR."<<endl;
	            bill += fprice[sfood[i] - 1];
			}


	        cout<<"\n\t---------------------------- Menu Bill -------------------------\n\n";
	        fout <<"\n\t---------------------------- Menu Bill -------------------------\n\n";

	        cout<<"\t\t\t\t\t\tTotal Bill : "<<bill<<"PKR."<<endl;
	        fout<<"\t\t\t\t\t\tTotal Bill : "<<bill<<"PKR."<<endl;
        }
     
	//operator overloading function definition   
    friend istream &operator >> (istream &i, Menu &m); 
    friend ostream &operator << (ostream &o, Menu &m);
	    
	~Menu(){
		fout.close();
	    fin.close();
	}
};

istream &operator >> (istream &i, Menu &m){
	int selectitems, rollfood, bill = 0;
	cout << "\nEnter the no. of items that you would love to select: ";
	cin >> selectitems;
    string line, word;
    int sfood[selectitems];
	for(int i = 0; i < selectitems; i++){
	    cout << "Enter item no.: ";
	    cin >> sfood[i];  
		m.i1.update_Inventory(sfood[i]);                 
	}
			
			
	cout<<"\n\t------------------------ Bill Details ---------------------\n\n";
	m.fout <<"\n\t------------------------ Bill Details ---------------------\n\n";

	//cout<<"\t---------------------- Taxt total is 400.99 $ ------------------\n\n";
	//outfile<<"\t---------------------- Taxt total is 400.99 $ ------------------\n\n";

	cout<<"\t-------------------------- Selected Items -----------------------\n\n";
	m.fout <<"\t-------------------------- Selected Items -----------------------\n\n";
	        
	for(int i = 0; i < selectitems; i++){
	    cout << "\t\t\t" << i + 1 << ": " << m.food[sfood[i] - 1] << "\t\t"<< m.fprice[sfood[i] - 1] <<"PKR."<<endl;
	    m.fout << "\t\t\t" << i + 1 << ": " << m.food[sfood[i] - 1] << "\t\t"<< m.fprice[sfood[i] - 1] <<"PKR."<<endl;
	    bill += m.fprice[sfood[i] - 1];
	}

    cout<<"\n\t---------------------------- Menu Bill -------------------------\n\n";
	m.fout <<"\n\t---------------------------- Menu Bill -------------------------\n\n";

	cout<<"\t\t\t\t\t\tTotal Bill : "<<bill<<"PKR."<<endl;
	m.fout<<"\t\t\t\t\t\tTotal Bill : "<<bill<<"PKR."<<endl;
}

ostream &operator << (ostream &o, Menu &m){
	vector<string> row;
    string line, word;
    int i = 0;
    cout << "\t ****************************** \t\n" 
	<< "\t   Menu Items \t\n"  
	<< "\t ****************************** \t\n";
	while(!m.fin.eof()){
	    row.clear();
  
        // read an entire row and
        // store it in a string variable 'line'
        getline(m.fin, line);
  
        // used for breaking words
        stringstream s(line);
        while (getline(s, word, ',')) {
            // add all the column data
            // of a row to a vector
            row.push_back(word);
        }
        cout << "\t " << row[0] << ". " << row[1] << "\t" << " ...PKR" << row[2] << endl;
        m.food[i] = row[1];
	    m.fprice[i] = stoi(row[2]);
	    m.fnum[i] = stoi(row[0]);
	    i++;
	    }
	    cout << endl;
}

class Customer{
	protected:
		char *name;
		string *id;
		int *table;
	public:
		Customer(){
			name=new char[100];
			id=new string;
			table = new int;
		}
		virtual void set_detail(){
		} 
		virtual void get_detail() = 0;	
};
class CustomerDetails : public Customer{
	public:
		void set_detail(){
			ofstream out11;
			out11.open("bill.txt",ios::out | ios::app);
			cout<<"\nEnter a your name : ";
			cin.get(name,100); // use charactor case
			cout<<"\n\nEnter a your id_card number : ";
			cin>>*id;
			cout<<"\n\nEnter a your table number : ";
			cin>>*table; 
		}
		void gets_detail(){
			ofstream out12;
			out12.open("bill.txt",ios::out | ios::app);
			cout<<"\nName: "<<name<<endl;
			out12<<"\nName: "<<name<<endl;
			cout<<"\nID_Card: "<<*id<<endl;
			out12<<"ID_Card: "<<*id<<endl;
			cout<<"\nTable: "<<*id<<endl;
			out12<<"Table: "<<*table<<endl;
		}
};

#endif
