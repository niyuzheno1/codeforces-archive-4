python3 C:\Users\zachn\OneDrive\Documents\CFTOOLS\recording.py "Compiling Judge for " %1
cd .\judge
type judge%1.cpp | clay > dg.cpp 
cl.exe /I C:\Users\zachn\OneDrive\Documents\include /Zi /EHsc /D DEBUG /D _CRT_NO_VA_START_VALIDATION /Fe: .\judge%1.exe dg.cpp