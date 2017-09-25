#!/bin/bash

# the answer is: babouchka

f=doll.bin

while ! [[ "$(file "$f")" =~ ': ASCII text'$ ]]; do
    gzip -dc "$f" > out.bin
    mv out.bin "$f"
done

cat "$f"
