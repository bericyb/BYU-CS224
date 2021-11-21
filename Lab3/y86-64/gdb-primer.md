# Debugging with GDB

The command line does provide a debugger for making sense of a misbehaving program. It is called `gdb`. It is invoke as follows.

```
$ gcc -Wall -g myxxd.c -o myxxd
egm@tajmahal:~/tmp$ gdb myxxd
GNU gdb (Ubuntu 8.1-0ubuntu3.2) 8.1.0.20180409-git
Copyright (C) 2018 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
<http://www.gnu.org/software/gdb/documentation/>.
For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from myxxd...done.
(gdb) 
```

Here are a few commands to get started:

  * Running and giving input: `run < input.txt` (`input.txt` can be any file)
  * Setting a break point on a line:  `break myxxd.c:37` (any line can be specified)
  * Stepping into a program stopped at some point: `step` (it steps into called functions)
  * Stepping over a program stopped at some point: `next` (it steps over called functions)
  * Continuing: `continue`
  * Deleting a breakpoint: `delete 1` (where 1 is the breakpoint number from where it was created)
  * Quitting `gdb`: `quit`
  * Printing local variables: `print i` or `print data[i]` (`print` followed be some variable)
  * Where a segmentation fault happens: `where`
  * Help: `help` (gives subtopics for example `help breakpoints`)

Here is an example session.

```
$ gdb myxxd
GNU gdb (Ubuntu 8.1-0ubuntu3.2) 8.1.0.20180409-git
Copyright (C) 2018 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
<http://www.gnu.org/software/gdb/documentation/>.
For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from myxxd...done.
(gdb) break myxxd.c:36 
Breakpoint 1 at 0x8c8: file myxxd.c, line 36.
(gdb) run < myxxd.c
Starting program: /users/faculty/egm/tmp/myxxd < myxxd.c

Breakpoint 1, printDataAsChars (data=0x7fffffffe2c0 "#include <stdio.\b\344\377\377\377\177", size=16) at myxxd.c:36
36		while(i < size) {
(gdb) print i
$1 = 0
(gdb) print size
$2 = 16
(gdb) next
37			c = data[i];
(gdb) next
38			if(c < ' ' || c > '~') {
(gdb) next
41			printf("%c", c);
(gdb) print data[i]
$3 = 35 '#'
(gdb) next
42			++i;
(gdb) next
36		while(i < size) {
(gdb) continue
Continuing.
00000000: 2369 6e63 6c75 6465 203c 7374 6469 6f2e  #include <stdio.

Breakpoint 1, printDataAsChars (data=0x7fffffffe2c0 "h>\n#include <std\b\344\377\377\377\177", size=16) at myxxd.c:36
36		while(i < size) {
(gdb) delete 1
(gdb) continue
Continuing.
...lots of output
(gdb) quit
$
```
