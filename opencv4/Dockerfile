FROM optsolution/ubuntu-openbox-vnc:18.04

RUN apt-get update \
    && apt-get install -y \
        git gcc-7 ninja-build \
        build-essential \
        curl unzip tar wget \
        libgtk2.0-dev pkg-config \
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
    && ./vcpkg integrate install \
    && /bin/bash -c "echo 'CMAKE_TOOLCHAIN_FILE=/home/vcpkg/scripts/buildsystems/vcpkg.cmake' >> ~/.bashrc"

RUN cd /home/vcpkg && ./vcpkg install opencv4[contrib,eigen,nonfree] --recurse \
    && rm -rf /home/vcpkg/packages/ \
    && rm -rf /home/vcpkg/buildtrees/ \
    && rm -rf /home/vcpkg/downloads/
