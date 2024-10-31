# lilOS
LilOS is a microkernel built for the purpose of 1) learning C and 2) gaining practical understanding of operating systems and the hardware-software interface.

For details about the kernel itself, see Daniel McCarthy's original [PeachOS](https://github.com/nibblebits/PeachOS).

## Running Locally
All development of this kernel was done in a VM of Ubuntu 24.04 LTS x86_64. I used Gnome Boxes, but if you're on Mac or Windows, try (VirtualBox)[https://www.virtualbox.org/]. Once you've cloned this repo and installed Qemu, you can run it using `[TODO find the exact command]`. You can type in the terminal, and if you shut down the OS and edit the files inside `lilOS/programs`, you can change the text that appears on screen, but that's pretty much it!

## Further development?
Development of LilOS is on indefinite hiatus. I've shifted my focus to [a new kernel project](https://github.com/elchukc/qwos) to test my knowledge on a more independent kernel project, so it's unlikely lilOS will see further development.