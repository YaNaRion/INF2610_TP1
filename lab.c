/* INF2610 - TP1
/ Matricule 1 : 
/ Matricule 2 : 
*/
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h> 
#include <stdbool.h>
#include <string.h>


struct Plane {
    char planeType[10];
    bool isAvailable;
    struct Wheel* wheels;
    struct Wing* wings;
    char* id;
};
typedef struct Plane Plane;

struct Wing {
    int* id;
};
typedef struct Wing Wing;

struct Wheel {
    int id;
    bool isRealWheel;
};
typedef struct Wheel Wheel;

Wheel* createWheels(int id) {
    int numberWheel = 7;
    Wheel* wheels = malloc(numberWheel * sizeof(Wheel));
    for (int i = 0; i < numberWheel; i++) {
        Wheel tempWheel;
        tempWheel.id = id;
        tempWheel.isRealWheel = i >= 3;
        wheels[i] = tempWheel;
        id++;
    }
    return wheels;
}

void populateWingAttributes(Wing* wingParam, long id) {
    int MOD_VALUE = 10;
    int arraySize = 9;
    int* idArray = malloc(arraySize * sizeof(Wheel));
    for (int i = arraySize - 1; i >= 0; i--) {
        int modTemp = id % MOD_VALUE;
        id /= MOD_VALUE;
        idArray[i] = modTemp;
    }
    wingParam->id = idArray;
}

Wing* createWings(long id) {
    int numberWings = 2;
    Wing* wings = malloc(numberWings * sizeof(Wheel));
    for (int i = 0; i < numberWings; i++) {
        Wing tempWing;
        populateWingAttributes(&tempWing, id);
        wings[i] = tempWing;
        id++;
    }
    return wings;   
}


void createPlanes(Plane* planes, char* ids, int numberOfPlanes){
    long idForWings = 1;
    int idForWheel = 1;
    for (int i = 0; i < numberOfPlanes; i++){
        Plane* tempsPlane;
        tempsPlane = &(planes[i]);
        planes[i].id = ids;
        
        tempsPlane->id = ids;
        tempsPlane->isAvailable = true;
        tempsPlane->wheels = createWheels(idForWheel);
        tempsPlane->wings = createWings(idForWings);
        
    }
    return;
}

void setAvailability(Plane* plane, bool availability) {
    plane->isAvailable = availability;
}

char** getAvailablePlanes(Plane* plane, int numberOfPlanes){
    char** planeIds = malloc(numberOfPlanes * sizeof(char*));
    for (int i = 0; i < numberOfPlanes; i++) {
        planeIds[i] = plane[i].id;
    }
    return planeIds;
}

void setPlaneType(Plane* plane) {
    int idWing0 = *(plane->wings->id);
    int idWingMod = idWing0 % 9;
    if (idWingMod < 3) {
        strcpy(plane->planeType, "Small");
        //plane->planeType = "small";
    } else if (idWingMod < 6) {
        strcpy(plane->planeType, "Medium");
    } else if (idWingMod < 8) {
        strcpy(plane->planeType, "Large");
    }
    
    

}

Plane* getPlanesByType(Plane* planes, char type[], int planeCount){

    Plane* validPlanes = malloc(sizeof(Plane));
    int validPlaneCount = 0;
    for( int i = 0; i < planeCount; i++){
        if(strcmp(type, planes[i].planeType)) {
            validPlanes[validPlaneCount++] = planes[i];
        }
    }

    return validPlanes;
}


int main(int argc, char** argv) {
    printf("Hello\n");
    /* Remove comment once the code is completed for the given section to test */
    int id = 1;


    /* PARTIE 2 - [10 points] */

    /* Create wheel - [2 points] */
    Wheel* wheels = createWheels(id);

    /* Create wing - [4 points] */
    
    long longId = 1;
    Wing* wings = createWings(longId);
    

    /* Create plane - [4 points] */
    
    int numberOfPlanes = 2;
    char* ids = "toto";
    Plane* planes = malloc(sizeof(Plane) * numberOfPlanes);
    createPlanes(planes, ids, 3);
    printf("id plane 0: %s \n", planes[0].id);
    printf("is Available plane 0: %d \n", planes[0].isAvailable);
    

    /* PARTIE 3 - [6 points] */

    /* Set availabilities - [1 point] */
    
    Plane* plane = &(planes[0]);
    setAvailability(plane, true);
    printf("Availability plane after modification: %d \n", plane->isAvailable);
    

    /* Get available planes - [1 point] */
    
    char** planeAvalible = getAvailablePlanes(planes, numberOfPlanes);
    printf("GetplaneAvalible: %s \n", planeAvalible[0]);

    /* Classify planes - [2 points] */
    
    Plane* planeType = &(planes[1]);
    setPlaneType(planeType);
    printf("plane type: %s \n", planeType->planeType);
    

    /* Return type specific planes - [2 points] */
    
    char planeTypeTest[] = "Small";
    Plane* typedPlanes = getPlanesByType(planes, planeTypeTest,numberOfPlanes);
    
}
