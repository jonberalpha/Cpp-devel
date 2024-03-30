# Quick Guide
In the build directory there is the 'asa-demo' which is the asa-program itself.
It can be executed e.g. like './asa-demo student_list.csv' which picks automatically 
the given csv-file in the data-directory. Then the program creates in the same directory
the seatlist.csv which contains the seated students.

In the same directory there is also the 'asa-test' executable which when executed 
runs the following Catch2-tests:
* Given: A negative row number
* Given: A negative column number
* Given: A non-existing file
* Given: 9 students who will be seated in a 6x8 matrix
