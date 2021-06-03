cd .\testset
type datagen%1.cpp | clay > dg.cpp 
cl.exe /I C:\Users\zachn\OneDrive\Documents\include /Zi /EHsc /D DEBUG /D _CRT_NO_VA_START_VALIDATION /Fe: .\testset%1.exe dg.cpp