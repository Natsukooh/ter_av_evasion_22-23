# First evasion technique: encrypting the shellcode

This is probably the most basic evasion technique.  
The shellcode is XORed with a key, and is decrypted at compile time, after it got copied to the allocated memory area, just before spawning the thread.  
There's a python script provided to help you XOR your shellcodes.  
It takes in argument a c shellcode file generated by metasploit, and XORs it with the given key (or generates one for you), before outputting the result in a file, ready to be included by you c++ source file.  
Use the `-h` switch to get some help if you are not sure how to use it.