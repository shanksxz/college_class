### ls
- it is used to list directory contents
```bash
ls # list files in current directory
ls -a # list all files in current directory including hidden files
ls -l # list detailed information about files in current directory
ls -la # combination of ls -a and ls -l
ls -l --author # list all files in current directory with author deatils
```

### cd
- it is used to change the current working directory
```bash
cd ~ # change to the home directory
cd documents # change to a specific directory
cd .. # move up one directory
cd - # navigate to previous directory
cd ../Downloads # using relative paths
cd "My Documents" #changing to a directory with spaces in the name
cd / # move to the root directory
```

### touch
- touch command is used to create empty files and also to modify the timestamp of a file
```bash
stat filename # get the access and modification times of an file

touch filename # update the access and modification times of a file to the current time
touch -a filename  # update only the access times of the file to the current time
touch –m file1.txt # update only the modification times of the file to the current time
touch file1 file2 file3 # update multiple files
touch -c non_existent_file # it will try to update the timestamps of the file to the current time if it exists, it will not create the file if it doesn't exits
touch –t 201210280605 file1.txt # it will change the access & modification date & time of file ‘file1.txt’ to 2012-10-28 06:05 
touch -d "2023-11-17 12:30:00" filename # update to speficied timestamp
touch -r oldfile newfile # this command effectively sets the access and modification times of newfile to be the same as those of oldfile.
```
### cat
```bash
cat > file1.txt # creats the file file1.txt and u can write anything inside of it. to exit writing file (ctrl + d). if the file already exits it just overwrites it.
cat file1.txt # displays the contents of the file1.txt
cat file1.txt file2.txt # display the content after concatenate the both files(it just displays it)
cat file1.txt file2.txt > file3.txt # it concatenates the two files then store their results in file3.txt
cat >> file1.txt # append the new content
cat -n filename # number all output lines
cat -A filename # display non-printing characters and line endings
cat -s filename # squeeze multiple blank lines
cat -E filename # show ends of each lines
```

### cp
- it is used to copy files and directories
```bash
cp source_file destination # copy a file to a different location
cp file1 file2 file3 destination_directory # copy multiple files to a directory
cp -r source_directory destination_directory # copy a directory and its contents recursively
cp --copy-contents source_directory destination_directory # copy the contents of a directory recursively
```

### mv
- it is used to move files and directories
```bash
mv old_file new_file # rename the old file
mv source_file destination # move a file to a different location
mv file1 file2 file3 destination_directory # move multiple files to a different location
mv -f source_file destination # move a file and force overwrite
mv -i source_file destination # move a file and prompt before overwrite
mv -n source_file destination # move a file without overwriting an existing file
```

### rm
- it is used to remove files or directories.
```bash
rm filename # remove a file
rm file1 file2 # remove multiple files
rm -i file1 # prompt before every removal. this option makes rm ask for confirmation before removing each file.
rm -r directory #remove a directory and its contents recursively
rm -f filename #ggnore nonexistent files and do not prompt for confirmation. this option allows rm to forcefully remove files without asking for confirmation
rm --force filename # same as above command
```

### mkdir
```bash
mkdir new_directory # create an directory
mkdir dir1 dir2 dir3 # create multiple directory
mkdir -m 755 new_directory # create a directory with specified permissions. m stand for modes
mkdir -p path/to/new_directory # create a directory and its parent directories
```

### rmdir
- it is used to remove empty directories
```bash
rmdir directory_name # removes an directory
rmdir dir1 dir2 dir3 # removes multiple directory
rmdir --ignore-fail-on-non-empty non_empty_directory # ignore each failure that is solely because a directory is non-empty. If a directory is not empty, the default behavior is to fail and not remove it. This option allows rmdir to ignore such failures
rmdir -p a/b/c
```


### cmp
```bash

cmp file1 file2 # compare two files
cmp -b file1 file2 # print differing bytes
cmp -i 100 file1 file2 # skip initial bytes and comapre
cmp -i 50:100 file1 file2 # skip initial bytes for each file
cmp -n 200 file1 file2 # comapre only first 200 bytes


ex:-

somya01@Shanks:~$ cat > file1.txt
file1
somya01@Shanks:~$ cat > file2.txt
file2
somya01@Shanks:~$ cmp file1.txt file.txt
somya01@Shanks:~$ cmp file1.txt file2.txt
file1.txt file2.txt differ: byte 5, line 1
```

### comm 
```bash
somya01@Shanks:~$  cat > file1.txt
hello
hmm
xd
somya01@Shanks:~$  cat > file2.txt
f
hkkk
k
xd
somya01@Shanks:~$  comm file1.txt file2.txt
        f
hello
        hkkk
hmm
        k
                xd
```

### diff
```bash
somya01@Shanks:~$ diff file1.txt file2.txt
1,2c1,3
< hello
< hmm
---
> f
> hkkk
> k
```

### df
- it is used to display information about disk space usage on mounted filesystems
```bash
df # it displays information about all the mounted file systems like total size, used space, usage percentage, and the
mount point
df -h # show a human-readable summary of disk space usage on all mounted filesystems
df filename # this command will display the mount information of the given filename
df --total # it will display the grand of total disk space usage at the end.
```

### du
- it is used to estimate file space usage. It shows the disk space used by files and directories
```bash
du # summary of disk usage of the current directory
du -h /path/to/directory # this command will display the disk space usage of the specified directory and its subdirectories. 
du -c <dirname> or du --total <dirname> #it will display the disk space usage along with the total disk usage of the given directory.
```
### mount/unmount
- The files and directories under Linux filesystem are arranged in a root directory called /.
- mount command is used to attach the filesystem of an external device to the filesystem of an
Operating System.
```bash
mount –t type <device> <directory> # it will mount the filesystem of device at the specified directory. If the directory is not given, it will look for the mount-point in /etc/fstab file. The /etc/fstab file contains information about which device should be
mounted where.
mount # it will display all currently mounted filesystems on a system
Umount <devicefile> # it will unmount (dettach) the filesystem of device.
```

### find
```bash
find /path/to/search -name "filename.txt" # find files by name
find /path/to/search -name "*.pdf" # find files by extension
find /path/to/search -type d # searches for directories under the specified path.
find /path/to/search -mtime -7 # searches for files modified within the last 7 days under the specified path.
find /path/to/search -name "oldfile.txt" -delete # this command finds and deletes files named "oldfile.txt" under the specified path.
find /path/to/search -empty # search for and list empty files and directories under the specified path.
find /path/to/search -perm 644 # search for files with permission 644 (rw-r--r--).
find /path/to/search -user username # search for files and directories owned by the specified username.
find /path/to/search -type f -name "filename" # search for files with the specified name under the specified path.
find /path/to/search -type d -name "dirname" # search for directories with the specified name under the specified path.

```
### locate
```bash
sudo apt-get install mlocate # locate use mlocate

locate filename # search for files
locate -i filename # case insensitive

# the locate command relies on a database that needs to be periodically updated. You can update the database using
sudo updatedb

# Keep in mind that while locate is fast, it may not find files that were created or modified after the last database update. If you need real-time information or are looking for recently modified files, consider using find or a combination of find and grep instead.
```

### more/less
- The more command is a simple pager that allows you to view the content of a file one screen at a time. You can navigate through the file using the spacebar or the Enter key.
- The less command is an improved version of more. It allows both forward and backward navigation through the file, search functionality, and more advanced features.
```bash
more filename
less filename

less -n 20 filename    # View the first 20 lines
less +5 filename       # Start from line 5
less /pattern filename  # Search for a pattern
```

### head/tail
- The head command is used to display the first few lines of a file. By default, it shows the first 10 lines, but you can specify a different number with the -n option.
- The tail command is used to display the last few lines of a file. By default, it shows the last 10 lines, but you can specify a different number with the -n option.

```bash

head -n 10 filename    # Display the first 10 lines
tail -n 20 filename    # Display the last 20 lines


# Display the last 15 lines of a file using tail
tail -n 15 filename

# Monitor a log file for new entries
tail -f /var/log/syslog
```


### chmod 
- chmod (Change Mode) command is used to change the access mode of a file.\
[Chmod Calculator](https://chmod-calculator.com/)
```bash
Permissions:
    Symbolic Method:
        u (user/owner), g (group), o (others), a (all)
        + (add permission), - (remove permission), = (set exact permission)
        r (read), w (write), x (execute)
    Numeric Method:
    Each digit represents the sum of the corresponding permissions.
    4 (read), 2 (write), 1 (execute)
    0 (no permission), 7 (read, write, execute)

# Give read and write permissions to the user, read-only to the group, and no permissions to others
chmod u=rw,g=r,o= file.txt

# Add execute permission for the group and others
chmod +x file.sh

# Remove write permission for others
chmod o-w file.txt


# Give read, write, and execute permissions to the user; read and execute to the group; and read-only to others
chmod 751 file.txt

# Add read and write permissions for the user and group
chmod 664 file.txt

# Remove execute permission for the others
chmod 644 file.sh
```

### chown
- chown command is used to change the owner or group of a file/directory
```bash
chown user1 file.txt # changes the owner of file.txt to user1
chown username:groupname filename/directory # sets both the owner and group to the specified values 
chown -c username:groupname filename/directory # report only if changes are made
```


### chgrp
- chgrp command is used to change the group ownership of a file/directory.
```bash
chgrp developers file.txt # changes the group ownership of file.txt to the group developers
chgrp -c <groupname> <file/directory> # it will display a confirmation message after changing the group ownership.
```



### Monitor Users
```bash
who # displays information about currently logged-in users
last # shows a list of last logged in users with login times and other details 
w # provides a summary of the current activity, including logged-in users and their processes.
id # displays user and group information, including user ID (UID) and group ID (GID).
```


### System Utility Commands
```bash
date # this command is used to display the current date and time on the system.
uptime # this command provides information about how long the system has been running, the number of users currently logged in, and the system load averages
hostname # this command returns the hostname of the system, which is the name associated with the machine on a network
uname -a # this command provides detailed information about the system, including the kernel name, network node hostname, kernel release, kernel version, machine hardware, and operating system.
which ls # this command is used to locate the executable file associated with the given command. In this case, it will show the path to the ls command, which is used to list files and directories in a directory.
cal # this command displays a simple calendar for the current month.
echo # the echo command is used to display messages or values in the terminal. It is often used for printing text or displaying the values of variables in shell scripts.
```

### Process Management & System Monitoring Commands
```bash
ps aux # it is used to display information about all running processes. 
bg %1 # this command is used to move a background job to the foreground. The %1 refers to job number 1.
fg %1 #  this command is used to bring a background job to the foreground. Again, %1 refers to job number 1
nice -n 10 command # the nice command is used to start a new process with a specified niceness value, which affects the scheduling priority of the process. A lower niceness value means a higher priority. In this case, nice -n 10 command starts the command with a niceness value of 10.

ex:-
nice -n 10 ls
```

### User Account Management
```bash
sudo useradd username # this command creates a new user account named "newuser."
cut -d: -f1 /etc/passwd # to get all the current users

sudo groupadd groupname # this command creates a new group named "newgroup."
sudo usermod -aG groupname username # this command adds the user "newuser" to the group "newgroup."
sudo userdel username # this command deletes the user account "existinguser."
sudo groupdel groupname # this command deletes the group "existing group"


su - username # the su command is used to switch to another user.
su - # ff you use su - without specifying a username, it switches to the root user.
sudo command # the sudo command is used to execute commands with elevated privileges.
sudo -i # the sudo -i command opens a new shell with elevated privileges, similar to logging in as the root user.
sudo ls /root # this command uses sudo to run the ls command with elevated privileges to list the contents of the /root directory.


# ex:-
sudo useradd john
sudo usermod -aG developers john
sudo userdel john
su -
sudo apt-get update
```
### grep
```bash
grep "pattern" filename # basic search
grep -i "pattern" filename # case-insensitive search
grep -r "pattern" directory # recursive search
grep -n "pattern" filename # display line number
grep -v "pattern" filename # invert match
grep -c "pattern" filename # count number of matches
grep -w "word" filename # search for whole word

command | grep "pattern" # search for a pattern from command cutput

ex:-
ps aux | grep "firefox" # this command lists all running processes using ps aux and then searches for lines containing the word "firefox" using grep.
```

### awk
```bash
awk '{print $1, $3}' data.txt # print specific columns from a file
awk '{sum += $1} END {print "Average:", sum/NR}' numbers.txt # calculate and print the avg
awk '/error/ {print}' logfile.txt # print lines matching an pattern
awk '{if ($3 > 50) print "High:", $1; else print "Low:", $1}' data.txt # conditional action
awk '{print "Number of fields:", NF}' file.txt # print number of fields in each line
awk '!seen[$2]++ {print $2}' names.txt # print unique entries in a column

```

### sed
```bash
sed 's/old_pattern/new_pattern/' filename # search and replace
sed 's/old_pattern/new_pattern/g' filename # global search
sed -i 's/old_pattern/new_pattern/g' filename # in-place editing
sed '/pattern/d' filename # delete lines matching an pattern
sed -n '5,10p' filename # print specific line
sed '/pattern/i\New text to insert' filename # insert text before an line
sed '/pattern/a\New text to append' filename # append text after an line
sed -n -e '/pattern/=' -e 'p' filename # print line numbers
```


### cut
```bash
cut -c 1-5 filename # cut characters from 1-5
cut -d ',' -f 1,3 filename.csv # this command extracts the first and third fields from each line of a CSV file where fields are separated by commas.
cut -d ' ' --complement -f 1 filename # this command extracts all fields except the first from each line of a space-separated file.
cut -c 1-5,8-12 filename # this command extracts characters 1 through 5 and 8 through 12 from each line.
ps aux | cut -c 1-20,30-40 # this command extracts specific character ranges from the output of the ps aux command.
cut -f 2,4 filename.tsv # this command extracts the second and fourth fields from each line of a tab-separated values (TSV) file.
cut -d ':' --complement -f 1,7 /etc/passwd # this command extracts all fields except the first and seventh from each line of the /etc/passwd file, using a colon as the delimiter.
```

### troubleshooting
```bash
ifconfig # this command displays the configuration details of all network interfaces on your system.
ping www.example.com # ping is used to test the reachability of a host on an Internet Protocol (IP) network. It sends ICMP echo request packets and waits for the corresponding echo reply.
traceroute www.example.com # traceroute (or traceroute in some systems) is used to trace the route that packets take from your computer to a destination host. It shows the IP addresses of intermediate routers along the path.
nslookup www.example.com # this command looks up the IP address associated with the domain name www.example.com using DNS.
dig www.example.com # this command retrieves detailed DNS information for the domain www.example.com, including IP addresses, name servers, and more.
netstat -an # this command shows a list of all open network connections and listening ports.
```