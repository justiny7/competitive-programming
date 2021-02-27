g++ -std=c++17 -O3 -o A A.cpp

for i in a b c d e f; do
    echo $i
    ./A.exe < $i.txt > $i.output
    # ./score < $i.out
done
wait
