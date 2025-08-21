cd ..\Out

mkdir API
cd API
cmake ../../Oriol/API
cmake --build .

cd ..
mkdir Oriol_Dev
cd Oriol_Dev
cmake ../../Oriol/Oriol_Dev
cmake --build .