set -v
echo -e "\e[31m"
echo -e "Help Menu Test  "
echo -e "_________________"
echo -e "\e[39m"
./matrix_math -h 
echo -e "\e[31m"
echo -e "Addition Test  "
echo -e "_________________"
echo -e "\e[39m"
./matrix_math F + F 
./matrix_math F + B 
echo -e "\e[31m"
echo -e "Subtraction Test"
echo -e "_________________"
echo -e "\e[39m"
./matrix_math F - F 
./matrix_math F - A 
echo -e "\e[31m"
echo -e "Multiplication Test"
echo -e "_________________"
echo -e "\e[39m"
./matrix_math F x F
echo -e "\e[31m"
echo -e "Scalar Division Test"
echo -e "_________________"
echo -e "\e[39m"
./matrix_math F / 2
echo -e "\e[31m"
echo -e "Scalar Multiplication Test"
echo -e "_________________"
echo -e "\e[39m"
./matrix_math F / 2
echo -e "\e[31m"
echo -e "Input and Output Test"
echo -e "_________________"
echo -e "\e[39m"
./matrix_math -inp F -out Z
echo -e "\e[31m"
echo -e "Sub Matrix test with output"
echo -e "_________________"
echo -e "\e[39m"
./matrix_math -sub F 1 1 -out Z
echo -e "\e[31m"
echo -e "Equality Test"
echo -e "_________________"
echo -e "\e[39m"
./matrix_math F / 2