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


## My customisation

My [dotfiles repo](https://github.com/icanalesm/dotfiles) contains the files for setting colors, default fonts and my `.xinitrc` file.

In `config.h`:

* Fonts
  - Default sans font: [IBM Plex Sans](https://github.com/IBM/plex)
  - Tags and layout: [Font Awesome](https://github.com/FortAwesome/Font-Awesome)
* Terminal: [rxvt-unicode](http://software.schmorp.de/pkg/rxvt-unicode.html)
* Volume control: [amixer](http://www.alsa-project.org)
* Backlight control: [brightctl](https://github.com/icanalesm/brightctl)
* Status: [tstat](https://github.com/icanalesm/tstat)
* Screenshots: [screenshot script](https://github.com/icanalesm/dotfiles/blob/master/scripts/scrshot)

The [screenshot script](https://github.com/icanalesm/dotfiles/blob/master/scripts/scrshot) requires [ImageMagick](https://www.imagemagick.org/).

To get Font Awesome's glyph codes, check the [cheatsheet](https://www.fontawesome.com/cheatsheet).

Useful tools for configration:

* `xev` to get the key codes for multimedia keys.
* `xfontsel` to get the name of fonts.
* `xfd` to get the unicode code of characters.
* `xprop` to get properties of clients for [dwm rules](https://dwm.suckless.org/customisation/rules).
