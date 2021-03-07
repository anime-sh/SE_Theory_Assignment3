echo "Testing via UnitRailways.cpp"
g++ -std=c++17 -Wshadow -Wall -Wextra -pedantic -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -Wno-unused-result -Wno-sign-conversion -D_GLIBCXX_DEBUG_PEDANTIC -fno-sanitize-recover=all -fstack-protector -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG ../UnitRailways.cpp ../Station.cpp ../Railways.cpp ../Application.cpp -o UnitRailways
echo "Done Compiling"
echo "Running the Test file"
echo $'-------------PROGRAM OUTPUT STARTS------------------ \n \n'
./UnitRailways
now=$(date +'%d_%m_%Y')
echo $'\n \n Saving output to file \n \n'
./UnitRailways > "../../Outputs/${now}_UnitRailways.log"
echo $'\n \n Validating with golden outputs '
if  cmp -s  "../../Outputs/GoldenOutputs/UnitRailways.log" "../../Outputs/${now}_UnitRailways.log"
then 
    echo $'\n Matches golden, unit tests passed !! \n'
else
    echo $'\n Doesnt Match golden, unit tests FAILED :( !! \n'
fi
rm UnitRailways
