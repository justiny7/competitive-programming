@echo off
gen > in
brute < in > out
D < in > out2
fc out out2
if errorlevel 1 exit
test

