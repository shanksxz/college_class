## File System
### Operations :-
- ```fopen()``` - Opens a file
- ```fclose()``` - Closes a file
- ```fgetc()``` - Reads a character from a file
- ```fputc()``` - Writes a character to a file
- ```fgetw()``` - Read an integer
- ```fputw()``` - Write an integer
- ```fprintf()``` - Prints formatted output to a file
- ```fscanf()``` - Reads formatted input from a file
- ```fgets()``` - Read string of characters from a file
- ```fputs()``` - Write string of characters to a file
- ```feof()``` - Detects end-of-file marker in a file
- ```fseek()``` - sets the file pointer to given position
- ```ftell()``` - returns current position
- ```rewind()``` - sets the file pointer to the beginning of the file

### Modes :-
- ```r``` - opens a text file in read mode
- ```w``` - opens a text file in write mode
- ```a``` - opens a text file in append mode
- ```r+``` - opens a text file in read and write mode
- ```w+``` - opens a text file in read and write mode
- ```a+``` - opens a text file in read and write mode
- ```rb``` - opens a binary file in read mode
- ```wb``` - opens a binary file in write mode
- ```ab``` - opens a binary file in append mode
- ```rb+``` - opens a binary file in read and write mode
- ```wb+```  - opens a binary file in read and write mode
- ```ab+```- opens a binary file in read and write mode

```c
int main() {

    //create a file
    FILE *f = fopen("./fs/newfile.txt","w");

    //open a file
    FILE *f = fopen("./fs/doc1.txt","r");
    fclose(f); // close 

    //write data to an file
    FILE *f = fopen("./doc1.txt","w");
    fprintf(f,"WRITING DATA"); //if there is somedata present, it will just overwrite it
    fclose(f);

    //append data to an file
    FILE *f = fopen("./doc1.txt","a");
    fprintf(f,"APPENDING DATA");
    fclose(f);

    //read input from file
    FILE *f = fopen("./doc1.txt","r");
    fscanf(f,"%d %d", &num1, &num2);
    printf("%i %i",num1,num2);
    fclose(f);

    //get char from a file
    FILE *f = fopen("./fs/doc1.txt","r");
    char ch;
    while ((ch = fgetc(f)) != EOF) {
        printf("%c",ch);
        // putchar(ch);
    }
    fclose(f);

    //put an ch in file
    FILE *f = fopen("./fs/doc1.txt","w");
    fputc('A',f);
    fclose(f);


    //get an string from a file
    char buffer[100];
    FILE *file = fopen("./fs/doc1.txt", "r");
    if (file != NULL) {
        if (fgets(buffer, sizeof(buffer), file) != NULL) {
            printf("Read: %s", buffer);
        }
    fclose(file);

    //put a string in a file
    char text[] = "Hello, world!";
    FILE *file = fopen("./fs/doc1.txt", "w");
    if (file != NULL) {
        fputs(text, file);
        fclose(file);
    }

    //rename
    rename(oldName, newName);

    //delete
    remove(filename);

    FILE *f = fopen("./fs/doc1.txt","w+");
    fseek(f,10,SEEK_SET); //sets the file position at 10th position from the beginning of the file.
    fseek(f,-5,SEEK_CUR); //move back by 5bytes from the curr positions
    fseel(f,-3,SEEK_END); //move back by 3bytes from the EOF
    //SEEK_SET = 0 - fseek(f,10,0);
    //SEEK_CUR = 1 - fseek(f,-5,1);
    //SEEK_END = 2 - fseek(f,-3,2);
    fclose(f);

    //get the curr positon of pointer in a file
    FILE *file = fopen("data.txt", "r");
    long int position = ftell(file); // Get current position
    printf("Current position: %ld\n", position);
    fclose(file);

    //reset the posi of pointer at the start of file
    FILE *file = fopen("data.txt", "r");
    rewind(file);
    fclose(file);

    return 0;
}
```