## What is Encryption Module?
Encryption Module is an USB peripheral for PC that allows you to encrypt data and files using its API.
It can encrypt with chunk mode - where it serializes specified amount of data or a stream mode where it serializes until its disconnected and rebooted.

## What algorithm is used inside EMO?
It uses VMPC which was featured at FEC 2005. It is quite secure algorithm according that you use quite good password (or password file). 

## What values does it support?
Password Length: 0-255 bytes
Chunk Size: 0-16384 bytes

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
