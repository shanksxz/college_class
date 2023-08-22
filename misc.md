
## Union vs. Union All
- ```UNION```: This operator combines the result sets of two or more SELECT statements and removes duplicate rows from the final result.
- ```UNION ALL```: This operator also combines the result sets of SELECT statements but retains all rows, including duplicates, in the final result.
  
### Rules of Union
- Each SELECT statement within a UNION or UNION ALL must have the same number of columns.
- The columns must also have similar data types.


### Natural Join
- A natural join combines two tables based on columns with the same name and data type.
- The resulting table contains all attributes from both tables but only one copy of each common column.
- If no condition is specified in a natural join, it returns rows based on the common column(s).


### Ex
```sql
    -- create a table to store student information
    CREATE TABLE students (
        student_id INT PRIMARY KEY,
        student_name VARCHAR(50),
        student_age INT,
        student_gender VARCHAR(10)
    );

    -- insert some sample data into the students table
    INSERT INTO students (student_id, student_name, student_age, student_gender)
    VALUES
        (1, 'Alice', 20, 'Female'),
        (2, 'Bob', 22, 'Male'),
        (3, 'Charlie', 21, 'Male'),
        (4, 'David', 19, 'Male'),
        (5, 'Eve', 20, 'Female');

    -- create a table to store course information
    CREATE TABLE courses (
        course_id INT PRIMARY KEY,
        course_name VARCHAR(50),
        course_credit INT
    );

    -- insert some sample data into the courses table
    INSERT INTO courses (course_id, course_name, course_credit)
    VALUES
        (101, 'Mathematics', 4),
        (102, 'History', 3),
        (103, 'Computer Science', 5),
        (104, 'Physics', 4),
        (105, 'Biology', 4);


    -- to find a list of all student names and course names
    SELECT student_name FROM students
    UNION
    SELECT course_name FROM courses;

    -- to find a list of all student names and course names, including duplicates
    SELECT student_name FROM students
    UNION ALL
    SELECT course_name FROM courses;

    -- to find students who are taking courses, assuming that there's a common column named 'student_id'
    -- dont forget to create the common column
    SELECT students.student_name, courses.course_name
    FROM students
    NATURAL JOIN courses;


```
## Equi-join
- An equi-join retrieves data from multiple tables based on an equality condition (e.g., =).
- In an equi-join, you cannot use comparison operators like <, >, <=, >=, !=, <>, BETWEEN, or AND in the join condition.


## Non - equi join
- A non-equi join retrieves data from multiple tables based on conditions other than equality. It accepts any condition that doesn't involve the equality operator (=)

## Expample of Equi-join
1. Creating two tables
    ```sql
    CREATE table test1 (
        sname VARCHAR(25),
        id INT 
    )

    CREATE table test2 (
        id INT,
        designation VARCHAR(25)
    )

    INSERT INTO test1(sname,id)
    VALUES('som',1)

    INSERT INTO test2(id,designation)
    VALUES(1,'somya')

    SELECT * from test1,test2 WHERE test1.id = test2.id


    --output

    +-------+----+----+-------------+
    | sname | id | id | designation |
    +-------+----+----+-------------+
    | som   | 1  |  1 | somya       |
    +-------+----+----+-------------+
    ```


## Diff btw equi and natural join
- In an equi-join, you explicitly specify the join condition based on equality, while in a natural join, the join is based on all columns with the same name and data type.
- In an equi-join, common columns appear twice in the result (once from each table), whereas in a natural join, common columns appear only once.



## Q) Write to get employee details from the table who having highest salary 

```sql
    CREATE Table employee (
        empid INT,
        empname VARCHAR(25),
        empsalary INT
    )

    INSERT INTO employee(empid,empname,empsalary)
    VALUES(1,'shiv','9800')

    INSERT INTO employee(empid,empname,empsalary)
    VALUES(2,'tani','9200')

    INSERT INTO employee(empid,empname,empsalary)
    VALUES(3,'shivansh','8900')

    INSERT INTO employee(empid,empname,empsalary)
    VALUES(4,'tanishq','9000')

    -- SELECT MAX(empsalary) FROM employee 
    -- it will only return the highest value in empsalary col(will not gave any details about row)

    SELECT *
    FROM employee
    WHERE empsalary = (SELECT MAX(empsalary) FROM employee);


    --output
    +-------+----------+-----------+
    | empid | empname  | empsalary |
    +-------+----------+-----------+
    | 1     | shiv     | 9800      |
    +-------+----------+-----------+

```

## SubQuery
- A subquery, also known as a nested query or inner query, is a SQL query nested within another SQL query. It is used to retrieve data needed for the main query by executing the subquery first. Subqueries can be used in various parts of a SQL statement, including the SELECT, FROM, WHERE, and HAVING clauses

## Non Co-related subquery
- A non-correlated subquery is a subquery that can be executed independently of the outer query. It doesn't reference columns from the outer query in its WHERE clause. Your example of finding the highest salary is a non-correlated subquery.
    

## SQL v/s PSQL
in sql 

hw : -
<!-- what is diff btw having clause and grou-wise clause -->


## Having Clause vs Group-Wise Clause

- GROUP BY Clause:
    - The GROUP BY clause is used to group rows from a table based on one or more columns.
    It is typically used with aggregate functions like SUM, COUNT, AVG, etc., to perform calculations on each group of rows.
    - The GROUP BY clause is used in the SELECT statement.
    It is used before the HAVING clause if you want to filter groups based on aggregate calculations.
- HAVING Clause:
    - The HAVING clause is used to filter the result set based on the result of an aggregate function.
        - It is used to specify a condition for groups created by the GROUP BY clause.
        - It is used in the SELECT statement, usually after the GROUP BY clause.
        - It filters groups, not individual rows, and is applied after the grouping is done.


### Ex:-
```sql
    CREATE TABLE student_scores (
        student_id INT PRIMARY KEY,`  `
        student_name VARCHAR(50),
        test_score INT
    );

    INSERT INTO student_scores (student_id, student_name, test_score)
    VALUES
    (1, 'Alice', 85),
    (2, 'Bob', 92),
    (3, 'Charlie', 78),
    (4, 'David', 95),
    (5, 'Eve', 88),
    (6, 'Frank', 72),
    (7, 'Grace', 90),
    (8, 'Hannah', 89),
    (9, 'Ivy', 68),
    (10, 'Jack', 98);

    SELECT student_name, AVG(test_score) AS average_score
    FROM student_scores
    GROUP BY student_name
    HAVING AVG(test_score) >= 85;

    -- output
     student_name | average_score
    --------------+---------------
     Alice        |            85
     Bob          |            92
     David        |            95
     Grace        |            90
     Jack         |            98


```
