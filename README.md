# My fork of dwm

Forked from [https://git.suckless.org/dwm/](https://git.suckless.org/dwm/) with my patches:

* [layoutfirst](https://github.com/icanalesm/dwm/tree/layoutfirst)
* [notitle](https://github.com/icanalesm/dwm/tree/notitle)

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

My [dotfiles repo](https://github.com/icanalesm/dotfiles) contains the scripts used in `config.h`, files for setting terminal colors, default fonts and my `.xinitrc` file, among other things.

In `config.h`:

* Fonts
  - Tags and layout: [Font Awesome](https://github.com/FortAwesome/Font-Awesome) (to get the glyph codes, check the [cheatsheet](https://www.fontawesome.com/cheatsheet))
* Key bindings
  - `dmenu`: [my fork of dmenu](https://github.com/icanalesm/dmenu)
  - Terminal: [my fork of st](https://github.com/icanalesm/st)
  - Volume control: [amixer](http://www.alsa-project.org) via [my script](https://github.com/icanalesm/dotfiles/blob/master/scripts/statctl)
  - Backlight control: [brightctl](https://github.com/icanalesm/brightctl)
  - Status: [tstat](https://github.com/icanalesm/tstat)
  - Screenshots: [my screenshot script](https://github.com/icanalesm/dotfiles/blob/master/scripts/scrshot) (requires [ImageMagick](https://www.imagemagick.org/))

Useful tools for configuration:

* `xev` to get the key codes for multimedia keys.
* `xfontsel` to get the name of fonts.
* `xfd` to get the unicode code of characters.
* `xprop` to get properties of clients for [dwm rules](https://dwm.suckless.org/customisation/rules).

Notice that `tstat` only sets (or prints to stdout) the status and it finishes. I manually update the status by pressing `MODKEY`+`Shift`+`b` when I need it. To automatically update the status, `tstat` can be put in a shell script:
```
while true; do
	tstat set
	sleep 1
done
```
