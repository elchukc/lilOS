#/bin/bash
# setup instructions for running on Ubuntu 24.04 LTS
# This script needs only be run once
sudo apt upgrade
sudo apt install -y nasm \
                    make \
                    qemu-system-i386 \
                    git \
                    build-essential \
                    bison flex \
                    libgmp3-dev \
                    libmpc-dev \
                    libmpfr-dev \
                    texinfo \
                    libisl-dev

export PREFIX="$HOME/opt/cross"
export TARGET=i686-elf
export PATH="$PREFIX/bin:$PATH"


# compile Binutils
cd $HOME/src
mkdir build-binutils
cd build-binutils
../binutils-2.35.1/configure --target=$TARGET --prefix="$PREFIX" --with-sysroot --disable-nls --disable-werror
make
make install


# compile GCC
cd ..
# The $PREFIX/bin dir _must_ be in the PATH. We did that above.
which -- $TARGET-as || echo $TARGET-as is not in the PATH

mkdir build-gcc
cd build-gcc
../gcc-10.2.0/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --enable-languages=c,c++ --without-headers
make all-gcc
make all-target-libgcc
make install-gcc
make install-target-libgcc


# create a mount point for loading /programs folder into lilOS's filesystem
sudo mkdir /mnt/d


echo "Setup complete! you can now test gcc with the command '$HOME/opt/cross/bin/$TARGET-gcc --version'"
echo "You can build the project with './build.sh'"