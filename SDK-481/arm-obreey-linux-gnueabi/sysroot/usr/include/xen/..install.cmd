cmd_/tmp/fc622_headers/include/xen/.install := perl /home/mike/ntx/linux-2.6.35.3/scripts/headers_install.pl /home/mike/ntx/linux-2.6.35.3/include/xen /tmp/fc622_headers/include/xen arm evtchn.h; perl /home/mike/ntx/linux-2.6.35.3/scripts/headers_install.pl /tmp/fc622_bin/include/xen /tmp/fc622_headers/include/xen arm ; touch /tmp/fc622_headers/include/xen/.install