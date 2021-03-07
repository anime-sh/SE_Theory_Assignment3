echo "Testing via UnitDate.cpp"
g++ -std=c++17 -Wshadow -Wall -Wextra -pedantic -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -Wno-unused-result -Wno-sign-conversion -D_GLIBCXX_DEBUG_PEDANTIC -fno-sanitize-recover=all -fstack-protector -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG ../UnitDate.cpp ../Date.cpp -o UnitDate
echo "Done Compiling"
echo "Running the Test file"
echo $'-------------PROGRAM OUTPUT STARTS------------------ \n \n'
./UnitDate
now=$(date +'%d_%m_%Y')
echo $'\n \n Saving output to file \n \n'
./UnitDate > "../../Outputs/${now}_UnitDate.log"
echo $'\n \n Validating with golden outputs '
if  cmp -s  "../../Outputs/GoldenOutputs/UnitDate.log" "../../Outputs/${now}_UnitDate.log"
then 
    echo $'\n Matches golden, unit tests passed !! \n'
else
    echo $'\n Doesnt Match golden, unit tests FAILED :( !! \n'
fi
rm UnitDate
