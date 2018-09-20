# CS 3251: Intermediate Software Design

## Programming Assignment 3

This assignment focuses on strong exception safety.  As always, you have been provided with several source files to start with:

* _include/ArrayList.h_
* _include/ArrayListIter.h_
* _include/ScopedArray.h_
* _src/ScopedArray.cpp_
 
And several building and testing files:

* _tests/main.cpp_
* _tests/arrayTest.cpp_
* _tests/arrayIterTest.cpp_
* _tests/constArrayTest.cpp_
* _CMakeLists.txt_
* _.clang-format_
* _.gitignore_
* _.travis.sh_
* _.travis.yml_

Do not modify any of these files.

The files _ArrayList.h_ and _ArrayListIter.h_ contain comments that specify the class's functionality. Your task is to implement all of the classes and methods declared in _ArrayList.h_ and _ArrayListIter.h_ in a **strongly-exception** safe manner. You can either use the _ScopedArray.h_ class that you completed previously, or the one supplied in this repository.

The assignment is to be submitted using the link to github.com sent out via email to all class members. DO NOT email your assignment to the professor or the TAs.  Emailed assignments ARE NOT accepted.  We will grade the last commit to your repository before the deadline date and time.  Any commits after that moment will be ignored.  If nothing has been committed at that time you will receive a zero grade. 


### Undergraduate Students: 

Undergraduates are to implement the functionality described in the _include/ArrayList.h_ and _include/ArrayListIter.h_ files.  Read through the files carefully, and study the test cases defined in _tests/arrayTest.cpp_ and _tests/arrayIterTest.cpp_.  These will be your guide for what the code must do.  Then review your code to ensure it is strongly exception safe.  **Undergraduates do not need to implement the const iterator.  Do not remove or change any of the supplied files because of this requirement.**.

### Graduate Students: 

Graduate students are to complete the same steps as the undergraduates, described above. Additionally, graduate students are required to implement a constant iterator version of the _ArrayListIterator_ class.  Declare the class at the bottom of _include/ArrayListIter.h_ and provide the implementation at the bottom of _src/ArrayListIter.cpp_.  Also create at least six (6) good test cases for the constant ArrayListIterator.  Use the skeleton testing file _tests/constArrayTest.cpp_ for the test code.

### REMINDERS:

* Ensure that your name, vunetid, email address, and the honor code appear in the header comments of all files that you have altered.

* Do not alter any of the project files unless explicitly directed otherwise!  Work only on those files specified above.  You must use the supplied `CMakeLists.txt` file as is.

* All students are required to abide by the CS 3251 coding standard, [available on the course web page](https://vuse-cs3251.github.io/style-guidelines/) and provided to you on the first day of class. Points will be deducted for not following the coding standard.

* For full credit, your program must compile with recent versions of `clang` and `gcc` and run successfully with Travis CI.
  * The Travis build *will* fail if your code is not properly formatted. **This is by design.** If your code is compiling and running successfully, but the build is failing, then your build is most likely failing because your code is not passing the linter. This can be confirmed by checking if a command involving `clang-format` in the Travis build output log has an exit code of 1.

* Your program(s) should always have an exit code of 0.  A non-zero exit code (generally indicative of a segmentation fault or some other system error) is reason to worry and must be corrected for full points.
  
* When submitting the assignment, all files that are provided to you, plus your solution files have been submitted. All files necessary to compile and run your program must reside in the GitHub.com repository.

