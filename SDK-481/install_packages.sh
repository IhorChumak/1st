#!/bin/bash - 
#===============================================================================
#
#          FILE:  install_packages.sh
# 
#         USAGE:  ./install_packages.sh 
# 
#   DESCRIPTION:  
# 
#       OPTIONS:  ---
#  REQUIREMENTS:  ---
#          BUGS:  ---
#         NOTES:  ---
#        AUTHOR: Sergii Sokolov, 
#       COMPANY: 
#       CREATED: 28.07.2015 10:00:43 EEST
#      REVISION:  ---
#===============================================================================

set -o nounset                              # Treat unset variables as an error

sudo apt-get update && sudo apt-get install libtag1-dev nodejs libsqlite3-0 libsqlite3-dev libjson-c-dev libjson0 libjson0-dev libc6-dev build-essential libgtk2.0-dev libgtk2.0-0 libicu-dev g++ libboost-dev cmake make git libtool gcc libmorph-dev libmorph libcurl4-openssl-dev openssl libtiff5* libjpeg-turbo8* libfreetype6* realpath sqlite sqlitebrowser cmake-qt-gui tortoisehg tortoisehg-nautilus rhino

platform=`uname -i`
if [ "$platform" == "x86_64" ]
then
	sudo apt-get install gcc-multilib g++-multilib libc6-dev-i386
fi
