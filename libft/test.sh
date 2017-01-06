#!/bin/bash

GNL=/Users/jblancha/Exercises/getnextline/libft
FDF=/Users/jblancha/Exercises/fdf/fdf1/libft
LIBFT=/Users/jblancha/Exercises/libft

SRC=$LIBFT
DEST=$GNL
basesrc=LIBFT
basedest=GNL

rm -rf fmanquant_${basesrc}_${basedest} 2>/dev/null
rm -rf fdiff_${basesrc}_${basedest} 2>/dev/null
echo "${SRC}======>${DEST}"
echo
for i in `find $SRC -type f -name "*.c" -exec basename {} \;`; do
	retls=`ls $DEST/$i 2>/dev/null`
	crls=$?
	if [ $crls -eq 1 ]; then
		echo $i >> fmanquant_${basesrc}_${basedest}
 	fi	
	if [ $crls -eq 0 ]; then
		diff=`diff $SRC/$i $DEST/$i 2>/dev/null`
		crdiff=$?
		if [ $crdiff -ne 0 ]; then
			echo $i >> fdiff_${basesrc}_${basedest}
		fi

 	fi	
done


SRC=$GNL
DEST=$LIBFT
basesrc=GNL
basedest=LIBFT

rm -rf fmanquant_${basesrc}_${basedest} 2>/dev/null
rm -rf fdiff_${basesrc}_${basedest} 2>/dev/null
echo "${SRC}======>${DEST}"
echo
for i in `find $SRC -type f -name "*.c" -exec basename {} \;`; do
	retls=`ls $DEST/$i 2>/dev/null`
	crls=$?
	if [ $crls -eq 1 ]; then
		echo $i >> fmanquant_${basesrc}_${basedest}
 	fi	
	if [ $crls -eq 0 ]; then
		diff=`diff $SRC/$i $DEST/$i 2>/dev/null`
		crdiff=$?
		if [ $crdiff -ne 0 ]; then
			echo $i >> fdiff_${basesrc}_${basedest}
		fi

 	fi	
done

SRC=$LIBFT
DEST=$FDF
basesrc=LIBFT
basedest=FDF

rm -rf fmanquant_${basesrc}_${basedest} 2>/dev/null
rm -rf fdiff_${basesrc}_${basedest} 2>/dev/null
echo "${SRC}======>${DEST}"
echo
for i in `find $SRC -type f -name "*.c" -exec basename {} \;`; do
	retls=`ls $DEST/$i 2>/dev/null`
	crls=$?
	if [ $crls -eq 1 ]; then
		echo $i >> fmanquant_${basesrc}_${basedest}
 	fi	
	if [ $crls -eq 0 ]; then
		diff=`diff $SRC/$i $DEST/$i 2>/dev/null`
		crdiff=$?
		if [ $crdiff -ne 0 ]; then
			echo $i >> fdiff_${basesrc}_${basedest}
		fi

 	fi	
done

SRC=$FDF
DEST=$LIBFT
basesrc=FDF
basedest=LIBFT

rm -rf fmanquant_${basesrc}_${basedest} 2>/dev/null
rm -rf fdiff_${basesrc}_${basedest} 2>/dev/null
echo "${SRC}======>${DEST}"
echo
for i in `find $SRC -type f -name "*.c" -exec basename {} \;`; do
	retls=`ls $DEST/$i 2>/dev/null`
	crls=$?
	if [ $crls -eq 1 ]; then
		echo $i >> fmanquant_${basesrc}_${basedest}
 	fi	
	if [ $crls -eq 0 ]; then
		diff=`diff $SRC/$i $DEST/$i 2>/dev/null`
		crdiff=$?
		if [ $crdiff -ne 0 ]; then
			echo $i >> fdiff_${basesrc}_${basedest}
		fi

 	fi	
done

SRC=$FDF
DEST=$GNL
basesrc=FDF
basedest=GNL

rm -rf fmanquant_${basesrc}_${basedest} 2>/dev/null
rm -rf fdiff_${basesrc}_${basedest} 2>/dev/null
echo "${SRC}======>${DEST}"
echo
for i in `find $SRC -type f -name "*.c" -exec basename {} \;`; do
	retls=`ls $DEST/$i 2>/dev/null`
	crls=$?
	if [ $crls -eq 1 ]; then
		echo $i >> fmanquant_${basesrc}_${basedest}
 	fi	
	if [ $crls -eq 0 ]; then
		diff=`diff $SRC/$i $DEST/$i 2>/dev/null`
		crdiff=$?
		if [ $crdiff -ne 0 ]; then
			echo $i >> fdiff_${basesrc}_${basedest}
		fi

 	fi	
done

SRC=$GNL
DEST=$FDF
basesrc=GNL
basedest=FDF

rm -rf fmanquant_${basesrc}_${basedest} 2>/dev/null
rm -rf fdiff_${basesrc}_${basedest} 2>/dev/null
echo "${SRC}======>${DEST}"
echo
for i in `find $SRC -type f -name "*.c" -exec basename {} \;`; do
	retls=`ls $DEST/$i 2>/dev/null`
	crls=$?
	if [ $crls -eq 1 ]; then
		echo $i >> fmanquant_${basesrc}_${basedest}
 	fi	
	if [ $crls -eq 0 ]; then
		diff=`diff $SRC/$i $DEST/$i 2>/dev/null`
		crdiff=$?
		if [ $crdiff -ne 0 ]; then
			echo $i >> fdiff_${basesrc}_${basedest}
		fi

 	fi	
done
