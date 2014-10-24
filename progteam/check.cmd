@ECHO OFF 
REM g++ %1 -std=c++0x -O2 -Wall -Wextra
g++ %1 -O2 -Wall -Wextra 
IF NOT errorlevel 1 (
	a < in.txt > out.txt
	FC /n /t ok.txt out.txt
)