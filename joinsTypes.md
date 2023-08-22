## Joins Types

### Inner Join
- An inner join returns only the rows where there is a match in both tables.

### Left Outer Join
- A left join returns all rows from the left table (students) and the matched rows from the right table (courses). If there is no match, NULL values are returned for columns from the right table.

### Right Outer Join
- A right join returns all rows from the right table (courses) and the matched rows from the left table (students). If there is no match, NULL values are returned for columns from the left table.

### Full Outer Join
- A full outer join returns all rows when there is a match in either the left table or the right table. If there is no match, NULL values are returned for columns from the table without a match.  

### Cross Join
- A cross join combines all rows from the left table with all rows from the right table, resulting in a Cartesian product.

### Ex
```sql
    -- create an table
    CREATE TABLE students (
        student_id INT PRIMARY KEY,
        student_name VARCHAR(50),
        course_id INT
    );

    -- inserting values
    INSERT INTO students (student_id, student_name, course_id)
    VALUES
        (1, 'Alice', 101),
        (2, 'Bob', 102),
        (3, 'Charlie', 101),
        (4, 'David', 103),
        (5, 'Eve', NULL); -- No course assigned

    -- creating an 2nd table
    CREATE TABLE courses (
        course_id INT PRIMARY KEY,
        course_name VARCHAR(50)
    );

    -- inserting value on it
    INSERT INTO courses (course_id, course_name)
    VALUES
        (101, 'Mathematics'),
        (102, 'History'),
        (103, 'Computer Science');


    -- inner outer join
    SELECT students.student_name, courses.course_name
    FROM students
    INNER JOIN courses ON students.course_id = courses.course_id;

    -- left outer join
    SELECT students.student_name, courses.course_name
    FROM students
    LEFT JOIN courses ON students.course_id = courses.course_id;

    -- right outer join
    SELECT students.student_name, courses.course_name
    FROM students
    RIGHT JOIN courses ON students.course_id = courses.course_id;

    -- full outer join
    SELECT students.student_name, courses.course_name
    FROM students
    FULL OUTER JOIN courses ON students.course_id = courses.course_id;

    -- cross join
    SELECT students.student_name, courses.course_name
    FROM students
    CROSS JOIN courses;

```