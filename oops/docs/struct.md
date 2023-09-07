## Structures

### Defining Strucuture
```c
struct <struct name> {
    properties(datat-types)
}

ex:-
struct students {
    int age;
    char name[20];
    float cgpa;
}
```

```c
#include<stdio.h>
#include<string.h> // to use strcpy

struct students {
    char name[5];
    float cgpa;
}

int main() {

    struct students s1 = {"somya",9.48}; 

    //or

    struct students s2;
    s1.cgpa = 9.48;
    s1.name = "somya" // this will throw err, we cannot assign a string to a character array


    //or

    struct students s3;
    s1.cgpa = 9.48;
    strcpy(s1.name,"somya") //using strcpy from string library

    //or

    struct students s4;
    gets(s1.name); //to take input
    scanf("%f",s1.cgpa);

    return 0;

}
```

### Structure Pointer
```c
#include<stdio.h>
#include<stdlib.h>

struct coordinates{
    int x;
    int y;
}


int main() {

    struct coordinates h1;
    struct coordinates *ptr = &h1; //pointer ptr initialized to h1

    ptr->x = 2;
    ptr->y = 4;


    //dynamic allocation
    struct coordinates *dynamicptr = (struct coordinates *)malloc(sizeof(struct coordinates));
    dynamicptr->x = 30;
    dynamicptr->y = 60;

    //free dynamically allocated memory when done
    free(dynamicptr)

    return 0;

}
```

### Arrays Of Structures
```c
#include<stdio.h>
#include<stdlib.h>

struct mystruct{
    int id;
    char namw[50];
}

int main() {

    struct mystruct s1[5]; //This creates an array of 5 structures

    //initialization
    myArray[0].id = 1;
    strcpy(myArray[0].name, "John");
    myArray[1].id = 2;
    strcpy(myArray[1].name, "Alice");


    struct MyStruct myArray[5] = {
        {1, "John"},
        {2, "Alice"},
        {3, "Bob"},
        {4, "Eve"},
        {5, "Charlie"}
    };

    //printing arrays
    for (int i = 0; i < 5; i++) {
        printf("ID: %d, Name: %s\n", myArray[i].id, myArray[i].name);
    }      
    
    return 0;
}
```

### Nested Structures
```c
#include<stdio.h>
#include<stdlib.h>

struct Address {
    char street[50];
    char city[30];
    char state[20];
    char zip[10];
};

struct Person {
    char name[50];
    int age;
    struct Address address; // Nested structure
};


int main(){

    //initialization
    struct Person person1;
    strcpy(person1.name, "John Doe");
    person1.age = 30;
    strcpy(person1.address.street, "123 Main St");
    strcpy(person1.address.city, "Cityville");
    strcpy(person1.address.state, "State");
    strcpy(person1.address.zip, "12345");


    //accesing elements
    printf("Name: %s\n", person1.name);
    printf("Age: %d\n", person1.age);
    printf("Street: %s\n", person1.address.street);
    printf("City: %s\n", person1.address.city);
    printf("State: %s\n", person1.address.state);
    printf("ZIP: %s\n", person1.address.zip);



}
```

### Array Of Nested Structures
```c
#include <stdio.h>
#include <string.h>

struct Address {
    char street[50];
    char city[30];
    char state[20];
    char zip[10];
};

struct Person {
    char name[50];
    int age;
    struct Address address;
};

int main() {
    struct Person people[2]; // Array of persons

    // Initialize the first person
    strcpy(people[0].name, "John Doe");
    people[0].age = 30;
    strcpy(people[0].address.street, "123 Main St");
    strcpy(people[0].address.city, "Cityville");
    strcpy(people[0].address.state, "State");
    strcpy(people[0].address.zip, "12345");

    // Initialize the second person
    strcpy(people[1].name, "Alice Smith");
    people[1].age = 25;
    strcpy(people[1].address.street, "456 Elm St");
    strcpy(people[1].address.city, "Townsville");
    strcpy(people[1].address.state, "State");
    strcpy(people[1].address.zip, "54321");

    // Access and print the data
    for (int i = 0; i < 2; i++) {
        printf("Person %d:\n", i + 1);
        printf("Name: %s\n", people[i].name);
        printf("Age: %d\n", people[i].age);
        printf("Street: %s\n", people[i].address.street);
        printf("City: %s\n", people[i].address.city);
        printf("State: %s\n", people[i].address.state);
        printf("ZIP: %s\n", people[i].address.zip);
        printf("\n");
    }

    return 0;
}

```

### Structures & Functions
```c
//passing structure varaible
struct Point {
    int x;
    int y;
};

void printCoordinates(int x, int y) {
    printf("Coordinates: (%d, %d)\n", x, y);
}

int main() {
    struct Point point1 = {2, 3};
    printCoordinates(point1.x, point1.y);

    return 0;
}


//passing the whole structure as a value
struct Point {
    int x;
    int y;
};

void printPoint(struct Point p) {
    printf("Coordinates: (%d, %d)\n", p.x, p.y);
}

int main() {
    struct Point point1 = {2, 3};
    printPoint(point1);

    return 0;
}


//passing a structure pointer ([ass by reference)
struct Point {
    int x;
    int y;
};

void modifyPoint(struct Point *p, int newX, int newY) {
    p->x = newX;
    p->y = newY;
}

int main() {
    struct Point point1 = {2, 3};
    printf("Original Coordinates: (%d, %d)\n", point1.x, point1.y);

    modifyPoint(&point1, 5, 6);
    printf("Modified Coordinates: (%d, %d)\n", point1.x, point1.y);

    return 0;
}

```

### Union
```c

union MyUnion {
    int intValue;
    float floatValue;
    char stringValue[20];
};


int main() {
    union MyUnion u1 = {42};           
    union MyUnion u2 = {3.14159f};    
    union MyUnion u3 = {"Hello"};   
    printf("Value of intValue: %d\n", u1.intValue);
    printf("Value of floatValue: %f\n", u2.floatValue);
    printf("Value of stringValue: %s\n", u3.stringValue);

    // the size of a union is determined by the size of its largest member. In the example above, the size of MyUnion will be the size of an char[20], which is typically 20 bytes.


    ex:-
    union Shape {
        int r, l;
    };

    float calcArea(union Shape *shape, int isRect) {
        if (isRect)
            return shape->l * shape->l;
        return 3.14 * shape->r * shape->r;
    }

    int main() {
        union Shape shape;
        shape.r = 20;
        printf("area of circle: %0.2f", calcArea(&shape, 0));
        shape.l = 10;
        printf("\narea of rect: %0.2f", calcArea(&shape, 1));
    }

    //value of both r and l will be 10 as both share same memory

    ex:-
    #include <stdio.h>

    union IntOrChar {
        int i;
        char r;
    };

    int main() {
        union IntOrChar u;
        
        u.i = 42;
        printf("Value of u.i: %d\n", u.i); // prints 42
        
        u.r = 'A';
        printf("Value of u.r: %c\n", u.r); // prints 'A'
        
        printf("Value of u.i: %d\n", u.i); // prints some unexpected value(value A = 65)
        
        return 0;
    }

}
```

### Enum
```c
enum Days {
    SUNDAY,    // 0
    MONDAY,    // 1
    TUESDAY,   // 2
    WEDNESDAY, // 3
    THURSDAY,  // 4
    FRIDAY,    // 5
    SATURDAY   // 6
};


int main() {

    enum Days today = WEDNESDAY;
    printf("Today is day %d\n", today); // Prints "Today is day 3"
    return 0;
}


ex:-
enum Colors {
    RED = 1,
    GREEN = 2,
    BLUE = 4
};

int main() {
    enum Colors color1 = RED;
    enum Colors color2 = GREEN;
    enum Colors color3 = BLUE;

    // You can use these variables like this:
    if (color1 == RED) {
        printf("Color 1 is red.\n");
    }
    
    switch (color2) {
        case RED:
            printf("Color 2 is red.\n");
            break;
        case GREEN:
            printf("Color 2 is green.\n");
            break;
        case BLUE:
            printf("Color 2 is blue.\n");
            break;
        default:
            printf("Color 2 is unknown.\n");
            break;
    }

    // You can also directly compare enum constants:
    if (color3 == BLUE) {
        printf("Color 3 is blue.\n");
    }

    return 0;
}
```