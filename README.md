<h1 align="center">Procedure to use building jtag interface with pio and clion on Linux</h1>

Here I assume that you have already setup pio and clion correctly and can flash firmware 
and do all the other stuff utilizing platformio and clion on your Linux Distribution installation.
Now, I am going to discuss how to

1. First, make sure that you have correctly configured
   `platformio.ini` file. For reference check the provided [platformio.ini](platformio.ini).
2. Once done with configuration, please click on the debug icon
   located in the top right corner.
   Alternatively, you can use the platformio tab as well and click debug icon there.
   **Put a few breakpoints before clicking the debug icon!**
3. Now the moment of truth. If everything goes well the debugger
   should start, and it will stop executing when it reaches the given breakpoint.
4. However, if this is not the case, and it seems like the debugger
   never ran then very likely
   we are missing some dependency or dependencies required by whatever debugger pio
   is trying to use.
5. To identify and install the missing dependencies:
    * Open the builtin terminal of clion and make sure that you are
      at the root of your pio project (*same level as your `platformio.ini`*).
    * Now the **run** following command
      ```bash
        pio debug --interface=gdb -x .pioinit
      ```
    * Now observe the output and see the missing dependency or dependencies
    * Install them on your system or provide symlink to appropriate directory
    * Now, ran the command again and now it should work on the terminal
    * Okay, now exit out of the gdb and close the terminal
    * Now you can do the Step 2 and things should work as usual

