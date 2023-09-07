## Retrive Data Method

### Selection
-  When retrieving data from a table with specific conditions, the "WHERE" keyword is used.
   
    ```sql
    select * from person where personId = 101;
    ```

### Projection
-  When retrieving data from a table without any specific conditions, it is known as projection.

    ```sql
    select * from person
    ```
   - Note: Both ```SELECT``` and ```PROJECT``` retrieve data from a single table. For retrieving data from multiple tables, we use joins.


### Joins
-  When we want to retrieve data from multiple tables, we use joins
  - Joins come in two formats:
    - ANSI format (new format style): In this format, we use the "ON" keyword.
      1. Inner Join
      2. Outer Join (Left, Right, Full)
      3. Cross Join
      4. Natural Join
    - Non-ANSI format (old format style): In this format, we use the "WHERE" keyword.

### Ex
```sql
--creating an table
CREATE TABLE Course(
    courseid INT,
    coursename VARCHAR(25),
    coursefee VARCHAR(25)
)

-- for joins, there must be at least one common column (here we have a "courseid" column) between the tables.
CREATE TABLE Student(
    stdid INT,
    sname VARCHAR(25),
    smail VARCHAR(25),
    courseid INT
)

-- inserting values
INSERT INTO student (stdid,sname,smail,courseid) VALUES(106,'A6','A6@gmail.com',4006)
INSERT INTO course (courseid,coursename,coursefee) VALUES(4006,'java',100000)

-- query
select * from student inner join course on student.courseid=course.courseid
```

  