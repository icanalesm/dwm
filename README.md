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
  - Tags and layout: [Font Awesome](https://github.com/FortAwesome/Font-Awesome)
* Key bindings
  - `dmenu`: [my fork of dmenu](https://github.com/icanalesm/dmenu)
  - Terminal: [rxvt-unicode](http://software.schmorp.de/pkg/rxvt-unicode.html)
  - Volume control: [amixer](http://www.alsa-project.org)
  - Backlight control: [brightctl](https://github.com/icanalesm/brightctl)
  - Status: [tstat](https://github.com/icanalesm/tstat)
  - Screenshots: [screenshot script](https://github.com/icanalesm/dotfiles/blob/master/scripts/scrshot) (requires [ImageMagick](https://www.imagemagick.org/))

Useful tools for configuration:

* `xev` to get the key codes for multimedia keys.
* `xfontsel` to get the name of fonts.
* `xfd` to get the unicode code of characters.
* `xprop` to get properties of clients for [dwm rules](https://dwm.suckless.org/customisation/rules).

To get Font Awesome's glyph codes, check the [cheatsheet](https://www.fontawesome.com/cheatsheet).

Notice that `tstat` only sets (or prints to std) the status and it finishes. I manually update the status by pressing `MODKEY`+`shift`+`b` when I need it. To automatically update the status, `tstat` can be put in a shell script:
```
while true; do
	tstat set
	sleep 1
done
```