#!/bin/bash

rm textout/*.txt
rm core*

root -l -q sim_digi.C >> textout/out.txt 2>textout/err.txt &
root -l -q sim_digi1.C >> textout/out1.txt 2>textout/err1.txt &
root -l -q sim_digi2.C  >> textout/out2.txt 2>textout/err2.txt &