# Example -- hello_kernel_module

Go to top menu : [click me](../README.md)

## 0x00. Purpose

Trying to make our own hello world kernel module.

## 0x01. How to do it

1. xx

## 0x02. Notes

### 1. "__init" and "__exit"

* You can see there have "__init" and "__exit" before function name

    ```c
    static int __init hello_init(void){}
    ```

* Meaning :
    1. "__init" and "__exit"  is a **MACRO** in kernel
    2. It can let compiler know the function is only used when init/exit happened.
    3. The **memory** will **be release** when it's work is finished.
       1. By putting the code at a specific area.

### 2. xx
