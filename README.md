# Table of Contents
- [Prerequisites](#prerequisites)
- [Project Structure](#project-structure)
    - [CMSIS](#cmsis)
    - [User](#user)
- [Setting Project Name](#setting-project-name)
- [Building](#building)
- [Flashing](#flashing)
- [Cleaning](#cleaning)
- [Debugging](#debugging)
    - [Session 1](#session-1)
    - [Session 2](#session-2)
    - [Frequently Used GDB Commands](#frequently-used-gdb-commands)
- [Tools](#tools)
- [References](#references)

# Prerequisites
Install the following packages:
- `gcc-arm-none-eabi`
- `binutils-arm-none-eabi`
- `libnewlib-arm-none-eabi`
- `gdb-multiarch`
- `cmake`
- `make`
- `openocd`

# Project Structure
The Development board, MCU and toolchain used by this project is:
| Key                  | Value           |
| -------------------- | --------------- |
| Development board    | STM32 Nucleo-64 |
| MCU                  | STM32L476RG     |
| MCU series           | STM32L4         |
| MCU CPU core         | ARM Cortex-M4   |
| MCU CPU architecture | ARMv7E-M        |
| Toolchain            | gcc             |

## CMSIS
The `CMSIS` directory contains components provided by [ARM](https://github.com/ARM-software/CMSIS_6/tree/main/CMSIS/Core) and [ST](https://github.com/STMicroelectronics/cmsis_device_l4).

```bash
CMSIS
├── Core
│   └── Include
│       ├── cmsis_compiler.h
|       ├── cmsis_gcc.h
│       ├── cmsis_version.h
│       ├── core_cm4.h
│       └── m-profile
│           ├── armv7m_mpu.h
│           └── cmsis_gcc_m.h
├── Device
│   └── ST
│       └── STM32L4xx
│           ├── Config
│           │   └── stm32l4xx_gcc.ld
│           ├── Include
│           │   ├── stm32l476xx.h
│           │   ├── stm32l4xx.h
│           │   └── system_stm32l4xx.h
│           └── Source
│               ├── gcc
│               │   └── startup_stm32l4xx.c
│               └── system_stm32l4xx.c
└── SVD
    └── STM32L476.svd
```

The components are selected based on:
| File                  | Why                    | Source |
| --------------------- | ---------------------- | ------ |
| `cmsis_compiler.h`    | Must be included       | ARM    |
| `cmsis_version.h`     | Must be included       | ARM    |
| `core_cm4.h`          | MCU CPU core           | ARM    |
| `armv7m_mpu.h`        | MCU CPU architecture   | ARM    |
| `cmsis_gcc.h`         | Toolchain              | ARM    |
| `cmsis_gcc_m.h`       | Toolchain & MCU core   | ARM    |
| `stm32l4xx_gcc.ld`    | Toolchain & MCU series | ST     |
| `stm32l476xx.h`       | MCU                    | ST     |
| `stm32l4xx.h`         | MCU series             | ST     |
| `startup_stm32l4xx.c` | MCU series             | ST     |
| `system_stm32l4xx.c`  | MCU series             | ST     |
| `STM32L476.svd`       | MCU                    | ST     |

> [!NOTE]
> When porting this project to other device, select appropriate files based on the criteria above. Modify the linker script `xxx.ld` using the corresponding FLASH and RAM size.

## User
The `User` directory contains demonstration code.

```bash
User
├── CMakeLists.txt
├── demo_common
│   ├── CMakeLists.txt
│   ├── include
│   │   └── demo_common_config.h
│   └── source
│       ├── demo_common_xxx.c
│       ├── cortex_m4_crt0.S
│       └── syscalls.c
├── demo_1
│   ├── CMakeLists.txt
│   ├── include
│   │   └── demo_1_config.h
│   └── source
│       └── demo_1_xxx.c
├── demo_2
│   ├── CMakeLists.txt
│   ├── include
│   │   └── demo_2_config.h
│   └── source
│       └── demo_2_xxx.c
└── main.c
```

- `demo_common` directory contains header and source code used by all demonstrations.

- `demo_x` directories contain header and source code used by individual demonstrations. Each demonstration contains `demo_x_enter.c` which provides the `demo_x_enter` function to initialize the device and run in an infinite loop.

- `main.c` invokes a specifc demonstration by calling the respective `demo_x_enter` function.

# Setting Project Name
In the project root directory, modify the <PROJECT_NAME> entry in `CMakeLists.txt`:
```cmake
project(
    <PROJECT_NAME>
    LANGUAGES C ASM
)
```

# Building
In the project root directory, use the following commands one by one:
```bash
cmake -B build .
cmake --build ./build
```

# Flashing
In the `build` directory, use the following command:
```bash
openocd -f interface/stlink.cfg -f target/stm32l4x.cfg -c "program User/firmware.elf verify reset exit"
```
> [!NOTE]
> When porting this project to other device, select appropriate interface and target to replace `interface/stlink.cfg` and `target/stm32l4x.cfg`.

# Cleaning
In the `build` directory, use the following command:
```bash
rm -rf *
```

# Debugging
The debugging process requires two shell sessions.

## Session 1
In any directory, use the following command:
```bash
openocd -f interface/stlink.cfg -f target/stm32l4x.cfg -c "gdb_port 3333"
```
> [!NOTE]
> When porting this project to other device, select appropriate interface and target to replace `interface/stlink.cfg` and `target/stm32l4x.cfg`.

## Session 2
In the `build` directory, open another terminal, use the following command:
```bash
gdb-multiarch User/firmware.elf
```

After seeing the prompt from GDB, use the following command:
```bash
target remote localhost:3333
```

## Frequently Used GDB Commands
| Command              | Description                            |
| -------------------- | -------------------------------------- |
| `monitor reset halt` | Reset and halt                         |
| `i b`                | List all breakpoints                   |
| `d 2`                | Delete breakpoint 2                    |
| `b foo.c:18`         | Set a breakpoint at line 18 of `foo.c` |
| `p foo`              | Print `foo` in decimal format          |
| `p/t foo`            | Print `foo` in binary format           |
| `p/x foo`            | Print `foo` in hexadecimal format      |
| `c`                  | Continue                               |
| `s`                  | Step into                              |
| `n`                  | Step over                              |
| `bt`                 | Print trace of all frames              |

# Tools
Use the following command to shows all the predefined macros
```bash
arm-none-eabi-gcc -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mthumb -E -dM -< /dev/null | sort
```

In the `build` directory, use the following command to view the dieassembly code:
```bash
arm-none-eabi-objdump -d User/firmware.elf
```

In the `build` directory, use the following command to view the symbol table:
```bash
arm-none-eabi-objdump -t User/firmware.elf | sort
```

In the `build` directory, use the following command to view the output information:
```bash
arm-none-eabi-readelf -S User/firmware.elf
```

In the `build` directory, use the following command to view the size of the executable:
```bash
arm-none-eabi-size User/firmware.elf
```

# References
- [ARMv7-M Architecture Reference Manual (DDI 0403)](https://developer.arm.com/documentation/ddi0403/latest/)
- [STM32L47xxx Reference Manual (RM0351)](https://www.st.com/resource/en/reference_manual/rm0351-stm32l47xxx-stm32l48xxx-stm32l49xxx-and-stm32l4axxx-advanced-armbased-32bit-mcus-stmicroelectronics.pdf)
- [STM32L476xx Datasheet (DS10198)](https://www.st.com/resource/en/datasheet/stm32l476je.pdf)
- [STM32 Nucleo-64 Boards User Manual (UM1724)](https://www.st.com/resource/en/user_manual/um1724-stm32-nucleo64-boards-mb1136-stmicroelectronics.pdf)