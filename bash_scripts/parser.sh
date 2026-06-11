#!/bin/bash
rm index.html
echo "Resolvendo URLs em: $1"
wget -q $1 | grep "calado"
cat index.html | egrep -E 'href="(https?://)?[^"]+"' | grep -w "http" | cut -d "/" -f 3 | cut -d '"' -f1 > temp.txt
for ip in $(cat temp.txt); do host "$ip" | grep "has" | cut -d " " -f1,4; done

