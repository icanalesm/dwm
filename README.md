# My fork of dwm

Forked from [https://git.suckless.org/dwm/](https://git.suckless.org/dwm/) with my patches:

* layoutfirst
* notitle


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
  - [Siji font](https://github.com/stark/siji) for tags and layout
  - Open Sans
* Terminal: urxvt
* Volume control: amixer
* Backlight control: scripts in [this repo](https://github.com/icanalesm/openSUSE-installation)

### Install Siji font

(Requires: bdftopcf, mkfontdir, xset)

```
git clone https://github.com/stark/siji.git
cd siji
sudo ./install.sh -d /usr/share/fonts/misc
```

To get the glyph codes, install `xfd` and execute
```
./view.sh
```

### Key codes

To get the key codes, use `xev`.
