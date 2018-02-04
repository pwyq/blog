---
title: Welcoming Arch Linux to My Thinkpad X1C
date: 2018-02-03
categories:
    - tech
tags:
    - Arch
    - Linux
---

## Under Construction

I blew my Ubuntu OS three days ago.   
Long story short, I stuck in an infinite login loop, and I couldn't find a workaround to address the problem (with 2-hour intensive googling). 
Well, since I need to re-install my system anyway, why not try something new.
Though I've spent more than one year on Ubuntu Linux (daily use and at work), it's still took me two nights to configure everything in Arch.

> I would definitely NOT recommend a total newbie to Linux to try *Arch Linux*. IT'S TOO "LIGHT"!

## Installation & Configuration
Since there are plenty of decent and mature online tutorials, it would be pointless for me to reinvent the wheel.
I will recommend some of them below that I followed with.  
**Notes**:  
> 1. Make sure you understand how each command works (use `man <cmd>` or `<cmd> --help` to display commands' descriptions)
> 2. *Always* refer to [Arch Wiki][6] first when you are confused

### Tutorial in English
- [Installing and configuring Arch Linux on Thinkpad X1 Carbon][4]

### Tutorials in Chinese
- [以官方Wiki的方式安装ArchLinux][1]
- [ArchLinux安装后的必须配置与图形界面安装教程][2]
- [ArchLinux你可能需要知道的操作与软件包推荐「持续更新」][3]
- [配置和美化Arch Linux][5]

I really like Thinkpad, as it doesn't require me to spend extra time to configure hardware.
Everything works out of box!
My configuration:

| Service | Name |
| ------- |:----:|
| Display server | Xorg |
| Desktop Environment | KDE Plasma 5 |
| Display Manager | SDDM |
| Window Manager | KDE |
| Shell | zsh + oh-my-zsh |
| Terminal emulator | Konsole |
| Widget toolkit | gtk5-base |
| more...

## Things Outside the Tutorials
Here I will talk about some stuff that are not covered in aforementioned tutorials.

### Reducing reboot waiting time
At early installation & configuration times, you need to reboot the system frequently,
during such period you might see a message like `A stop job is running for session ... (1 min 30s)`.
This waits for 90 sec to continue the reboot process.
You can reduced the time out in `/etc/system/system.conf`:

    DefaultTimeoutStartSec=30s
    DefaultTimeoutStopSec=30s

Then you need to reload system manager with `systemctl daemon-reload`.

### Calling terminal using keyboard shortcut
In my configuration, it didn't come with the default `ctrl+alt+t` to call a terminal.
If you are using `KDE` desktop environment, this can be set in `Global Shortcuts`.
First, press the `Super` (aka `Win`) key to show the menu. Then, just search with `shortcut`.

One lesson I learnt for this time is to: **first explore available settings via GUI**, then play with the command-line & scripts.
In next point, I will talk about my exhausted experience to merely remap caps-lock and ctrl key via scripting, which cost me more than 3 hours...

### Remap caps-lock & ctrl
Actually, this can be set with GUI if you're using `KDE`, or with `gnome-tweak-tool` if you're using `Gnome`.

Before I knew this can be easily set with GUI, I tried a trillion times to modify scripts/settings like `.Xmodmap`, `autostart-scripts`, `.xinitrc`, `setxkbmap`, and `/usr/share/sddm/scripts/Xsetup`,
and rebooted a trillion+1 times.
All the scripts either worked on current run but fails to load after a reboot,
or didn't auto-load/parse due to low priority in `KDE Plasama`,
or cost me extra few seconds to wait on login...

Again, **go through settings that available on GUI first**, just like read an instruction before using a product.
~~I know lots of people skip this, including me.~~

### Changing Weird Font on Google Chrome
I change my web browser to Google Chrome as I have a lot of important bookmarks and plug-ins on Chrome
(the default web browser is also way too "hacker" to use for me).

Anyway, the font can be set in Chrome built-in settings.

`Settings -> Advanced -> Customized Fonts`

### HiDPI Settings for High Resolution Screen
If you're using high resolution screen, the first thing you will complain is that, everything is surprisingly tiny!
The font size is like 5 or 6. 

I copied the KDE settings below, by [Arch wiki][7]:

> KDE
> You can use KDE's settings to fine tune font, icon, and widget scaling. This solution affects both Qt and Gtk+ applications.
>
> To adjust font, widget, and icon scaling together:
>
> 1. System Settings → Display and Monitor → Display Configuration → Scale Display
> 2. Drag the slider to the desired size
> 3. Restart for the settings to take effect
>
> To adjust only font scaling:
> 1. System Settings → Fonts
> 2. Check "Force fonts DPI" and adjust the DPI level to the desired value. This setting should take effect immediately for newly started applications. You will have to logout and login for it to take effect on Plasma desktop.
>
> To adjust only icon scaling:
> 1. System Settings → Icons → Advanced
> 2. Choose the desired icon size for each category listed. This should take effect immediately.


## Thoughts


<div style="text-align: right"> At Markham, 11:25 PM </div>


[1]: http://www.viseator.com/2017/05/17/arch_install/
[2]: http://www.viseator.com/2017/05/19/arch_setup/
[3]: http://www.viseator.com/2017/07/02/arch_more/
[4]: https://kozikow.com/2016/06/03/installing-and-configuring-arch-linux-on-thinkpad-x1-carbon/
[5]: http://www.bijishequ.com/detail/220866
[6]: https://wiki.archlinux.org/