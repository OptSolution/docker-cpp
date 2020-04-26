FROM optsolution/ubuntu-openbox-vnc:18.04

RUN apt-get update \
    && apt-get install -y \
        git gcc-7 ninja-build \
        build-essential \
        curl unzip tar wget \
        libgtk2.0-dev pkg-config \
        xorg-dev libpng-dev\
        libxi-dev libgl1-mesa-dev \
        libglu1-mesa-dev mesa-common-dev \
        libxrandr-dev libxxf86vm-dev \
        libgl1-mesa-glx \
        libosmesa6-dev mesa-utils \
        libglew-dev libglfw3-dev \
    && apt-get autoclean \
    && apt-get autoremove \
    && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /home/cmake \
    && wget  https://github.com/Kitware/CMake/releases/download/v3.14.5/cmake-3.14.5.tar.gz \
    && tar xzvf cmake-3.14.5.tar.gz && cd cmake-3.14.5 \
    && ./bootstrap && make -j8 install \
    && cd ~ && rm -rf /home/cmake/

RUN cd /home && git clone https://github.com/Microsoft/vcpkg.git \
    && cd vcpkg && ./bootstrap-vcpkg.sh \
    && ./vcpkg integrate install

ENV CMAKE_TOOLCHAIN_FILE /home/vcpkg/scripts/buildsystems/vcpkg.cmake

RUN cd /home/vcpkg && ./vcpkg install qhull tinyfiledialogs \
    && ./vcpkg install opencv4[contrib,eigen,nonfree] --recurse \
    && rm -rf /home/vcpkg/packages/ \
    && rm -rf /home/vcpkg/buildtrees/ \
    && rm -rf /home/vcpkg/downloads/

RUN cd /home && git clone --recursive https://github.com/intel-isl/Open3D \
    && cd Open3D && mkdir build && cd build \
    && cmake -DCMAKE_TOOLCHAIN_FILE=$CMAKE_TOOLCHAIN_FILE -DBUILD_PYBIND11=OFF \
        -DGLIBCXX_USE_CXX11_ABI=1 \
        -DBUILD_PYTHON_MODULE=OFF -DBUILD_PYTHON_TUTORIALS=OFF -DBUILD_EIGEN3=ON  \
        -DBUILD_GLEW=OFF -DBUILD_GLFW=ON -DBUILD_JSONCPP=ON -DBUILD_PNG=OFF \
        -DBUILD_CPP_EXAMPLES=OFF .. \
    && make -j8 install && cd ~ && rm -rf /home/Open3D/
