# Hospital-Patient-Records-Management-System
For Efficient Management of Patient Records in Hospitals



Functions
void menu(int size);
  
patientInfo *buildPatientRecords(int size);
    Dynamically allocates memory to store generated patient information, based on size inputed by user. 
    
void printPatientRecords(patientInfo *patientArray, int size);
    Prints all patient record
    
void printFamilyName(patientInfo *patientArray);
    Prints based on requested family name
    
void summaryOfPatientRecords(patientInfo *patientArray, int size);
    Prints summary of general information (i.e no of patients, average bill etc)

void searchFamilyName(patientInfo *patientArray, int size);
    searches throgh last names based on users request, it will then call printFamilyName(patientInfo *patientArray).

void quit(patientInfo *patientArray);
    Quits and frees memory
