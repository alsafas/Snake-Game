#!/bin/bash 

out=`(./ALTester)`
echo $out
if [[ $out == *"!!!FAILURES!!!"* ]]; then
  exit 1;
fi


