---
title: Welcoming Arch Linux to My Thinkpad X1C
date: 2018-02-03
categories:
    - tech
tags:
    - Arch
    - Linux
---

My Ubuntu OS was blown up three days ago (ㄒoㄒ).  

Long story short, I stuck in an infinite and helpless login loop in Ubuntu, and there is no feasible workaround to address the problem (with 2-hour intensive googling). 
Well, since I need to re-install my system anyway, why not try something new.
Though I've spent more than one year on Ubuntu Linux (daily use and at work), it's still took me two nights + one day to configure everything in Arch.

> I would definitely NOT recommend a total Linux newbie to try *Arch Linux*. IT'S TOO "LIGHT"!


## Installation & Configuration
Since there are plenty of decent and mature online tutorials, it would be pointless for me to reinvent the wheel.
I will recommend some of them below that I followed with.  
**Notes**:  
> 1. Make sure you understand how each command works (use `man <cmd>` or `<cmd> --help` to display commands' descriptions)
> 2. *Always* refer to [Arch Wiki][6]{:target="_blank"} when you are confused


### Tutorial in English
- [Installing and configuring Arch Linux on Thinkpad X1 Carbon][4]{:target="_blank"}


### Tutorials in Chinese
- [以官方Wiki的方式安装ArchLinux][1]{:target="_blank"}
- [ArchLinux安装后的必须配置与图形界面安装教程][2]{:target="_blank"}
- [ArchLinux你可能需要知道的操作与软件包推荐「持续更新」][3]{:target="_blank"}
- [配置和美化Arch Linux][5]{:target="_blank"}

### Everything works out of box
My installation was really smooth, thanks to above authors' hard work on their posts.
I'd like to thank Thinkpad as well, since it doesn't require extra time to configure hardware ^_^

My arch-linux configurations:

| Service Name | Type / Version |
| ------- |:----:|
| Display server | Xorg |
| Desktop Environment | KDE Plasma 5 |
| Display Manager | SDDM |
| Window Manager | KDE |
| File Manager | Dolphin |
| Shell | zsh + oh-my-zsh |
| Terminal emulator | Konsole |
| Widget toolkit | gtk5-base |


## Things Outside the Tutorials
Here I'd like to talk about some stuff that are not covered in aforementioned tutorials but are helpful to know.


### Reducing reboot waiting time
At early installation & configuration stage, you need to reboot the system frequently,
during such period you might see a message like `A stop job is running for session ... (1 min 30s)`.
This waits for 90 sec to continue the reboot process.
You can reduced the time out in `/etc/systemd/system.conf` (Here reduced to 30s):

    DefaultTimeoutStartSec=30s
    DefaultTimeoutStopSec=30s

Then you need to reload system manager with `systemctl daemon-reload`.


### Calling terminal using keyboard shortcut
In my configuration, it didn't come with the default `ctrl+alt+t` to call a terminal.
If you are using `KDE` desktop environment, this can be set in `Global Shortcuts`.
First, press the `Super` (aka `Win`) key to show the menu. Then, just search with `shortcut`.

One lesson I learnt form this time is to: **first explore available settings via GUI**, then play with the command-line & scripts.
In next point, I will talk about my exhausted experience to merely remap caps-lock and ctrl key via scripting, which cost me more than 3 hours...


### Remapping caps-lock & ctrl
Actually, this can be set with GUI if you're using `KDE`, or with `gnome-tweak-tool` if you're using `Gnome`.

In KDE, `Keyboard and Hardware Layout -> Advanced -> Ctrl Position -> Swap Ctrl and Caps Lock`

Before I knew this can be easily set with GUI, I tried a trillion times to modify scripts/settings like `.Xmodmap`, `autostart-scripts`, `.xinitrc`, `setxkbmap`, and `/usr/share/sddm/scripts/Xsetup`,
and rebooted a trillion+1 times.
All the scripts either worked on current run but fails to load after a reboot,
or didn't auto-load/parse due to low priority in `KDE Plasama`,
or cost me extra few seconds to wait on login...

Again, **go through settings that available on GUI first**! Just like read an instruction before using a product.
~~I know lots of people skip this, including me.~~


### Changing Weird Font on Google Chrome
I change my web browser to Google Chrome as I have a lot of important bookmarks and plug-ins on Chrome
(the default web browser `Konqueror` is also way too "hacker" to use for me).

Anyway, the font can be set in Chrome built-in settings.

`Settings -> Advanced -> Customized Fonts`


### HiDPI Settings for High Resolution Screen
If you're using high resolution screen, the first thing you will complain is that, everything is surprisingly tiny!
The font size is like 1-2 mm. 

I copied the KDE settings below, by [Arch wiki][7]{:target="_blank"}:

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

**Update**: you might find weird horizontal lines appear and disappear in Konsole after you scaling, this is a [known bug][8]{:target="_blank"}.


#### Adjusting Google Chrome DPI
If you feel Chrome toolbar is too small and want to scaling it, using following method ([source][9]{:target="_blank"}):

1. Open `/usr/share/applications/google-chrome`
2. Find `Exec=/usr/bin/google-chrome-stable %U`
3. change it to `Exec=/usr/bin/google-chrome-stable --force-device-scale-factor=1 %U`.
    - Change to your desire scale factor, floating point acceptable.

If above is not working, using following, ([source][10]{:target="_blank"}):

1. `sudo touch /usr/bin/google-chrome` create a file as workaround;
2. `sudo chmod a+x /usr/bin/google-chrome` make its executable;
3. `sudo vim /usr/bin/google-chrome` start editing
4. add & save (adjust scale factor to your need)
```
#!/bin/bash
google-chrome-stable --force-device-scale-factor=1
```
5. start Google Chrome in terminal using `google-chrome`
    - I find that if I start Chrome from menu, it remains the old settings. I assume this must be a path problem.
    Will try to find a workaround so that I don't need to start Chrome from terminal every time.

    
### Setting Wallpaper
**Note**: I only tested this with my configuration (as listed above)
There are a lot third parties application can also achieve this (just google it!).

For Main Screen:

    1. right click anywhere of main screen -> Configure Desktop  
    2. choose a file

For Login Screen:

    1. System Settings -> Start up and Shutdown -> Login Screen (SDDM) -> Background


## Recommended Software (Updating)
I'm still exploring on this part. QAQ

A full list of applications can be found at [here (Arch Wiki)][11]{:target="_blank"}.

- Network Manager: `NetworkManager`
- Maths: `octave`
- VPN clients: `OpenVPN`
- Webcam: `guvcview` (work for X1C, haven't check for other machines)
- Office suites: `libreoffice-fresh`


## Random Thoughts
Yeahhh, finally done the configuration and post.
Let me first show something:  
![alt text][12]
![alt text][13]

I've set so many personal first-time during this week:  
- first time to encounter an un-fixable system bug in Ubuntu
- first time to use a terminal in `tty` mode in Ubuntu (the entire machine just have no GUI, and terminal font size is like 2mm large)
- first time to install Arch from scratch!
- first time to write scripts for installation & configuration
- ...

In addition, I found myself have become much more sensitive and picky on the installation of application/dependency/package since I started using Arch.
For instance, I once installed an undesired application.
When I wanted to delete it later, I unconsciously wanted to compare all installed related dependencies one by one with the `pacman Rcns xxx` list.
Honestly, I was feeling quite uncomfortable until I was certain that every redundant dependency had been removed. Oops, am I becoming software mysophobia?


<div style="text-align: right"> At Markham, 3:44 PM </div>


[1]: http://www.viseator.com/2017/05/17/arch_install/
[2]: http://www.viseator.com/2017/05/19/arch_setup/
[3]: http://www.viseator.com/2017/07/02/arch_more/
[4]: https://kozikow.com/2016/06/03/installing-and-configuring-arch-linux-on-thinkpad-x1-carbon/
[5]: http://www.bijishequ.com/detail/220866
[6]: https://wiki.archlinux.org/
[7]: https://wiki.archlinux.org/index.php/HiDPI
[8]: https://bugs.kde.org/show_bug.cgi?id=373232
[9]: http://kernpanik.com/geekstuff/2015/05/20/chrome-change-default-hidpi-setting.html
[10]: https://bbs.archlinux.org/viewtopic.php?id=227131
[11]: https://wiki.archlinux.org/index.php/list_of_applications

[12]: /assets/images/posts/Arch-Linux-Install/login.JPG "Login Page - Darling in the Franxx 02"
[13]: /assets/images/posts/Arch-Linux-Install/info-center.png "Info Center - Arch Linux"