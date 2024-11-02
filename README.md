# lilOS
LilOS is a microkernel built for the purpose of 1) learning C and 2) gaining practical understanding of operating systems and the hardware-software interface.

For details about the kernel itself, see Daniel McCarthy's original [PeachOS](https://github.com/nibblebits/PeachOS).

## Running Locally
All development of this kernel was done in a VM of Ubuntu 24.04 LTS x86_64. I used Gnome Boxes, but if you're on Mac or Windows, try [VirtualBox](https://www.virtualbox.org/). On your VM application of choice, create a new virtual machine out of a Ubuntu 24.04 LTS x86_64 image. I would recommend allocating 25 GB of disk space for developing in the VM, or less if you intend only to try running it.

### Setting up your VM environment
It is recommended that you go into Settings > Power > Make sure 'Screen Blank' is set to 'Never'.

Open the terminal and enter this command to update all your packages and install the necessary dependencies for this system with `sudo apt upgrade && sudo apt install -y nasm make qemu-system-i386 git`. And then git clone this repository.

You also need the deps for the GCC Cross-compiler so the C programs will work alongside assembly. The following steps are borrowed from the [OSDev Wiki GCC Guide](https://wiki.osdev.org/GCC_Cross-Compiler#Installing_Dependencies).
```
sudo apt install -y build-essential \
                    bison flex \
                    libgmp3-dev \
                    libmpc-dev \
                    libmpfr-dev \
                    texinfo \
                    libisl-dev
```

Then you need to download the source code of BinUtils and GCC.

#### BinUtils
Go to https://ftp.gnu.org/gnu/binutils/, scroll down to the latest version, and click on the link that ends in `.tar.xz` e.g. `binutils-2.43.tar.xz`.

#### GCC
Then select a [mirror to download](https://www.gnu.org/software/gcc/mirrors.html) GCC's source code. Any one of the links listed should take you to a page that looks like a file directory.

Then go to releases > gcc-10.2.0 > gcc-10.2.0.tar.gz. It may take a few minutes to download.

Create an `src/` folder in your Home directory and move binutils in there.

**[For now, follow the steps on OSDev to finish installing GCC. Build script coming soon.]**

### Running the kernel
Use the terminal to navigate the the workspace root and run `./build.sh`. Then `cd bin` and run lilOS using `qemu-system-i386 -hda ./os.bin`. You can type in the terminal, and if you shut down the OS and edit the files inside `lilOS/programs/`, you can change the text that appears on screen. You can also type!

## Further development?
Development of LilOS is on indefinite hiatus. I've shifted my focus to [a new kernel project](https://github.com/elchukc/qwos) to test my knowledge on a more independent kernel project, so it's unlikely lilOS will see further development.