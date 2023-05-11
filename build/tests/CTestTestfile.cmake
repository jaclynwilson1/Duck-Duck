# CMake generated Testfile for 
# Source directory: /Users/jaclyn/Desktop/Duck-Duck/tests
# Build directory: /Users/jaclyn/Desktop/Duck-Duck/build/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(.unit_tests "/Users/jaclyn/Desktop/Duck-Duck/build/unit_tests" "--reporters=junit --out=coverage.xml")
set_tests_properties(.unit_tests PROPERTIES  _BACKTRACE_TRIPLES "/Users/jaclyn/Desktop/Duck-Duck/tests/CMakeLists.txt;26;add_test;/Users/jaclyn/Desktop/Duck-Duck/tests/CMakeLists.txt;0;")
