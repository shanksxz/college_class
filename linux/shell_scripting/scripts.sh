

# echo "Hello World !"



name="Somya Bhatt"
echo "Hello, $name!"


# to get input from user
# read -p "Enter a : " a
# read -p "Enter b : " b



sum=$((a+b))
mul=$((a*b))
div=$((a/b))


# sum=$((4+5))
# mul=$((4*5))
# div=$((5/5))


# echo $sum $mul $div



#loop

# for((i = 1; i<=10; i++)); do
#     echo "2 x $i = $((2 * i))"
# done

# for i in {1..10}; do
#     echo "2 x $i = $((2 * i))"
# done


# swap
# num1=5
# num2=6

# num1=$((num1 + num2))
# num2=$((num1 - num2))
# num1=$((num1 - num2))
# echo $num1 $num2


# pattern
for((i = 0; i<5; i++)); do
    for((j = 0; j<=i; j++)); do
        echo -n "*"
    done
    echo " "
done



# var1=100
# var2=50
# var3=45

# var4=$[$var1 * ($var2 - $var3)]
# echo The final result is $var4


# if pwd
# then
#     echo "It worked"
# fi


# echo $pwd


echo $?


# read -p "Enter a number: " num

# if [ $num -gt 10 ]
# then
#     echo "The number is greater than 10."
# else
#     echo "The number is equal to or less than 10."
# fi


# say_hello() {
#     echo "Hello $1 $2!"
# }

# say_hello "Somya" "Bhatt"


# read into an file
# echo "Hello World !" > output.txt


# read from a file
# while read output; do
#     echo "The output is: $output"
# done < output.txt



# check if a file exists
# if [ -e "output.txt" ]
# then
#     echo "File exists"
# else
#     echo "File does not exist"
# fi


# echo "Script name: $0"
# echo "First argument: $1"
# echo "Second argument: $2"



# while loopx
# count=1
# while [ $count -le 5 ]; do
#   echo "Iteration $count"
#   ((count++))
# done



# echo $[(5+4)] #9