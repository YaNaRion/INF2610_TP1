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


struct Plane {
    char planeType[10];
    bool isAvailable;
    struct Wheel* wheels;
    struct Wing* wings;
    char id[];
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


void createPlanes(Plane** planes, char** ids, int numberOfPlanes){
    for (int i = 0; i < numberOfPlanes; i++){
        planes[i]->id = ids[i];
    }
    return;
}


int main(int argc, char** argv) {
    printf("Hello\n");
    /* Remove comment once the code is completed for the given section to test */
    int id = 1;


    /* PARTIE 2 - [10 points] */

    /* Create wheel - [2 points] */
    Wheel* wheels = createWheels(id);    
    printf("%d", wheels[3].isRealWheel);

    /* Create wing - [4 points] */
    
    long longId = 1;
    Wing* wings = createWings(longId);
    printf("%d", wings[0].id[8]);
    

    /* Create plane - [4 points] */
    /*
    int numberOfPlanes = 3;
    Plane* planes = malloc(sizeof(Plane) * numberOfPlanes);
    createPlanes(planes, *id, 3);
    */

    /* PARTIE 3 - [6 points] */

    /* Set availabilities - [1 point] */
    /*
    Plane plane = planes[0];
    setAvailability(plane, true);
    */

    /* Get available planes - [1 point] */
    /*
    getAvailablePlanes(planes, numberOfPlanes);
    */

    /* Classify planes - [2 points] */
    /*
    Plane plane = planes[1];
    setPlaneType(plane);
    */

    /* Return type specific planes - [2 points] */
    /*
    char planeType[] = "Small";
    getPlanesByType(planes, planeType,numberOfPlanes);
    */
}
