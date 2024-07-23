#!/bin/bash

rm textout/*.txt
rm core*

root -l -q postReco.C >> textout/out.txt 2>textout/err.txt &
root -l -q postReco1.C >> textout/out1.txt 2>textout/err1.txt &
root -l -q postReco2.C  >> textout/out2.txt 2>textout/err2.txt &