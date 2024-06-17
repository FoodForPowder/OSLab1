#!/bin/bash -e

directory="/shared_volume"
lock_file="$directory/file_lock"
containerId=$(shuf -i 1-100000000 -n1)
I=1

while true; do

exec 9>"$lock_file"
flock -x 9
while [ -f "/$directory/$(printf "%03d" $I)" ]; do
I=$((I+1))
done
fileName=$(printf "%03d" $I)

echo "Container $containerId create file $fileName with content $containerId $fileName"
echo "$containerId $fileName" > "/$directory/$fileName"
I=$((I+1))
flock -u 9
sleep 1

echo "Container $containerId delete file $fileName"
rm "/$directory/$fileName"

sleep 1

done
