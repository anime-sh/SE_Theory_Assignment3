# Assignment 3 #    
### Animesh Jha  19CS10070 ###
This directory contains the source code, unit tests and testing scripts for Software Engineering Theory Assignment 3  \
\
NOTE: In my solution I have used  `BookingClass` instead of `BookingClasses` please note the difference while evaluating
Number | File Name | Content
| :--- | :--- | :---
1 | TestingScripts/testing.sh | Runs the file testing.cpp which contains the test given in Section C, stores the output at `../Outputs/MM_DD_YYYY_testing.log` and compares it with the golden output present at `../Outputs/GoldenOutput/testing.log`
2 | TestingScripts/UnitTestBooking.sh | Runs the unit test for the `class Booking`, stores the output at `../Outputs/MM_DD_YYYY_UnitTestBooking.log` and compares it with the golden output present at `../Outputs/GoldenOutput/UnitTestBooking.log`
3 | TestingScripts/UnitTestBookingClass.sh | Runs the unit test for the `class BookingClass`, stores the output at `../Outputs/MM_DD_YYYY_UnitTestBookingClass.log` and compares it with the golden output present at `../Outputs/GoldenOutput/UnitTestBookingClass.log`
4 | TestingScripts/UnitTestDate.sh | Runs the unit test for the `class Date`, stores the output at `../Outputs/MM_DD_YYYY_UnitTestDate.log` and compares it with the golden output present at `../Outputs/GoldenOutput/UnitTestDate.log`
5 | TestingScripts/UnitTestRailways.sh | Runs the unit test for the `class Railways`, stores the output at `../Outputs/MM_DD_YYYY_UnitTestRailways.log` and compares it with the golden output present at `../Outputs/GoldenOutput/UnitTestRailways.log`
6 | TestingScripts/UnitTestStation.sh | Runs the unit test for the `class Station`, stores the output at `../Outputs/MM_DD_YYYY_UnitTestStation.log` and compares it with the golden output present at `../Outputs/GoldenOutput/UnitTestStation.log`
7 | TestingScripts/customtesting.sh | Runs the file customtesting.cpp which contains a custom test, stores the output at `../Outputs/MM_DD_YYYY_customtesting.log` and compares it with the golden output present at `../Outputs/GoldenOutput/customtesting.log`
8|Application.cpp| Defines static members of various classes
9|Booking.cpp| Implements interfaces of `class Booking`
10|Booking.h| Defines the `class Booking`
11|BookingClass.cpp|Implements interfaces of the various classes with base class `BookingClass`
12|BookingClass.h| Defines various classes with base class `BookingClass`
13|Date.cpp|Implements interfaces of `class Date`
14|Date.h|Defines the `class Date`
15|Railways.cpp|Implements interfaces of `class Railways`
16|Railways.h|Defines the `class Railways`
17|Station.cpp|Implements interfaces of `class Station`
18|Station.h|Defines the `class Station`
19|testing.cpp| Contains the code of the given test in Section C
20|customtesting.cpp| Contains the code for a custom total test
21|UnitBooking.cpp|Calls the unit test for `Booking`
22|UnitBookingClass.cpp|Calls the unit tests for all classes with base class `BookingClass`
23|UnitDate.cpp|Calls the unit test for `Date`
24|UnitRailways.cpp|Calls the unit test for the singleton `Railways` 
25|UnitStation.cpp| Calls the unit test for `Station`


## Compiling and running different files
1. Compiler Used: g++
2. C++ Standard Used: c++17
3. Flags Used
    1. "-Wshadow"
    1. "-Wall"
    1. "-Wextra"
    1. "-pedantic"
    1. "-Wformat=2"
    1. "-Wfloat-equal"
    1. "-Wconversion"
    1. "-Wlogical-op"
    1. "-Wshift-overflow=2"
    1. "-Wduplicated-cond"
    1. "-Wcast-qual"
    1. "-Wcast-align"
    1. "-Wno-unused-result"
    1. "-Wno-sign-conversion"
    1. "-D_GLIBCXX_DEBUG_PEDANTIC"
    1. "-fno-sanitize-recover=all"
    1. "-fstack-protector"
    1. "-D_FORTIFY_SOURCE=2"
    1. "-fsanitize=address"
    1. "-fsanitize=undefined"
    1. "-D_GLIBCXX_DEBUG"

Number | File Name | Command
| :--- | :--- | :---
1 | customtest.cpp| `g++ -std=c++17 -Wshadow -Wall -Wextra -pedantic -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -Wno-unused-result -Wno-sign-conversion -D_GLIBCXX_DEBUG_PEDANTIC -fno-sanitize-recover=all -fstack-protector -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG customtesting.cpp Station.cpp Booking.cpp BookingClass.cpp Application.cpp Railways.cpp Date.cpp -o customtesting`
2 | testing.cpp|`g++ -std=c++17 -Wshadow -Wall -Wextra -pedantic -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -Wno-unused-result -Wno-sign-conversion -D_GLIBCXX_DEBUG_PEDANTIC -fno-sanitize-recover=all -fstack-protector -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG testing.cpp Station.cpp Booking.cpp BookingClass.cpp Application.cpp Railways.cpp Date.cpp -o testing`
3 | UnitTestBooking.cpp|`g++ -std=c++17 -Wshadow -Wall -Wextra -pedantic -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -Wno-unused-result -Wno-sign-conversion -D_GLIBCXX_DEBUG_PEDANTIC -fno-sanitize-recover=all -fstack-protector -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG UnitBooking.cpp Station.cpp Railways.cpp Date.cpp Booking.cpp BookingClass.cpp Application.cpp -o UnitBooking`
4 | UnitTestBookingClass.cpp|`g++ -std=c++17 -Wshadow -Wall -Wextra -pedantic -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -Wno-unused-result -Wno-sign-conversion -D_GLIBCXX_DEBUG_PEDANTIC -fno-sanitize-recover=all -fstack-protector -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG UnitBookingClass.cpp BookingClass.cpp -o UnitBookingClass`
5 | UnitTestDate.cpp|`g++ -std=c++17 -Wshadow -Wall -Wextra -pedantic -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -Wno-unused-result -Wno-sign-conversion -D_GLIBCXX_DEBUG_PEDANTIC -fno-sanitize-recover=all -fstack-protector -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG UnitDate.cpp Date.cpp -o UnitDate`
6 | UnitTestRailways.cpp|`g++ -std=c++17 -Wshadow -Wall -Wextra -pedantic -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -Wno-unused-result -Wno-sign-conversion -D_GLIBCXX_DEBUG_PEDANTIC -fno-sanitize-recover=all -fstack-protector -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG UnitRailways.cpp Station.cpp Railways.cpp Application.cpp -o UnitRailways`
7 | UnitTestStation.cpp|`g++ -std=c++17 -Wshadow -Wall -Wextra -pedantic -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -Wno-unused-result -Wno-sign-conversion -D_GLIBCXX_DEBUG_PEDANTIC -fno-sanitize-recover=all -fstack-protector -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG UnitStation.cpp Station.cpp Railways.cpp Application.cpp -o UnitStation`
