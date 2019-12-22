for i in {${2}..4}
do
    time ./p${i} < ${1} > p${i}-${1}.out
done
for i in {${2}..4}
do
    for j in {${2}..4}
    do
        diff p${i}-${1}.out p${j}-${1}.out
    done
done

