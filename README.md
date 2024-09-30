# Kernel-Lab

## 0x00. Description

A repo for recording the code of testing the linux kernel.

## 0x01. Environment

### My env

* A VM in proxmox-ve (PVE hypervisor)
  * VM Hardware :
    * 20 core vCPU
    * 16 GiB RAM
    * 96 GB storage
  * OS :
    * ubuntu server 24.04
      * info of ```uname -s``` :
        * Linux ubuntu-server 6.8.0-45-generic #45-Ubuntu SMP PREEMPT_DYNAMIC Fri Aug 30 12:02:04 UTC 2024 x86_64 x86_64 x86_64 GNU/Linux
* Host :
  * hardware :
    * 19-10900E (10c20t)
    * 128 GiB ram
  * OS :
    * PVE 8.2.2 (Linux 6.8.4-2-pve)

## 0x02. Examples

### A. Hello-module

note : [hello_kernel_module](hello_kernel_module/README.md)

## 0x03. some useful commands

* **lsmod** :
  * purpose : list modules which has been loaded into kernel
  * full name : list modules
  * included info :
    * module name
    * module size
    * used by other module?
* **modinfo** :
  * purpose : list the info of a specific module
  * full name : module info
  * included info :
    * file name (path)
    * license
    * author
    * description
    * ... etc
* **dmesg** :
  * purpose : display boot message.
  * full name : display message
  * other :
    * we can see module init/exit message here.
* **uname** :
  * full name : unix name
  * purpose : show the system info
  * arguments :
    * **-a** : all info
      * include : kernel name, host name, os ver, cpu type ... etc
    * **-r** : kernel release number
