# My fork of dwm

Forked from [https://git.suckless.org/dwm/](https://git.suckless.org/dwm/) with my patches:

* [layoutfirst](https://github.com/icanalesm/dwm/tree/layoutfirst)
* [notitle](https://github.com/icanalesm/dwm/tree/notitle)
* [fixFontExtents](https://github.com/icanalesm/dwm/tree/fixFontExtents)

![mydwm](img/mydwm.png)


## Installation

Requirements: libX11, libXft and libXinerama header files.

```
git clone https://github.com/icanalesm/dwm.git
cd dwm
make
sudo make install
```


## Execution

Add the following line at the end of `~/.xinitrc` to start dwm using `startx`:
```
exec dwm
```


## My customisation (`config.h`)

* Fonts
  - [Font Awesome](https://github.com/FortAwesome/Font-Awesome) (tags and layout)
  - Open Sans
* Terminal: urxvt
* Volume control: amixer
* Backlight control: scripts in [my other repo](https://github.com/icanalesm/openSUSE-installation)

### Install Font Awesome

```
git clone https://github.com/FortAwesome/Font-Awesome.git
cd Font-Awesome
sudo cp use-on-desktop/*.otf /usr/share/fonts/truetype
fc-cache -f
```

To get the glyph codes, check [Font Awesome's cheatsheet](https://www.fontawesome.com/cheatsheet)

### Key codes

To get the key codes, use `xev`.

