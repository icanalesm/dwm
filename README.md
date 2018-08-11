# My fork of dwm

Forked from [https://git.suckless.org/dwm/](https://git.suckless.org/dwm/) with my patches:

* [layoutfirst](https://github.com/icanalesm/dwm/tree/layoutfirst)
* [notitle](https://github.com/icanalesm/dwm/tree/notitle)
* [fixFontExtents](https://github.com/icanalesm/dwm/tree/fixFontExtents)

![mydwm](img/mydwm.png)


## Requirements

In order to build dwm, the libX11, libXft and libXinerama header files are required.

## Installation

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
  - [Open Sans](https://fonts.google.com/specimen/Open+Sans)
  - [Font Awesome](https://github.com/FortAwesome/Font-Awesome) (tags and layout)
* Terminal: [urxvt](http://software.schmorp.de/pkg/rxvt-unicode.html)
* Volume control: [amixer](http://www.alsa-project.org)
* Backlight control: [brightctl](https://github.com/icanalesm/brightctl)

To get the glyph codes, check [Font Awesome's cheatsheet](https://www.fontawesome.com/cheatsheet)

To get the key codes, use `xev`.

