cmake -DCMAKE_INSTALL_PREFIX=..\work .. -DQt5_DIR=D:\Qt\5.15.1\msvc2019_64\lib\cmake\Qt5 -DOpenCV_DIR=C:\lib\build_opencv
cmake --build .
cmake --install . --config Debug