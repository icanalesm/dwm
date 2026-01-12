# My fork of dwm

Forked from [https://git.suckless.org/dwm/](https://git.suckless.org/dwm/) with my patches:

* [tagIndicator](https://github.com/icanalesm/dwm/tree/tagIndicator)
* [layoutfirst](https://github.com/icanalesm/dwm/tree/layoutfirst)
* [notitle](https://github.com/icanalesm/dwm/tree/notitle)
* [free_fontset](https://github.com/icanalesm/dwm/tree/free_fontset)

![mydwm](img/mydwm.png)


## Requirements

To build dwm, the libX11, libXft and libXinerama header files are required.

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

[My dotfiles](https://github.com/icanalesm/dotfiles) contain the scripts used in `config.h`, files for setting terminal colors, default fonts and my `.xinitrc` file, among other things.

In `config.h`:

* Fonts
  - Tags and layout: [Font Awesome](https://github.com/FortAwesome/Font-Awesome) (to get the codes, [search icons](https://fontawesome.com/icons))
* Key bindings
  - `dmenu`: [my fork of `dmenu`](https://github.com/icanalesm/dmenu)
  - Terminal: [my fork of `st`](https://github.com/icanalesm/st)
  - Volume control: [`wpctl`](https://pipewire.pages.freedesktop.org/wireplumber/tools/wpctl.html) and [dwmui](https://github.com/icanalesm/dwmui)
  - Backlight control: [`brightnessctl`](https://github.com/Hummer12007/brightnessctl) and [dwmui](https://github.com/icanalesm/dwmui)
  - Status: [my configuration](https://github.com/icanalesm/dwmui/blob/master/dwmblocks-async/config.h) of [dwmblocks-async](https://github.com/UtkarshVerma/dwmblocks-async)
  - Screenshots: [my script](https://github.com/icanalesm/dotfiles/blob/master/.local/bin/scrshot) (requires [ImageMagick](https://www.imagemagick.org/))
  - Monitor configuration: [my script](https://github.com/icanalesm/dotfiles/blob/master/.local/bin/monctl)

Useful tools for configuration:

* `xev` to get the key codes for multimedia keys.
* `xfontsel` to get the name of fonts.
* `xfd` to get the unicode code of characters.
* `xprop` to get properties of clients for [dwm rules](https://dwm.suckless.org/customisation/rules).

