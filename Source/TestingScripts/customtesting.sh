echo "Testing via customtesting.cpp"
g++ -std=c++17 -Wshadow -Wall -Wextra -pedantic -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -Wno-unused-result -Wno-sign-conversion -D_GLIBCXX_DEBUG_PEDANTIC -fno-sanitize-recover=all -fstack-protector -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG ../customtesting.cpp ../Station.cpp ../Booking.cpp ../BookingClass.cpp ../Application.cpp ../Railways.cpp ../Date.cpp -o customtesting
echo "Done Compiling"
echo "Running the Test file"
echo $'-------------PROGRAM OUTPUT STARTS------------------ \n \n'
./customtesting


now=$(date +'%d_%m_%Y')
echo $'\n \n Saving output to file \n \n'

./customtesting > "../../Outputs/${now}_customtesting.log"

echo $'\n \n Validating with golden outputs '
if  cmp -s  "../../Outputs/GoldenOutputs/customtesting.log" "../../Outputs/${now}_customtesting.log"
then 
    echo $'\n Matches golden, unit tests passed !! \n'
else
    echo $'\n Doesnt Match golden, unit tests FAILED :( !! \n'
fi
rm customtesting
