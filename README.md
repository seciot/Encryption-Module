## Does it use AES module?
NO. It uses purely software-based encryption via VMPC algorithm.

## Disclaimer
Beware: this device is provided as-is and it's security has not been tested. It's not recommended to use this device to encrypt crucial-security files. Even if the USB impedance was matched closely to 90 Ohms to reduce radiation it is recommended to put it in metal (eg. aluminium) enclosure.  
Beware2: USB packets can be sniffed and thus attacker can steal the password sent to device. The device IV is considered more crucial to device security rather than password.  
**>> IT IS NOT RECOMMENDED TO USE THIS DEVICE AS SECURE ENCRYPTION TOOL! <<**

## Known vulnerabilities
- USB sniffing (password and data is sent in plaintext)
- EM emission is not tested - it may be possible to capture data via emitted EM radiation - can be reduced by using metal chassis
- Device integrity is not ensured - someone can alter it

## What is Encryption Module?
Encryption Module is an USB peripheral for PC that allows you to encrypt data and files using its API.
It can encrypt with chunk mode - where it serializes specified amount of data or a stream mode where it serializes until its disconnected and rebooted.

## What algorithm is used inside EMO?
It uses VMPC which was featured at FSE 2004. It is quite secure algorithm according that you use quite good password (or password file). 

## What values does it support?
Password Length: 0-255 bytes  
Chunk Size: 0-8192 bytes

## How fast is it?
It can encrypt up to 200kB/s (limit of USB CDC on FS) or even up to 40MB/s when it is used only to generate VMPC cipher data and encryption proceeds on PC's processor. (Tested on Ryzen 9 3900X)
So it's... fast (in some cases)

## Can you share the PCB layout files?
YES: https://oshwlab.com/business/stm32er3_copy
Everything was designed in EasyEDA, so there you will always have latest files.

## Where are .STL files for case?
All case files are located in EasyEDA project page (section attachments). GitHub is only for firmware & support / issues.

## How about selling this product? Can I do it?
Yes, feel free to use this as commercial product, but remember that you hold responsibility for any data breaches. If you wish you could also support me with small donation.

## How to modify the Encryption Chunk Size to eg. 64 bytes?
~~Change ```const uint16_t STREAM_CHUNK_SIZE = 0x1;``` inside `config.c` file to desired size eg. 0x40.~~  
New option: before you begin stream encryption you can send 0xF2 0x0 <16-bit number, MSB first> to set STREAM_CHUNK_SIZE variable. Beware: it needs to be done each single time you want to have it changed from default. Otherwise go with `config.c` change and reflash firmware on your EMO.

## How to communicate with module?
You can use eg. C# to send and data (example API [here](https://github.com/H1M4W4R1/Encryption-Module-API)), via any Serial library that can communicate with serial ports or for example via RealTerm. As device uses USB CDC it uses default Windows/Linux driver to handle it as Serial Port.
  
## Do I need to do anything before flashing it into EMO board?
Yes, you should change the IV for VMPC (unless you're testing device, then it's recommended to run with default one which is used in all demonstration videos).
The IV is located inside `config.c` file.
```c
// VMPC Initialization Vector, can be changed
unsigned char InitVector[IV_LENGTH] = {
0xf5, 0xb8, 0xe0, 0x36, 0x42, 0x20, 0x1a, 0xc9, 0x2d, 0x8d, 0xee, 0xd0, 0x4c, 0x5c, 0xfe, 0xb1,
0x19, 0xee, 0x2e, 0x01, 0xd3, 0x31, 0xcd, 0x7e, 0x14, 0xdb, 0x37, 0x71, 0xe9, 0xf2, 0x58, 0x94,
0xc5, 0x9e, 0xac, 0xed, 0x6e, 0xf9, 0x1b, 0x3d, 0x28, 0x8f, 0x31, 0x0c, 0xd2, 0x6a, 0x85, 0xaf,
0xe2, 0x12, 0xb5, 0x0a, 0xef, 0x68, 0x0d, 0xa9, 0x3a, 0xf7, 0xb9, 0x2a, 0xa0, 0x81, 0x77, 0xd8}; // Hardcoded
```
This vector should consist of 64 bytes (512 bits). ~~No more, no less. Otherwise it may cause firmware to crash.
I recommend to generate random 64 bytes and then enter them into `config.c` file replacing default vector.~~
With the new version of firmware updated with [this commit](https://github.com/H1M4W4R1/Encryption-Module/commit/a092f10310f43995a66dde27f71c7aa170ac6456) the IV length can be changed within `config.h` and `config.c` files. Remember to match the length of array to IV_LENGTH, otherwise there may be a bunch of errors.

