# CMake generated Testfile for 
# Source directory: C:/Users/romulo/dev/unreal-projects/MyProject/Source/logic
# Build directory: C:/Users/romulo/dev/unreal-projects/MyProject/Source/logic
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(logic_unit_tests "C:/Users/romulo/dev/unreal-projects/MyProject/Source/logic/Debug/logic.exe")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(logic_unit_tests "C:/Users/romulo/dev/unreal-projects/MyProject/Source/logic/Release/logic.exe")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(logic_unit_tests "C:/Users/romulo/dev/unreal-projects/MyProject/Source/logic/MinSizeRel/logic.exe")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(logic_unit_tests "C:/Users/romulo/dev/unreal-projects/MyProject/Source/logic/RelWithDebInfo/logic.exe")
else()
  add_test(logic_unit_tests NOT_AVAILABLE)
endif()
subdirs("googletest-build")
