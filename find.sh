if [ $# -ne 1 ]
  then
    echo "error: find.sh need an argument.\nusage: sh find.sh <query>"
    exit
fi

for file in /usr/local/opt/vtk/lib/*
do
	if [ -f "$file" ]; then
		SEARCH=`nm -gU $file | grep -i $1`
		if [ "$SEARCH" != "" ]; then
			echo $file
		fi
	fi
#	SEARCH=
done


#nm -gU /usr/local/opt/vtk/lib/* 2>/dev/null | grep -i "getoutputport"
