cd images
for filename in *
do
	../filter -${1:0:1} $filename ../$1_$filename
done
