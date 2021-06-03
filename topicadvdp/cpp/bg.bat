python3 %CFTOOL%\recording.py "Compiling Data Generator for " %1
cd .\testset
type datagen%1.ocl | clay_ext > dg.cpp 
cl.exe /I C:\Users\zachn\OneDrive\Documents\include /Zi /EHsc /D DEBUG /D _CRT_NO_VA_START_VALIDATION /Fe: .\testset%1.exe dg.cpp
