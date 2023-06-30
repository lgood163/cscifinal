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
        while(currentAnimal != NULL) {
            printf("Name: %s\n", currentAnimal->name);
            printf("Age: %d\n", currentAnimal->age);
            printf("Species: %s\n", currentAnimal->species);

            currentAnimal = currentAnimal->nextAnimal;
        }
}

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
}
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

           previousAnimal = currentAnimal;
           currentAnimal = currentAnimal->nextAnimal;
    }

    free(currentAnimal);
}
}


int main() {
    struct Exhibit* exhibitList = NULL;
    struct Animal* animalList = NULL;
    int i, choice, numOfExhibits, numOfAnimals;

    while(choice != 6) {
        fflush(stdout);
        system("clear");
        printf("Menu\n");
        printf("1 - Create new zoo\n");
        printf("2 - Add exhibit\n");
        printf("3 - Add animal\n");
        printf("4 - Remove animal\n");
        printf("5 - Remove exhibit\n");
        printf("6 - Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        putchar('\n');
        fflush(stdout);
        if(choice ==1) {
                printf("How many exhibits would you like to start with? > ");
                scanf("%d", &numOfExhibits);
                struct Exhibit* exhibitList = NULL;
                for(i = 0; i < numOfExhibits; i++) {
                        struct Exhibit* exhibit = (struct Exhibit*)malloc(sizeof(struct Exhibit));
                        printf("Enter exhibit name > ");
                        scanf("%s", exhibit->name);
                        printf("Enter exhibit capacity > ");
                        scanf("%d", exhibit->capacity);
                        createNewExhibit(exhibit->name, exhibit->capacity);
                }
                printf(&exhibitList);
        }

        else if(choice == 2) {
                printf("How many exhibits would you like to add? > ");
                scanf("%d", &numOfExhibits);
                for(i = 0; i < numOfExhibits; i++) {
                        struct Exhibit* exhibit = (struct Exhibit*)malloc(sizeof(struct Exhibit));
                        printf("Enter exhibit name > ");
                        scanf("%s", exhibit->name);
                        printf("Enter exhibit capacity > ");
                        scanf("%d", exhibit->capacity);
                        insertExhibit(&exhibitList, exhibit->name, exhibit->capacity);
                }
        }


        else if(choice == 3) {
                printf("How many animals would you like to add? > ");
                scanf("%d", &numOfAnimals);
                for(i = 0; i < numOfAnimals; i++) {
                        struct Animal* animal = (struct Animal*)malloc(sizeof(struct Animal));
                        printf("Enter animal name > ");
                        scanf("%s", animal->name);
                        printf("Enter animal age > ");
                        scanf("%d", animal->age);
                        printf("Enter animal species > ");
                        scanf("%s", animal->species);
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
                printf("How many exhibits would you like to delete? > ");
                scanf("%d", &numOfExhibits);
                for(i = 0; i < numOfExhibits; i++) {
                        char exhibitName[50];
                        printf("Enter exhibit name > ");
                        scanf("%s", exhibitName);
            //          remove the exhibit name from the list
                        deleteExhibit(&exhibitList, exhibitName);
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
             
