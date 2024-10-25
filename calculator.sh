echo "Enter a number "
read num1
echo "Enter the operator"
read operator
echo "Enter another number "
read num2
ans=$(echo "$num1 $operator $num2" | bc)
echo "The answer is,$ans"