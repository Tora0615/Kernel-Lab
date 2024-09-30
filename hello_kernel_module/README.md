# Example -- hello_kernel_module

Go to top menu : [click me](../README.md)

## 0x00. Purpose

Trying to make our own hello world kernel module.

## 0x01. How?

### A. 

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

### 2. printK

* purpose : output data or messages to the kernel log buffer (ring buffer)
* usage :

    ```c
    printk(KERN_INFO "Message: %s\n", arg);
    ```

  * notice :
    * There **DON'T have a comma** between KERN_INFO and "Message"
    * KERN_INFO is a **MACRO** of string
* how to see log
  * by using ```sudo dmesg``` (recommend)
  * you can also see log by command```sudo cat /dev/kmsg``` to direct access log file

### 3. Makefile

#### Example code

```shell
# filename : Makefile

obj-m += hello_kernel_module.o  

all:
<tab>make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
<tab>make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

# Tab is hard to see, so I use <tab> instead
```

#### Meaning

* **obj-m += hello_kernel_module.o**
  * obj-m 是 Makefile 中常用於編譯內核模組的變數。
  * 這告訴內核編譯系統要將 hello_kernel_module.o 編譯成核心模組 hello_kernel_module.ko
    * 但你可能有疑惑，我只有 hello_kernel_module.c，hello_kernel_module.o 是怎來的？
      * 實際上，這依賴的是 kernel 的自動編譯機制 :
        * 當你執行 make 時，kernel 的構建系統會自動搜索與 .o 相對應的 .c 程式碼，並使用適當的編譯器（如 gcc 或 clang）將它編譯成 .o 文件。
        * 最終，它還會將 .o 文件進一步編譯和鏈接，生成 .ko 文件（即可加載的內核模塊）。
  * 因此這行指令更像是告訴 kernel 構建系統，你的模組名稱叫做 hello_kernel_module
* **all 與 clean 區塊**
  * 它實際上是編譯目標 (target)，是數個編譯指令的集合代名詞。
  * 呼叫方法如下 :
    * all 區塊的呼叫 : ```make all```
      * 實際會被執行的為 : ```make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules```
    * clean 區塊的呼叫 : ```make clean```
      * 實際會被執行的為 : ```make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean```
  * 撰寫規則如下 :

    ```shell
    <target>: <dependiency1> <dependiency2> <dependiency3>...
    <tab><rule1>
    <tab><rule2>
    ```

    * target 的可執行與否，依賴於所有 dependiency 是否滿足
    * 對於所有的 rule，前面都是 tab，而不是空格
  * 其他 : 
    * 當只執行單單一個 make 時，Makefile 會執行第一個出現的目標（通常是 all），除非你指定了特定目標 (e.g. clean)
* **關於指令 (rules)**
  * make 的 **-C** 參數
    * 切換工作目錄至指定路徑
  * /lib/modules/$(shell uname -r)/build
    * 該目錄是 kernel 的構建目錄，裡面包含了編譯內核模塊所需的所有文件。
    * uname -r 會返回當前內核的版本號。
  * M=$(PWD)
    * 告訴 kernel 構建系統在當前目錄（module source code directory）中尋找 Makefile 和 source code
  * 尾部的 modules 與 clean **也是 Makefile 的目標 (target)**
    * 其定義位於 ```/lib/modules/`uname -r`/build``` 目錄中的 Makefile 內。同屬 Linux kernel 構建系統的一部分。
    * 例如 clean，他的定義其實如此複雜

        ```shell
        clean: $(clean-dirs)
        $(call cmd,rmfiles)
        @find $(or $(KBUILD_EXTMOD), .) $(RCS_FIND_IGNORE) \
            \( -name '*.[aios]' -o -name '*.rsi' -o -name '*.ko' -o -name '.*.cmd' \
            -o -name '*.ko.*' \
            -o -name '*.dtb' -o -name '*.dtbo' \
            -o -name '*.dtb.S' -o -name '*.dtbo.S' \
            -o -name '*.dt.yaml' \
            -o -name '*.dwo' -o -name '*.lst' \
            -o -name '*.su' -o -name '*.mod' \
            -o -name '.*.d' -o -name '.*.tmp' -o -name '*.mod.c' \
            -o -name '*.lex.c' -o -name '*.tab.[ch]' \
            -o -name '*.asn1.[ch]' \
            -o -name '*.symtypes' -o -name 'modules.order' \
            -o -name '*.c.[012]*.*' \
            -o -name '*.ll' \
            -o -name '*.gcno' \
            -o -name '*.*.symversions' \) -type f -print \
            -o -name '.tmp_*' -print \
            | xargs rm -rf
        ```

* **其他小細節**
  * filename **SHOULD** same as "Makefile" at spelling and upper/lower case

## 0x03. ref

[[Linux Kernel慢慢學]快速上手Makefile和Kbuild Makefile](https://meetonfriday.com/posts/5523c739/)

[Makefile 介紹](https://ithelp.ithome.com.tw/articles/10317723)
