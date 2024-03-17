## Table of Contents
- [Prerequisites](#prerequisites)
- [Project Structure](#project-structure)
- [Setting Project Name](#setting-project-name)
- [Building](#building)
- [Flashing](#flashing)
- [Cleaning](#cleaning)
- [Tools](#tools)

## Prerequisites
Install the following packages:
- `gcc-arm-none-eabi`
- `binutils-arm-none-eabi`
- `libnewlib-arm-none-eabi`
- `gdb-multiarch`
- `cmake`
- `make`
- `openocd`

## Project Structure

### CMSIS
The `CMSIS` directory contains components provided by [ARM](https://github.com/ARM-software/CMSIS_6/tree/main/CMSIS/Core) and [ST](https://github.com/STMicroelectronics/cmsis_device_l4).

```bash
CMSIS
├── Core
│   └── Include
│       ├── cmsis_compiler.h
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

The MCU and toolchain used by this project is:
| Key                  | Value         |
| -------------------- | ------------- |
| MCU                  | STM32L476RG   |
| MCU series           | STM32L4       |
| MCU CPU core         | ARM Cortex-M4 |
| MCU CPU architecture | ARMv7E-M      |
| Toolchain            | gcc           |

The components are selected based on:
| File                  | Why                    | Source |
| --------------------- | ---------------------- | ------ |
| `cmsis_compiler.h`    | Must be included       | ARM    |
| `cmsis_version.h`     | Must be included       | ARM    |
| `core_cm4.h`          | MCU CPU core           | ARM    |
| `armv7m_mpu.h`        | MCU CPU architecture   | ARM    |
| `cmsis_gcc_m.h`       | Toolchain              | ARM    |
| `stm32l4xx_gcc.ld`    | Toolchain & MCU series | ST     |
| `stm32l476xx.h`       | MCU                    | ST     |
| `stm32l4xx.h`         | MCU series             | ST     |
| `startup_stm32l4xx.c` | MCU series             | ST     |
| `system_stm32l4xx.c`  | MCU series             | ST     |
| `STM32L476.svd`       | MCU                    | ST     |

When porting this project to other device, select appropriate files based on the criteria above. Modify the linker script `xxx.ld` using the corresponding FLASH and RAM size.

### User
The `User` directory contains demonstration code.

```bash
User
├── CMakeLists.txt
├── common
│   ├── CMakeLists.txt
│   ├── include
│   │   └── common_config.h
│   └── source
│       ├── common_xxx.c
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
│   ├── README.md
│   └── source
│       └── demo_2_xxx.c
└── main.c
```

`common` directory contains header and source code used by all demonstrations.

`demo_x` directories contain header and source code used by individual demonstrations. Each demonstration contains `demo_x_enter.c` which provides the `demo_x_enter` function to initialize the device and run in an infinite loop.

`main.c` invokes a specifc demonstration by calling the respective `demo_x_enter` function.

## Setting Project Name
In the project root directory, modify the <PROJECT_NAME> entry in `CMakeLists.txt`:
```cmake
project(
    <PROJECT_NAME>
    LANGUAGES C ASM
)
```

## Building
In the project root directory, use the following commands one by one:
```bash
cmake -B build .
cmake --build ./build
```

## Flashing
In the `build` directory, use the following command:
```bash
openocd -f interface/stlink.cfg -f target/stm32l4x.cfg -c "program <PROJECT_NAME>.elf verify reset exit"
```

## Cleaning
In the `build` directory, use the following command:
```bash
rm -rf *
```

## Tools
Use the following command to shows all the predefined macros
```bash
arm-none-eabi-gcc -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mthumb -E -dM -< /dev/null | sort
```

In the `build` directory, use the following command to view the dieassembly code:
```bash
arm-none-eabi-objdump -d <PROJECT_NAME>.elf
```

In the `build` directory, use the following command to view the symbol table:
```bash
arm-none-eabi-objdump -t <PROJECT_NAME>.elf
```

In the `build` directory, use the following command to view the output information:
```bash
arm-none-eabi-readelf -S <PROJECT_NAME>.elf
```

In the `build` directory, use the following command to view the size of the executable:
```bash
arm-none-eabi-size <PROJECT_NAME>.elf
```