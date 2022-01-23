/*
 ____    ___           __            __                          ____
/\  _`\ /\_ \         /\ \__        /\ \__                      /\  _`\
\ \,\L\_\//\ \     ___\ \ ,_\    __ \ \ ,_\ __  __   ____       \ \ \L\ \
 \/_\__ \ \ \ \   /',__\ \ \/  /'__`\\ \ \//\ \/\ \ /',__\ ______\ \ ,  /
   /\ \L\ \\_\ \_/\__, `\ \ \_/\ \L\.\\ \ \\ \ \_\ /\__, `/\______\ \ \\ \
   \ `\____/\____\/\____/\ \__\ \__/.\_\ \__\ \____\/\____\/______/\ \_\ \_\
    \/_____\/____/\/___/  \/__/\/__/\/_/\/__/\/___/ \/___/          \/_/\/ /


 ______  __   __  ____    __  __
/\  _  \/\ \ /\ \/\  _`\ /\ \/\ \
\ \ \L\ \ `\`\/'/\ \ \L\_\ \ `\\ \
 \ \  __ `\/ > <  \ \  _\L\ \ , ` \
  \ \ \/\ \ \/'/\`\\ \ \L\ \ \ \`\ \
   \ \_\ \_\/\_\\ \_\ \____/\ \_\ \_\
    \/_/\/_/\/_/ \/_/\/___/  \/_/\/_/




*/
/* See LICENSE file for copyright and license details. */

/* interval between updates (in ms) */
const unsigned int interval = 500;

/* text to show if no value can be retrieved */
static const char unknown_str[] = "n/a";

/* maximum output string length */
#define MAXLEN 2048

/*
 * function            description                     argument (example)
 *
 * battery_perc        battery percentage              battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * battery_state       battery charging state          battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * battery_remaining   battery remaining HH:MM         battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * cpu_perc            cpu usage in percent            NULL
 * cpu_freq            cpu frequency in MHz            NULL
 * datetime            date and time                   format string (%F %T)
 * disk_free           free disk space in GB           mountpoint path (/)
 * disk_perc           disk usage in percent           mountpoint path (/)
 * disk_total          total disk space in GB          mountpoint path (/")
 * disk_used           used disk space in GB           mountpoint path (/)
 * entropy             available entropy               NULL
 * gid                 GID of current user             NULL
 * hostname            hostname                        NULL
 * ipv4                IPv4 address                    interface name (eth0)
 * ipv6                IPv6 address                    interface name (eth0)
 * kernel_release      `uname -r`                      NULL
 * keyboard_indicators caps/num lock indicators        format string (c?n?)
 *                                                     see keyboard_indicators.c
 * keymap              layout (variant) of current     NULL
 *                     keymap
 * load_avg            load average                    NULL
 * netspeed_rx         receive network speed           interface name (wlp4s0)
 * netspeed_tx         transfer network speed          interface name (wlp4s0)
 * num_files           number of files in a directory  path
 *                                                     (/home/foo/Inbox/cur)
 * ram_free            free memory in GB               NULL
 * ram_perc            memory usage in percent         NULL
 * ram_total           total memory size in GB         NULL
 * ram_used            used memory in GB               NULL
 * run_command         custom shell command            command (echo foo)
 * swap_free           free swap in GB                 NULL
 * swap_perc           swap usage in percent           NULL
 * swap_total          total swap size in GB           NULL
 * swap_used           used swap in GB                 NULL
 * temp                temperature in degree celsius   sensor file
 *                                                     (/sys/class/thermal/...)
 *                                                     NULL on OpenBSD
 *                                                     thermal zone on FreeBSD
 *                                                     (tz0, tz1, etc.)
 * uid                 UID of current user             NULL
 * uptime              system uptime                   NULL
 * username            username of current user        NULL
 * vol_perc            OSS/ALSA volume in percent      mixer file (/dev/mixer)
 * wifi_perc           WiFi signal in percent          interface name (wlp4s0)
 * wifi_essid          WiFi ESSID                      interface name (wlp4s0)
 *
	{ netspeed_rx ,     "^c#8EC07C^       {   %s   "   ,     "wlp4s0"                            },
	{ netspeed_tx ,     " %s } "               ,     "wlp4s0"    		                 },
	{ cpu_perc    ,     "{   %s%% } "         ,     NULL               				 },
 */
static const struct arg args[] = {
	/* function format          argument */
//    { netspeed_rx  , "^b#1d2021^^c#98971A^       %s | ", "wlp4s0"},
//    { netspeed_tx  , "祝%s          ","wlp4s0"},
    { run_command  , "^b#1d2021^^c#d79921^ 🎵 %s ", "/home/raxen/.local/configs/sourcepkgs/slstatus/components/music_notify.sh"},
	{ ram_used     , "^b#1d2021^^c#689D6A^         ﬙ %s", NULL },
	{ ram_total    , "/%s          ", NULL},
// 	{ run_command  , "^b#1d2021^^c#B16286^                    %s                   ", "amixer -c 1 -M sget Master | awk -F\"[][]\" '/%/ { print $2 }' | head -n1 | sed 's/.$//'" },
//   { run_command  , "^b#1d2021^^c#d79921^                    %s                   ", "brightnessctl -d 'amdgpu_bl0' -m | awk -F ',' '{ print $4 }' | sed 's/.$//' "},
	{ battery_perc , "^b#1d2021^^c#458588^                  %s ", "BAT0"},
    { battery_state, "%s                 ", "BAT0"},
	{ datetime     , "^b#1d2021^^c#fb4834^ %s   ", "%a %b %d %l:%M %p"},
};
