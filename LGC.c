#include <stdio.h>                                                                                                                                                
#include <stdlib.h>
#include <string.h>

struct Animal {
    char name[50];
    int age;
    char species[50];
    struct Animal* nextAnimal;
};

struct Exhibit {
    char name[50];
    int capacity;
    struct Animal* nextAnimal;
    struct Exhibit* nextExhibit;
};


//print_exhibits that prints each new name at the front
void printExhibits(struct Exhibit* allExhibit) {
    struct Exhibit* currentExhibit = allExhibit;

    while(currentExhibit != NULL) {
        printf("%s", currentExhibit->name);

        if(currentExhibit->nextExhibit != NULL) {
            printf(" -> ");
        }
        else {
            printf("\n\n");
        }
        currentExhibit = currentExhibit->nextExhibit;
    }
}
void printAnimals(struct Animal* allAnimals) {
    struct Animal* currentAnimal = allAnimals;
 //struct Animal* animal = animal->allAnimals;
    //ASSIGN animalList AT START
//    if(animal == NULL) {
  //      printf("No animals");
   // }
   // else {
        while(currentAnimal != NULL) {
            printf("Name: %s\n", currentAnimal->name);
            printf("Age: %d\n", currentAnimal->age);
            printf("Species: %s\n", currentAnimal->species);

            currentAnimal = currentAnimal->nextAnimal;
        }
        //ARE YOU REASSIGNING TO Animal ANYWHERE?
    }
//}
struct Exhibit* createNewExhibit(const char* name, int capacity) {
    struct Exhibit* newExhibit = (struct Exhibit*)malloc(sizeof(struct Exhibit));
    if (newExhibit == NULL) {
        printf("Failed to allocate memory for new exhibit.\n");
        return NULL;
    }

    strncpy(newExhibit->name, name, sizeof(newExhibit->name) - 1);
    newExhibit->name[sizeof(newExhibit->name) - 1] = '\0'; // Ensure null-termination
    newExhibit->capacity = capacity;
    newExhibit->nextAnimal = NULL;
    newExhibit->nextExhibit = NULL;

    return newExhibit;
}
struct Animal* createNewAnimal(const char* name, int age, const char* species) {
    struct Animal* newAnimal = (struct Animal*)malloc(sizeof(struct Animal));
    if (newAnimal == NULL) {
        printf("Failed to allocate memory for new animal.\n");
        return NULL;
    }

    strncpy(newAnimal->name, name, sizeof(newAnimal->name) - 1);
    newAnimal->name[sizeof(newAnimal->name) - 1] = '\0'; // Ensure null-termination
    newAnimal->age = age;
    strncpy(newAnimal->species, species, sizeof(newAnimal->species) - 1);
    newAnimal->species[sizeof(newAnimal->species) - 1] = '\0'; // Ensure null-termination
    newAnimal->nextAnimal = NULL;

    return newAnimal;
}

//insert_exhibit+at_front using a start pointer
void insertExhibit(struct Exhibit** exhibitList, const char* name, int capacity) {
    struct Exhibit* newExhibit = createNewExhibit(name, capacity);
    if (newExhibit == NULL) {
        printf("Failed to create new exhibit.\n");
        return;
    }

    newExhibit->nextExhibit = *exhibitList;
    *exhibitList = newExhibit;
}

void insertAnimal(struct Animal** animalList, const char* name, int age, const char* species) {
    struct Animal* newAnimal = createNewAnimal(name, age, species);
    if (newAnimal == NULL) {
        printf("Failed to create new animal. \n");
        return;
    }

    if(*animalList == NULL) {
            *animalList = newAnimal;
            return;

        }

    struct Animal* currentAnimal = *animalList;
    while(currentAnimal->nextAnimal != NULL) {
            currentAnimal = currentAnimal->nextAnimal;
}
        currentAnimal->nextAnimal = newAnimal;
    //newAnimal->nextAnimal = *animalList;
    //*animalList = newAnimal;
}
//delete_exhibit...trying to delete the entered exhibit but running through to find matches...not working 
//got it working but kind of messy
void deleteExhibit(struct Exhibit** start, char* exhibitName) {
    struct Exhibit* currentExhibit = *start;
    struct Exhibit* previousExhibit = NULL;

    while (currentExhibit != NULL) {
        if (strcmp(currentExhibit->name, exhibitName) == 0) {
            if (previousExhibit == NULL) {
                *start = currentExhibit->nextExhibit;
            }
            else {
                previousExhibit->nextExhibit = currentExhibit->nextExhibit;
                }
        free(currentExhibit);
            return;
        }
        previousExhibit = currentExhibit;
        currentExhibit = currentExhibit->nextExhibit;
    }

}
void deleteAnimal(struct Animals** start, char* animalName) {
   // if (animal->animalList == animal) {
     //   // Animal is the first in the list
     //   animal->animalList = animal->nextAnimal;
    //} 
   // else {
        // Find the previous animal in the list
        struct Animal* currentAnimal = start;
        struct Animal* previousAnimal = NULL;
        while (currentAnimal != NULL) {
            if (strcmp(currentAnimal->name, animalName) == 0) {
             if (previousAnimal == NULL) {
                *start = currentAnimal->nextAnimal;
             }
             else {
                 previousAnimal->nextAnimal = currentAnimal->nextAnimal;

             free(currentAnimal);
             return;

        }

        // Update the previous animal's next pointer
       // previousAnimal->nextAnimal = animal->nextAnimal;
           previousAnimal = currentAnimal;
           currentAnimal = currentAnimal->nextAnimal;
    }

    // Free the memory for the animal
    free(currentAnimal);
}
}
*
/*
//delete_all by looping through the list and removing exhibits until current is blank, no more exhibits left
void deleteAllExhibits(struct Exhibit** start) {
    struct Exhibit* currentExhibit = *start;
    struct Exhibit* nextExhibit;

    while (currentExhibit != NULL) {
        nextExhibit = currentExhibit->nextExhibit;
        free(currentExhibit);
        currentExhibit = nextExhibit;
    }
    *start = NULL;  // Update the start pointer to indicate an empty list
}
*/

int main() {
    struct Exhibit* exhibitList = NULL;
    int i, choice, numOfExhibits, numOfAnimals;
    printf("Menu\n");
    printf("1 - Create new zoo\n");
    printf("2 - Add exhibit\n");
    printf("3 - Add animal\n");
    printf("4 - Remove animal\n");
    printf("5 - Remove exhibit\n");
    printf("6 - Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    while(choice != 6) {
        if(choice == 1) {
                printf("How many exhibits would you like to start with? > ");
                scanf("%d", &numOfExhibits);
                struct Exhibit* exhibitList = NULL;
        //      getting user input based on how many exhibits they wanted to add
                for(i = 0; i < numOfExhibits; i++) {
       //               struct Exhibit* exhibit = (struct Exhibit*)malloc(sizeof(struct Exhibit));
                        printf("Enter exhibit name > ");
                        scanf("%s", Exhibit->name);
        //              put the exhibit name in the exhibit list and recurse
                        createNewExhibit(&exhibitList, Exhibit);
                }
        }

        else if(choice == 2) {
                printf("How many exhibits would you like to add? > ");
                scanf("%d", &numOfExhibits);
        //      prompt for new exhibits based on how many the user wants to add
                for(i = 0; i < numOfExhibits; i++) {
                        struct Exhibit* exhibit = (struct Exhibit*)malloc(sizeof(struct Exhibit));
                        printf("Enter exhibit name > ");
                        scanf("%s", exhibit->name);
                        //insert the exhibit(s) to the front of the list
                        insertExhibit(&exhibitList, exhibit->name, exhibit->capacity);
                }
        }
               printf("How many animals would you like to add? > ");
                scanf("%d", &numOfAnimals);
                for(i = 0; i < numOfAnimals; i++) {
                        struct Animal* animal = (struct Animal*)malloc(sizeof(struct Animal));
                        printf("Enter animal name > ");
                        scanf("%s", animal->name);
                        insertAnimal(&animalList, animal->name, animal->age, animal->species);
                }
        }

        else if (choice == 4) {
                printf("How many animals would you like to delete? > ");
                scanf("%d", &numOfAnimals);
                for(i = 0; i < numOfAnimals; i++) {
                        char animalName[50];
                        printf("Enter animal name > ");
                        scanf("%s", animalName);
                        deleteAnimal(&animalList, animalName);
                }
        }

        else if(choice == 5) {
     //         deleting specific exhibits
                printf("How many exhibits would you like to delete? > ");
                scanf("%d", &numOfExhibits);
        //      getting user input on which exhibits to remove from the list
                for(i = 0; i < numOfExhibits; i++) {
                        char exhibitName[50];
                        printf("Enter exhibit name > ");
                        scanf("%s", exhibitName);
            //          remove the exhibit name from the list
                        deleteExhibit(&exhibitList,&animalList, exhibitName);
                }
        }

        else if(choice == 6) {
                printf("Bye");
                return 0;
        }

        else {
                printf("Invalid");
        }
}
}
   