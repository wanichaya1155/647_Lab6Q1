for file in $(find . -type f -name "*.c")
do    
    prog_name=`echo $file | cut -d'/' -f2 | cut -d'.' -f1`
    prog=$(echo $file | cut -d'/' -f2)
    gcc $prog -o $prog_name 
    if [ -f $prog_name ]
    then
        ans=$(./$prog_name)
    if [ "$ans" = 20 ] 
    then
        score=10
    elif [ "$ans" != 20 ] 
    then
        score=7
    else 
        score=5
    fi
    printf "%s.c %s\n" $prog_name $score
done
//runไม่ออกค่ะหนูไม่รู้ว่าทำไม T-T
