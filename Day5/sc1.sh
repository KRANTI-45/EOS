#!bin/bash

echo -n "enter l and b"
read l b
area=`expr $l \* $b`
echo " area is :$area"

echo -n "radius"
read r
area=`echo "3.14 * $r * $r" | bc`
echo "area of circle=$area"
