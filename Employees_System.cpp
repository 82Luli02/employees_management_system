#include <iostream>

using namespace std;

/*
 * Name: Alia AlGhamdi
 * EMAIL: 82Luli02@gmail.com
 */
 
class Employee{

private:
    /* declaring private attributes 
    -access only through setters and getters*/
    string name;
    int ID;
    double Salary;
    Employee *next;
    

public:
    /********************************** Constructors **********************************/
    Employee(string name, int id, double salary){
        this->name = name;
        ID = id;
        Salary = salary;
        next = NULL;
    } 

    Employee(){
        name = "";
        ID = 0;
        Salary = 0;
        next = NULL;
    }
    
    /********************************** Setters **********************************/
    
    void setName(string name){
        this->name = name;
    }
    
    void setSalary(double salary){
        Salary = salary;
    }
    
    void setId(int id){
        ID = id;
    }
    
    void setNext(Employee *next){
        this->next = next;
    }
    
    /********************************** Getters **********************************/
    
    string getName(){
        return name;
    }
    
    double getSalary(){
        return Salary;
    }
    
    Employee *getNext(){
        return next;
    }
    
    int getId(){
        return ID;
    }
    
};//end of Employee class


class EmployeeList {

private:
    Employee *head;
    int count =1; // to display ordered number of employees

public:
    
    /********************************** Constructors **********************************/
    EmployeeList(Employee *head){
        this->head= head ;
    }
    
    EmployeeList(){
        head = NULL;
    }
     
    /********************************** Setter **********************************/
    void setHead(Employee *head){
        this->head = head;
    }   

    /********************************** Getter **********************************/
    Employee *getHead(){
        return head;
    }
        
    //--------1st method  
    void insertEmployment(int id, string name, double salary){
        Employee *newEmpolyee = new Employee(); 
        Employee *temp = head;
        
        newEmpolyee->setId(id);
        newEmpolyee->setSalary(salary);
        newEmpolyee->setName(name);
        

        if (head == NULL){ //To check if the list is empty
            newEmpolyee->setNext(head);
            head = newEmpolyee; 
            return;
        }
        
        else{
            while (temp->getNext() != NULL){
                temp = temp->getNext(); // continue traversing 
            }
            
            // inserting value at the last node
            newEmpolyee->setNext(temp->getNext());
            temp->setNext(newEmpolyee);
        }
    }//end of insertEmployment method
    
    //--------2nd method 
    void findEmploymentInfoId(int id) {
        Employee *temp = head;
        
            while (temp != NULL) { // to access every node
                if (temp->getId() == id) {
                    cout << "Employee found\n\n";
                    cout << "Employee Name: " << temp->getName() << endl;
                    cout << "Employee ID: " << temp->getId() << endl;
                    cout << "Employee Salary: " << temp->getSalary() << endl;
                    return;
                }
                temp = temp->getNext();// continue traversing 
            }
         cout<< "There is no record of this employee in this system"<<endl; // when the employee doesn't exist    
    }//end of findEmploymentInfoId method
    
    //--------3rd method 
    void deleteEmploymentId(int id) {
        if (head->getId() == id){ // if node to delete is the first node
             head = head->getNext();
            cout << "The employee With ID '" << id << "' was successfully deleted from the List "<<endl;
        }
        else{
            Employee *temp = head;
            // Traverse to correct deletion point
            while (temp->getNext() != NULL) {
                if (temp->getNext()->getId() == id) {
                    temp->setNext(temp->getNext()->getNext());
                    cout << "The employee With ID '" << id << "' was successfully deleted from the List "<<endl;
                    return;
                }
                temp = temp->getNext();// continue traversing 
            }//end of while loop
           cout << "\nThere is no employee with the id '"<<id<<"' in the system"<<endl;
        }
    }//end of deleteEmploymentId method
    
    //--------4th method
    void searchHightSalary() {
        Employee *temp = head;
        Employee *largest = head;
        double max = 0;
        while (temp != NULL) { // to chek every node
            if (temp->getSalary() > max) {
                max = temp->getSalary(); 
            }
            temp = temp->getNext();// continue traversing 
        }
        
        cout<<"The employee with the highest salary is: \n";
        
        while (largest != NULL) {// to chek every node
            if (largest->getSalary() == max) {
                cout << "Employee Name: " << largest->getName() << endl;
                cout << "Employee ID: " << largest->getId() << endl;
                cout << "Employee Salary: " << largest->getSalary() << endl << "\n";
            }//end of if condition
            
            largest = largest->getNext(); // continue traversing 
        }//end of while loop
        
    }//end of searchHightSalary meyhod
    
    //--------5th method
    void displayAllEmployement() {
        Employee *temp = head;
        
        cout<<"The list of employees in the system are: \n"<<endl;

        while (temp != NULL) {
            // Print the data value of the node
            cout << count <<"- Employee Name:" << temp->getName();
            cout << "\nEmployee ID:" << temp->getId();
            cout << "\nEmployee Salary:" << temp->getSalary()<<" S.R";
            cout << "\n---------------------------------------\n";
            temp = temp->getNext(); // continue traversing 
            count++;
        }//end of while loop
        cout << endl;
    }//end of displayAllEmployement method
    
    //--------6th method
    void reverseDisplayAllEmployments(Employee *temp) {
        if (temp == NULL) { // base case
            return;
        }//end of if condition
        
        else {
            if(count>1){
            reverseDisplayAllEmployments(temp->getNext()); // recursion 
            cout <<count-1<<"- Employee Name:" << temp->getName() << endl
                 << "Employee ID:" << temp->getId() << endl
                 << "Employee Salary:" << temp->getSalary() << " S.R"
                 << "\n---------------------------------------\n";
            count--;
            }
        }//end of else
    }//end of reverseDisplayAllEmployments method
    
};//end of EmployeeList class

//class Project1{
int main(){
    // declaring variables 
    int inputNum;
    string name;
    int id;
    double salary;
    int deletedEmp;
    EmployeeList *empList = new EmployeeList(); // empList is an object from the class EmployeeList
   
    do {
        cout << "\n\n************************************************************"
             << "\n**************** EMPLOYEE MANAGEMENT SYSTEM ****************" 
             << "\n************************************************************\n\n";
        cout<< "\n1-->Press '1' to INSERT EMPLOYMENT:" 
            << "\n2-->Press '2' to FIND EMPLOYMENT INFO ID:"
            << "\n3-->Press '3' to DELETE EMPLOYMENT ID" 
            << "\n4-->Press '4' to SEARCH HIGHEST SALARY:" 
            << "\n5-->Press '5' to DISPLAY ALL EMPLOYMENTS:"  
            << "\n6-->Press '6' to REVERSE DISPLAY ALL EMPLOYMENTS:" 
            << "\n7-->Press '7' to Exit:\n\n";

        cout << "Choose a number from the menu: ";
        cin >> inputNum;

        switch (inputNum) {
        case 1:
            cout  <<"\n**INSERTEMPLOYMENT**\n";
            cout << "\nEnter Employee Name: ";
            cin.ignore();   //To ignore white spaces 
            getline(cin, name);
            cout << "Enter Employee ID: ";
            cin >> id;
            cout << "Enter Employee salary: ";
            cin >> salary;
            empList->insertEmployment(id, name, salary);
            cout << "The employee record was added successfully.\n\n";
            break;
            
        case 2:
            cout << "\n**FINDEMPLOYMENTINFO ID**\n";
            
            if (empList->getHead() != NULL) { //To check if list is not empty
                cout << "Enter Employee id: ";
                cin >> id;
                empList->findEmploymentInfoId(id);
            }//end of if condition
            
            else{
                cout << "The List is Empty"<<endl;
            }
            
            break;
            
        case 3:
            cout <<"\n**DELETEEMPLOYMENT ID**\n";

            if (empList->getHead() != NULL) { //To check if list isn't empty
                
                cout << "Enter Employee Id: ";
                cin >> deletedEmp;
                empList->deleteEmploymentId(deletedEmp);
            }//end of if condition
            
            else{
                cout << "The List is Empty."<<endl;
            }
            
            break;
            
        case 4:
            cout << "\n**SEARCHHIGHESTSALARY**\n";
            
            if (empList->getHead() != NULL) { //To chek if list is not empty
                empList->searchHightSalary();
            }//end of if condition
            
            else{
                cout << "The List is Empty."<<endl;
            }
            
            break;
            
        case 5:
            cout  << "\n**DISPLAYALLEMPLOYMENTS**\n\n";

            if (empList->getHead() != NULL) { //To chek if list is not empty
                empList->displayAllEmployement();
            }//end of if condition
            
            else{
                cout << "The List is Empty."<<endl;
            }
            
            break;
            
        case 6:
            cout << "\n**REVERSEDISPLAYALLEMPLOYMENTS**\n";
            
            if (empList->getHead() != NULL) { //To chek if list is not empty
                Employee* temp = empList->getHead();
                empList->reverseDisplayAllEmployments(temp);
            }//end of if condition
            
            else{
                cout << "The List is Empty."<<endl;
            }
            
            break;
            
        case 7:
            cout << "Thank you, \nProgram ended.."<<endl;
            break;
            
        default:
            cout << "Invalid input, re-try"<<endl;

        }//end of switch

    } while (inputNum != 7);


    return 0;
}