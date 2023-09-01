This lab consists of a series of tasks you must complete **individually** 
using the bash shell (command line interface) on `ibanez.cs.wfu.edu`.

# Questions
For each question, 
indicate the command that solves it 
and provide the output of your command, 
if any, 
when executed on `ibanez.cs.wfu.edu`.
For your answers, 
which you will enter in the text box below, 
make sure you **clearly** indicate what question you are answering. 
Note the point value per question.

1. Assuming you are in your home directory, 
what is the command that counts the number of all regular files (not directories) 
in the `/usr/share` directory? ($4$ points)
2. The `uname`` command provides details about the server. 
What flag(s) should you supply to list all the system information? 
How did you find out that information? 
What was the result of your command? ($2$+$2$+$1$ points)
3. The `ls` command lists directories and files in alphabetical order. 
Assuming you are in your home directory, 
what is the command to list the `/usr` directory, 
one line per item, 
based on last modified date, 
oldest date first (top of the output)? ($5$ points)
4. Give the command that will return the location of the `passwd` file(s) ($2$ points). 
What is/are the location(s) of the `passwd` text file(s) (in ASCII) ($2$ points)? 
Give the command to determine which file(s) is/are ASCII text file ($3$ points).
5. The file `ip-ranges.json` 
(hopefully you have downloaded this file in your unix-lab directory; 
if not, see the tutorial) 
contains information about AWS cloud resources (region, IP address, service, etc.). 
The information is in json format, 
so items are grouped using curly-braces and separated using commas, for example:
    ```json    
    ...
    {       
      "ip_prefix": "3.2.34.0/26",
      "region": "af-south-1",
      "service": "AMAZON",
      "network_border_group": "af-south-1"     
    },
    {       
      "ip_prefix": "3.5.140.0/22",
      "region": "ap-northeast-2",
      "service": "AMAZON",
      "network_border_group": "ap-northeast-2"     
    }, 
    ...
    ```
    Answer the following questions about this file. For each question, assume you are in your `unix-lab` directory.

    - What command displays the _full_ contents of this file to the screen? ($1$ point)
    - What command determines the number of lines in this file? ($2$ points)
    - Every server in the file is associated with a service 
    ("AMAZON", "CLOUDFRONT", "GLOBALACCELERATOR", etc.). 
    What command returns the number of "CLOUDFRONT" servers? ($3$ points)
    - Give the command that returns the number of unique services offered. 
    What are these unique services listed in the file? ($5$ points)
    - A "region" is the general location that an AWS service is hosted. 
    Example region names include "eu-west-1", "eu-east-2", etc. 
    Give the command that returns the number of unique "eu-west" regions in the file 
    (for example, there is "eu-west-1" and "eu-west-2", 
    but is there a "eu-west-3" or a "eu-west-4"?). 
    What are the unique "eu-west" regions listed in the file? ($8$ points)
6. Write a bash script called `count_bugs.sh` 
that will return the number of times the word "bug," "bugs," or "buggy" appears 
in all the `.h` files in the `/usr/include/linux` directory. 
Do not include other words (e.g. "debug"). 
Note the output for each file should include the filename 
and the number of times the word "bug," "bugs," or "buggy" appears. 
Make sure your script is executable. ($15$ points)
