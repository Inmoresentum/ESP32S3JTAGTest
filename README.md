<h1 align="center">Procedure to use builtin jtag interface with pio/platformio and clion</h1>

Here I assume that you have already setup [pio](https://platformio.org/)
and [clion](https://www.jetbrains.com/clion/) correctly and can flash firmware 
and do all the other stuff utilizing platformio (*pio*) and
clion on your Linux Distribution installation.
Now, I am going to discuss how to use the
ESP32-S3 builtin [JTAG interface](https://en.wikipedia.org/wiki/JTAG) (*usb*)
along with clion IDE's advanced debugging features.
Similar steps should work with other supported boards as well.

1. First, make sure that you have correctly configured
   `platformio.ini` file. For reference check the provided [platformio.ini](platformio.ini).
2. Once done with configuration, please click on the debug icon
   located in the top right corner.
   Alternatively, you can use the platformio tab as well and click debug icon there.
   **Put a few breakpoints before clicking the debug icon!**
3. Now the moment of truth. If everything goes well the debugger
   should start, and it will stop executing when it reaches the given breakpoint.
4. However, if this is not the case, and it seems like the debugger
   never ran (*no error or anything is thrown or shown*) then very likely
   we are missing some dependency or dependencies required by whatever debugger pio
   is trying to use.
5. To identify and install the missing dependencies:
    * Open the builtin terminal of clion and make sure that you are
      at the root of your pio project (*same level as your `platformio.ini` file*).
    * Now **run** the following command:
      ```bash
        pio debug --interface=gdb -x .pioinit
      ```
    * After previous step, observe the output and see the missing dependency or dependencies
    * Install them on your system or provide symlink to appropriate directory
    * Now, run the command again and it should work on the terminal
    * If everything is okay then exit out of the gdb and close the terminal
    * Finally, you can do the Step 2 and things should work as usual

If this is helpful then please give it a star!

##### In case of problem, feel free to create [issue(s)](https://github.com/Inmoresentum/ESP32S3JTAGTest/issues/new).

