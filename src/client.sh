set -m
make clean
make

for ((i=1; i<=$3; i++))
do
    (./client $1 $2) &
done
