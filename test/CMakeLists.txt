file(GLOB TEST_SRC "*.cpp")


add_executable (tests ${TEST_SRC})
target_link_libraries(tests demo)
add_test (SpecTests tests)
