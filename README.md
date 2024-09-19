# Hospital-Patient-Records-Management-System
This project aims to efficiently manage patient records in hospitals by providing functionalities to store, retrieve, and summarize patient information. The program dynamically allocates memory to store patient records and offers various functions to interact with the data.


Functions
void menu(int size)
Displays the menu options for the user to interact with the patient records.

patientInfo *buildPatientRecords(int size)
Dynamically allocates memory to store generated patient information based on the size inputted by the user.

void printPatientRecords(patientInfo *patientArray, int size)
Prints all patient records stored in the array.

void printFamilyName(patientInfo *patientArray)
Prints patient records based on the requested family name.

void summaryOfPatientRecords(patientInfo *patientArray, int size)
Prints a summary of general information, such as the number of patients and the average bill.

void searchFamilyName(patientInfo *patientArray, int size)
Searches through last names based on the user’s request and calls printFamilyName(patientInfo *patientArray) to display the results.

void quit(patientInfo *patientArray)
Quits the program and frees the allocated memory.
