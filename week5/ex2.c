#!/bin/bash

while [ -f "file.lock" ] ; do
    sleep 0.1
done

if [ ! -f file ] ; then
    echo 1 > file
fi

ln file file.lock
read="$(cat file | awk '{print $NF}')" && ((read+=1))

echo "$(cat file) $read" > file

rm file.lock
