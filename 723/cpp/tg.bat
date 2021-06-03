python3 %CFTOOL%\recording.py "Testing" %1
.\testset\testset%1.exe 5450 < ins.txt > input.txt
.\%1\main.exe < .\input.txt > .\output.txt

if "%~2"=="" goto skipped

.\%2\main.exe < .\input.txt > .\answer.txt

goto done 

:skipped



goto done 

:done

.\judge\judge%1.exe
