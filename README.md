<p align="center"><img src="buildroot/share/pixmaps/logo/marlin-outrun-nf-500.png" height="250" alt="MarlinFirmware's logo" /></p>

<h1 align="center">Marlin 3D Printer Firmware</h1>

<p align="center">
    <a href="/LICENSE"><img alt="GPL-V3.0 License" src="https://img.shields.io/github/license/marlinfirmware/marlin.svg"></a>
    <a href="https://github.com/MarlinFirmware/Marlin/graphs/contributors"><img alt="Contributors" src="https://img.shields.io/github/contributors/marlinfirmware/marlin.svg"></a>
    <a href="https://github.com/MarlinFirmware/Marlin/releases"><img alt="Last Release Date" src="https://img.shields.io/github/release-date/MarlinFirmware/Marlin"></a>
    <a href="https://github.com/MarlinFirmware/Marlin/actions"><img alt="CI Status" src="https://github.com/MarlinFirmware/Marlin/actions/workflows/test-builds.yml/badge.svg"></a>
    <a href="https://github.com/sponsors/thinkyhead"><img alt="GitHub Sponsors" src="https://img.shields.io/github/sponsors/thinkyhead?color=db61a2"></a>
    <br />
    <a href="https://twitter.com/MarlinFirmware"><img alt="Follow MarlinFirmware on Twitter" src="https://img.shields.io/twitter/follow/MarlinFirmware?style=social&logo=twitter"></a>
</p>

Additional documentation can be found at the [Marlin Home Page](https://marlinfw.org/).
Please test this firmware and let us know if it misbehaves in any way. Volunteers are standing by!

## Marlin RAMPS x9

This fork lets you control 9 steppers with a single Arduino Mega and RAMPS 1.4 using the recently added 9 axis support for Marlin in bugfix 2.1.

Only DRV8825 drivers tested.

A new board has been added, "BOARD_RAMPS_14_x9", its pinout is:
| Description      |  Pin   | Location  | Description |  Pin   | Location |
| :---             | :----: |     ---:  | :---        | :----: |     ---: |
| __X Motor/Axis__ |        |           |__X Endstop__|        |          |
| X_STEP_PIN       |   54   | X Socket  | X_MIN_PIN   |    3   | Endstops |
| X_DIR_PIN        |   55   | X Socket  | X_MAX_PIN   |    2   | Endstops |
| X_ENABLE_PIN     |   38   | X Socket  |             |        |          |
| __Y motor/Axis__ |        |           |__Y Endstop__|        |          |
| Y_STEP_PIN       |   60   | Y Socket  | Y_MIN_PIN   |   14   | Endstops |
| Y_DIR_PIN        |   61   | Y Socket  | Y_MAX_PIN   |   15   | Endstops |
| Y_ENABLE_PIN     |   56   | Y Socket  |             |        |          |
| __Z motor/Axis__ |        |           |__Z Endstop__|        |          |
| Z_STEP_PIN       |   46   | Z Socket  | Z_MIN_PIN   |   18   | Endstops |
| Z_DIR_PIN        |   48   | Z Socket  | Z_MAX_PIN   |   19   | Endstops |
| Z_ENABLE_PIN     |   62   | Z Socket  |             |        |          |
|__A motor/I Axis__|        |           |__I Endstop__|        |          |
| I_STEP_PIN       |   26   | E0 Socket | I_MIN_PIN   |   63   |   Aux2   |
| I_DIR_PIN        |   28   | E0 Socket | I_MAX_PIN   |   40   |   Aux2   |
| I_ENABLE_PIN     |   24   | E0 Socket |             |        |          |
|__B motor/J Axis__|        |           |__J Endstop__|        |          |
| J_STEP_PIN       |   36   | E1 Socket | J_MIN_PIN   |   42   |   Aux2   |
| J_DIR_PIN        |   34   | E1 Socket | J_MAX_PIN   |   65   |   Aux2   |
| J_ENABLE_PIN     |   30   | E1 Socket |             |        |          |
|__C motor/K Axis__|        |           |__K Endstop__|        |          |
| K_STEP_PIN       |   41   |   Aux4    | K_MIN_PIN   |   59   |   Aux2   |
| K_DIR_PIN        |   39   |   Aux4    | K_MAX_PIN   |   64   |   Aux2   |
| K_ENABLE_PIN     |   37   |   Aux4    |             |        |          |
| __U motor/Axis__ |        |           |__U Endstop__|        |          |
| U_STEP_PIN       |   35   |   Aux4    | U_MIN_PIN   |   44   |   Aux2   |
| U_DIR_PIN        |   33   |   Aux4    | U_MAX_PIN   |   66   |   Aux2   |
| U_ENABLE_PIN     |   31   |   Aux4    |             |        |          |
| __V motor/Axis__ |        |           |__V Endstop__|        |          |
| V_STEP_PIN       |   29   |   Aux4    | V_MIN_PIN   |   32   |   Aux4   |
| V_DIR_PIN        |   27   |   Aux4    | V_MAX_PIN   |   47   |   Aux4   |
| V_ENABLE_PIN     |   25   |   Aux4    |             |        |          |
| __W motor/Axis__ |        |           |__W Endstop__|        |          |
| W_STEP_PIN       |   23   |   Aux4    | W_MIN_PIN   |   45   |   Aux4   |
| W_DIR_PIN        |   17   |   Aux4    | W_MAX_PIN   |   43   |   Aux4   |
| W_ENABLE_PIN     |   16   |   Aux4    |             |        |          |

Changes made in Configuration.h:
- X_DRIVER_TYPE (line 170)
- AXIS4_ROTATES (line 210)
- DEFAULT_AXIS_STEPS_PER_UNIT (800 steps/unit, 1/4 microstepping, line 1016)
- DEFAULT_MAX_FEEDRATE (10 unit/s, 600 RPM, line 1026)
- DEFAULT_MAX_ACCELERATION (5 unit/s^2, line 1036)
- USE_XMIN_PLUG (line 880)
- X_ENABLE_ON (line 1400)
- INVERT_X_DIR (line 1439)
- X_HOME_DIR (line 1480)
- X_MAX_POS X_MIN_POS (line 1497)
- HOMING_FEEDRATE_MM_M (line 1884)

Changes made in Configuration_adv.h:
- HOMING_BUMP_MM (line 837)
- HOMING_BUMP_DIVISOR (line 838)
- AXIS_RELATIVE_MODE (line 1014)

Besides, some adjustments were needed in:
- /src/modules/probe.h: 9 arguments in NUM_AXIS_ARRAY
- /src/core/types.h: Rename operators with "v" argument to "vi"

## Marlin 2.0 Bugfix Branch

__Not for production use. Use with caution!__

Marlin 2.0 takes this popular RepRap firmware to the next level by adding support for much faster 32-bit and ARM-based boards while improving support for 8-bit AVR boards. Read about Marlin's decision to use a "Hardware Abstraction Layer" below.

This branch is for patches to the latest 2.0.x release version. Periodically this branch will form the basis for the next minor 2.0.x release.

Download earlier versions of Marlin on the [Releases page](https://github.com/MarlinFirmware/Marlin/releases).

## Example Configurations

Before building Marlin you'll need to configure it for your specific hardware. Your vendor should have already provided source code with configurations for the installed firmware, but if you ever decide to upgrade you'll need updated configuration files. Marlin users have contributed dozens of tested example configurations to get you started. Visit the [MarlinFirmware/Configurations](https://github.com/MarlinFirmware/Configurations) repository to find the right configuration for your hardware.

## Building Marlin 2.0

To build Marlin 2.0 you'll need [Arduino IDE 1.8.8 or newer](https://www.arduino.cc/en/main/software) or [PlatformIO](https://docs.platformio.org/en/latest/ide.html#platformio-ide). We've posted detailed instructions on [Building Marlin with Arduino](https://marlinfw.org/docs/basics/install_arduino.html) and [Building Marlin with PlatformIO for ReArm](https://marlinfw.org/docs/basics/install_rearm.html) (which applies well to other 32-bit boards).

## Hardware Abstraction Layer (HAL)

Marlin 2.0 introduces a layer of abstraction so that all the existing high-level code can be built for 32-bit platforms while still retaining full 8-bit AVR compatibility. Retaining AVR compatibility and a single code-base is important to us, because we want to make sure that features and patches get as much testing and attention as possible, and that all platforms always benefit from the latest improvements.

### Supported Platforms

  Platform|MCU|Example Boards
  --------|---|-------
  [Arduino AVR](https://www.arduino.cc/)|ATmega|RAMPS, Melzi, RAMBo
  [Teensy++ 2.0](https://www.microchip.com/en-us/product/AT90USB1286)|AT90USB1286|Printrboard
  [Arduino Due](https://www.arduino.cc/en/Guide/ArduinoDue)|SAM3X8E|RAMPS-FD, RADDS, RAMPS4DUE
  [ESP32](https://github.com/espressif/arduino-esp32)|ESP32|FYSETC E4, E4d@BOX, MRR
  [LPC1768](https://www.nxp.com/products/processors-and-microcontrollers/arm-microcontrollers/general-purpose-mcus/lpc1700-cortex-m3/512-kb-flash-64-kb-sram-ethernet-usb-lqfp100-package:LPC1768FBD100)|ARM® Cortex-M3|MKS SBASE, Re-ARM, Selena Compact
  [LPC1769](https://www.nxp.com/products/processors-and-microcontrollers/arm-microcontrollers/general-purpose-mcus/lpc1700-cortex-m3/512-kb-flash-64-kb-sram-ethernet-usb-lqfp100-package:LPC1769FBD100)|ARM® Cortex-M3|Smoothieboard, Azteeg X5 mini, TH3D EZBoard
  [STM32F103](https://www.st.com/en/microcontrollers-microprocessors/stm32f103.html)|ARM® Cortex-M3|Malyan M200, GTM32 Pro, MKS Robin, BTT SKR Mini
  [STM32F401](https://www.st.com/en/microcontrollers-microprocessors/stm32f401.html)|ARM® Cortex-M4|ARMED, Rumba32, SKR Pro, Lerdge, FYSETC S6
  [STM32F7x6](https://www.st.com/en/microcontrollers-microprocessors/stm32f7x6.html)|ARM® Cortex-M7|The Borg, RemRam V1
  [SAMD51P20A](https://www.adafruit.com/product/4064)|ARM® Cortex-M4|Adafruit Grand Central M4
  [Teensy 3.5](https://www.pjrc.com/store/teensy35.html)|ARM® Cortex-M4|
  [Teensy 3.6](https://www.pjrc.com/store/teensy36.html)|ARM® Cortex-M4|
  [Teensy 4.0](https://www.pjrc.com/store/teensy40.html)|ARM® Cortex-M7|
  [Teensy 4.1](https://www.pjrc.com/store/teensy41.html)|ARM® Cortex-M7|
  Linux Native|x86/ARM/etc.|Raspberry Pi

## Submitting Patches

Proposed patches should be submitted as a Pull Request against the ([bugfix-2.1.x](https://github.com/MarlinFirmware/Marlin/tree/bugfix-2.1.x)) branch.

- This branch is for fixing bugs and integrating any new features for the duration of the Marlin 2.0.x life-cycle.
- Follow the [Coding Standards](https://marlinfw.org/docs/development/coding_standards.html) to gain points with the maintainers.
- Please submit Feature Requests and Bug Reports to the [Issue Queue](https://github.com/MarlinFirmware/Marlin/issues/new/choose). Support resources are also listed there.
- Whenever you add new features, be sure to add tests to `buildroot/tests` and then run your tests locally, if possible.
  - It's optional: Running all the tests on Windows might take a long time, and they will run anyway on GitHub.
  - If you're running the tests on Linux (or on WSL with the code on a Linux volume) the speed is much faster.
  - You can use `make tests-all-local` or `make tests-single-local TEST_TARGET=...`.
  - If you prefer Docker you can use `make tests-all-local-docker` or `make tests-all-local-docker TEST_TARGET=...`.

## Marlin Support

The Issue Queue is reserved for Bug Reports and Feature Requests. To get help with configuration and troubleshooting, please use the following resources:

- [Marlin Documentation](https://marlinfw.org) - Official Marlin documentation
- [Marlin Discord](https://discord.gg/n5NJ59y) - Discuss issues with Marlin users and developers
- Facebook Group ["Marlin Firmware"](https://www.facebook.com/groups/1049718498464482/)
- RepRap.org [Marlin Forum](https://forums.reprap.org/list.php?415)
- Facebook Group ["Marlin Firmware for 3D Printers"](https://www.facebook.com/groups/3Dtechtalk/)
- [Marlin Configuration](https://www.youtube.com/results?search_query=marlin+configuration) on YouTube

## Contributors

Marlin is constantly improving thanks to a huge number of contributors from all over the world bringing their specialties and talents. Huge thanks are due to [all the contributors](https://github.com/MarlinFirmware/Marlin/graphs/contributors) who regularly patch up bugs, help direct traffic, and basically keep Marlin from falling apart. Marlin's continued existence would not be possible without them.

## Administration

Regular users can open and close their own issues, but only the administrators can do project-related things like add labels, merge changes, set milestones, and kick trolls. The current Marlin admin team consists of:

 - Scott Lahteine [[@thinkyhead](https://github.com/thinkyhead)] - USA - Project Maintainer &nbsp; [💸 Donate](https://www.thinkyhead.com/donate-to-marlin)
 - Roxanne Neufeld [[@Roxy-3D](https://github.com/Roxy-3D)] - USA
 - Keith Bennett [[@thisiskeithb](https://github.com/thisiskeithb)] - USA &nbsp; [💸 Donate](https://github.com/sponsors/thisiskeithb)
 - Peter Ellens [[@ellensp](https://github.com/ellensp)] - New Zealand
 - Victor Oliveira [[@rhapsodyv](https://github.com/rhapsodyv)] - Brazil
 - Chris Pepper [[@p3p](https://github.com/p3p)] - UK
 - Jason Smith [[@sjasonsmith](https://github.com/sjasonsmith)] - USA
 - Luu Lac [[@shitcreek](https://github.com/shitcreek)] - USA
 - Bob Kuhn [[@Bob-the-Kuhn](https://github.com/Bob-the-Kuhn)] - USA
 - Erik van der Zalm [[@ErikZalm](https://github.com/ErikZalm)] - Netherlands &nbsp; [💸 Donate](https://flattr.com/submit/auto?user_id=ErikZalm&url=https://github.com/MarlinFirmware/Marlin&title=Marlin&language=&tags=github&category=software)

## License

Marlin is published under the [GPL license](/LICENSE) because we believe in open development. The GPL comes with both rights and obligations. Whether you use Marlin firmware as the driver for your open or closed-source product, you must keep Marlin open, and you must provide your compatible Marlin source code to end users upon request. The most straightforward way to comply with the Marlin license is to make a fork of Marlin on Github, perform your modifications, and direct users to your modified fork.

While we can't prevent the use of this code in products (3D printers, CNC, etc.) that are closed source or crippled by a patent, we would prefer that you choose another firmware or, better yet, make your own.
