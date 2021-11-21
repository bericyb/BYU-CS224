# Lab 0 - Linux Systems

This lab will introduce you to the basics of the Linux systems we will be using this semester. 
Every student is required to use the departments linux lab machines for this class. 
This can be done either by physically being in the labs and logging onto the machines, or by using another computer to remotely log into the machines.  Tasks that need to be performed to complete the lab are indicated as follows: 

---

#### Task: What you need to do. 

---

Tasks are things that must be performed before moving on, and that will ensure you are familiar with all the content of the lab that is important. 

Lab questions that you will need to record and submit your answers for are indicated as

---

  * **Lab Question**: This you need to answer.

---

You will submit answers to lab questions on Canvas. 


### The Command Line
In this class we will use a terminal to interact with our computer. A terminal is a text-based interface, where the user types commands which the computer then executes.  The terminal is also referred to as the console, command line, command prompt, or shell.  

You might be more familiar with Graphical User Interfaces (GUI) for computers, which visually show you information and require you to click on parts of the screen to interact with the computer.  A Command Line Interface (CLI) is more primitive and more powerful than a GUI.

In the remainder of this lab description, instructions written like:
```
instruction
```
Indicate that you should type `instruction` on the command line and press enter.  The instruction will then be executed by the machine you are logged into. 

## Part 1. Access Terminal on your machine

Open a terminal window on your machine. How to do this will depend on your operating system. Each will display a window with some sort of prompt (line with your username and current folder and ending with a `>` or `$`.  This is the command prompt, where you will type in your commands. 

###  Windows 

Go to the search window in task bar and type `cmd`. This will bring up the *Command Prompt* app, which you then should launch.  

### Macs and Linux

You will need to find and launch the Terminal application.  It is sometimes in the *Utilities* folder on Macs

Once you have located and run the terminal application you will use it to run the commands that are described in what follows. 

---

#### Task 1: Find and run the terminal application on your machine.

---

## Part 2. Remotely log onto the department lab machines.  

(If you are physically at a lab machine, then you can skip this part.)


### Step 1. Secure Shell (SSH)
To remotely log into the department machines, we will use a program called `ssh`.  This stands for *Secure Shell* or *Secure Socket Shell*.  This program allows us to be on the terminal of another computer from a terminal on another computer. 

To run the `ssh` program, you will need to type the following at the command prompt: 

```
ssh user@schizo.cs.byu.edu
```

where `user` should be replaced by your cs id / user name.  This will connect to the schizo machine in the department, which will in turn connect you to another lab machine which you will work on. If you ever want to connect directly to a specific lab machine, you can replace `schizo` with the name of that machine in the ssh command.
It rarely matters exactly which machine you are connected to, and all CS machines have access to the same file system, so all of your files and folders will be exactly the same on any CS machine.
You will be prompted to enter your CS account password. You will then be asked if you want to trust the certificate of the `schizo` machine (since this is your first time connecting).  You can type `Y` or `Yes` and then press enter. 

If you have trouble with your CS account, look first at https://docs.cs.byu.edu/doku.php?id=setting-up-your-account-with-the-cs-authentication-system for help.  If that does not work, then submit a ticket via the ticket system at https://ticket.cs.byu.edu which is the primary support point for the open labs (preferred). The System Administrators may be contacted in person at 1140 TMCB or at system@cs.byu.edu if needed.

Once authenticated, you will see a welcome message from the department machine and then another command prompt, which will display `user@machine:~$`, where `user` will be replaced by your cs user name and `machine` will be the name of the machine that you get connected to.

You are now remotely logged into a lab machine and can type commands at the terminal (the prompt you are now looking at) which will be executed on the remote machine. 

---

#### Task 2: ssh into a lab machines

---

#### Note for Windows Users
Some older versions of Windows do not come with `ssh` natively available from within the *Command Prompt* app.  If you type the `ssh` command above and you get an error message indicating that it doesn't know what `ssh` is, then you probably need to install a separate program that supports ssh.  One option is PuTTY (https://www.chiark.greenend.org.uk/~sgtatham/putty/).  Others also exist.  You will need to install PuTTY or whatever other program you choose and then follow its instructions to use `ssh` to connect to the lab machines.  If you run into problems with this step, please contact a TA immediately so that we can help you get it resolved and so you can complete the lab. 

## Part 3. Navigating the Directory System
We will now learn about the commands that are used to navigate the directory system.

### Command 1. pwd
When operating from the terminal, you are always *in* a directory on the machine.  A directory, also sometimes called a folder, is a location on the hard disk of the machine that can contain files or other (sub)directories.  Usually you can tell which directory you are in by the command prompt that is shown, but there is also a command that will give you this information directly.  This is a very useful command to find out where you are (the *path* to the current directory).  The command is called `pwd`, which stands  for *print working directory*.  To run this you simply type: 
```
pwd
```
and the current directory will be displayed. By default the terminal will open in your home directory. 

---

  * **Lab Question 1 (5 points)**: What is the path to your home directory on a lab machine?  To answer this, use the `pwd` command in the terminal window after you first (remotely) log in. 

---

Terminal opens by default in your home directory.  

### Command 2. ls

It is rarely any good to be in a directory without being able to see what is in that directory.  The command to do this is `ls`, which stands for *list*.  This command will list out all the contents of the current directory.  To run this command you simply type
```
ls
```
There are command line options that you can use with `ls`.  For example, typing `ls -l` (*list long*) will show more details about each file, including file size, modification date, and type. This is often useful.  

---

#### Task 3: Use `ls` to find out what is in your home directory.  

---

### Command 3. mkdir

To modify the directory system we need to be able to create new (sub)directories and files within the current folder.  We will first focus on directories and then discuss files later.  The command to create a new directory within the current directory is `mkdir`, which stands for *make directory*.  This command requires another argument, which is the name of the directory that we want to make.  

We will use the `mkdir` command to create a directory for you to store all of your work for this class. You might want to call your folder `CS224` or `cs224` or `cs-224`, etc.  The choice is yours!  To create a folder called `cs224` you would type 
```
mkdir cs224
```

---

#### Task 4: Use `mkdir` to create a directory to contain your work for this class. 

---

After creating your directory, you should use `ls` to display the contents of the directory and confirm that your new directory in fact was created.  You are encouraged to use `ls` to confirm that tasks have been completely correctly in the remainder of this lab.

### Command 4. cd

To change the terminal's current directory we use the `cd` command, which stands for *change directory*.  This command also requires you to type the name of the directory you would like to change to.  For example, if there is a subdirectory inside the current directory called `cs224`, you would type the following command to change/move to that directory. 

```
cd cs224
```

To move out of a subdirectory to the directory that contains it, you type two dots for the directory name.  So, if you had moved into the `cs224` directory, you would type the following to change back/out/up to your home directory.

```
cd ..
```

If you type `cd` and press enter (without an argument) it will return you to your home directory. 

---

#### Task 5. Use `cd` to move into the directory you created for Task 5.  Then use `cd ..` to move back into your home directory.

---

---

  * **Lab Question 2 (5 points)**: What is the full path to your new directory? (hint: use `pwd` after you have moved into the directory)

---

## Part 4. Working with Files
We will now introduce the commands that allow us to work with files through the terminal. 

### Command 1. touch

To create an empty file of a specific name in the current directory, we will use the command `touch`.  This command requires the name of the file to be created/touched.  If the file already exists, then the file will not be changed, except for the time stamp that indicates when it was modified.  This is useful in many situations. If the file does not exist, then `touch` will create it.  As an example, to create a file called `lab0.txt` you would type
```
touch lab0.txt
```
in the directory where you want the file to be created. 

---

#### Task 6. Use `touch` to create a file called `lab0.txt` in the directory you created for Task 5. 

---

### Command 2. cp
Often we want to copy a file from some location where it already exists to our current location.  To do this we use the `cp` command, which stands for *copy*.  `cp` needs you to specify the name/path of the file to be copied, as well as the path/name of the new copied file that it will create.  To create a copy of our file called `lab0.txt`, and name the new copied file `lab00.txt`, you would type
```
cp lab0.txt lab00.txt
```

Often we are copying a file from another directory to another directory, and we want the file to keep the same name.  In this case the second argument, where before we had the name of the newly copied file, will instead indicate the directory where the file should be copied.  As an example, say we are currently in a directory that has two subdirectories: `dir1` and `dir2`.  Let's also say that there is a file in `dir` called `README.txt` that we want to copy into `dir2`.  To do this we would type

```
cp dir1/README.txt dir2/
```

To copy that same file into the current directory and keep the file's current name, we use single period `.` to indicate the location.  This would be done as follows

```
cp dir1/README.txt .
```

After using `cp` the file will still exist in the old location, and the newly named and created copy will exist in the new location.

---

#### Task 7. Use `cp` to create a copy of the `lab0.txt` file you created for Task 6.  Name it `task7.txt`. 

---

### Command 3. mv
If we want to move a file to another location, so that it no longer is at the previous location, we use the `mv` command, which stands for *move*.  This command is used in exactly the same way as the `cp` command.  You first give the path to the original file, then the path to the new location for the file.  You can rename the file when you move it, or you can leave the name the same.  This command is often used to rename a file without changing the directory that it is in.  To rename a file `file1.txt` in the current directory to have the new name `file2.txt` the following would be typed. 

```
mv file1.txt file2.txt
```

---

#### Task 8. Rename the copy of lab0.txt that you created for Task 7.  Name it `task8.txt`. 

---

When this is done, you should use the `ls` command to ensure that you only have two files: `lab0.txt` and `task8.txt` in your newly created folder.  

### Command 4. rm
To delete a file, we use the `rm` command, which stands for *remove*.  It simply needs the path/name of the file to be deleted.  If you want to delete the `task8.txt` file that we created in Task 7 and renamed in Task 8, you would type the following

```
rm task8.txt
```

---

#### Task 9. Delete the `task8.txt` file that you worked with in Tasks 7 and 8. 

---

Use the `ls` command to confirm that it is gone. 

The `rm` command can also be used to delete an empty directory, but for that requires the `-d` option. If the directory is not empty, the `-r` option (for *recursive*) will also remove the directory's contents.  To remove a directory named `dir1` and its contents, you would type `rm -r dir1`.

#### Note
Be extremely careful when using the `rm` command, especially with some of its options.  Once something is deleted, it is gone forever.  It is possible by being not careful to delete all of your files or your entire operating system with a single incorrect command.  Just be careful!


## Part 5.  Editing Files with nano

The basic program that we will use to edit files in this class is `nano`.  (There are many others that can be used, you are welcome to use another if you prefer it).  To open a file (say `lab0.txt`) for editing you simply type 
```
nano lab0.txt
```
If the file you give doesn't exist, then it will be created.  At this point the terminal window will display an editor.  You can navigate around with the arrow keys and type text as normal in the file. To save a file you hit CTRL-O and then type in the name of the file to save (it defaults to the current name of the file, in which case you can just hit ENTER).  You type CTRL-X to exit the program and go back to the terminal. Other commands are displayed at the bottom of the window. 

---

#### Task 10. Use `nano` to edit the `lab0.txt` file you created in Task 7.  Type in some text, save it, and then exit back to the terminal. 
---

To view the contents of a file from the command line, without being able to edit them you can use the `cat` command, which takes the file name/path as an argument.  To view the contents of a file name `file1.txt` you would type
```
cat file1.txt
```

---

#### Task 11. Use `cat` to view the contents of `lab0.txt` from the terminal. 

---

## Part 6. File System Tasks

You now have the skills necessary to work with directories and files.  You will copy a compressed directory from our class directory, decompress/extract it, and then use the skills you have learned to answer questions about it and modify it. Make sure you execute the following commands from the directory for this class that you created in Task 4. 

### Step 1. Copy the compressed lab directory 

```
cp /users/groups/cs224ta/lab0.tar.gz .
```

### Step 2. Extract the directory

```
tar -xzvf lab0.tar.gz
```
This command will unzip the compressed file and you should be able to see a `Lab0` subdirectory after executing the command. 

The following questions and tasks concern the `Lab0` directory and its contents that you just extracted. To begin, move into the `Lab0` directory.  You will find there three subdirectories (`f1`, `f2`, and `f3`) and one file (`src.c`). 

---

 * **Lab Question 3 (5 points)**: How many subdirectories are in the `f1` directory?  What are their names?
 * **Lab Question 4 (10 points)**: How many files are in the `f1` directory? What are their names?
 * **Lab Question 5 (10 points)**: How many subdirectories are in the `f2` directory (counting all subdirectories of subdirectories etc. as well)? What are their names?
 * **Lab Question 6 (10 points)**: How many files are in the `f2` directory (and its sub(sub)directories? Give the name and path to each one. 
 * **Lab Question 7 (10 points)**: Give the command(s) you would use to copy `Goldilocks.txt` into the `beds` directory, assuming you start in the `f2` directory.
 * **Lab Question 8 (10 points)**: Give the command(s) you would use to delete the `JustRight.txt` file from the `chairs` subdirectory (since Goldilocks broke it), assuming you start from the `f2` directory.
 * **Lab Question 9 (15 points)**: Our hero Theseus is looking for the Minotaur monster somewhere in the `f3` directory's maze of subdirectories.  Find the file `Minotaur.txt` and give the `mv` command(s) that would move the `Theseus.txt` file into the same directory as `Minotaur.txt` so that Theseus can save the day. (assume that you start in the `f3` directory)
 * **Lab Question 10 (10 points)**: What is the full path to the directory where Theseus and the Minotaur now are?

---

## Part 7. Editing, Compiling, and Running a C Program

### Step 1. Compiling a C program
In the `Lab0` directory there is a file named `src.c`.  This is a simple C program.  To run this program it needs to be compiled into an executable program.  This is done using the `gcc` compiler.  To compile the program type the following at the command prompt

```
gcc src.c
```

You can now use `ls` to see another file in the directory called `a.out`.  This file is the executable program. 

### Step 2. Running a program
To run the executable program that you just created you type the following

```
./a.out
```

The program will display some text, indicating what the value of a first and second number are, and then what the result of some computation is.  All three numbers that are displayed should be 0. 

You will now edit the `src.c` file to modify its behavior.  Hopefully the contents of the file are not completely foreign, given your previous programming background.  Do not worry about any specifics of the file for now, these will be covered in class throughout the coming weeks. 

---

#### Task 12. Open the src.c file and modify it so that instead of each constant being set to 0, they are now set to new values as follows: first is set to 270 and second to 289.  Recompile the program and run it again.

---

---

 * **Lab Question 11 (10 points)**. What is the result that is now output by the `a.out` program?

---

## Part 8. Redirections, Input and Output
A final two commands are super useful for connecting the input and output of programs to files or other programs. 
These are important to be introduced to, as you will use them in the labs. 

The first of these commands is `>` (or `<`), which redirects the file or output on the bigger side to whatever is on the other side.  
As an example the command `./a.out > output.txt` will redirect the output of the program `a.out` (which is the text printed to the terminal), into a file called `output.txt` (which will be created).  

#### Task 13. Create an output.txt file by using the previous redirection.  Use `cat` to view the contents of the file. 

This redirection can also be used to send a file as input to a program that normally gets its input from the command line.  For example, `grep` is a command/program that finds patterns in files. 
To see how this works, type `grep 'first' output.txt` on the command line.  grep will print out the line from the file that has the pattern 'first' in it.  
If no file is given to grep, then it will find the pattern in what is typed at the command line.  
You can try this by typing `grep 'first'` on the command-line.  Then you can type lines of text.  If your line includes the pattern 'first' then grep will reprint it after you type enter. 
(Type Ctrl-D (press Control and the D key at the same time) to end your input to grep). 

---

#### Task 14. Send output.txt as the input to grep using redirection, by typing ``grep 'first' < output.txt``

---

The second command is called a pipe, and is the symbol `|`.  It is used to connect the output of one program with the input of another.  

For example, another way to send the output.txt file to grep is to use the cat command (which outputs the file to the terminal) and then connect that output to the input of grep with the pipe (|). 

---

#### Task 15. Send output.txt as the input to grep using `cat` and the pipe (`|`) command, by typing ``cat output.txt | grep 'first'``

---

Try other patterns (instead of 'first') and see what grep outputs.  You will become more familiar with these two redirection commands over the course of this semester. 


## Conclusion
Congratulations!  Having finished all of the above steps you just need to enter your answers to the lab questions into Canvas and then you are done with Lab 0!  Before you go, here are a few tips and tricks for working with the terminal that might prove helpful during the course of this class. 

#### Command Line Tips and Tricks

---

 * You can use the up and down arrows from the command prompt to cycle through the previous commands that you have typed in.  This is especially useful for longer commands that take a long time to type in, or that are hard to remember.  If you have done the command recently, you can just push up and it will bring it back.  A common time this occurs is when you will repeatedly use `nano` to edit some code, then compile it, and then run it.  Since the code never works right the first time, you can press up three times and you are back to the `nano` command, then when you are done editing you can press up three times to be back to the compile command, and then up three times to the run program command.  
 * The command line supports tab completion of directory and file names.  When you are typing the name of a file you can press TAB and it will complete the name.  You need to have enough of the name typed in so that it knows what you want, but this often can save a lot of typing.
 * Another useful command is `tree` which will display the file and (sub)directory structure of the current folder.  Try this with the `Lab0` folder and see how easy it makes getting a sense for the structure of the file system. 
 * The `man` command (for *manual*) will give you the details of how to use any command that we have talked about, and many more.  For example, just type `man ls` to get the manual for `ls` command.  This can be useful if you can't remember a specific option for a command.
 * To kill a runaway program from the command line, type CTRL-C.  This is super useful if you accidentally put an infinite loop or something in your code. 
 * The internet is full of tutorials and guides for using the command line.  There is no limit to what you can do with it, and most experienced programmers use it almost entirely to interact with their machines, because it is so powerful.  Feel free to explore and learn, but the set of commands related to the terminal that you will need for this class is fairly limited, and most are contained in this document.  Others will be introduced when necessary for subsequent labs or assignments.  


#### Summary of concepts and commands from Lab 0

---

 * `ssh` (secure shell), this allows us to remotely connect to another machine and use its terminal. 
 * `pwd` (print working directory) this shows us what the current directory of the terminal is. 
 * `ls` (list) this list the contents of the current directory
 * `mkdir` (make directory) this makes a new subdirectory in the current directory.  
 * `cd` (change directory) this changes to a new directory.  Use `..` to change out of a directory to its parent directory. 
 * `touch` create a new file if it doesn't exist, or make change it's modification time-stamp if it does
 * `cp` (copy) create a copy of a file (or directory with the `-r` option)
 * `mv` (move) move a file
 * `rm` (remove) delete a file (or directory with the `-d` or `-r` options)
 * `nano` editor for files
 * `cat` (concatentate) displays the contents of a file to the terminal
 * `gcc` our compiler for C code. 
 * `>` redirection of output to a file, and `<` redirection of a file to input
 * `|` pipe - connecting the output of a program to the input of another