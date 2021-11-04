#!/bin/sh
# vim: set noexpandtab
path="$HOME/.local/configs/sourcepkgs/xmenu/icons"
xmenu <<EOF | sh &
IMG:$path/applications-multimedia.png	Entertainment
	IMG:$path/freetube.png	freetube	freetube
	IMG:$path/lbry.png	lbry	lbry
	IMG:$path/spotify.png	Spotify	spotify
	IMG:$path/noson.png	Noson-app	noson-app
	IMG:$path/hakuneko-desktop.png	Hakuneko	hakuneko-desktop
IMG:$path/applications-internet.png	Internet
	IMG:$path/librewolf.png	LibreWolf	librewolf	
	IMG:$path/firefox.png	firefox	firefox
	IMG:$path/chromium.png	chromium	chromium
	IMG:$path/brave.png	Brave	brave
	IMG:$path/amfora.png	Amfora (Gemini TUI Browser)	xterm -e amfora
	IMG:$path/tor.png	Tor	torbrowser-launcher
IMG:$path/applications-games.png	Games
	IMG:$path/lutris.png	lutris	prime-run	lutris
	IMG:$path/yuzu.png	yuzu	prime-run yuzu
	IMG:$path/retroarch.png	retroarch	prime-run	retroarch
	IMG:$path/heroic.png	Heroic	prime-run	heroic	
	IMG:$path/steam.png	steam	prime-run steam
IMG:$path/tools.png	Tools
	IMG:$path/easyeffects.png	easyeffects	easyeffects
	IMG:$path/gimp.png	gimp	gimp
	IMG:$path/audacity.png	audacity	audacity
	IMG:$path/openshot.png	opneshot	prime-run openshot-qt
	IMG:$path/qalculator.png	qalculate	qalculate-gtk
	IMG:$path/gcolor2.png	gcolor3	gcolor3
	IMG:$path/org.inkscape.Inkscape.png	inkscape	inkscape
	IMG:$path/simplescreenrecorder.png	ScreenRecorder	prime-run simplescreenrecorder
	IMG:$path/picard.png	picard	picard	
	IMG:$path/gparted.png	gparted	gparted
	IMG:$path/kiwix	kiwix	kiwix-desktop
IMG:$path/chat.png	Chat
	IMG:$path/discord.png	Discord	discord
	IMG:$path/element-desktop-nightly.png	Element-dekstop-nightly	element-dekstop-nightly
IMG:$path/media.png	Media
	IMG:$path/vlc.png	vlc	vlc
	IMG:$path/mpv.png	mpv	mpv
IMG:$path/qbittorrent.png	qbittorrent	qbittorrent
IMG:$path/mail.png	email
	IMG:$path/electron-mail.png	Proton-mail	electron-mail
	IMG:$path/tutanota-desktop.png	Tuta-mail	tutanota-desktop
	IMG:$path/thunderbird.png	thunderbird	thunderbird
IMG:$path/pcmanfm.png	FileManager	pcmanfm
IMG:$path/text-editor.png	Text-Editor
	IMG:$path/atom.png	atom	atom
	IMG:$path/neovim.png	NVIM	st -e nvim
IMG:$path/terminal.png	Terminal-apps
	IMG:$path/st.png	st	st
	IMG:$path/alacritty.png	alacritty	alacritty
	IMG:$path/nnn.png	NNN	alacritty -e nnn 
	IMG:$path/newsboat.png	NEWSBOAT	alacritty -e newsboat 
	IMG:$path/amfora.png	Amfora (Gemini TUI Browser)	xterm -e amfora
	IMG:$path/rtv.png	tuir	alacritty -e tuir
	IMG:$path/htop.png	htop	alacritty -e htop 
	IMG:$path/bpytop.png	bpytop	alacritty -e	bpytop 
	IMG:$path/ncdu.png	Ncdu	alacritty -e ncdu 
	IMG:$path/clyrics.png	clyrics	alacritty -e clyrics -c 
	IMG:$path/	wikicurse	alacritty -e wikicurses
IMG:$path/applications-accessories.png	Accessories
	IMG:$path/org.pwmt.png	Zathura	zathura
	IMG:$path/lyriek.png	Lyriek (Lyriek)	lyriek
	IMG:$path/glava.png	Glava(MusicVisulaizer)	glava
	IMG:$path/monero-gui.png	Monero GUI (Monero-GUI)	monero-wallet-gui
	IMG:$path/virtualbox.png	Oracle VM VirtualBox (Virtual Machine)	VirtualBox
IMG:$path/applications-office.png	Office
	IMG:$path/libreoffice-base.png	LibreOffice Base (Database Development)	libreoffice --base
	IMG:$path/libreoffice-calc.png	LibreOffice Calc (Spreadsheet)	libreoffice --calc
	IMG:$path/libreoffice-draw.png	LibreOffice Draw (Drawing Program)	libreoffice --draw
	IMG:$path/libreoffice-impress.png	LibreOffice Impress (Presentation)	libreoffice --impress
	IMG:$path/libreoffice-math.png	LibreOffice Math (Formula Editor)	libreoffice --math
	IMG:$path/libreoffice-startcenter.png	LibreOffice (Office)	libreoffice
	IMG:$path/libreoffice-writer.png	LibreOffice Writer (Word Processor)	libreoffice --writer
IMG:$path/preferences-desktop.png	Settings
	IMG:$path/preferences-desktop-theme.png	Lxappearance	lxappearance
	IMG:$path/nitrogen.png	nitrogen (Wallpaper Setter)	nitrogen
	IMG:$path/nvidia-settings.png	NVIDIA X Server Settings	prime-run /usr/bin/nvidia-settings
	IMG:$path/multimedia-volume-control.png	PulseAudio Volume Control (Volume Control)	pavucontrol
	IMG:$path/qv4l2.png	Qt V4L2 test Utility	qv4l2
	IMG:$path/qvidcap.png	Qt V4L2 video capture utility	qvidcap
	IMG:$path/blueman.png	Bluetooth Manager	blueman-manager
	IMG:$path/winetricks.png	Winetricks	winetricks --gui
	IMG:$path/preferences-desktop-theme.png	Qt5 Settings	qt5ct
	IMG:$path/logo.png	LSHW	/usr/sbin/gtk-lshw
	ARandR (Screen Settings)	arandr
	Hardware Locality lstopo	lstopo
	Avahi Zeroconf Browser	/usr/bin/avahi-discover
IMG:$path/poweroffmenu.png	Power_Menu
	IMG:$path/poweroff.png	Poweroff	systemctl poweroff
	IMG:$path/reboot.png	Reboot	systemctl reboot
EOF
