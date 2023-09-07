## Q) Write a query to display employee detail from the table whose department is same as department of employee smith and scott

```sql
    -- creating an table
    CREATE Table employeee (
        empid int,
        empname VARCHAR(25),
        empsalary int,
        empdepartment VARCHAR(25)
    )

    -- inserting values
    INSERT into employeee
    VALUES(101,'Sai',25000,'SAP')
    VALUES(102,'Allen',15000,'FIN')
    VALUES(103,'Scott',17000,'HR')
    VALUES(104,'warner',19000,'FIN')
    VALUES(105,'smith',14000,'FIN')
    VALUES(106,'ford',25000,'FIN')
   r  VALUES(107,'miller',50000,'FIN')

    -- to get all the data
    SELECT * from employeee


    SELECT empdepartment from employeee where empname = 'Scott' or empname = 'smith'

    SELECT * from employeee where empdepartment in (SELECT empdepartment from employeee where empname = 'Scott' or empname = 'smith' )

```


### Ex

```sql

    CREATE Table employeee (
        empid int,
        empname VARCHAR(25),
        empsalary int,
        empdepartment VARCHAR(25)
    )

  
    INSERT into employeee
    VALUES(101,'Sai',25000,'SAP')
    VALUES(102,'Allen',15000,'FIN')
    VALUES(103,'Scott',17000,'HR')
    VALUES(104,'warner',19000,'FIN')
    VALUES(105,'smith',14000,'FIN')
    VALUES(106,'ford',25000,'FIN')
    VALUES(107,'miller',50000,'FIN')

    SELECT * from employeee

    SELECT empdepartment from employeee where empname = 'Scott' or empname = 'smith'

    SELECT * from employeee where empdepartment in (SELECT empdepartment from employeee where empname = 'Scott' or empname = 'smith' )

    SELECT * from employeee WHERE empdepartment = "hr" or empdepartment = "sap"

    -- to get 2nd highest
    SELECT MAX(empsalary)
    FROM employeee
    WHERE empsalary < (SELECT MAX(empsalary) FROM employeee)

    -- to get 3rd highest
    SELECT MAX(empsalary) from employeee  WHERE empsalary < (
    SELECT MAX(empsalary)
    FROM employeee
    WHERE empsalary < (SELECT MAX(empsalary) FROM employeee))

    -- to get 4th highest salary (an better way order should be (n-1))
    SELECT DISTINCT empsalary from employeee ORDER BY empsalary DESC LIMIT 1 OFFSET 3
```



### find out the no. of employee working in an each particular job with an count


## having clause
- if i want to perform some condition on groups build by a group wise clause, we can use having clause
    - having and group by both are pairing groups for pairing clause, without group by clause we cannot use having clause



## why cursor