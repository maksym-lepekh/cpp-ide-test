FROM docker.io/library/alpine:edge@sha256:f2d1645cd73c7e54584dc225da0b5229d19223412d719669ebda764f41396853

# toolchain
RUN apk add --no-cache llvm17 clang17 clang17-extra-tools
RUN apk add --no-cache libc++ libc++-dev libc++-static compiler-rt musl-dev
RUN apk add --no-cache make

# project tools
RUN apk add --no-cache pkgconf ninja-build ninja-is-really-ninja lf ccache git just gdb

# deps
RUN apk add --no-cache linux-headers

# cmake 3.28
ARG CMAKE_VER="v3.28.0-rc5"
RUN apk add --no-cache openssl-dev
RUN wget https://gitlab.kitware.com/cmake/cmake/-/archive/${CMAKE_VER}/cmake-${CMAKE_VER}.tar.gz \
    && tar xzf cmake-${CMAKE_VER}.tar.gz \
    && cd cmake-${CMAKE_VER}/ \
    && ./bootstrap --parallel=8 \
    && make -j \
    && make install \
    && cd .. && rm -rf cmake-*

# libc++ with modules
RUN git clone https://github.com/llvm/llvm-project.git --depth 1 --branch 'release/17.x'
RUN cd llvm-project \
    && mkdir build
RUN cd llvm-project \
    && CC=clang CXX=clang++ cmake -G Ninja -S runtimes -B build \
    -DLIBCXX_ENABLE_STD_MODULES=ON \
    -DLLVM_ENABLE_RUNTIMES="libcxx;libcxxabi;libunwind" \
    -DCMAKE_BUILD_TYPE=Release \
    -DLIBCXX_HAS_MUSL_LIBC=ON
RUN cd llvm-project \
    && ninja -C build
