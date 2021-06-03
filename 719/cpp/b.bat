python3 %CFTOOL%\recording.py "Submitting" %1
type clay%1.cpp | clay > .\%1\main.cpp 
type .\%1\main.cpp  | clip