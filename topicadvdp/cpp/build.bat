type clay%1.ocl | clay_ext > .\%1\main.cpp 
cd .\%1
cl.exe /I C:\Users\zachn\OneDrive\Documents\include /Zi /EHsc /D DEBUG  /Fe: main.exe main.cpp
