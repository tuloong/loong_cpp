add_test([=[SampleTest.Test1]=]  /cygdrive/c/Users/volo/Documents/GitHub/awesome_cpp/test_main.exe [==[--gtest_filter=SampleTest.Test1]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[SampleTest.Test1]=]  PROPERTIES WORKING_DIRECTORY /cygdrive/c/Users/volo/Documents/GitHub/awesome_cpp SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[SampleTest.Test2]=]  /cygdrive/c/Users/volo/Documents/GitHub/awesome_cpp/test_main.exe [==[--gtest_filter=SampleTest.Test2]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[SampleTest.Test2]=]  PROPERTIES WORKING_DIRECTORY /cygdrive/c/Users/volo/Documents/GitHub/awesome_cpp SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  test_main_TESTS SampleTest.Test1 SampleTest.Test2)
