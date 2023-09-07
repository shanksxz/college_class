#include<stdio.h>
#include<stdlib.h>


struct students {
    char name[35];
};


int main() {

    struct students s1[2];

    for(int i = 0; i<2; i++){
        printf("Enter Name\n");
        scanf("%s",&s1[i].name);
    }

    //printing age and rollno
    for(int i = 0; i<2; i++){
        printf("%s",s1[i].name);
        printf("\n");
    }

    return 0;
}