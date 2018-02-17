for i in `seq 1 50`; do
    ./make_data ${i} > data/input_${i}.txt
done
