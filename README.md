# ABCU-Advising-Assistance-Program-Data-Structures-and-Algorithms-
A C++ command-line advising application that reads course data from a CSV file and stores courses in a hash table. Users can load data, print an alphanumeric list of courses, and search a specific course to view its title and prerequisites. Demonstrates data structures, algorithms, and runtime analysis.

# Reflection questions
Reflection
What was the problem you were solving in the projects for this course?

The problem I was solving was creating an advising assistance program for ABC University that allows academic advisors to quickly access course information. The program needed to read course data from a file, store the courses in a data structure, print all courses in alphanumeric order, and allow advisors to search for a specific course to view its title and prerequisites. The project required both planning and implementation to make sure the program worked efficiently and correctly.

How did you approach the problem? Consider why data structures are important to understand.

I approached the problem by first designing pseudocode and analyzing multiple data structures before writing any actual code. I compared vectors, hash tables, and binary search trees to determine which structure would provide the best performance. This helped me understand that data structures directly affect how fast a program can search, store, and retrieve data. I selected a hash table because advisors will frequently search for specific courses, and a hash table allows fast lookup times.

How did you overcome any roadblocks you encountered while going through the activities or project?

One of the main roadblocks I encountered was reading the course file and handling formatting issues in the CSV file. Some lines contained extra commas and spaces, which caused errors when validating prerequisites. I also struggled with compiling and running the program in the Codio environment. I overcame these challenges by debugging step by step, testing individual functions, and adjusting the program to ignore invalid blank prerequisites. Over time I became more comfortable using the terminal and identifying compile and runtime errors.

How has your work on this project expanded your approach to designing software and developing programs?

This project changed how I approach programming. Previously I would start writing code immediately, but I learned that planning and design are essential. Writing pseudocode and analyzing runtime complexity helped me understand how the program should function before implementing it. I now recognize that choosing the correct data structure is just as important as writing the code itself, and it can significantly improve performance.

How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?

This project improved how I organize and write programs. I separated the program into functions for loading data, printing courses, and searching courses instead of placing everything inside the main function. I also used clear naming and comments to improve readability. Adding error handling made the program more reliable and adaptable to different input files. As a result, I now focus more on structure, readability, and maintainability rather than just getting the program to run.
