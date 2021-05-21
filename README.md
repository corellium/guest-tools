# guest-tools

Corellium Virtual Machines expose extra features to researchers and programmers compared to physical devices.
Some of these features can be accessed from inside the VM (from the guest OS kernel or user programs).

This repository contains snippets of code, and some simple tests for them, that exercise these features:

- `ranchu` - for Android VMs
    - `rtc` - precise real time (unaffected by VM RTC)
    - `unicopy` - read kernel information and access kernel / physical RAM of the VM
- `ios` - for iOS VMs (**note:** Makefile is for Darwin cross-tools)
    - `rtc` - precise real time (unaffected by VM RTC)
    - `unicopy` - read kernel information and access kernel / physical RAM of the VM

More information is available at [Corellium Knowledge Base](https://support.corellium.com/hc/en-us).
