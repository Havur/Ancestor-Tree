
add_executable(testPerson TestPerson.cpp)
add_test(NAME testPerson COMMAND testPerson)
target_include_directories(testPerson PUBLIC "${CMAKE_SOURCE_DIR}/include")
