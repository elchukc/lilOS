# lilOS
LilOS is a microkernel built for the purpose of 1) learning C and 2) gaining practical understanding of operating systems and the hardware-software interface. For details about the kernel itself, see Daniel McCarthy's original [PeachOS](https://github.com/nibblebits/PeachOS).

## Running in a Virtual Machine (VM)
All development of this kernel was done in a VM of Ubuntu 24.04 LTS x86_64. I used Gnome Boxes, but if you're on Mac or Windows, try [VirtualBox](https://www.virtualbox.org/). On your VM application of choice, create a new virtual machine out of a Ubuntu 24.04 LTS x86_64 image. I would recommend allocating 25 GB of disk space for developing in the VM, or 12 GB if you intend only to run it.

> It is recommended that you go into Settings > Power > Make sure 'Screen Blank' is set to 'Never'.

Then, create a directory named `src/` in your Home folder. We're going to move the downloaded Binutils and GCC source folders into here. This repo has been tested with versions **GCC 10.2.0** and **Binutils 2.35.1**. Later versions may have breaking changes.

### Download BinUtils
Go to the [binutils GNU mirror site](https://ftp.gnu.org/gnu/binutils/), scroll down to `binutils-2.35.1.tar.gz`, and click on it to download. You may have to double-click the `.tar.gz` file to extract. Then move your downloaded `binutils-2.35.1` folder into the `/home/src` directory you created above.

### Download GCC
Go to the [GCC GNU mirror site](https://ftp.gnu.org/gnu/gcc/) GCC's source code. Click on gcc-10.2.0 > gcc-10.2.0.tar.gz. It may take a few minutes to download. Like Binutils, double-click the `.tar.gz` file and move `gcc-10.2.0` into `/home/src`.

### Finish with the bash script
Finally, run the one-time command `./setup.sh` to finish setting up your Ubuntu environment. It may take a while. It automates the steps outlines in [OSDev Wiki's GCC Guide](https://wiki.osdev.org/GCC_Cross-Compiler#Installing_Dependencies), plus creating a necessary mount point for building the kernel.

## Running the kernel
Use the terminal to navigate the the workspace root and run `./build.sh`. Then `cd bin` and run lilOS using `qemu-system-i386 -hda ./os.bin`. You can type in the terminal, and if you shut down the OS and edit the files inside `lilOS/programs/`, you can change the text that appears on screen. You can also type!
![lilOS terminal](https://github.com/user-attachments/assets/8e036267-fa67-42e0-bcee-f1457dd90866)

## Further development?
Development of LilOS is on indefinite hiatus. I've shifted my focus to [a new kernel project](https://github.com/elchukc/qwos) to test my knowledge on a more independent kernel project, so it's unlikely lilOS will see further development.
