---
title: Working Without Mouse or Trackpad On Linux
date: 2017-09-04
categories:
    - tech
tags:
    - Ubuntu
    - Linux
    - Vim
    - Efficiency
---

A significant and continuous improvement on my working efficiency has been observed, since the day I started to work with only a keyboard.
As this working style makes me feel so delighted (and has many advantages),
I thus consider this is a must to share my thoughts and some basic techniques about how to work without a mouse.

> Note:    
> 1. Some techniques in this post can also be applied to **Windows** and **Mac OS**.
> 2. ~~As I am still learning, I may update this post occasionally.~~
> 3. While I am talking about Linux in this post, I mainly refer to `Ubuntu` distribution.

## Benefits
After you gained some techniques from this post, you will find the major benefits of working without a mouse are:

- **Saving time** of moving your hands as they almost never leave the main area of the keyboard
- **Alleviating** wrist and finger **pain** <sup>1</sup>
- Improving your working **efficiency** and **productivity**
- Enhancing your **typing speed** subconsciously
- It looks **coooooooool**

1: A research conducted by Foye et al. (2002) states that "repetitive or prolonged" using a computer mouse may contribute to Tenosynovitis.
According to AAOS (American Academy of Orthopaedic Surgeons), Tenosynovitis is the inflammation of the sheath that surrounds the tendon,
which can cause chronic pain and "tenderness along the thumb side of the wrist".

## Who Is Suitable To Work Without A Mouse?
Not every type of work is suitable with this working style, so choose your style wisely.
For instance, if you are a UI developer, then go with IDEs and mouse; those are your good friends.  
If you satisfy most following conditions, this post is going to boost your efficiency like a Saturn-V Rocket.  

- You rarely do front-end developing
- You rarely do graphic design / research
- You prefer working with command line than GUI (Graphical User Interface)
- You are exciting about learning new technologies
- Coding/writing accounts for your most working time

## Tools That Help You Leave Your Mouse
Since you are already here, I assume you have a Linux OS on your machine (FYI: I use Ubuntu 16.04 when I wrote the post).
If you have not installed Linux, then this may be a good opportunity to have one.

Some tools I will talk about:

- A mechanical keyboard (recommend `brown` or `blue` switch for long-time typing)
- [Vimium](#loc_vimium) (an extension for browsing, available on Chrome)
- [Vim](#loc_vim) (a highly-configurable text editor)
- [wasavi](#loc_wasavi) (an extension that changes a text-area element to virtual vi editor, available on Chrome, Opera and Firefox)

In addition to the tools mentioned above, I strongly encourage you to use ten fingers for typing.
If you are struggling with it, there are a lot of great online resources that can help you practising your typing skill (search with keywords like: `typing practise` or `typing game`).

Short story: I used to type with only three to five fingers.
One day, before I decided to transfer to ECE (~~Early Childhood Education~~Electrical & Computer Engineering),
I realized if I let typing be the obstacle on my study career, then that would be too ridiculous.
Therefore, I settled down and started practising typing like a kid who get access to a computer for the first time.
Beginning with single letters, to short prefixes, suffixes and phrases until long sentences.
Believe it or not, it was really tough for the first few days.
My fingers were so dump as if I could not control them.
After over a month of practising, my average wpm (word per minute) increased from 30 to 80.

So give yourself some time to let ten-finger typing be one of your friends :)
  

### Common Shortcut Keys On General

Note: following commands are **case-sensitive**.

1. View Keyboard Shortcuts manual

    > long press `Super`; `Super` is another name of `Win` key on Linux.
    
    ![alt text][7]
    
2. Select software from the left-side launcher

    > Method-1: Long press `Super` until number shows on the left-side launcher; press the corresponding number to open the software.  
    > Method-2: use `Super + Tab` to switch (like how you use `Alt + Tab` to switch program)  
    > Method-3: use `Super + Shift + number`.

3. Maximize/minimize or share screen

    `Ctrl + Super + up`&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - maximize (until full screen)  
    `Ctrl + Super + down`&nbsp;&nbsp;&nbsp; - minimize (to default / until it minimized to launcher)  
    `Ctrl + Super + left`&nbsp;&nbsp;&nbsp; - move window to the left  
    `Ctrl + Super + right` - move window to the right
3. Open & close terminal

    `Ctrl + Alt + t` - open a new terminal  
    `Ctrl + Shift + t` - open a new terminal tab  
    `Ctrl + Shift + w` - close current terminal tab
4. Use `cd` to travel everywhere (file system) on your Linux

5. Remap `CapsLock` to `Ctrl` to increase efficiency, and to ease finger pain; a guide -> [How To Remap][10]

    If you are comfortable with current `Ctrl` position, then stay with it.
6. Switch software

    `Alt+Tab`
7. Open window menu

    `Alt + space`
    > For example, I can press `Alt + space` to see a drop down menu, then type `c` to close the selected software. 
8. Access top drop down menu (file menu) for most software
    
    `Alt + ` corresponding letter
    > When you press `Alt`, there will be a underline of a letter for each option in the top menu.  
    > This also works with the file system.
9. Open files in GUI

    > Type the filename; a small box will then appear on the right bottom of your screen;  
    > Corresponding file will be highlighted;  
    > Hit `Enter` to open.

<a name="loc_vimium"></a>
### [Vimium][1]

With `Vimium`, you can enable keyboard shortcuts for navigation and control on any web-pages.

#### Most used commands:

> `f` - open a link on current page  
> `F` - open a link on a new page  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Alternatively, `f` + `Shift` + corresponding char  
> `h` - scroll screen left  
> `l` - scroll screen right  
> `j` - scroll screen down  
> `k` - scroll screen up  
> `u` - scroll page up  
> `d` - scroll page down
  
> `gg` - move to the top of the page  
`G`&nbsp;&nbsp;&nbsp; - move down to the bottom of the page  

> `Shift + h` - go back to the previous page  
> `Shift + l` - go to the next page  
> `Shift + j` - move to one left tab  
> `Shift + k` - move to one right tab

#### Detailed Cheat Sheet:
![alt text][8]

<a name="loc_vim"></a>
### [Vim][5]

In fact, `Vimium` is built in the spirit of `Vim`. Hence, you can find some commands in common.
> Then why introduced `Vim` after `Vimium`?
    
Because `Vim` is really a tool for life-long learning, and moreover, I just used it for few weeks,
the stuff I know is merely the tip of an iceberg. 

Through the process of finding information about Vim,  
I found somebody said he has been using Vim **over 15 years and still learning**;  
I found somebody has his vimrc (Vim configuration file) **over 1500 lines**;  
I also found a joke says: "A highly-configured `Vim` can reach **one-third** performance of `Visual Studio.`" :)

#### Basic commands (case-sensitive):

1. Move cursor

	`h` - moving left for one unit  
	`l` - moving right for one unit  
	`j` - moving down for one line  
	`k` - moving up for one line
2. Move screen

    `Shift + PageUP/PageDown`
3. Search word/phrases

	`/` + the word you are searching  
	
	`*` - next occurrence of the word  
	`#` - previous occurrence of the word
4. Save & quit

    `:w!` - save  
	`:q!` - quit  
	`:wq!` - save & quit  
	`:w !sudo tee %` - top permission to save & quit
	> `!` stands for overwrite
5. Enter Visual mode
	
	`V`, then move cursor to select line(s)
6. Copy & paste

    `dd` - cut current line  
	`p` - paste the line after the cursor  
	`P` - paste the line before the cursor
7. Move to the end of a line.

    `$` - simply move to the end of the line  
    `A` - appending at the end of the line. (i.e. this auto enters `insert` mode)
8. Delete

    `x` - delete the single character at the cursor  
    `dw` - delete all characters of a word that after the cursor  
    `d$` - delete to the end of the line after cursor
    
#### Detailed Cheat Sheet
![alt text][9]

<a name="loc_wasavi"></a>
### [Wasavi][6]

> wasavi is a clone of vi editor and extends a TEXT-AREA element.  
> If you focus a TEXT-AREA element and press `Ctrl+Enter`, TEXT-AREA turns into `vi` editor.

A browser extension wrote by Japanese developers. It has similar commands as the `Vim` text editor. 

P.S. Can anyone tell me what `wasavi` means in Japanese? I could not find an answer...

### Browser (Chrome)

Below are some shortcut keys that works with Chrome.
I believed these are common for most browsers, but I only tested with Chrome.
Taken responsibilities into account, I suggest you play these commands with blank pages first to avoid potential losses.

Additionally, these commands are still useful even when you have `Vimium` installed,
because you may use `Incognito` mode sometimes (unless you enable extension on `Incognito` mode).

#### Useful commands:

`Ctrl + w` - close current tab  
`Ctrl + n` - open a new tab

`Shift + 9` - go to the last tab  
`Shift + w` - show current tab in a new window.  
`Shift + number key` - go to the corresponding tab (counts form left)

`Ctrl + Shift + t` - open last closed tab  
`Ctrl + Shift + n` - enter `Incognito` mode

`Alt + left` - go back to the previous page  
`Alt + right` - go to the next page

## Useful Links

`Vim`, `Vimium` and `wasavi` are open source software on Github, you can find them here:  
- [Vim - Github][4]
- [Vimium - Github][3]
- [wasavi - Github][6]

## References
1. Foye, P. M., Cianca, J. C., & Prather, H. (2002). Cumulative trauma disorders of the upper limb in computer users. Archives of Physical Medicine and Rehabilitation, 83. doi:10.1053/apmr.2002.32144  
Retrieved from http://www.archives-pmr.org/article/S0003-9993(02)80005-3/pdf
2. De Quervain's Tendinosis. (n.d.). American Academy of Orthopaedic Surgeons, Retrieved from http://orthoinfo.aaos.org/topic.cfm?topic=A00007

[1]: https://chrome.google.com/webstore/detail/vimium/dbepggeogbaibhgnhhndojpepiihcmeb?hl=en
[2]: https://vimium.github.io/
[3]: https://github.com/philc/vimium
[4]: https://github.com/vim
[5]: https://vim.sourceforge.io/
[6]: https://github.com/akahuku/wasavi

[7]: /assets/images/posts/Work-Without-Mouse/linux_keyboard_shortcuts.jpg "Ubuntu Keyboard Shortcut"
[8]: /assets/images/posts/Work-Without-Mouse/vimium-cheatsheet-big.png "Vimium Cheat Sheet"
[9]: /assets/images/posts/Work-Without-Mouse/vim-cheatsheet.png "Vim Cheat Sheet"

[10]: https://askubuntu.com/questions/33774/how-do-i-remap-the-caps-lock-and-ctrl-keys