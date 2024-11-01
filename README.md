# lilOS
LilOS is a microkernel built for the purpose of 1) learning C and 2) gaining practical understanding of operating systems and the hardware-software interface.

For details about the kernel itself, see Daniel McCarthy's original [PeachOS](https://github.com/nibblebits/PeachOS).

## Running Locally
All development of this kernel was done in a VM of Ubuntu 24.04 LTS x86_64. I used Gnome Boxes, but if you're on Mac or Windows, try [VirtualBox](https://www.virtualbox.org/). On your VM application of choice, create a new virtual machine out of a Ubuntu 24.04 LTS x86_64 image. I would recommend allocating 25 GB of disk space for developing in the VM, or less if you intend only to try running it.

### Setting up your VM environment
Open the terminal and enter this command to update all your packages and install the necessary dependencies for this system with `sudo apt upgrade && sudo apt install -y nasm make qemu-system-i386 git`. And then git clone this repository.

It is also recommended that you go into Settings > Power > Make sure 'Screen Blank' is set to 'Never'.

Use the terminal to navigate the the workspace root and run `./build.sh`. Then `cd bin` and run lilOS using `qemu-system-i386 -hda ./os.bin`. You can type in the terminal, and if you shut down the OS and edit the files inside `lilOS/programs/`, you can change the text that appears on screen. You can also type!

## Further development?
Development of LilOS is on indefinite hiatus. I've shifted my focus to [a new kernel project](https://github.com/elchukc/qwos) to test my knowledge on a more independent kernel project, so it's unlikely lilOS will see further development.