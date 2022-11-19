#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct employeeStruct {
    int SSN;
    int ID;
} Employee;
 
typedef struct {
    Employee* ssnSort;
    Employee* idSort;
    int numEmployees;
} EmpDatabase;
 
EmpDatabase createSearchableEmployeeDB(Employee ** m, int count) {
    EmpDatabase newDB;
    newDB.numEmployees = count;
    Employee* ssnArray = malloc(count*sizeof(Employee));
    memcpy(ssnArray, *m, count*sizeof(Employee));
    Employee* idArray = malloc(count*sizeof(Employee));
    memcpy(idArray, *m, count*sizeof(Employee));
    newDB.ssnSort = ssnArray;
    newDB.idSort = idArray;
   
    for (int i=1; i<count; i++) {
        for (int j=i; j-1>=0; j--) {
            if (ssnArray[j].SSN < ssnArray[j-1].SSN) {
                Employee temp = ssnArray[j-1]; // void??? any data type??
                ssnArray[j-1]=ssnArray[j];
                ssnArray[j]=temp;
            }
            else {
                break;
            }
        }
    }
   
    for (int i=1; i<count; i++) {
        for (int j=i; j-1>=0; j--) {
            if (idArray[j].ID < idArray[j-1].ID) {
                Employee temp = idArray[j-1]; // void??? any data type??
                idArray[j-1]=idArray[j];
                idArray[j]=temp;
            }
            else {
                break;
            }
        }
    }
    return newDB;
}
 
Employee* findEmpBySSN (int findSSN, EmpDatabase m) {
    int high = m.numEmployees;
    int low = 0;
    while (low != high) {
        int mid = low + (high-low)/2;
        if (m.ssnSort[mid].SSN == findSSN) {
            return m.ssnSort+low;
        }
        else if (m.ssnSort[mid].SSN > findSSN) {
            high = mid - 1;
        }
        else if (m.ssnSort[mid].SSN < findSSN) {
            low = mid + 1;
        }
    }
    return NULL;  
}
 
Employee* findEmpByID (int findID, EmpDatabase m) {
    int high = m.numEmployees;
    int low = 0;
    while (low != high) {
        int mid = low + (high-low) / 2;
        if (m.idSort[mid].ID == findID) {
            return m.idSort+low;
        }
        else if (m.idSort[mid].ID > findID) {
            high = mid - 1;
        }
        else if (m.ssnSort[mid].ID < findID) {
            low = mid + 1;
        }
    }
    return NULL;
}
 
void freeEmpDatabase (EmpDatabase m) {
    free(m.idSort);
    free(m.ssnSort);
}
 
int main() {
    int count = 10;
    Employee array[count];
    Employee* ptr = array;
    for (int i=0; i<count; i++) {
        array[i].ID = i+1;  // 1 ~ 10
    }
    for (int j=0; j<count; j++) {
        array[j].SSN = j+11; // 11 ~ 20
    }
   
    EmpDatabase dataStore = createSearchableEmployeeDB(&ptr, count);
   
    int ssn1 = 11;
    Employee* foundSSN = findEmpBySSN(ssn1, dataStore);
    if (foundSSN != NULL) printf("ID: %d, SSN: %d\n", foundSSN->ID, foundSSN->SSN);
    else printf("didnt find\n");
 
    // int ssn2 = 250;
    // foundSSN = findEmpBySSN(ssn2, dataStore);
    // if (foundSSN != NULL) printf("ID: %d, SSN: %d\n", foundSSN->ID, foundSSN->SSN);
    // else printf("didnt find\n");
 
    // int id1 = 4;
    // Employee* foundID = findEmpByID(id1, dataStore);
    // if (foundID != NULL) printf("ID: %d, SSN: %d\n", foundID->ID, foundID->SSN);
    // else printf("didnt find\n");
 
    freeEmpDatabase(dataStore);
 
    return 0;
}
