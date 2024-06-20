#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



typedef struct {
        
    char firstName[6]; 
    char familyName[10];
    int department; //ranges from 1-6
    int dailyCost; //ranges from 1-50
    int numberOfDays; //range 0 - 30 days
    int serverity; //ranges from 0-3, is the level of severity of injury 
         
} patientInfo;


//Function Declartions
void menu(int size);
patientInfo *buildPatientRecords(int size);
void printPatientRecords(patientInfo *patientArray, int size);
void printFamilyName(patientInfo *patientArray);
void summaryOfPatientRecords(patientInfo *patientArray, int size);
void searchFamilyName(patientInfo *patientArray, int size);
void printPatientInfoSize();
void quit(patientInfo *patientArray);


int main(int argc, char *argv[] ){

    int numberOfRecords = atoi(argv[1]);
    
    if(numberOfRecords <= 5 || numberOfRecords >=20){ //To maintain user input
        printf("Enter valid number of Patient Recodrds. \nPatient records must be greater than 5 and less than 20.\n");
    }else{
        menu(numberOfRecords);
    }

return 0;
}

//Builds patient record and returns patient array
patientInfo *buildPatientRecords(int size){

    //Sample Names
    char* firstName[8] = {"Emily", "Liam", "Sophia", "Noah", "Olivia","Ethan", "Ava", "Lucas"};
    char* lastName[5] = {"Smith", "Patel", "Tremblay", "Nguyen", "MacDonald"};
    
    
    patientInfo *patientArray;  //pointer to the aray of patients
    patientArray = (patientInfo*)malloc(size * sizeof(patientInfo)); //memory allocation
    if (patientArray == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    
    srand(time(0)); /* set seed for random number generation */
    for(int i = 0; i < size; i++){
        strcpy(patientArray[i].firstName, firstName[rand() % 8]);
        strcpy(patientArray[i].familyName, lastName[rand() % 5]);
        patientArray[i].department = (rand() % 6) + 1;
        patientArray[i].dailyCost = (rand() % 50) + 1;
        patientArray[i].numberOfDays = (rand() % 31);
        patientArray[i].serverity = (rand() % 4);   
    }    
    return patientArray;  
}


void menu(int size){

    patientInfo *patientArray = buildPatientRecords(size);

    while(1){
        int selection;
        
        printf("\nMenu:\n");
        printf("1. Print all patient records.\n");
        printf("2. Summary of the patient records.\n");
        printf("3. Search for all patients by Family Name.\n");
        printf("4. Size of the structure.\n");
        printf("5. Quit.\n");
        
        
        printf("Enter selection: ");
        scanf("%d", &selection); 
        
        if(selection > 5 || selection <1){
        printf("\n Please enter a valid selection\n"); 
        }else{       
            switch (selection){
                case 1:
                    printPatientRecords(patientArray, size);
                    break; 
                case 2: 
                    summaryOfPatientRecords(patientArray,size);
                    break;  
                case 3:
                    searchFamilyName(patientArray, size);
                    break;
                case 4: 
                    printPatientInfoSize();
                    break;
                case 5: 
                    quit(patientArray);
                    break;     
            
            }
        }
    }

}

//Will print all records
void printPatientRecords(patientInfo *patientArray, int size){
 
    printf("First Name    Last Name    Department    Daily Cost    Number Of Days    Severity\n");
    
    for(int i = 0; i < size; i++){    
        printf("%d)", i+1);
        printf("%-12s",patientArray[i].firstName);
        printf("%-12s", patientArray[i].familyName);
        printf("%-12d", patientArray[i].department);
        printf("%-12d", patientArray[i].dailyCost);
        printf("%-18d", patientArray[i].numberOfDays);
        printf("%-12d\n", patientArray[i].serverity);  

    }
}


//Will print only patients with specified family name 
void printFamilyName(patientInfo *patientArray){
        printf("%-12s",patientArray->firstName);
        printf("%-12s", patientArray->familyName);
        printf("%-12d", patientArray->department);
        printf("%-12d", patientArray->dailyCost);
        printf("%-12d", patientArray->numberOfDays);
        printf("%-12d\n", patientArray->serverity); 
}



void summaryOfPatientRecords(patientInfo *patientArray, int size){
   
    int totalNumOfPatients = size;
    int d1 = 0, d2 = 0, d3 = 0, d4 = 0, d5 = 0, d6 = 0;//num of patients per department
    int avgDailyCost = 0; //For all patients
    int avgDaySpent = 0; //For all patients
    int commonSeverity = 0; //Severity with highest patient count
    int s0 = 0, s1 = 0, s2 = 0, s3 = 0;
    

    //Total number of patients in each department
    for(int i = 0; i < size ; i++){
        if(patientArray[i].department == 1){
            d1++;
        }else if(patientArray[i].department ==2){
            d2++;        
        }else if(patientArray[i].department == 3){
            d3++;        
        }else if(patientArray[i].department == 4){
            d4++;
        }else if(patientArray[i].department == 5){
            d5++;
        }else{
            d6++;
        }
    } 
    
    //avg daily cost
     for(int i = 0; i < size ; i++){
        avgDailyCost += patientArray[i].dailyCost;
    } 
    avgDailyCost = avgDailyCost/size; 
    
    //sum of days spent
    for(int i = 0; i < size ; i++){
        avgDaySpent += patientArray[i].numberOfDays;
    } 
    avgDaySpent = avgDaySpent/size;
    
    //Severity Count   
    for(int i = 0; i < size ; i++){
        if(patientArray[i].serverity == 0){
            s0++;
        }else if(patientArray[i].serverity ==1){
            s1++;        
        }else if(patientArray[i].serverity == 2){
            s2++;        
        }else{
            s3++;
        }
    }  
    
    //Gets max severity count 
    if (s0 >= s1 && s0 >= s2 && s0 >= s3) {
        commonSeverity = 0;
    } else if (s1 >= s0 && s1 >= s2 && s1 >= s3) {
        commonSeverity = 1;
    } else if (s2 >= s0 && s2 >= s1 && s2 >= s3) {
        commonSeverity = 2;
    } else {
        commonSeverity = 3;
    }
      
      
      printf("Total number of patients in the hospital: %d\n", totalNumOfPatients);
      printf("The number of patients by department: \n");
      printf("1)%d \n2)%d \n3)%d \n4)%d \n5)%d \n6)%d \n", d1, d2, d3, d4, d5, d6);
      printf("The average daily cost for all patients: %d \n", avgDailyCost);
      printf("Average number of days each patient spends in the hospital: %d \n", avgDaySpent);
      printf("Severity level with the highest patient count: %d\n", commonSeverity);

}

void searchFamilyName(patientInfo *patientArray, int size){

    char famName[20];
    printf("\nEnter the desired family name to search: ");
    scanf("%s", famName);
    
    int toCheck = 0; //will increment if matching record is found if not then print error
    
    
    for(int i = 0; i < size; i++){
        if(strcmp(patientArray[i].familyName, famName) == 0){
            printFamilyName(&patientArray[i]);
            toCheck++;
        }
    }
    
    if(toCheck == 0){
        printf("Family Name not found in Record.\n");
    }
}

//Prints size of struct
void printPatientInfoSize() {
    printf("Size of patientInfo structure: %lu bytes\n\n", sizeof(patientInfo));
}



void quit(patientInfo *patientArray){
  char toQuit;
    
    printf("Are you sure you want to quit? (y/n): ");
    scanf(" %c", &toQuit);
    
    if (toQuit == 'y' || toQuit == 'Y') {
        free(patientArray);
        printf("Memory has been freed.\n");
        exit(0);
    } else {
        printf("Returning to the menu.\n");
    }

}







