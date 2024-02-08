# Group Project
SOFT20091 Software Design and Implementation Coursework Assessment
Group A2 Dustin Sumartlie, Leasther Anak Peter, Rodney Sydney, Weiyi Zhu

Code Description
This program is intended to simulate an e-transport marketplace. The program works with three user types, namely cargo owner, transportation company, and driver. Each user type would have unique functionalities depending on their needs.

As the program is yet unfinished, this document will only talk about functionalities that are already implemented. Currently, all three user types are able to register for an account. The registration form takes in the user input and inserts them into a SQLite database.

For easier organisation, all the classes used in this program are included in separate header files. There is a header file for the User class, and header files for each user type, which inherits common attributes from User. There is also a header file for the Cargo class, which includes the dimensions and condition of the cargo.

Coding Standards Statement
This repository follows the below standard:

The code is written in C++ with SQL integration (via SQLite 3) for database management using the Visual Studio 2022 IDE
Function and variable naming should follow camelCase naming convention
Classes are organised into header (.h) files and cpp (.cpp) files
Comments are used to further elaborate on code where necessary
Reference Manual
Classes
User
cargoOwner : protected User
Driver : protected User
transportComp : protected User
Cargo
Cities
Order : protected Cargo, Cities
Lorries
Functions
User class:
void setFName(string fn);
void setSName(string sn);
void setUsername(string un);
void setPass(string p);
void setEmail(string e);
void setAddress(string a);
void setUType(string ut);
void setMobileNo(int no);
void setBNo(int bno);
void setBAdd(string badd);
string getFName();
string getSName();
string getUsername();
string getPass();
string getEmail();
string getAddress();
string getUType();
string getMobileNo();
string getBNo();
string getBAdd();
cargoOwner class:
void cargoOwnerDBStart();
void cargoOwnerReg();
void cargoOwnerLogin();
void fetchUserID(string username, string password);
int getUserID() const { return caOwID; }
Driver class:
void driverDBStart();
void driverReg();
void driverLogin();
transportComp class:
void tcDBStart();
void tcReg();
void tcLogin();
Cargo class:
void inputDimensions();
int getHeight() const { return cargoHeight; }
int getWidth() const { return cargoWidth; }
int getLength() const { return cargoLength; }
int getWeight() const { return cargoWeight; }
int getLorryType() const { return lorryType; }
std::string getCondition() const { return cargoCondition; }
Cities class:
int citiesCalc();
std::string getOriginCityName() const { return originCityName; }
std::string getDestCityName() const { return destCityName; }
int getDist() const { return dist; }
Order class:
void orderDBStart();
void orderDBInsert(cargoOwner caOw);
void placeOrder(cargoOwner caOw);
void viewOrder(cargoOwner caOw);
void feeCalc();
Lorries class:
void lorryDBStart();
Hash password:
string hashPassword(string password);
Test Tables
Test tables are included within the report file 'Group_A2_SDI_Report' within submission folder

Instructions for SQLite 3 Integration
Please follow the below instructions to enable SQLite 3 integration when cloning the repository:

Navigate to the directory in your machine where the repository is cloned
Find the sqlite-amalgamation-3400100 folder
Copy the path to the sqlite-amalgamation-3400100 folder ("...\sqlite-amalgamation-3400100")
On the Visual Studio Solution Explorer, access the solution's properties by right-clicking on sdi_coursework and selecting Properties
Select VC++ Directories
Click on the Include Directories section and click on the downwards arrow on the right side to open the dropdown menu
Select <Edit...>
Paste the path to the sqlite-amalgamation-3400100 folder into the Include Directories section
Follow the same steps to paste the path to the Library Directories section
Click Apply to apply the changes
If all the above steps are successful, SQLite 3 integration should be enabled on your local clone of the repository
Instructions for OpenSSL
Please follow the below instructions to enable OpenSSL hashing for password when cloning the repository:

Navigate to the directory in your machine where the repository is cloned
Find the OpenSSL-Win64 folder
Copy the path to the include folder within the OpenSSL-Win64 folder ("...\OpenSSL-Win64\include")
On the Visual Studio Solution Explorer, access the solution's properties by right-clicking on sdi_coursework and selecting Properties
Select C/C++ -> General
Click on the Additional Include Directories section and click on the downwards arrow on the right side to open the dropdown menu
Select <Edit...>
Paste the path to the OpenSSL-Win64\include folder
Navigate back to the OpenSSL-Win64 folder and copy the path to the lib folder within the OpenSSL-Win64 folder ("...\OpenSSL-Win64\lib")
On the solution properties, select Linker -> General
Click on the Additional Library Directories section and click on the downwards arrow on the right side to open the dropdown menu
Select <Edit...>
Paste the path to the OpenSSL-Win64\lib folder
Select Linker -> Input
Click on the Additional Dependencies section and click on the downwards arrow on the right side to open the dropdown menu
Select <Edit...>
Type libssl.lib
On a new line, type libcrypto.lib and click OK
Click Apply to apply the changes
If all the above steps are successful, OpenSSL should be enabled on your local clone of the repository
Known Possible Issues
If you are getting error C1083, follow the below instructions:

On the Visual Studio Solution Explorer, navigate to Source Files and find the sqlite3.c file
Right-click on sqlite3.c and delete the file
Re-add the sqlite3.c file by right-clicking Source Files -> Add -> Existing Item..., navigate to the folder where the repository files are located, and select sqlite3.c inside the sqlite-amalgamation-3400100 folder
If you are getting error LNK1104: Cannot open file 'kernel32.lib', follow the below instructions:

On the Visual Studio Solution Explorer, access the solution's properties by right-clicking on sdi_coursework and selecting Properties
Select VC++ Directories
Click on the Include Directories section and click on the downwards arrow on the right side to open the dropdown menu
Select inherit from parent
