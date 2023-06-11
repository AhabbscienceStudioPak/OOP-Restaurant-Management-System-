#include <iostream>
#include "main.h"
#include "inventory.h"
#include <bits/stdc++.h>

using namespace std;

int main() {
	char op;
	Restaurant r("Bon Appetit"); //Restaurant Class Object
	Menu m1; //Menu Class Object
	r.disInfo(); //displays Restaurant name
	cout << endl;
	
	//m1.displayMenu();
	cout << m1; //loads displayMenu() function using operator overloading and displays Menu
	
	do{
		//m1.selectMenu();
	    cin >> m1; //loads selectMenu() function using operator overloading and let user select their cuisine
	    
	    cout<<"\nWould you like to continue. (Y/N): ";
	    cin >> op;
	    
	}while((op == 'y') || (op == 'Y'));
	
	Inventory* i1; //Inventory Class Pointer Object
	DisplayInventory i1d; //DisplayInventory Derived Class Object
    i1 = &i1d; // case polymorphism
    cout << endl;
    i1 -> displayInventory(); // runtime use polymorphism
}
