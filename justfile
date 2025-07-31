build:
    echo "Building c++ project"
    g++ main.cpp player.cpp gui.cpp $(pkg-config --libs --cflags raylib) -o main  
    echo "Success!"
run:
    echo "starting c++ project"
    ./main
    echo "started successfully"
