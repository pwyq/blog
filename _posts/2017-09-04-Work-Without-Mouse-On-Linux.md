---
title: Work Without Mouse or Trackpad On Linux
date: 2017-09-04
categories:
    - tech
tags:
    - Linux
    - Vim
    - Efficiency
---

A significant improvement on my working efficiency has been observed, since the day I started to work with only a keyboard.
As this working style makes me feel so delighted, I thus decided to share my thoughts and some basic techniques about it.

Sidenotes:
 
> 1. Some techniques in this post can also be applied to Windows and Mac OS.
> 2. As I'm still learning, I will keep updating this post from time to time.

## Benefits
The major benefits of working without mouse are:

- **Saving time** of moving your hands as they never leave the main area of the keyboard
- Saving manipulating time of most software with powerful commands (using the least amount of keystrokes)
- Improving your working **efficiency** and **productivity**
- **Alleviating** wrist and finger **pain** of using mouse
- Enhancing your **typing speed** subconsciously
- It looks **coooool** <= *this one is more than enough, isn't it?*

## Am I Suitable To Work Without Mouse?
Not every type of work is suitable with this working style, so choose your style wisely.
For instance, if you are a `CSS+HTML` developer, then go with IDEs and mouse; those are your good friends.  
If you satisfy most following conditions, this post going to boost your efficiency like a Saturn-V Rocket.  

- You rarely do front-end developing
- You rarely do graphical design
- You prefer working with command line than GUI (graphic user interface)
- You are existing about learning new technologies
- coding/writing accounts for your most working time

## Tools That Help You Leave Your Mouse
Since you're already here, I assume you have a Linux OS on your machine (FYI: I use Ubuntu 16.04).
If you haven't installed Linux, then this may be a good opportunity to have one.

Some tools I will talk about:

- A mechnical keyboard (recommend `brown` or `blue` switch for long-time typing)
    - I heard `Dvorak` layout keyboard is even incredible for typing
- [Vimium][1] (an extension for browsing, availbe on Chrome)
- [Vim][5] (a highly-configurable text editor)
- [wasavi][6] (an extension that changes a textarea element to virtual vi editor, available on Chrome, Opera and Firefox)

In addition to the tools mentioned above, I strongly encourage you to use ten fingers for typing.
If you are struggling with it, there are a lot of great online resources that can help you practising your typing skill (search with keywords like: `typing practise` or `typing game`).

Short story: I used to type with only three to five fingers.
One day, before I decided to transfer to ECE (~~Early Childhood Education~~Electrical & Computer Engineering),
I realized if I let typing be the obstacle on my study career, then that would be too ridiculous.
Therefore, I settled down and started practising typing like a kid who get access to a computer for the first time.
Beginning with single letters, to short prefixes, suffixes and phrases until long sentences.
Believe it or not, it was really tough for the first few days.
My fingers was so dump as if I could not control it.
After over a month of practising, my wpm (word per minute) increased from 30 to 80.

So give yourself some time to let ten-finger typing be one of your friends :)
  

### Common Shortcut Keys On General

Note: following commands are case-sensitive

1. To view Keyboard Shortcuts manual

    > long press `Super`; `Super` is another name of `Win` key on Linux.
    
    ![alt text][7]
    
2. To select software from the left-side launcher

    > Long press `Super` until number shows on the left-side launcher;  
    > Press corresponding number to open the software.   

3. To maximize/minimize or share screen

    `Ctrl + Super + up`&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - maximize (until full screen)  
    `Ctrl + Super + down`&nbsp;&nbsp;&nbsp; - minimize (to default / until it minimized to luncher)  
    `Ctrl + Super + left`&nbsp;&nbsp;&nbsp; - move window to the left  
    `Ctrl + Super + right` - move window to the right
3. To open terminal

    `Ctrl + Shift + t`
4. Use `cd` to travel everywhere (file system) on your Linux

5. Remap `CapsLock` to `Ctrl` to increase effiency, and to ease finger pain

    If you're comfortable with current `Ctrl` position, then stay with it.
6. To switch software

    `Alt+Tab`
7. To open window menu

    `Alt + space`
    > For example, I can press `Alt + space` to see the drop down menu, then type `c` to close a software. 
8. To access top drop down menu (file menu) for most software
    
    `Alt + ` corresponding letter
    > When you press `Alt`, there will be a underline of a letter for each option in the top menu.  
    > This also works with the file system.
9. Open files in GUI

    > Type the filename; a small box will then apear on the right bottom of your scrren;
    > Corresponding file will be highlighted;
    > Hit `Enter` to open.

### Vimium

With Vimium, you can enable keyboard shortcut for navigation and control on web-pages.

#### Most used commands:

> `f` - open link on current page  
> `F` - open link on a new page  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Alternatively, `f` + `Shift` + corresponding char
> `h` - move screen left  
> `l` - move screen right  
> `j` - move screen down  
> `k` - move screen up  
> `u` - scroll page up  
> `d` - scroll page down
  
> `gg` - move to the top of page  
`G`&nbsp;&nbsp;&nbsp; - move down to the bottom of the page  

> `Shift + h` - go back to previous page  
> `Shift + l` - go to the next page  
> `Shift + j` - move to one left tab  
> `Shift + k` - move to one right tab

#### Detailed Cheat Sheet:
![alt text][8]

### Vim

In fact, `Vimium` is built in the spirit of `Vim`. Hence, you can find some commands in common.
> Then why introduce `Vim` after `Vimium`?
    
Because `Vim` is really a tool for life-long learning, and moreover, I just used it for few weeks,
the stuff I know about vim is only the tip of an iceberg. 

Through the process of finding infomation about Vim,  
I found somebody said he uses Vim **over 15 years and still learning**;  
I found somebody has his vimrc **over 1500 lines**;  
I also found a joke says: "A highly-configured `Vim` can reach **one-third** performance of `Visual Studio.`" :)

#### Basic commands (case-sensitive):

1. To move cursor

	`h` - moving left for one unit  
	`l` - moving right for one unit  
	`j` - moving down for one line  
	`k` - moving up for one line
2. To move screen

    `Shift + PageUP/PageDown`
3. Search words in vim

	`/` + the word you're searching  
	
	`*` - next occurence of the word  
	`#` - previous occurence of the word
4. To save & quit

    `:w!` - save  
	`:q!` - quit  
	`:wq!` - save & quit  
	`:w !sudo tee %` - top permission to save & quit
	> `!` stands for overwrite
5. To enter visual mode
	
	`V`, then move cursor to select line
6. To copy & paste

    `dd` - cut current line
	`p` - paste the line after the cursor  
	`P` - paste the line before the cursor
7. To move to the end of a line.

    `$` - simply move to the end of the line  
    `A` - appending at end of line. (auto enter `insert` mode)
8. To delete

    `x` - delete the single character at the cursor  
    `dw` - delete all characters of a word that after the cursor  
    `d$` - delete to the end of the line after cursor
    
#### Detailed Cheat Sheet
![alt text][9]

### Wasavi

> wasavi is a clone of vi editor and extends a TEXTAREA element.  
> If you focus TEXTAREA element and press `Ctrl+Enter`, TEXTAREA turns into `vi` editor.

A browser extension by japanese developers. Similar commands as the `Vim` text editor. 

P.S.: Can anyone tell me what `wasavi` means in japanese? I couldn't find an answer...

### Browser (Chrome)

Below are some shortcut keys that works with Chrome.
I believed these are common for most browsers, but I only tested with Chrome.
Due to responsibility, I suggest you play these commands with blank pages first.

Additionally, these commands are still useful even you have `Vimium` installed, since you may use `Incognito` mode sometimes (unless you turn on extension on `Incognito` mode).

#### Useful commands:

`Ctrl + w` - close current tab  
`Ctrl + n` - open a new tab  
`Shift + 9` - go to the last tab  
`Shift + w` - show current tab in a new window.  
`Shift + number key` - go to the corresponding tab (counts form left)

`Ctrl + Shift + t` - open last closed tab  
`Ctrl + Shift + n` - enter `Incognito` mode

`Alt + left` - go back to previous page  
`Alt + right` - go to the next page

## Useful Links

`Vim`, `Vimium` and `wasavi` are open source software on Github, you can find them here:  
- [Vim - Github][4]
- [Vimium - Github][3]
- [wasavi - Github][6]


[1]: https://chrome.google.com/webstore/detail/vimium/dbepggeogbaibhgnhhndojpepiihcmeb?hl=en
[2]: https://vimium.github.io/
[3]: https://github.com/philc/vimium
[4]: https://github.com/vim
[5]: https://vim.sourceforge.io/
[6]: https://github.com/akahuku/wasavi

[7]: /assets/images/posts/Work-Without-Mouse/linux_keyboard_shortcuts.jpg "Ubuntu Keyboard Shortcut"
[8]: /assets/images/posts/Work-Without-Mouse/vimium-cheatsheet-big.png "Vimium Cheat Sheet"
[9]: /assets/images/posts/Work-Without-Mouse/vim-cheatsheet.png