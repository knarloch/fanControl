# fanControl

Simple proportional regulator for fan speed of ATI card using Radeon dirver on linux.

## installation
Build, copy (i.e. to /etc/) and then add to your `/etc/rc.local`:
```
/etc/fanController </dev/null &>/dev/null &
```
